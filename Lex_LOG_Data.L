%{

#include <dirent.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>
#include "Yacc_CSV_Data.tab.h"
#include "Common.h"
#include "Automate.h"

extern int yynerrs;

long    LINE_NB = 1;
long    COLUMN  = 0;
int     NB_ERREUR = 0;

FILE *O_FILE = NULL;
FILE *O_FILE_2 = NULL;
FILE *CSVO_FILE = NULL;
FILE *CSVD_FILE = NULL;

bool bSeenEOL = false;
bool bSeenEOF = false;


%}

%option noyywrap
%option batch

VAL_ENTIER                          (;;[0-9]+)
VAL_NOMBRE_REEL                     ([\+\-]?[0-9]*,[0-9]+)
VAL_FORMAT_HEXA                     ([0-9ABCDEFabcdef]+)

VAL_BLANC                           (([ ]+)|(\"{1})|([\r\n\t]))
VAL_SEPARATEUR                      (;{1})

%%

{VAL_NOMBRE_REEL}           {
                                char* pChar;
                                char test[32];
                                strcpy(test, yytext);
                                pChar = strrchr(test, ',');
                                if(pChar != NULL) {
                                    *pChar = '.';
                                }
                                else {
                                    printf("erreur, pointeur null");
                                }
                                yylval.FLOAT = atof(test);
                                return NOMBRE_REEL;
                            }
{VAL_FORMAT_HEXA}           {  /* fprintf(O_FILE,"\tL%d C%d: VAL_FORMAT_HEXA\r\n", LINE_NB, COLUMN); */ return FORMAT_HEXA; }

{VAL_BLANC}                 {}
{VAL_SEPARATEUR}            {
                                return  SEPARATEUR;
                            }

{VAL_ENTIER}                {
                                sscanf(&yytext[2], "%I64d", &yylval.LLONG);   // On formate les entiers en 64 bits pour �tre capacitaire du "Timestamp" en [ms] > 32 bits
                                /* fprintf(O_FILE,"L%d C%d: NOMBRE_ENTIER\r\n", LINE_NB, COLUMN); */
                                return ENTIER;
                            }

<<EOF>>                     {
                                if (bSeenEOL){
                                    if (COLUMN == 0){
                                        fprintf(O_FILE,"Le fichier de CANOpen est vide ! \n");
                                    }
                                    return  0;
                                }else{
                                    bSeenEOL = true;
                                    return LOG_STOPPED;
                                }
                            }

.                           {ECHO;}

%%

int main(int argc, char *argv[]) {
    const char *InputDir = "Input/";
    const char *OutputDir = "Output/";
    DIR *dossier;
    struct dirent *entree;
    FILE *I_FILE = NULL;

    if ((dossier = opendir(InputDir)) != NULL) {
        while ((entree = readdir(dossier)) != NULL) {
            if (strstr(entree->d_name, "AGV_") == entree->d_name) {
                const char *chiffres = entree->d_name + 4;
                char chemin_fichier[256];
                snprintf(chemin_fichier, sizeof(chemin_fichier), "%s/%s", InputDir, entree->d_name);
                I_FILE = fopen(chemin_fichier, "r");
                if (I_FILE != 0) {
                    bSeenEOF = false;
                    processFile(OutputDir, entree->d_name);
                    fprintf(CSVO_FILE,"Ligne ; Timestamp ; Noeud ; Type de Message ; Can_State ; Read/Write ; Expedited/Segmented ; Data_Size ; Index ; Sub_Index ; Commentaires\r");
                    fprintf(CSVD_FILE,"Ligne ; Timestamp ; Noeud ; Type de Message ; Can_State ; Read/Write ; Expedited/Segmented ; Data_Size ; Index ; Sub_Index ; Commentaires\r");
                    yyin = I_FILE;
                    yyrestart(I_FILE);
                    yylineno = 1;
                    LINE_NB = 1;
                    analyzeNewFile();
                    yyparse();
                    if (yynerrs == 0){
                        fprintf(O_FILE,"*** OK ***\r\n");
                        bSeenEOF = true;
                    }else{
                        fprintf(O_FILE,"*** NOK ***\r\n");
                    }
                    fclose(I_FILE);
                    fclose(CSVO_FILE);
                    fclose(CSVD_FILE);
                    fclose(O_FILE);
                    fclose(O_FILE_2);
                }
                else {
                    perror("Erreur lors de l'ouverture du fichier");
                }
            }
        }
        closedir(dossier);
        printf("Analyzing Completed");
    }
    else {
        perror("Erreur lors de l'ouverture du répertoire");
        return 1;
    }

    return 0;
}

void processFile(const char *repertoire, const char *nom_fichier) {
    // Extraire le nom de l'AGV (XXXX_XX)
    char agv_nom[256];
    if (sscanf(nom_fichier, "AGV_%255[^.]", agv_nom) == 1) {
        // Créer un répertoire portant le nom de l'AGV
        char chemin_repertoire[256];
        snprintf(chemin_repertoire, sizeof(chemin_repertoire), "%s/%s", repertoire, agv_nom);

        // Vérifier si le répertoire existe
        DIR *dossier = opendir(chemin_repertoire);
        if (dossier == NULL) {
            // Si le répertoire n'existe pas, créez-le
            mkdir(chemin_repertoire);
        } else {
            closedir(dossier);
        }

        printf("Analyzing File : %s........\n", agv_nom);
        // Ouvrir Output.CSV dans le répertoire de l'AGV
        char chemin_output[256];
        snprintf(chemin_output, sizeof(chemin_output), "%s/Output.CSV", chemin_repertoire);
        CSVO_FILE = fopen(chemin_output, "w+");

        // Ouvrir Debug.CSV dans le répertoire de l'AGV
        char chemin_debug[256];
        snprintf(chemin_debug, sizeof(chemin_debug), "%s/Debug.CSV", chemin_repertoire);
        CSVD_FILE = fopen(chemin_debug, "w+");

        // Ouvrir Debug.txt dans le répertoire de l'AGV
        char chemin_debugtxt[256];
        snprintf(chemin_debugtxt, sizeof(chemin_debugtxt), "%s/Debug.txt", chemin_repertoire);
        O_FILE = fopen(chemin_debugtxt, "w+");

        // Ouvrir Debug2.txt dans le répertoire de l'AGV
        char chemin_debug2txt[256];
        snprintf(chemin_debug2txt, sizeof(chemin_debug2txt), "%s/Debug2.txt", chemin_repertoire);
        O_FILE_2 = fopen(chemin_debug2txt, "w+");
    }
}

void analyzeNewFile(void) {
    nRadio.StateWrite = eEtape1;
    nIO.StateWrite = eEtape1;
    nEDS.StateWrite = eEtape1;
    nLDriver.StateWrite = eEtape1;
    nRDriver.StateWrite = eEtape1;
    nGuidance.StateWrite = eEtape1;

    nRadio.StateRead = eEtape1;
    nIO.StateRead = eEtape1;
    nEDS.StateRead = eEtape1;
    nLDriver.StateRead = eEtape1;
    nRDriver.StateRead = eEtape1;
    nGuidance.StateRead = eEtape1;
}

void yyerror(const char *errormsg)
{
    NB_ERREUR++;
    fprintf(O_FILE,"L%d C%d yyerror : %s\r\n", LINE_NB, COLUMN, errormsg);
    fprintf(O_FILE, "Ligne = %ld, colonne = %ld, text = %s\r\n\n", LINE_NB, COLUMN, yyget_text());
}





