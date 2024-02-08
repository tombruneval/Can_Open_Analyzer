#include "Common.h"
bool RChoice = true;
bool WChoice = false;

void concatenerNombresHexIndexRead(tNode *nNodeType, char *MSB, char *LSB)
{
// Compléter avec des zéros à gauche si nécessaire
if (strlen(MSB) == 1)
{
    memmove(MSB + 1, MSB, strlen(MSB) + 1);
    MSB[0] = '0';
}
if (strlen(LSB) == 1)
{
    memmove(LSB + 1, LSB, strlen(LSB) + 1);
    LSB[0] = '0';
}

// Concaténer les chaînes
sprintf(nNodeType->VALEUR_HEXA_ASCII_Read_INDEX, "%s%s", MSB, LSB);
strcpy(nNodeType->VALEUR_HEXA_ASCII_Read_SUB_INDEX, LigneEnCours.VALEUR_HEXA_ASCII_DATA3);

nNodeType->iNodeIndexRead = (int)strtol(nNodeType->VALEUR_HEXA_ASCII_Read_INDEX, NULL, 16);
nNodeType->iNodeSubIndexRead = (int)strtol(nNodeType->VALEUR_HEXA_ASCII_Read_SUB_INDEX, NULL, 16);

// fprintf(O_FILE_2,"Read : %d , Index : %d Sous-Index : %d Ligne : %d\n",nNodeType->bSeenSDORead, nNodeType->iNodeIndexRead,nNodeType->iNodeSubIndexRead, LINE_NB);
}
void concatenerNombresHexIndexWrite(tNode *nNodeType, char *MSB, char *LSB)
{
// Compléter avec des zéros à gauche si nécessaire
if (strlen(MSB) == 1)
{
    memmove(MSB + 1, MSB, strlen(MSB) + 1);
    MSB[0] = '0';
}
if (strlen(LSB) == 1)
{
    memmove(LSB + 1, LSB, strlen(LSB) + 1);
    LSB[0] = '0';
}

// Concaténer les chaînes
sprintf(nNodeType->VALEUR_HEXA_ASCII_Write_INDEX, "%s%s", MSB, LSB);
strcpy(nNodeType->VALEUR_HEXA_ASCII_Write_SUB_INDEX, LigneEnCours.VALEUR_HEXA_ASCII_DATA3);

nNodeType->iNodeIndexWrite = (int)strtol(nNodeType->VALEUR_HEXA_ASCII_Write_INDEX, NULL, 16);
nNodeType->iNodeSubIndexWrite = (int)strtol(nNodeType->VALEUR_HEXA_ASCII_Write_SUB_INDEX, NULL, 16);

// fprintf(O_FILE_2,"Write : %d , Index : %d Sous-Index : %d Ligne : %d\n",nNodeType->bSeenSDOWrite, nNodeType->iNodeIndexWrite,nNodeType->iNodeSubIndexWrite, LINE_NB);
}
void concatenerNombresHexErrorCode(char *MSB, char *LSB, char *ErrorCode)
{
// Compléter avec des zéros à gauche si nécessaire
if (strlen(MSB) == 1)
{
    memmove(MSB + 1, MSB, strlen(MSB) + 1);
    MSB[0] = '0';
}
if (strlen(LSB) == 1)
{
    memmove(LSB + 1, LSB, strlen(LSB) + 1);
    LSB[0] = '0';
}

// Concaténer les chaînes
sprintf(ErrorCode, "%s%s", MSB, LSB);
LigneEnCours.iErrorCodes = (int)strtol(ErrorCode, NULL, 16);
LigneEnCours.iErrorRegister = (int)strtol(LigneEnCours.VALEUR_HEXA_ASCII_DATA2, NULL, 16);
}
void concatener8BytesData(char *Data0, char *Data1, char *Data2, char *Data3, char *Data4, char *Data5, char *Data6, char *Data7, char *FullString)
{
FullString[0] = 0;

// Compléter avec des zéros à gauche si nécessaire
if (strlen(Data0) == 1)
{
    memmove(Data0 + 1, Data0, strlen(Data0) + 1);
    Data0[0] = '0';
    Data0[2] = 0;
}
if (strlen(Data1) == 1)
{
    memmove(Data1 + 1, Data1, strlen(Data1) + 1);
    Data1[0] = '0';
    Data1[2] = 0;
}
if (strlen(Data2) == 1)
{
    memmove(Data2 + 1, Data2, strlen(Data2) + 1);
    Data2[0] = '0';
    Data2[2] = 0;
}
if (strlen(Data3) == 1)
{
    memmove(Data3 + 1, Data3, strlen(Data3) + 1);
    Data3[0] = '0';
    Data3[2] = 0;
}
if (strlen(Data4) == 1)
{
    memmove(Data4 + 1, Data4, strlen(Data4) + 1);
    Data4[0] = '0';
    Data4[2] = 0;
}
if (strlen(Data5) == 1)
{
    memmove(Data5 + 1, Data5, strlen(Data5) + 1);
    Data5[0] = '0';
    Data5[2] = 0;
}
if (strlen(Data6) == 1)
{
    memmove(Data6 + 1, Data6, strlen(Data6) + 1);
    Data6[0] = '0';
    Data6[2] = 0;
}
if (strlen(Data7) == 1)
{
    memmove(Data7 + 1, Data7, strlen(Data7) + 1);
    Data7[0] = '0';
    Data7[2] = 0;
}

// Concaténer les chaînes
strcat(FullString, Data0); // Copiez la première chaîne dans la chaîne de destination
strcat(FullString, Data1);
strcat(FullString, Data2);
strcat(FullString, Data3);
strcat(FullString, Data4);
strcat(FullString, Data5);
strcat(FullString, Data6);
strcat(FullString, Data7);
}
void concatener7BytesData(char *Data1, char *Data2, char *Data3, char *Data4, char *Data5, char *Data6, char *Data7, char *FullString)
{
FullString[0] = 0;

// Compléter avec des zéros à gauche si nécessaire
if (strlen(Data1) == 1)
{
    memmove(Data1 + 1, Data1, strlen(Data1) + 1);
    Data1[0] = '0';
    Data1[2] = 0;
}
if (strlen(Data2) == 1)
{
    memmove(Data2 + 1, Data2, strlen(Data2) + 1);
    Data2[0] = '0';
    Data2[2] = 0;
}
if (strlen(Data3) == 1)
{
    memmove(Data3 + 1, Data3, strlen(Data3) + 1);
    Data3[0] = '0';
    Data3[2] = 0;
}
if (strlen(Data4) == 1)
{
    memmove(Data4 + 1, Data4, strlen(Data4) + 1);
    Data4[0] = '0';
    Data4[2] = 0;
}
if (strlen(Data5) == 1)
{
    memmove(Data5 + 1, Data5, strlen(Data5) + 1);
    Data5[0] = '0';
    Data5[2] = 0;
}
if (strlen(Data6) == 1)
{
    memmove(Data6 + 1, Data6, strlen(Data6) + 1);
    Data6[0] = '0';
    Data6[2] = 0;
}
if (strlen(Data7) == 1)
{
    memmove(Data7 + 1, Data7, strlen(Data7) + 1);
    Data7[0] = '0';
    Data7[2] = 0;
}

// Concaténer les chaînes
strcat(FullString, Data1);
strcat(FullString, Data2);
strcat(FullString, Data3);
strcat(FullString, Data4);
strcat(FullString, Data5);
strcat(FullString, Data6);
strcat(FullString, Data7);
/*
fprintf(O_FILE_2, "Data 1, Ligne : %d Chaine : %s\n",LINE_NB, Data1);
fprintf(O_FILE_2, "Data 2, Ligne : %d Chaine : %s\n",LINE_NB, Data2);
fprintf(O_FILE_2, "Data 3, Ligne : %d Chaine : %s\n",LINE_NB, Data3);
fprintf(O_FILE_2, "Data 4, Ligne : %d Chaine : %s\n",LINE_NB, Data4);
fprintf(O_FILE_2, "Data 5, Ligne : %d Chaine : %s\n",LINE_NB, Data5);
fprintf(O_FILE_2, "Data 6, Ligne : %d Chaine : %s\n",LINE_NB, Data6);
fprintf(O_FILE_2, "Data 7, Ligne : %d Chaine : %s\n",LINE_NB, Data7);
*/
}
void concatener4BytesData(char *Data4, char *Data5, char *Data6, char *Data7, char *FullString)
{
FullString[0] = 0;

// Compléter avec des zéros à gauche si nécessaire
if (strlen(Data4) == 1)
{
    memmove(Data4 + 1, Data4, strlen(Data4) + 1);
    Data4[0] = '0';
    Data4[2] = 0;
}
if (strlen(Data5) == 1)
{
    memmove(Data5 + 1, Data5, strlen(Data5) + 1);
    Data5[0] = '0';
    Data5[2] = 0;
}
if (strlen(Data6) == 1)
{
    memmove(Data6 + 1, Data6, strlen(Data6) + 1);
    Data6[0] = '0';
    Data6[2] = 0;
}
if (strlen(Data7) == 1)
{
    memmove(Data7 + 1, Data7, strlen(Data7) + 1);
    Data7[0] = '0';
    Data7[2] = 0;
}

strcat(FullString, Data4);
strcat(FullString, Data5);
strcat(FullString, Data6);
strcat(FullString, Data7);
}
void concatener2BytesData(char *Data1, char *Data2, char *FullString)
{
FullString[0] = 0;

// Compléter avec des zéros à gauche si nécessaire
if (strlen(Data1) == 1)
{
    memmove(Data1 + 1, Data1, strlen(Data1) + 1);
    Data1[0] = '0';
    Data1[2] = 0;
}
if (strlen(Data2) == 1)
{
    memmove(Data2 + 1, Data2, strlen(Data2) + 1);
    Data2[0] = '0';
    Data2[2] = 0;
}

strcat(FullString, Data1);
strcat(FullString, Data2);
}
void concatener2Segments(char *PartString, char *FullString)
{
strcat(FullString, PartString);
/*
fprintf(O_FILE_2, "PartString, Ligne : %d Chaine : %s\n",LINE_NB, PartString);
fprintf(O_FILE_2, "FullString, Ligne : %d Chaine : %s\n",LINE_NB, FullString);
*/
}
void hexStringToAscii(char *hexStr, bool *fChoice)
{
//int len = strlen(hexStr);
if(fChoice) {
    fprintf(CSVO_FILE, "%s", hexStr);
}
else {
    fprintf(CSVD_FILE, "%s", hexStr);
}

/*
fprintf(O_FILE_2, "HexStringToAscii, Ligne : %d Chaine : %s\n", LINE_NB, hexStr);
for (int i = 0; i < len; i += 2)
{
    // Extraire une paire de caractères hexadécimaux
    char hexPair[3];
    hexPair[0] = hexStr[i];
    hexPair[1] = hexStr[i + 1];
    hexPair[2] = 0;

    // Convertir la paire hexadécimale en entier
    int asciiValue;
    sscanf(hexPair, "%x", &asciiValue);

    fprintf(O_FILE_2, "%c", (char)asciiValue);
    // Afficher le caractère correspondant
    if (fChoice)
    {
        //fprintf(CSVO_FILE, "%c", (char)asciiValue);
    }
    else
    {
        //fprintf(CSVD_FILE, "%c", (char)asciiValue);
    }
}
*/
}
void hexStringToBinString(char *hexStr)
{
unsigned int hexValue;
sscanf(hexStr, "%X", &hexValue);

// Afficher la représentation binaire
char binaryString[9]; // Pour stocker la représentation binaire (8 bits + terminateur nul)
itoa(hexValue, binaryString, 2);

return binaryString;
}
