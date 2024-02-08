%{
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Common.h"
#include "Automate.h"

void Compare(void);
void DetermineProtocolPDO(void);
void DetermineProtocolGuardState(tNode *nNodeTypeState);
void DetermineProtocolNMTNode(bool fChoice);

%}

// Bison declarations :

%union {
    unsigned int     INT;
    long long        LLONG;
    double           FLOAT;
    char *          STRING;
}

%token          UNKNOWN_LABEL
%token  <LLONG>     ENTIER
%token  <FLOAT>     NOMBRE_REEL
%token          FORMAT_HEXA
%token          SEPARATEUR
%token          LOG_STOPPED

%type   <INT>     ValeurENTIER
%type   <FLOAT>   ValeurNOMBRE_REEL

//Première règle à executer
%start   Fichier_Data_LOG


%%
// Grammar rules

Fichier_Data_LOG :
                  /* Cas d'un fichier vide */
                | Fichier_Data_LOG  Ligne  {     /* Cas d'un fichier de plusieurs lignes */
                                           }
                | error  SEPARATEUR        /* En cas d'erreur, on indique � l'analyseur de continuer au prochain lexem SEPARATEUR */
                ;

Ligne :
          Ligne_CAN_OPEN            {
                                    }
        | LOG_STOPPED               {
                                    }
        ;

Ligne_CAN_OPEN :
        Time   Channel   Fctn   Cob_ID   Length    Data0   Data1   Data2   Data3   Data4   Data5   Data6   Data7   Line_number
        {
            COLUMN = 1;
            Compare();

            LINE_NB++;
        }
    |   Time   Channel   Fctn   Cob_ID   Length    Data0   Data1   Data2   Data3   Data4   Data5   Data6   Line_number
        {
            COLUMN = 1;
            Compare();

            LINE_NB++;
        }
    |   Time   Channel   Fctn   Cob_ID   Length    Data0   Data1   Data2   Data3   Data4   Data5   Line_number
        {
            COLUMN = 1;
            Compare();

            LINE_NB++;
        }
    |   Time   Channel   Fctn   Cob_ID   Length    Data0  Line_number
        {
            COLUMN = 1;
            Compare();

            LINE_NB++;
        }
    |   Time   Channel   Fctn   Cob_ID   Length    Data0    Data1   Line_number
        {
            COLUMN = 1;
            Compare();

            LINE_NB++;
        }
    |   Time   Channel   Fctn   Cob_ID   Length    Data0    Data1   Data2   Data3   Line_number
        {
            COLUMN = 1;
            Compare();

            LINE_NB++;
        }
    |   Time   Channel   Fctn   Cob_ID   Length    Line_number
        {
            COLUMN = 1;
            Compare();

            LINE_NB++;
        }
    |   Time  ValeurHexaASCII  ValeurENTIER  Line_number
        {
            COLUMN = 1;
            fprintf(O_FILE,"Ligne Incorrecte : %d\n",LINE_NB);

            LINE_NB++;
        }

    ;

Time :
        ValeurNOMBRE_REEL   SEPARATEUR {  LigneEnCours.VALEUR_FLOAT = $1; /*printf("%10.6f", $1);*/  /*sprintf((char *)&LigneEnCours.VALEUR_FLOAT, "%10.6f", $1);*/ COLUMN++;}
    ;

Channel :
        ValeurHexaASCII     SEPARATEUR
        {
            strcpy((char *)&LigneEnCours.VALEUR_HEXA_ASCII_CHANNEL, (char *)&LigneEnCours.VALEUR_HEXA_ASCII);
            /* printf((char *)&LigneEnCours.VALEUR_HEXA_ASCII_CHANNEL ); */
            LigneEnCours.iCHANNEL = (int)strtol(LigneEnCours.VALEUR_HEXA_ASCII_CHANNEL, NULL, 16);
            COLUMN++;
        }
    ;

Fctn :
        ValeurHexaASCII     SEPARATEUR
        {
            strcpy((char *)&LigneEnCours.VALEUR_HEXA_ASCII_FCTN, (char *)&LigneEnCours.VALEUR_HEXA_ASCII);
            /* printf((char *)&LigneEnCours.VALEUR_HEXA_ASCII_FCTN ); */
            LigneEnCours.iFCTN = (int)strtol(LigneEnCours.VALEUR_HEXA_ASCII_FCTN, NULL, 16);
            Node = (eNode)LigneEnCours.iFCTN;
            NodeBMS = (eNode)LigneEnCours.iFCTN;
            /* fprintf(O_FILE,"FCTN : %s  %d    Line : %d \n",LigneEnCours.VALEUR_HEXA_ASCII_FCTN,LigneEnCours.iFCTN,LINE_NB); */
            COLUMN++;
        }
    ;

Cob_ID :
        ValeurHexaASCII     SEPARATEUR
        {
            strcpy((char *)&LigneEnCours.VALEUR_HEXA_ASCII_COB_ID, (char *)&LigneEnCours.VALEUR_HEXA_ASCII);
            /* printf((char *)&LigneEnCours.VALEUR_HEXA_ASCII_COB_ID ); */
            LigneEnCours.iCOB_ID = (int)strtol(LigneEnCours.VALEUR_HEXA_ASCII_COB_ID, NULL, 16);
            COLUMN++;
        }
    ;

Length :
        ValeurHexaASCII     SEPARATEUR
        {
            strcpy((char *)&LigneEnCours.VALEUR_HEXA_ASCII_LENGTH, (char *)&LigneEnCours.VALEUR_HEXA_ASCII);
            /* printf((char *)&LigneEnCours.VALEUR_HEXA_ASCII_LENGTH ); */
            LigneEnCours.iLENGTH = (int)strtol(LigneEnCours.VALEUR_HEXA_ASCII_LENGTH, NULL, 16);
            COLUMN++;
        }
    ;

Data0 :
        ValeurHexaASCII     SEPARATEUR
        {
            strcpy((char *)&LigneEnCours.VALEUR_HEXA_ASCII_DATA0, (char *)&LigneEnCours.VALEUR_HEXA_ASCII);
            /* printf((char *)&LigneEnCours.VALEUR_HEXA_ASCII_DATA0 ); */
            LigneEnCours.iDATA0 = (int)strtol(LigneEnCours.VALEUR_HEXA_ASCII_DATA0, NULL, 16);
            /* printf("%d     %d    \n", StateCAN.SDORx, StateCAN.SDOTx); */
            /* fprintf(O_FILE,"Fctn : %s  %d   Data0 : %s  %d    Line : %d \n",LigneEnCours.VALEUR_HEXA_ASCII_FCTN,LigneEnCours.iFCTN,LigneEnCours.VALEUR_HEXA_ASCII_DATA0,StateCAN.SDORx,LINE_NB); */
            COLUMN++;
        }
    ;

Data1 :
        ValeurHexaASCII     SEPARATEUR
        {
            strcpy((char *)&LigneEnCours.VALEUR_HEXA_ASCII_DATA1, (char *)&LigneEnCours.VALEUR_HEXA_ASCII);
            /* printf((char *)&LigneEnCours.VALEUR_HEXA_ASCII_DATA1 ); */
            LigneEnCours.iDATA1 = (int)strtol(LigneEnCours.VALEUR_HEXA_ASCII_DATA1, NULL, 16);
            COLUMN++;
        }
    ;

Data2 :
        ValeurHexaASCII     SEPARATEUR
        {
            strcpy((char *)&LigneEnCours.VALEUR_HEXA_ASCII_DATA2, (char *)&LigneEnCours.VALEUR_HEXA_ASCII);
            /* printf((char *)&LigneEnCours.VALEUR_HEXA_ASCII_DATA2 ); */
            LigneEnCours.iDATA2 = (int)strtol(LigneEnCours.VALEUR_HEXA_ASCII_DATA2, NULL, 16);
            COLUMN++;
        }
    ;

Data3 :
        ValeurHexaASCII     SEPARATEUR
        {
            strcpy((char *)&LigneEnCours.VALEUR_HEXA_ASCII_DATA3, (char *)&LigneEnCours.VALEUR_HEXA_ASCII);
            /* printf((char *)&LigneEnCours.VALEUR_HEXA_ASCII_DATA3 ); */
            LigneEnCours.iDATA3 = (int)strtol(LigneEnCours.VALEUR_HEXA_ASCII_DATA3, NULL, 16);
            COLUMN++;
        }
    ;

Data4 :
        ValeurHexaASCII     SEPARATEUR
        {
            strcpy((char *)&LigneEnCours.VALEUR_HEXA_ASCII_DATA4, (char *)&LigneEnCours.VALEUR_HEXA_ASCII);
            /* printf((char *)&LigneEnCours.VALEUR_HEXA_ASCII_DATA4 ); */
            LigneEnCours.iDATA4 = (int)strtol(LigneEnCours.VALEUR_HEXA_ASCII_DATA4, NULL, 16);
            COLUMN++;
        }
    ;

Data5 :
        ValeurHexaASCII     SEPARATEUR
        {
            strcpy((char *)&LigneEnCours.VALEUR_HEXA_ASCII_DATA5, (char *)&LigneEnCours.VALEUR_HEXA_ASCII);
            /* printf((char *)&LigneEnCours.VALEUR_HEXA_ASCII_DATA5 ); */
            LigneEnCours.iDATA5 = (int)strtol(LigneEnCours.VALEUR_HEXA_ASCII_DATA5, NULL, 16);
            COLUMN++;
        }
    ;

Data6 :
        ValeurHexaASCII     SEPARATEUR
        {
            strcpy((char *)&LigneEnCours.VALEUR_HEXA_ASCII_DATA6, (char *)&LigneEnCours.VALEUR_HEXA_ASCII);
            /* printf((char *)&LigneEnCours.VALEUR_HEXA_ASCII_DATA6 ); */
            LigneEnCours.iDATA6 = (int)strtol(LigneEnCours.VALEUR_HEXA_ASCII_DATA6, NULL, 16);
            COLUMN++;
        }
    ;

Data7 :
        ValeurHexaASCII     SEPARATEUR
        {
            strcpy((char *)&LigneEnCours.VALEUR_HEXA_ASCII_DATA7, (char *)&LigneEnCours.VALEUR_HEXA_ASCII);
            /* printf((char *)&LigneEnCours.VALEUR_HEXA_ASCII_DATA7 ); */
            LigneEnCours.iDATA7 = (int)strtol(LigneEnCours.VALEUR_HEXA_ASCII_DATA7, NULL, 16);
            COLUMN++;
        }
    ;

Line_number :
        Separateurs Separateurs2 ValeurENTIER
        {
            /* fprintf(O_FILE,"Line Number : %d \r\n",$3); */
            COLUMN++;
        }
    ;

Separateurs :
        SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR
        ;

Separateurs2 :

    |    SEPARATEUR
    |    SEPARATEUR SEPARATEUR
    |    SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR
    |    SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR
    |    SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR
    |    SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR
    |    SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR
    |    SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR SEPARATEUR
    ;



ValeurENTIER :
        ENTIER        {  $$= yylval.INT; strcpy(&LigneEnCours.VALEUR_INT, yyget_text()); }
       ;
ValeurNOMBRE_REEL :
       NOMBRE_REEL   { $$ = yylval.FLOAT; }
       ;
ValeurHexaASCII:
       FORMAT_HEXA    { strcpy((char *)&LigneEnCours.VALEUR_HEXA_ASCII, (const char *) yyget_text()); }
       ;

%%

// Additional C code

void Compare(void){
    if(LigneEnCours.iCHANNEL == 1) {
        switch ((eNode)Node) {
            /* ********Radio******** */
            case ePDO1_Radio:
                /* Output File */
                fprintf(CSVO_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVO_FILE,"Radio;");
                fprintf(CSVO_FILE,"PDO1;");
                fprintf(CSVO_FILE,";");
                PDODetailsRadio(&nRadio, true);
                fprintf(CSVO_FILE,"\r");

                /* Debug File */
                fprintf(CSVD_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVD_FILE,"Radio;");
                fprintf(CSVD_FILE,"PDO1;");
                fprintf(CSVD_FILE,";");
                PDODetailsRadio(&nRadio, false);
                fprintf(CSVD_FILE,"\r");

                //DetermineProtocolPDO();
            break;
            case eSDO_Rx_Radio:
                DetermineProtocolSDO(&nRadio);
                //fprintf(O_FILE,"SDO RX Node : %d Ligne : %d\n", Node, LINE_NB);
            break;
            case eSDO_Tx_Radio:
                DetermineProtocolSDO(&nRadio);
                //fprintf(O_FILE,"SDO TX Node : %d Ligne : %d\n", Node, LINE_NB);
            break;
            case eGuard_Radio:
                /* Output File */
                fprintf(CSVO_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVO_FILE,"Radio;");
                fprintf(CSVO_FILE,"GUARD;");

                /* Debug File */
                fprintf(CSVD_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVD_FILE,"Radio;");
                fprintf(CSVD_FILE,"GUARD;");

                DetermineProtocolGuardState(&nRadio);

                /* Output File */
                fprintf(CSVO_FILE,"\r");
                /* Debug File */
                fprintf(CSVD_FILE,"\r");
            break;
            case eEMCY_Radio:
                /* Output File */
                fprintf(CSVO_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVO_FILE,"Radio;");
                fprintf(CSVO_FILE,"EMCY;");
                AnalyzeEMCYContent(&nIO, true);

                /* Debug File */
                fprintf(CSVD_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVD_FILE,"Radio;");
                fprintf(CSVD_FILE,"EMCY;");
                AnalyzeEMCYContent(&nIO, false);


                /* Output File */
                fprintf(CSVO_FILE,"\r");
                /* Debug File */
                fprintf(CSVD_FILE,"\r");
            break;

            /* ********IO******** */
            case ePDO1_IO:
                /* Output File */
                fprintf(CSVO_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVO_FILE,"IO;");
                fprintf(CSVO_FILE,"PDO1;");
                fprintf(CSVO_FILE,";");
                PDODetailsIO(&nIO, true);
                fprintf(CSVO_FILE,"\r");

                /* Debug File */
                fprintf(CSVD_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVD_FILE,"IO;");
                fprintf(CSVD_FILE,"PDO1;");
                fprintf(CSVD_FILE,";");
                PDODetailsIO(&nIO, false);
                fprintf(CSVD_FILE,"\r");

            break;
            case eSDO_Rx_IO:
                DetermineProtocolSDO(&nIO);
            break;
            case eSDO_Tx_IO:
                DetermineProtocolSDO(&nIO);
            break;
            case eGuard_IO:
                /* Output File */
                fprintf(CSVO_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVO_FILE,"IO;");
                fprintf(CSVO_FILE,"GUARD;");

                /* Debug File */
                fprintf(CSVD_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVD_FILE,"IO;");
                fprintf(CSVD_FILE,"GUARD;");

                DetermineProtocolGuardState(&nIO);

                /* Output File */
                fprintf(CSVO_FILE,"\r");
                /* Debug File */
                fprintf(CSVD_FILE,"\r");
            break;
            case eEMCY_IO:
                /* Output File */
                fprintf(CSVO_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVO_FILE,"IO;");
                fprintf(CSVO_FILE,"EMCY;");
                fprintf(CSVO_FILE,";");
                AnalyzeEMCYContent(&nIO, true);
                fprintf(CSVO_FILE,"\r");

                /* Debug File */
                fprintf(CSVD_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVD_FILE,"IO;");
                fprintf(CSVD_FILE,"EMCY;");
                fprintf(CSVD_FILE,";");
                AnalyzeEMCYContent(&nIO, false);
                fprintf(CSVD_FILE,"\r");

            break;

            /* ********EDS******** */
            case ePDO1_EDS:
                /* Output File */
                fprintf(CSVO_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVO_FILE,"EDS;");
                fprintf(CSVO_FILE,"PDO1;");
                fprintf(CSVO_FILE,";");
                PDODetailsEDS(&nEDS, true);
                fprintf(CSVO_FILE,"\r");

                /* Debug File */
                fprintf(CSVD_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVD_FILE,"EDS;");
                fprintf(CSVD_FILE,"PDO1;");
                fprintf(CSVD_FILE,";");
                PDODetailsEDS(&nEDS, false);
                fprintf(CSVD_FILE,"\r");

            break;
            case eSDO_Rx_EDS:
                DetermineProtocolSDO(&nEDS);
            break;
            case eSDO_Tx_EDS:
                DetermineProtocolSDO(&nEDS);
            break;
            case eGuard_EDS:
                /* Output File */
                fprintf(CSVO_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVO_FILE,"EDS;");
                fprintf(CSVO_FILE,"GUARD;");

                /* Debug File */
                fprintf(CSVD_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVD_FILE,"EDS;");
                fprintf(CSVD_FILE,"GUARD;");

                DetermineProtocolGuardState(&nEDS);

                /* Output File */
                fprintf(CSVO_FILE,"\r");
                /* Debug File */
                fprintf(CSVD_FILE,"\r");
            break;
            case eEMCY_EDS:
                /* Output File */
                fprintf(CSVO_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVO_FILE,"EDS;");
                fprintf(CSVO_FILE,"EMCY;");
                AnalyzeEMCYContent(&nIO, true);

                /* Debug File */
                fprintf(CSVD_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVD_FILE,"EDS;");
                fprintf(CSVD_FILE,"EMCY;");
                AnalyzeEMCYContent(&nIO, false);

                /* Output File */
                fprintf(CSVO_FILE,"\r");
                /* Debug File */
                fprintf(CSVD_FILE,"\r");
            break;

            /* ********Guidance******** */
            case ePDO1_Guidance:
                /* Output File */
                fprintf(CSVO_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVO_FILE,"Guidance;");
                fprintf(CSVO_FILE,"PDO1;");
                fprintf(CSVO_FILE,";");
                PDODetailsGuidance(&nGuidance, true);
                fprintf(CSVO_FILE,"\r");

                /* Debug File */
                fprintf(CSVD_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVD_FILE,"Guidance;");
                fprintf(CSVD_FILE,"PDO1;");
                fprintf(CSVD_FILE,";");
                PDODetailsGuidance(&nGuidance, false);
                fprintf(CSVD_FILE,"\r");

            break;
            case eSDO_Rx_Guidance:
                DetermineProtocolSDO(&nGuidance);
            break;
            case eSDO_Tx_Guidance:
                DetermineProtocolSDO(&nGuidance);
            break;
            case eGuard_Guidance:
                /* Output File */
                fprintf(CSVO_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVO_FILE,"Guidance;");
                fprintf(CSVO_FILE,"GUARD;");

                /* Debug File */
                fprintf(CSVD_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVD_FILE,"Guidance;");
                fprintf(CSVD_FILE,"GUARD;");

                DetermineProtocolGuardState(&nGuidance);

                /* Output File */
                fprintf(CSVO_FILE,"\r");
                /* Debug File */
                fprintf(CSVD_FILE,"\r");
            break;
            case eEMCY_Guidance:
                /* Output File */
                fprintf(CSVO_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVO_FILE,"Guidance;");
                fprintf(CSVO_FILE,"EMCY;");
                AnalyzeEMCYContent(&nIO, true);

                /* Debug File */
                fprintf(CSVD_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVD_FILE,"Guidance;");
                fprintf(CSVD_FILE,"EMCY;");
                AnalyzeEMCYContent(&nIO, false);

                /* Output File */
                fprintf(CSVO_FILE,"\r");
                /* Debug File */
                fprintf(CSVD_FILE,"\r");
            break;

            /* ********LDRIVER******** */
            case ePDO1_LDriver:
                /* Output File */
                fprintf(CSVO_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVO_FILE,"LDriver;");
                fprintf(CSVO_FILE,"PDO1;");
                fprintf(CSVO_FILE,";");
                PDO1DetailsDrivers(&nLDriver, true);
                fprintf(CSVO_FILE,"\r");

                /* Debug File */
                fprintf(CSVD_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVD_FILE,"LDriver;");
                fprintf(CSVD_FILE,"PDO1;");
                fprintf(CSVD_FILE,";");
                PDO1DetailsDrivers(&nLDriver, false);
                fprintf(CSVD_FILE,"\r");

            break;
            case ePDO2_LDriver:
                /* Output File */
                fprintf(CSVO_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVO_FILE,"LDriver;");
                fprintf(CSVO_FILE,"PDO2;");
                fprintf(CSVO_FILE,";");
                PDO2DetailsDrivers(&nLDriver, true);
                fprintf(CSVO_FILE,"\r");

                /* Debug File */
                fprintf(CSVD_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVD_FILE,"LDriver;");
                fprintf(CSVD_FILE,"PDO2;");
                fprintf(CSVD_FILE,";");
                PDO2DetailsDrivers(&nLDriver, false);
                fprintf(CSVD_FILE,"\r");

            break;
            case ePDO3_LDriver:
                /* Output File */
                fprintf(CSVO_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVO_FILE,"LDriver;");
                fprintf(CSVO_FILE,"PDO3;");
                fprintf(CSVO_FILE,";");
                PDO3DetailsDrivers(&nLDriver, true);
                fprintf(CSVO_FILE,"\r");

                /* Debug File */
                fprintf(CSVD_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVD_FILE,"LDriver;");
                fprintf(CSVD_FILE,"PDO3;");
                fprintf(CSVD_FILE,";");
                PDO3DetailsDrivers(&nLDriver, false);
                fprintf(CSVD_FILE,"\r");

            break;
            case eSDO_Rx_LDriver:
                DetermineProtocolSDO(&nLDriver);
            break;
            case eSDO_Tx_LDriver:
                DetermineProtocolSDO(&nLDriver);
            break;
            case eGuard_LDriver:
                /* Output File */
                fprintf(CSVO_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVO_FILE,"LDriver;");
                fprintf(CSVO_FILE,"GUARD;");

                /* Debug File */
                fprintf(CSVD_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVD_FILE,"LDriver;");
                fprintf(CSVD_FILE,"GUARD;");

                DetermineProtocolGuardState(&nLDriver);

                /* Output File */
                fprintf(CSVO_FILE,"\r");
                /* Debug File */
                fprintf(CSVD_FILE,"\r");
            break;
            case eEMCY_LDriver:
                /* Output File */
                fprintf(CSVO_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVO_FILE,"LDriver;");
                fprintf(CSVO_FILE,"EMCY;");
                AnalyzeEMCYContent(&nLDriver, true);

                /* Debug File */
                fprintf(CSVD_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVD_FILE,"LDriver;");
                fprintf(CSVD_FILE,"EMCY;");
                AnalyzeEMCYContent(&nLDriver, false);

                /* Output File */
                fprintf(CSVO_FILE,"\r");
                /* Debug File */
                fprintf(CSVD_FILE,"\r");
            break;

            /* ********RDRIVER******** */
            case ePDO1_RDriver:
                /* Output File */
                fprintf(CSVO_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVO_FILE,"RDriver;");
                fprintf(CSVO_FILE,"PDO1;");
                fprintf(CSVO_FILE,";");
                PDO1DetailsDrivers(&nRDriver, true);
                fprintf(CSVO_FILE,"\r");

                /* Debug File */
                fprintf(CSVD_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVD_FILE,"RDriver;");
                fprintf(CSVD_FILE,"PDO1;");
                fprintf(CSVD_FILE,";");
                PDO1DetailsDrivers(&nRDriver, false);
                fprintf(CSVD_FILE,"\r");

            break;
            case ePDO2_RDriver:
                /* Output File */
                fprintf(CSVO_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVO_FILE,"RDriver;");
                fprintf(CSVO_FILE,"PDO2;");
                fprintf(CSVO_FILE,";");
                PDO2DetailsDrivers(&nRDriver, true);
                fprintf(CSVO_FILE,"\r");

                /* Debug File */
                fprintf(CSVD_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVD_FILE,"RDriver;");
                fprintf(CSVD_FILE,"PDO2;");
                fprintf(CSVD_FILE,";");
                PDO2DetailsDrivers(&nRDriver, false);
                fprintf(CSVD_FILE,"\r");

            break;
            case ePDO3_RDriver:
                /* Output File */
                fprintf(CSVO_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVO_FILE,"RDriver;");
                fprintf(CSVO_FILE,"PDO3;");
                fprintf(CSVO_FILE,";");
                PDO3DetailsDrivers(&nRDriver, true);
                fprintf(CSVO_FILE,"\r");

                /* Debug File */
                fprintf(CSVD_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVD_FILE,"RDriver;");
                fprintf(CSVD_FILE,"PDO3;");
                fprintf(CSVD_FILE,";");
                PDO3DetailsDrivers(&nRDriver, false);
                fprintf(CSVD_FILE,"\r");

            break;
            case eSDO_Rx_RDriver:
                DetermineProtocolSDO(&nRDriver);
            break;
            case eSDO_Tx_RDriver:
                DetermineProtocolSDO(&nRDriver);
            break;
            case eGuard_RDriver:
                /* Output File */
                fprintf(CSVO_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVO_FILE,"RDriver;");
                fprintf(CSVO_FILE,"GUARD;");

                /* Debug File */
                fprintf(CSVD_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVD_FILE,"RDriver;");
                fprintf(CSVD_FILE,"GUARD;");

                DetermineProtocolGuardState(&nRDriver);

                /* Output File */
                fprintf(CSVO_FILE,"\r");
                /* Debug File */
                fprintf(CSVD_FILE,"\r");
            break;
            case eEMCY_RDriver:
                /* Output File */
                fprintf(CSVO_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVO_FILE,"RDriver;");
                fprintf(CSVO_FILE,"EMCY;");
                AnalyzeEMCYContent(&nRDriver, true);

                /* Debug File */
                fprintf(CSVD_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVD_FILE,"RDriver;");
                fprintf(CSVD_FILE,"EMCY;");
                AnalyzeEMCYContent(&nRDriver, false);

                /* Output File */
                fprintf(CSVO_FILE,"\r");
                /* Debug File */
                fprintf(CSVD_FILE,"\r");
            break;

            /* ********RFH6x0******** */
            case ePDO1_RFH6x0:
                /* Output File */
                fprintf(CSVO_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVO_FILE,"RFH6x0;");
                fprintf(CSVO_FILE,"PDO1;");
                fprintf(CSVO_FILE,";");
                fprintf(CSVO_FILE,"\r");

                /* Debug File */
                fprintf(CSVD_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVD_FILE,"RFH6x0;");
                fprintf(CSVD_FILE,"PDO1;");
                fprintf(CSVD_FILE,";");
                fprintf(CSVD_FILE,"\r");

            break;
            case ePDO4_RFH6x0:
                /* Output File */
                fprintf(CSVO_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVO_FILE,"RFH6x0;");
                fprintf(CSVO_FILE,"PDO4;");
                fprintf(CSVO_FILE,";");
                fprintf(CSVO_FILE,"\r");

                /* Debug File */
                fprintf(CSVD_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVD_FILE,"RFH6x0;");
                fprintf(CSVD_FILE,"PDO4;");
                fprintf(CSVD_FILE,";");
                fprintf(CSVD_FILE,"\r");

            break;
            case eSDO_Rx_RFH6x0:
                DetermineProtocolSDO(&nRFH6x0);
            break;
            case eSDO_Tx_RFH6x0:
                DetermineProtocolSDO(&nRFH6x0);
            break;
            case eGuard_RFH6x0:
                /* Output File */
                fprintf(CSVO_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVO_FILE,"RFH6x0;");
                fprintf(CSVO_FILE,"GUARD;");

                /* Debug File */
                fprintf(CSVD_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVD_FILE,"RFH6x0;");
                fprintf(CSVD_FILE,"GUARD;");

                DetermineProtocolGuardState(&nRFH6x0);

                /* Output File */
                fprintf(CSVO_FILE,"\r");
                /* Debug File */
                fprintf(CSVD_FILE,"\r");
            break;

            /* ********DTM425******** */
            case ePDO1_DTM425:
                /* Output File */
                fprintf(CSVO_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVO_FILE,"DTM425;");
                fprintf(CSVO_FILE,"PDO1;");
                fprintf(CSVO_FILE,";");
                fprintf(CSVO_FILE,"\r");

                /* Debug File */
                fprintf(CSVD_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVD_FILE,"DTM425;");
                fprintf(CSVD_FILE,"PDO1;");
                fprintf(CSVD_FILE,";");
                fprintf(CSVD_FILE,"\r");

            break;
            case ePDO2_DTM425:
                /* Output File */
                fprintf(CSVO_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVO_FILE,"DTM425;");
                fprintf(CSVO_FILE,"PDO2;");
                fprintf(CSVO_FILE,";");
                fprintf(CSVO_FILE,"\r");

                /* Debug File */
                fprintf(CSVD_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVD_FILE,"DTM425;");
                fprintf(CSVD_FILE,"PDO4;");
                fprintf(CSVD_FILE,";");
                fprintf(CSVD_FILE,"\r");

            break;
            case eSDO_Rx_DTM425:
                DetermineProtocolSDO(&nDTM425);
            break;
            case eSDO_Tx_DTM425:
                DetermineProtocolSDO(&nDTM425);
            break;
            case eGuard_DTM425:
                /* Output File */
                fprintf(CSVO_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVO_FILE,"DTM425;");
                fprintf(CSVO_FILE,"GUARD;");

                /* Debug File */
                fprintf(CSVD_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVD_FILE,"DTM425;");
                fprintf(CSVD_FILE,"GUARD;");

                DetermineProtocolGuardState(&nDTM425);

                /* Output File */
                fprintf(CSVO_FILE,"\r");
                /* Debug File */
                fprintf(CSVD_FILE,"\r");
            break;

            /* ********PCU******** */
            case eSDO_Rx_PCU:
                DetermineProtocolSDO(&nPCU);
            break;
            case eSDO_Tx_PCU:
                DetermineProtocolSDO(&nPCU);
            break;
            case eGuard_PCU:
                /* Output File */
                fprintf(CSVO_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVO_FILE,"PCU;");
                fprintf(CSVO_FILE,"GUARD;");

                /* Debug File */
                fprintf(CSVD_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVD_FILE,"PCU;");
                fprintf(CSVD_FILE,"GUARD;");

                DetermineProtocolGuardState(&nPCU);

                /* Output File */
                fprintf(CSVO_FILE,"\r");
                /* Debug File */
                fprintf(CSVD_FILE,"\r");
            break;
            case eEMCY_PCU:
                /* Output File */
                fprintf(CSVO_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVO_FILE,"PCU;");
                fprintf(CSVO_FILE,"EMCY;");
                AnalyzeEMCYContent(&nPCU, true);

                /* Debug File */
                fprintf(CSVD_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVD_FILE,"PCU;");
                fprintf(CSVD_FILE,"EMCY;");
                AnalyzeEMCYContent(&nPCU, false);

                /* Output File */
                fprintf(CSVO_FILE,"\r");
                /* Debug File */
                fprintf(CSVD_FILE,"\r");
            break;

            /* ********OTHER******** */
            case eSync:
                /* Output File */
                fprintf(CSVO_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVO_FILE,"SYNC;");
                fprintf(CSVO_FILE,"SYNC");
                fprintf(CSVO_FILE,"\r");

                /* Debug File */
                fprintf(CSVD_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVD_FILE,"SYNC;");
                fprintf(CSVD_FILE,"SYNC");
                fprintf(CSVD_FILE,"\r");

            break;
            case eNMT:
                /* Output File */
                fprintf(CSVO_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                DetermineProtocolNMTNode(true);
                fprintf(CSVO_FILE,"NMT;");

                /* Debug File */
                fprintf(CSVD_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                DetermineProtocolNMTNode(false);
                fprintf(CSVD_FILE,"NMT;");

                NMTProtocol.NMTState = (eNode)LigneEnCours.iDATA0;
                switch(NMTProtocol.NMTState) {
                    case eNMTStateENTOperationnal:
                        /* Output File */
                        fprintf(CSVO_FILE,"Enter Operationnal;");
                        /* Debug File */
                        fprintf(CSVD_FILE,"Enter Operationnal;");
                    break;
                    case eNMTStateENTStop:
                        /* Output File */
                        fprintf(CSVO_FILE,"Enter Stop;");
                        /* Debug File */
                        fprintf(CSVD_FILE,"Enter Stop;");
                    break;
                    case eNMTStateENTPreOperationnal:
                        /* Output File */
                        fprintf(CSVO_FILE,"Enter Pre-Operationnal;");
                        /* Debug File */
                        fprintf(CSVD_FILE,"Enter Pre-Operationnal;");
                    break;
                    case eNMTStateRSTNode:
                        /* Output File */
                        fprintf(CSVO_FILE,"Reset Node;");
                        /* Debug File */
                        fprintf(CSVD_FILE,"Reset Node;");
                    break;
                    case eNMTStateRSTCommunication:
                        /* Output File */
                        fprintf(CSVO_FILE,"Reset Communication;");
                        /* Debug File */
                        fprintf(CSVD_FILE,"Reset Communication;");
                    break;
                }
                /* Output File */
                fprintf(CSVO_FILE,"\r");
                /* Debug File */
                fprintf(CSVD_FILE,"\r");
            break;
            default:
                /* Output File */
                fprintf(CSVO_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVO_FILE,"N/A;");
                fprintf(CSVO_FILE,"CAS_INCONNU;");
                fprintf(CSVO_FILE,";");
                fprintf(CSVO_FILE,"\r");

                /* Debug File */
                fprintf(CSVD_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVD_FILE,"N/A;");
                fprintf(CSVD_FILE,"CAS_INCONNU;");
                fprintf(CSVD_FILE,";");
                fprintf(CSVD_FILE,"\r");

                //fprintf(O_FILE,"Node : %d Ligne : %d\n", Node, LINE_NB);

            break;
        }
    }
    if(LigneEnCours.iCHANNEL == 2) {
        if( ((eNode)NodeBMS == e0x351) || ((eNode)NodeBMS == e0x352) || ((eNode)NodeBMS == e0x353) || ((eNode)NodeBMS == e0x354) || ((eNode)NodeBMS == e0x355) || ((eNode)NodeBMS == e0x356) || ((eNode)NodeBMS == e0x357) || ((eNode)NodeBMS == e0x358) || ((eNode)NodeBMS == e0x359) || ((eNode)NodeBMS == e0x35B) || ((eNode)NodeBMS == e0x35C) || ((eNode)NodeBMS == e0x35D) || ((eNode)NodeBMS == e0x380) || ((eNode)NodeBMS == e0x381) || ((eNode)NodeBMS == e0x382) || ((eNode)NodeBMS == e0x383) || ((eNode)NodeBMS == e0x384) || ((eNode)NodeBMS == e0x385) || ((eNode)NodeBMS == e0x386)) {
            Node = eBMS;
        }
        switch ((eNode)Node) {
            case eBMS :
                /* Output File */
                fprintf(CSVO_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVO_FILE,"BMS;");
                fprintf(CSVO_FILE,"CAN2;");
                fprintf(CSVO_FILE,";");

                /* Debug File */
                fprintf(CSVD_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVD_FILE,"BMS;");
                fprintf(CSVD_FILE,"CAN2;");
                fprintf(CSVD_FILE,";");

                AnalyzeBMS();

                /* Output File */
                fprintf(CSVO_FILE,"\r");
                /* Debug File */
                fprintf(CSVD_FILE,"\r");
            break;
            default:
                /* Output File */
                fprintf(CSVO_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVO_FILE,"N/A;");
                fprintf(CSVO_FILE,"CAS_INCONNU;");
                fprintf(CSVO_FILE,";");
                fprintf(CSVO_FILE,"\r");

                /* Debug File */
                fprintf(CSVD_FILE,"%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVD_FILE,"N/A;");
                fprintf(CSVD_FILE,"CAS_INCONNU;");
                fprintf(CSVD_FILE,";");
                fprintf(CSVD_FILE,"\r");

                //fprintf(O_FILE,"Node : %d Ligne : %d\n", Node, LINE_NB);

            break;
        }
    }
}


void DetermineProtocolGuardState(tNode *nNodeTypeState) {
    nNodeTypeState->StateCAN.GuardState = (eNode)LigneEnCours.iDATA0;
    switch (nNodeTypeState->StateCAN.GuardState) {
        case eGUARDStateBooting:
            /* Output File */
            fprintf(CSVO_FILE,"Booting;");
            /* Debug File */
            fprintf(CSVD_FILE,"Booting;");
        break;
        case eGUARDStateStopped:
            /* Output File */
            fprintf(CSVO_FILE,"Stopped;");
            /* Debug File */
            fprintf(CSVD_FILE,"Stopped;");
        break;
        case eGUARDStateOperationnal:
            /* Output File */
            fprintf(CSVO_FILE,"Operationnal;");
            /* Debug File */
            fprintf(CSVD_FILE,"Operationnal;");
        break;
        case eGUARDStatePreOperationnal:
            /* Output File */
            fprintf(CSVO_FILE,"Pre-Operationnal;");
            /* Debug File */
            fprintf(CSVD_FILE,"Pre-Operationnal;");
        break;
    }
}

void DetermineProtocolNMTNode(bool fChoice) {
    NMTProtocol.NMTNodeNBR = (eNode)LigneEnCours.iDATA1;
    switch(NMTProtocol.NMTNodeNBR){
        case eNMTLDriver:
            if(fChoice) {
                fprintf(CSVO_FILE,"LDriver;");
            }
            else {
                fprintf(CSVD_FILE,"LDriver;");
            }
        break;
        case eNMTRDriver:
            if(fChoice) {
                fprintf(CSVO_FILE,"RDriver;");
            }
            else {
                fprintf(CSVD_FILE,"RDriver;");
            }
        break;
        case eNMTGuidance:
            if(fChoice) {
                fprintf(CSVO_FILE,"Guidance;");
            }
            else {
                fprintf(CSVD_FILE,"Guidance;");
            }
        break;
        case eNMTRFH6x0_Id:
            if(fChoice) {
                fprintf(CSVO_FILE,"RFH6x0;");
            }
            else {
                fprintf(CSVD_FILE,"RFH6x0;");
            }
        break;
        case eNMTDTM425_Id:
            if(fChoice) {
                fprintf(CSVO_FILE,"DTM425;");
            }
            else {
                fprintf(CSVD_FILE,"DTM425;");
            }
        break;
        case eNMTCPU_Id:
            if(fChoice) {
                fprintf(CSVO_FILE,"CPU;");
            }
            else {
                fprintf(CSVD_FILE,"CPU;");
            }
        break;
        case eNMTPCU_Id:
            if(fChoice) {
                fprintf(CSVO_FILE,"PCU;");
            }
            else {
                fprintf(CSVD_FILE,"PCU;");
            }
        break;
        case eNMTIO_Id:
            if(fChoice) {
                fprintf(CSVO_FILE,"IO;");
            }
            else {
                fprintf(CSVD_FILE,"IO;");
            }
        break;
        case eNMTEDS_Id:
            if(fChoice) {
                fprintf(CSVO_FILE,"EDS;");
            }
            else {
                fprintf(CSVD_FILE,"EDS;");
            }
        break;
        case eNMTSICK_EXPANDER_Id:
            if(fChoice) {
                fprintf(CSVO_FILE,"Sick_Expander;");
            }
            else {
                fprintf(CSVD_FILE,"Sick_Expander;");
            }
        break;
        case eNMTRADIO_Id:
            if(fChoice) {
                fprintf(CSVO_FILE,"Radio;");
            }
            else {
                fprintf(CSVD_FILE,"Radio;");
            }
        break;
    }
}














