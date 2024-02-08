#include "Common.h"
#include "Index.h"
#include "Automate.h"

tLigne LigneEnCours = {{0}};
tLigne Ligne[MaxNbLigne] = {{{0}}};

tNode nRadio = {
    .cNodeType = "Radio", // Initialisation du tableau de caractères
    .iDATA4_Size_Actual_Read = 0,
    .iDATA4_Size_Maximum_Read = 0,
    .iDATA4_Size_Actual_Write = 0,
    .iDATA4_Size_Maximum_Write = 0,
    .NbrReptitionsRead = 1,
    .NbrReptitionsWrite = 1,
    .bSeenHibernOn = false, // Initialisation des booléens
    .bSeenHibernOff = false,
    .bSeenSize7Read = false,
    .bSeenSize7Write = false,
    .bSeenFinalSegmentRead = false,
    .bSeenFinalSegmentWrite = false,
    .bSeenFinalData7bytesRead = false,
    .bSeenFinalData4bytesRead = false,
    .bSeenFinalData7bytesWrite = false,
    .bSeenFinalData4bytesWrite = false,
    .StateWrite = eEtape1, // Initialisation de l'énumération
    .StateRead = eEtape1,
    .ptrCompareDefines = CompareWithDefinesRadio,
    .ptrCompareErrorCodes = CompareErrorCodesRadio,
    .ptrIndexDetails7BytesRead = IndexDetails7BytesRead,
    .ptrIndexDetails4BytesRead = IndexDetails4BytesRead,
    .ptrIndexDetails7BytesWrite = IndexDetails7BytesWrite,
    .ptrIndexDetails4BytesWrite = IndexDetails4BytesWrite};
tNode nIO = {
    .cNodeType = "IO", // Initialisation du tableau de caractères
    .iDATA4_Size_Actual_Read = 0,
    .iDATA4_Size_Maximum_Read = 0,
    .iDATA4_Size_Actual_Write = 0,
    .iDATA4_Size_Maximum_Write = 0,
    .NbrReptitionsRead = 1,
    .NbrReptitionsWrite = 1,
    .bSeenHibernOn = false, // Initialisation des booléens
    .bSeenHibernOff = false,
    .bSeenSize7Read = false,
    .bSeenSize7Write = false,
    .bSeenFinalSegmentRead = false,
    .bSeenFinalSegmentWrite = false,
    .bSeenFinalData7bytesRead = false,
    .bSeenFinalData4bytesRead = false,
    .bSeenFinalData7bytesWrite = false,
    .bSeenFinalData4bytesWrite = false,
    .StateWrite = eEtape1, // Initialisation de l'énumération
    .StateRead = eEtape1,
    .ptrCompareDefines = CompareWithDefinesIO,
    .ptrCompareErrorCodes = CompareErrorCodesIO,
    .ptrIndexDetails7BytesRead = IndexDetails7BytesRead,
    .ptrIndexDetails4BytesRead = IndexDetails4BytesRead,
    .ptrIndexDetails7BytesWrite = IndexDetails7BytesWrite,
    .ptrIndexDetails4BytesWrite = IndexDetails4BytesWrite};
tNode nEDS = {
    .cNodeType = "EDS", // Initialisation du tableau de caractères
    .iDATA4_Size_Actual_Read = 0,
    .iDATA4_Size_Maximum_Read = 0,
    .iDATA4_Size_Actual_Write = 0,
    .iDATA4_Size_Maximum_Write = 0,
    .NbrReptitionsRead = 1,
    .NbrReptitionsWrite = 1,
    .bSeenHibernOn = false, // Initialisation des booléens
    .bSeenHibernOff = false,
    .bSeenSize7Read = false,
    .bSeenSize7Write = false,
    .bSeenFinalSegmentRead = false,
    .bSeenFinalSegmentWrite = false,
    .bSeenFinalData7bytesRead = false,
    .bSeenFinalData4bytesRead = false,
    .bSeenFinalData7bytesWrite = false,
    .bSeenFinalData4bytesWrite = false,
    .StateWrite = eEtape1, // Initialisation de l'énumération
    .StateRead = eEtape1,
    .ptrCompareDefines = CompareWithDefinesEDS,
    .ptrCompareErrorCodes = CompareErrorCodesEDS,
    .ptrIndexDetails7BytesRead = IndexDetails7BytesRead,
    .ptrIndexDetails4BytesRead = IndexDetails4BytesRead,
    .ptrIndexDetails7BytesWrite = IndexDetails7BytesWrite,
    .ptrIndexDetails4BytesWrite = IndexDetails4BytesWrite};
tNode nGuidance = {
    .cNodeType = "Guidance", // Initialisation du tableau de caractères
    .iDATA4_Size_Actual_Read = 0,
    .iDATA4_Size_Maximum_Read = 0,
    .iDATA4_Size_Actual_Write = 0,
    .iDATA4_Size_Maximum_Write = 0,
    .NbrReptitionsRead = 1,
    .NbrReptitionsWrite = 1,
    .bSeenHibernOn = false, // Initialisation des booléens
    .bSeenHibernOff = false,
    .bSeenSize7Read = false,
    .bSeenSize7Write = false,
    .bSeenFinalSegmentRead = false,
    .bSeenFinalSegmentWrite = false,
    .bSeenFinalData7bytesRead = false,
    .bSeenFinalData4bytesRead = false,
    .bSeenFinalData7bytesWrite = false,
    .bSeenFinalData4bytesWrite = false,
    .StateWrite = eEtape1, // Initialisation de l'énumération
    .StateRead = eEtape1,
    .ptrCompareDefines = CompareWithDefinesGuidance,
    .ptrCompareErrorCodes = CompareErrorCodesGuidance,
    .ptrIndexDetails7BytesRead = IndexDetails7BytesRead,
    .ptrIndexDetails4BytesRead = IndexDetails4BytesRead,
    .ptrIndexDetails7BytesWrite = IndexDetails7BytesWrite,
    .ptrIndexDetails4BytesWrite = IndexDetails4BytesWrite};
tNode nLDriver = {
    .cNodeType = "LDriver", // Initialisation du tableau de caractères
    .iDATA4_Size_Actual_Read = 0,
    .iDATA4_Size_Maximum_Read = 0,
    .iDATA4_Size_Actual_Write = 0,
    .iDATA4_Size_Maximum_Write = 0,
    .DriversMotorRatedCurrent = 10000,
    .NbrReptitionsRead = 1,
    .NbrReptitionsWrite = 1,
    .bSeenHibernOn = false, // Initialisation des booléens
    .bSeenHibernOff = false,
    .bSeenSize7Read = false,
    .bSeenSize7Write = false,
    .bSeenFinalSegmentRead = false,
    .bSeenFinalSegmentWrite = false,
    .bSeenFinalData7bytesRead = false,
    .bSeenFinalData4bytesRead = false,
    .bSeenFinalData7bytesWrite = false,
    .bSeenFinalData4bytesWrite = false,
    .StateWrite = eEtape1, // Initialisation de l'énumération
    .StateRead = eEtape1,
    .ptrCompareDefines = CompareWithDefinesDrivers,
    .ptrCompareErrorCodes = CompareErrorCodesDrivers,
    .ptrIndexDetails7BytesRead = IndexDetails7BytesRead,
    .ptrIndexDetails4BytesRead = IndexDetails4BytesRead,
    .ptrIndexDetails7BytesWrite = IndexDetails7BytesWrite,
    .ptrIndexDetails4BytesWrite = IndexDetails4BytesWrite};
tNode nRDriver = {
    .cNodeType = "RDriver", // Initialisation du tableau de caractères
    .iDATA4_Size_Actual_Read = 0,
    .iDATA4_Size_Maximum_Read = 0,
    .iDATA4_Size_Actual_Write = 0,
    .iDATA4_Size_Maximum_Write = 0,
    .DriversMotorRatedCurrent = 10000,
    .NbrReptitionsRead = 1,
    .NbrReptitionsWrite = 1,
    .bSeenHibernOn = false, // Initialisation des booléens
    .bSeenHibernOff = false,
    .bSeenSize7Read = false,
    .bSeenSize7Write = false,
    .bSeenFinalSegmentRead = false,
    .bSeenFinalSegmentWrite = false,
    .bSeenFinalData7bytesRead = false,
    .bSeenFinalData4bytesRead = false,
    .bSeenFinalData7bytesWrite = false,
    .bSeenFinalData4bytesWrite = false,
    .StateWrite = eEtape1, // Initialisation de l'énumération
    .StateRead = eEtape1,
    .ptrCompareDefines = CompareWithDefinesDrivers,
    .ptrCompareErrorCodes = CompareErrorCodesDrivers,
    .ptrIndexDetails7BytesRead = IndexDetails7BytesRead,
    .ptrIndexDetails4BytesRead = IndexDetails4BytesRead,
    .ptrIndexDetails7BytesWrite = IndexDetails7BytesWrite,
    .ptrIndexDetails4BytesWrite = IndexDetails4BytesWrite};
tNode nRFH6x0 = {
    .cNodeType = "RFH6x0", // Initialisation du tableau de caractères
    .iDATA4_Size_Actual_Read = 0,
    .iDATA4_Size_Maximum_Read = 0,
    .iDATA4_Size_Actual_Write = 0,
    .iDATA4_Size_Maximum_Write = 0,
    .NbrReptitionsRead = 1,
    .NbrReptitionsWrite = 1,
    .bSeenHibernOn = false, // Initialisation des booléens
    .bSeenHibernOff = false,
    .bSeenSize7Read = false,
    .bSeenSize7Write = false,
    .bSeenFinalSegmentRead = false,
    .bSeenFinalSegmentWrite = false,
    .bSeenFinalData7bytesRead = false,
    .bSeenFinalData4bytesRead = false,
    .bSeenFinalData7bytesWrite = false,
    .bSeenFinalData4bytesWrite = false,
    .StateWrite = eEtape1, // Initialisation de l'énumération
    .StateRead = eEtape1,
    .ptrCompareDefines = CompareWithDefinesRFH6x0,
    .ptrCompareErrorCodes = NULL,
    .ptrIndexDetails7BytesRead = IndexDetails7BytesRead,
    .ptrIndexDetails4BytesRead = IndexDetails4BytesRead,
    .ptrIndexDetails7BytesWrite = IndexDetails7BytesWrite,
    .ptrIndexDetails4BytesWrite = IndexDetails4BytesWrite};
tNode nDTM425 = {
    .cNodeType = "DTM425", // Initialisation du tableau de caractères
    .iDATA4_Size_Actual_Read = 0,
    .iDATA4_Size_Maximum_Read = 0,
    .iDATA4_Size_Actual_Write = 0,
    .iDATA4_Size_Maximum_Write = 0,
    .NbrReptitionsRead = 1,
    .NbrReptitionsWrite = 1,
    .bSeenHibernOn = false, // Initialisation des booléens
    .bSeenHibernOff = false,
    .bSeenSize7Read = false,
    .bSeenSize7Write = false,
    .bSeenFinalSegmentRead = false,
    .bSeenFinalSegmentWrite = false,
    .bSeenFinalData7bytesRead = false,
    .bSeenFinalData4bytesRead = false,
    .bSeenFinalData7bytesWrite = false,
    .bSeenFinalData4bytesWrite = false,
    .StateWrite = eEtape1, // Initialisation de l'énumération
    .StateRead = eEtape1,
    .ptrCompareDefines = CompareWithDefinesDTM425,
    .ptrCompareErrorCodes = NULL,
    .ptrIndexDetails7BytesRead = IndexDetails7BytesRead,
    .ptrIndexDetails4BytesRead = IndexDetails4BytesRead,
    .ptrIndexDetails7BytesWrite = IndexDetails7BytesWrite,
    .ptrIndexDetails4BytesWrite = IndexDetails4BytesWrite};
tNode nPCU = {
    .cNodeType = "PCU", // Initialisation du tableau de caractères
    .iDATA4_Size_Actual_Read = 0,
    .iDATA4_Size_Maximum_Read = 0,
    .iDATA4_Size_Actual_Write = 0,
    .iDATA4_Size_Maximum_Write = 0,
    .NbrReptitionsRead = 1,
    .NbrReptitionsWrite = 1,
    .bSeenHibernOn = false, // Initialisation des booléens
    .bSeenHibernOff = false,
    .bSeenSize7Read = false,
    .bSeenSize7Write = false,
    .bSeenFinalSegmentRead = false,
    .bSeenFinalSegmentWrite = false,
    .bSeenFinalData7bytesRead = false,
    .bSeenFinalData4bytesRead = false,
    .bSeenFinalData7bytesWrite = false,
    .bSeenFinalData4bytesWrite = false,
    .StateWrite = eEtape1, // Initialisation de l'énumération
    .StateRead = eEtape1,
    .ptrCompareDefines = CompareWithDefinesPCU,
    .ptrCompareErrorCodes = NULL,
    .ptrIndexDetails7BytesRead = IndexDetails7BytesRead,
    .ptrIndexDetails4BytesRead = IndexDetails4BytesRead,
    .ptrIndexDetails7BytesWrite = IndexDetails7BytesWrite,
    .ptrIndexDetails4BytesWrite = IndexDetails4BytesWrite};

void DetermineProtocolSDO(tNode *nNodeType)
{
    DetermineProtocolSDORead(nNodeType);
    DetermineProtocolSDOWrite(nNodeType);
}
void DetermineProtocolSDORead(tNode *nNodeType)
{
    /*
    strcpy(LigneEnCours.VALEUR_HEXA_ASCII_INDEX, LigneEnCours.VALEUR_HEXA_ASCII_DATA2);
    strcat(LigneEnCours.VALEUR_HEXA_ASCII_INDEX, LigneEnCours.VALEUR_HEXA_ASCII_DATA1);
    strcpy(LigneEnCours.VALEUR_HEXA_ASCII_SUB_INDEX, LigneEnCours.VALEUR_HEXA_ASCII_DATA3);
    */
    nNodeType->StateCAN.SDORx = (eNode)LigneEnCours.iDATA0;
    nNodeType->StateCAN.SDOTx = (eNode)LigneEnCours.iDATA0;

    /* fprintf(O_FILE,"Fctn : %s  %d   Data0 : %s  %d    Line : %d \n",LigneEnCours.VALEUR_HEXA_ASCII_FCTN,LigneEnCours.iFCTN,LigneEnCours.VALEUR_HEXA_ASCII_DATA0,StateCAN.SDORx,LINE_NB); */
    switch (nNodeType->StateRead)
    {
    case eEtape1:
        nNodeType->VALEUR_HEXA_ASCII_Read_FullSegment[0] = 0;
        nNodeType->bSeenFinalData7bytesRead = false;
        nNodeType->bSeenFinalData4bytesRead = false;
        if (nNodeType->StateCAN.SDORx == eSDORxReadExpedited40)
        {
            nNodeType->bSeenSDORead = true;
        }
        /* Concatenation de l'index et stockage du sous index */
        concatenerNombresHexIndexRead(nNodeType, LigneEnCours.VALEUR_HEXA_ASCII_DATA2, LigneEnCours.VALEUR_HEXA_ASCII_DATA1);

        if (nNodeType->StateCAN.SDORx == eSDORxReadExpedited40)
        {
            /* Debug File */
            fprintf(CSVD_FILE, "%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
            fprintf(CSVD_FILE, "%s;", nNodeType->cNodeType);
            fprintf(CSVD_FILE, "SDO_RX;");
            fprintf(CSVD_FILE, ";");
            fprintf(CSVD_FILE, "Read;");
            fprintf(CSVD_FILE, "Expedited;");
            fprintf(CSVD_FILE, "N/A;");
            fprintf(CSVD_FILE, "%s;", nNodeType->VALEUR_HEXA_ASCII_Read_INDEX);
            fprintf(CSVD_FILE, "%s;", nNodeType->VALEUR_HEXA_ASCII_Read_SUB_INDEX);
            nNodeType->ptrCompareDefines(nNodeType, false, RChoice);

            if (nNodeType->NbrReptitionsRead != 1)
            {
                nNodeType->NbrReptitionsRead++;

                /* Debug File */
                fprintf(CSVD_FILE, "Repetition N: %d;", nNodeType->NbrReptitionsRead);

                /* Output File */
                fprintf(CSVO_FILE, "%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVO_FILE, "%s;", nNodeType->cNodeType);
                fprintf(CSVO_FILE, "SDO_RX;");
                fprintf(CSVO_FILE, ";");
                fprintf(CSVO_FILE, "Read;");
                fprintf(CSVO_FILE, "Expedited;");
                fprintf(CSVO_FILE, "N/A;");
                fprintf(CSVO_FILE, "%s;", nNodeType->VALEUR_HEXA_ASCII_Read_INDEX);
                fprintf(CSVO_FILE, "%s;", nNodeType->VALEUR_HEXA_ASCII_Read_SUB_INDEX);
                nNodeType->ptrCompareDefines(nNodeType, true, RChoice);
                fprintf(CSVO_FILE, "Repetition N: %d;", nNodeType->NbrReptitionsRead);
                fprintf(CSVO_FILE, "\r");
            }
            if (nNodeType->NbrReptitionsRead >= 2)
            {
                nNodeType->NbrReptitionsRead = 1;
            }

            fprintf(CSVD_FILE, "\r");

            // fprintf(O_FILE,"Node : %s Etape : %d Repetitions : %d Ligne : %d\n",nNodeType->cNodeType,nNodeType->StateRead,nNodeType->NbrReptitionsRead, LINE_NB);
            nNodeType->StateRead = eEtape2;
        }
        break;

    case eEtape2:
        if ((nNodeType->StateCAN.SDORx != eSDORxReadExpedited40) && (nNodeType->StateCAN.SDOTx == eSDOTxReadExpedited42 || nNodeType->StateCAN.SDOTx == eSDOTxReadExpedited43 || nNodeType->StateCAN.SDOTx == eSDOTxReadExpedited47 || nNodeType->StateCAN.SDOTx == eSDOTxReadExpedited4b || nNodeType->StateCAN.SDOTx == eSDOTxReadExpedited4f))
        {
            nNodeType->NbrReptitionsRead = 1;
            nNodeType->bSeenFinalData4bytesRead = true;
            nNodeType->ptrIndexDetails4BytesRead(nNodeType);
            /* Output File */
            fprintf(CSVO_FILE, "%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
            fprintf(CSVO_FILE, "%s;", nNodeType->cNodeType);
            fprintf(CSVO_FILE, "SDO_TX;");
            fprintf(CSVO_FILE, ";");
            fprintf(CSVO_FILE, "Read;");
            fprintf(CSVO_FILE, "Expedited;");
            switch (nNodeType->StateCAN.SDOTx)
            {
            case eSDOTxReadExpedited42:
                fprintf(CSVO_FILE, "4;");
                break;
            case eSDOTxReadExpedited43:
                fprintf(CSVO_FILE, "3;");
                break;
            case eSDOTxReadExpedited4b:
                fprintf(CSVO_FILE, "2;");
                break;
            case eSDOTxReadExpedited4f:
                fprintf(CSVO_FILE, "1;");
                break;
            default:
                fprintf(CSVO_FILE, "N/A;");
                break;
            }
            fprintf(CSVO_FILE, "%s;", nNodeType->VALEUR_HEXA_ASCII_Read_INDEX);
            fprintf(CSVO_FILE, "%s;", nNodeType->VALEUR_HEXA_ASCII_Read_SUB_INDEX);
            nNodeType->ptrCompareDefines(nNodeType, true, RChoice);
            fprintf(CSVO_FILE, "\r");

            /* Debug File */
            fprintf(CSVD_FILE, "%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
            fprintf(CSVD_FILE, "%s;", nNodeType->cNodeType);
            fprintf(CSVD_FILE, "SDO_TX;");
            fprintf(CSVD_FILE, ";");
            fprintf(CSVD_FILE, "Read;");
            fprintf(CSVD_FILE, "Expedited;");
            switch (nNodeType->StateCAN.SDOTx)
            {
            case eSDOTxReadExpedited42:
                fprintf(CSVD_FILE, "4;");
                break;
            case eSDOTxReadExpedited43:
                fprintf(CSVD_FILE, "3;");
                break;
            case eSDOTxReadExpedited4b:
                fprintf(CSVD_FILE, "2;");
                break;
            case eSDOTxReadExpedited4f:
                fprintf(CSVD_FILE, "1;");
                break;
            default:
                fprintf(CSVD_FILE, "N/A;");
                break;
            }
            fprintf(CSVD_FILE, "%s;", nNodeType->VALEUR_HEXA_ASCII_Read_INDEX);
            fprintf(CSVD_FILE, "%s;", nNodeType->VALEUR_HEXA_ASCII_Read_SUB_INDEX);
            nNodeType->ptrCompareDefines(nNodeType, false, RChoice);
            fprintf(CSVD_FILE, "\r");

            // fprintf(O_FILE,"Cas 1, Node : %s Etape : %d Repetitions : %d Ligne : %d\n",nNodeType->cNodeType,nNodeType->StateRead, nNodeType->NbrReptitionsRead, LINE_NB);
            nNodeType->StateRead = eEtape1;
        }
        if ((nNodeType->StateCAN.SDORx != eSDORxReadExpedited40) && (nNodeType->StateCAN.SDOTx == eSDOTxReadSegmented40 || nNodeType->StateCAN.SDOTx == eSDOTxReadSegmented41))
        {
            nNodeType->NbrReptitionsRead = 1;
            /* Debug File */
            fprintf(CSVD_FILE, "%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
            fprintf(CSVD_FILE, "%s;", nNodeType->cNodeType);
            fprintf(CSVD_FILE, "SDO_TX;");
            fprintf(CSVD_FILE, ";");
            fprintf(CSVD_FILE, "Read;");
            fprintf(CSVD_FILE, "Segmented;");

            nNodeType->iDATA4_Size_Maximum_Read = LigneEnCours.iDATA4;
            nNodeType->iDATA4_Size_Actual_Read = LigneEnCours.iDATA4;
            if (nNodeType->iDATA4_Size_Maximum_Read <= 7)
            {
                nNodeType->bSeenSize7Read = true;
            }
            else
            {
                nNodeType->bSeenSize7Read = false;
            }
            fprintf(CSVD_FILE, "%d;", nNodeType->iDATA4_Size_Maximum_Read);

            fprintf(CSVD_FILE, "%s;", nNodeType->VALEUR_HEXA_ASCII_Read_INDEX);
            fprintf(CSVD_FILE, "%s;", nNodeType->VALEUR_HEXA_ASCII_Read_SUB_INDEX);
            nNodeType->ptrCompareDefines(nNodeType, false, RChoice);
            fprintf(CSVD_FILE, "\r");

            // fprintf(O_FILE,"Cas 2, Node : %s Etape : %d Repetitions : %d Ligne : %d\n",nNodeType->cNodeType,nNodeType->StateRead, nNodeType->NbrReptitionsRead, LINE_NB);
            nNodeType->StateRead = eEtape3;
        }
        if (nNodeType->StateCAN.SDORx == eSDORxReadExpedited40)
        {
            nNodeType->NbrReptitionsRead = 1;
            nNodeType->NbrReptitionsRead++;
            /* Output File */
            fprintf(CSVO_FILE, "%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
            fprintf(CSVO_FILE, "%s;", nNodeType->cNodeType);
            fprintf(CSVO_FILE, "SDO_RX;");
            fprintf(CSVO_FILE, ";");
            fprintf(CSVO_FILE, "Read;");
            fprintf(CSVO_FILE, "Expedited;");
            fprintf(CSVO_FILE, "N/A;");
            fprintf(CSVO_FILE, "%s;", nNodeType->VALEUR_HEXA_ASCII_Read_INDEX);
            fprintf(CSVO_FILE, "%s;", nNodeType->VALEUR_HEXA_ASCII_Read_SUB_INDEX);
            nNodeType->ptrCompareDefines(nNodeType, true, RChoice);
            fprintf(CSVO_FILE, "Repetition N: %d;", nNodeType->NbrReptitionsRead);
            fprintf(CSVO_FILE, "\r");

            /* Debug File */
            fprintf(CSVD_FILE, "%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
            fprintf(CSVD_FILE, "%s;", nNodeType->cNodeType);
            fprintf(CSVD_FILE, "SDO_RX;");
            fprintf(CSVD_FILE, ";");
            fprintf(CSVD_FILE, "Read;");
            fprintf(CSVD_FILE, "Expedited;");
            fprintf(CSVD_FILE, "N/A;");
            fprintf(CSVD_FILE, "%s;", nNodeType->VALEUR_HEXA_ASCII_Read_INDEX);
            fprintf(CSVD_FILE, "%s;", nNodeType->VALEUR_HEXA_ASCII_Read_SUB_INDEX);
            nNodeType->ptrCompareDefines(nNodeType, false, RChoice);
            fprintf(CSVD_FILE, "Repetition N: %d;", nNodeType->NbrReptitionsRead);
            fprintf(CSVD_FILE, "\r");

            // fprintf(O_FILE,"Cas 3, Node : %s Etape : %d Repetitions : %d Ligne : %d\n",nNodeType->cNodeType,nNodeType->StateRead, nNodeType->NbrReptitionsRead, LINE_NB);
            nNodeType->StateRead = eEtape1;
        }
        break;

    case eEtape3:
        if (nNodeType->StateCAN.SDORx == eSDORxReadSegmented60)
        {
            /* Debug File */
            fprintf(CSVD_FILE, "%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
            fprintf(CSVD_FILE, "%s;", nNodeType->cNodeType);
            fprintf(CSVD_FILE, "SDO_RX;");
            fprintf(CSVD_FILE, ";");
            fprintf(CSVD_FILE, "Read;");
            fprintf(CSVD_FILE, "Segmented;");
            fprintf(CSVD_FILE, "N/A;");
            fprintf(CSVD_FILE, "SegmentedMessageOk;");
            fprintf(CSVD_FILE, "\r");

            // fprintf(O_FILE,"Node : %s Etape : %d   Ligne : %d\n",nNodeType->cNodeType,nNodeType->StateRead, LINE_NB);
            nNodeType->StateRead = eEtape4;
        }
        else
        {
            /* Output File */
            fprintf(CSVO_FILE, "%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
            fprintf(CSVO_FILE, "%s;", nNodeType->cNodeType);
            fprintf(CSVO_FILE, "SDO_RX;");
            fprintf(CSVO_FILE, ";");
            fprintf(CSVO_FILE, "Read;");
            fprintf(CSVO_FILE, "Segmented;");
            fprintf(CSVO_FILE, "N/A;");
            fprintf(CSVO_FILE, "ErrorFrameInterrupted;");
            fprintf(CSVO_FILE, ";");
            fprintf(CSVO_FILE, "Transmission SDO NOK;");
            fprintf(CSVO_FILE, "\r");

            /* Debug File */
            fprintf(CSVD_FILE, "%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
            fprintf(CSVD_FILE, "%s;", nNodeType->cNodeType);
            fprintf(CSVD_FILE, "SDO_RX;");
            fprintf(CSVD_FILE, ";");
            fprintf(CSVD_FILE, "Read;");
            fprintf(CSVD_FILE, "Segmented;");
            fprintf(CSVD_FILE, "N/A;");
            fprintf(CSVD_FILE, "ErrorFrameInterrupted;");
            fprintf(CSVD_FILE, ";");
            fprintf(CSVD_FILE, "Transmission SDO NOK;");
            fprintf(CSVD_FILE, "\r");
            // fprintf(O_FILE,"Cas 3, Node : %s Etape : %d   Ligne : %d\n",nNodeType->cNodeType,nNodeType->StateRead, LINE_NB);
            nNodeType->StateRead = eEtape1;
        }
        break;

    case eEtape4:
        if (nNodeType->StateCAN.SDOTx != eSDOTxReadSegmented1 && nNodeType->StateCAN.SDOTx != eSDOTxReadSegmented40 && nNodeType->StateCAN.SDOTx != eSDOTxReadSegmented41 && nNodeType->StateCAN.SDOTx != eSDOTxReadExpedited43 && nNodeType->StateCAN.SDOTx != eSDOTxReadExpedited47 && nNodeType->StateCAN.SDOTx != eSDOTxReadExpedited4b && nNodeType->StateCAN.SDOTx != eSDOTxReadExpedited4f)
        {
            nNodeType->ptrIndexDetails7BytesRead(nNodeType);
            /* Debug File */
            fprintf(CSVD_FILE, "%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
            fprintf(CSVD_FILE, "%s;", nNodeType->cNodeType);
            fprintf(CSVD_FILE, "SDO_TX;");
            fprintf(CSVD_FILE, ";");
            fprintf(CSVD_FILE, "Read;");
            fprintf(CSVD_FILE, "Segmented;");
            if (nNodeType->bSeenSize7Read)
            {
                fprintf(CSVD_FILE, "%d;", nNodeType->iDATA4_Size_Maximum_Read);
            }
            else
            {
                fprintf(CSVD_FILE, "7;");
                nNodeType->iDATA4_Size_Actual_Read = nNodeType->iDATA4_Size_Actual_Read - 7;
                if (nNodeType->iDATA4_Size_Actual_Read <= 7)
                {
                    nNodeType->bSeenFinalSegmentRead = true;
                    nNodeType->StateRead = eEtape6;
                }
                else
                {
                    nNodeType->bSeenFinalSegmentRead = false;
                }
            }

            fprintf(CSVD_FILE, "SegmentedMessageData;");
            fprintf(CSVD_FILE, ";");
            fprintf(CSVD_FILE, "N/A"); // Emplacement Data
            fprintf(CSVD_FILE, ";");
            fprintf(CSVD_FILE, "\r");

            // fprintf(O_FILE,"Cas 1, Node : %s Etape : %d   Ligne : %d\n",nNodeType->cNodeType,nNodeType->StateRead, LINE_NB);
            // fprintf(O_FILE,"SizeMax : %d  SizeActual : %d\n",nNodeType->iDATA4_Size_Maximum_Read,nNodeType->iDATA4_Size_Actual_Read);
            nNodeType->StateRead = eEtape5;
        }
        if (nNodeType->StateCAN.SDOTx == eSDOTxReadSegmented1 || nNodeType->StateCAN.SDOTx == eSDOTxReadSegmented5 || nNodeType->StateCAN.SDOTx == eSDOTxReadSegmented3)
        {
            nNodeType->bSeenFinalData7bytesRead = true;
            nNodeType->ptrIndexDetails7BytesRead(nNodeType);
            /* Output File */
            fprintf(CSVO_FILE, "%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
            fprintf(CSVO_FILE, "%s;", nNodeType->cNodeType);
            fprintf(CSVO_FILE, "SDO_TX;");
            fprintf(CSVO_FILE, ";");
            fprintf(CSVO_FILE, "Read;");
            fprintf(CSVO_FILE, "Segmented;");
            fprintf(CSVO_FILE, "%d;", nNodeType->iDATA4_Size_Maximum_Read);
            fprintf(CSVO_FILE, "SegmentedMessageDataEndOfSegment;");
            fprintf(CSVO_FILE, "Transmission SDO OK;");
            nNodeType->ptrCompareDefines(nNodeType, true, RChoice);
            // hexStringToAscii(nNodeType, nNodeType->VALEUR_HEXA_ASCII_FullSegment, true);
            fprintf(CSVO_FILE, ";");
            fprintf(CSVO_FILE, "\r");

            /* Debug File */
            fprintf(CSVD_FILE, "%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
            fprintf(CSVD_FILE, "%s;", nNodeType->cNodeType);
            fprintf(CSVD_FILE, "SDO_TX;");
            fprintf(CSVD_FILE, ";");
            fprintf(CSVD_FILE, "Read;");
            fprintf(CSVD_FILE, "Segmented;");
            // nNodeType->iDATA4_Size_Actual_Read = nNodeType->iDATA4_Size_Actual_Read % 7;
            // fprintf(CSVD_FILE,"%d;", nNodeType->iDATA4_Size_Actual_Read);
            nNodeType->iDATA4_Size_Actual_Read = nNodeType->iDATA4_Size_Actual_Read % 7;
            if (nNodeType->iDATA4_Size_Actual_Read == 0)
            {
                fprintf(CSVD_FILE, "7;");
            }
            else
            {
                fprintf(CSVD_FILE, "0;");
            }
            fprintf(CSVD_FILE, "SegmentedMessageDataEndOfSegment;");
            fprintf(CSVD_FILE, ";");
            fprintf(CSVD_FILE, "Transmission SDO OK;");
            nNodeType->ptrCompareDefines(nNodeType, false, RChoice);
            // hexStringToAscii(nNodeType, nNodeType->VALEUR_HEXA_ASCII_FullSegment, false);
            fprintf(CSVD_FILE, ";");
            fprintf(CSVD_FILE, "\r");

            // fprintf(O_FILE,"Cas 2, Node : %s Etape : %d   Ligne : %d\n",nNodeType->cNodeType,nNodeType->StateRead, LINE_NB);
            nNodeType->StateRead = eEtape1;
        }
        break;

    case eEtape5:
        if (nNodeType->StateCAN.SDORx != eSDORxReadExpedited40 && nNodeType->StateCAN.SDORx != eSDORxWriteSegmented20 && nNodeType->StateCAN.SDORx != eSDORxWriteSegmented21 && nNodeType->StateCAN.SDORx != eSDORxWriteExpedited23 && nNodeType->StateCAN.SDORx != eSDORxWriteExpedited27 && nNodeType->StateCAN.SDORx != eSDORxWriteExpedited2b && nNodeType->StateCAN.SDORx != eSDORxWriteExpedited2f)
        {
            if ((nNodeType->StateCAN.SDORx == eSDORxReadSegmented60 || nNodeType->StateCAN.SDORx == eSDORxReadSegmented70) && nNodeType->bSeenFinalSegmentRead == true)
            {
                /* Debug File */
                fprintf(CSVD_FILE, "%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVD_FILE, "%s;", nNodeType->cNodeType);
                fprintf(CSVD_FILE, "SDO_RX;");
                fprintf(CSVD_FILE, ";");
                fprintf(CSVD_FILE, "Read;");
                fprintf(CSVD_FILE, "Segmented;");
                fprintf(CSVD_FILE, ";");
                fprintf(CSVD_FILE, "SegmentedMessageFinalOk;");
                fprintf(CSVD_FILE, "\r");

                // fprintf(O_FILE,"Cas 1, Node : %s Etape : %d   Ligne : %d\n",nNodeType->cNodeType,nNodeType->StateRead, LINE_NB);
                nNodeType->StateRead = eEtape6;
            }
            else if ((nNodeType->StateCAN.SDORx == eSDORxReadSegmented60 || nNodeType->StateCAN.SDORx == eSDORxReadSegmented70) && nNodeType->bSeenFinalSegmentRead == false)
            {
                /* Debug File */
                fprintf(CSVD_FILE, "%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVD_FILE, "%s;", nNodeType->cNodeType);
                fprintf(CSVD_FILE, "SDO_RX;");
                fprintf(CSVD_FILE, ";");
                fprintf(CSVD_FILE, "Read;");
                fprintf(CSVD_FILE, "Segmented;");
                fprintf(CSVD_FILE, ";");
                fprintf(CSVD_FILE, "SegmentedMessageOkFlipped;");
                fprintf(CSVD_FILE, "\r");

                // fprintf(O_FILE,"Cas 2, Node : %s Etape : %d   Ligne : %d\n",nNodeType->cNodeType,nNodeType->StateRead, LINE_NB);
                nNodeType->StateRead = eEtape4;
            }
        }
        else
        {
            /* Output File */
            fprintf(CSVO_FILE, "%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
            fprintf(CSVO_FILE, "%s;", nNodeType->cNodeType);
            fprintf(CSVO_FILE, "SDO_RX;");
            fprintf(CSVO_FILE, ";");
            fprintf(CSVO_FILE, "Read;");
            fprintf(CSVO_FILE, "Segmented;");
            fprintf(CSVO_FILE, "N/A;");
            fprintf(CSVO_FILE, "ErrorFrameInterrupted;");
            fprintf(CSVO_FILE, ";");
            fprintf(CSVO_FILE, "Transmission SDO NOK;");
            fprintf(CSVO_FILE, "\r");

            /* Debug File */
            fprintf(CSVD_FILE, "%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
            fprintf(CSVD_FILE, "%s;", nNodeType->cNodeType);
            fprintf(CSVD_FILE, "SDO_RX;");
            fprintf(CSVD_FILE, ";");
            fprintf(CSVD_FILE, "Read;");
            fprintf(CSVD_FILE, "Segmented;");
            fprintf(CSVD_FILE, "N/A;");
            fprintf(CSVD_FILE, "ErrorFrameInterrupted;");
            fprintf(CSVD_FILE, ";");
            fprintf(CSVD_FILE, "Transmission SDO NOK;");
            fprintf(CSVD_FILE, "\r");
            // fprintf(O_FILE,"Cas 3, Node : %s Etape : %d   Ligne : %d\n",nNodeType->cNodeType,nNodeType->StateRead, LINE_NB);
            nNodeType->StateRead = eEtape1;
        }
        break;

    case eEtape6:
        if (nNodeType->StateCAN.SDOTx == eSDOTxReadSegmented1 || nNodeType->StateCAN.SDOTx == eSDOTxReadSegmented3 || nNodeType->StateCAN.SDOTx == eSDOTxReadSegmented0b || nNodeType->StateCAN.SDOTx == eSDOTxReadSegmented11 || nNodeType->StateCAN.SDOTx == eSDOTxReadSegmented19 || nNodeType->StateCAN.SDOTx == eSDOTxReadSegmented1d || nNodeType->StateCAN.SDOTx == eSDOTxReadSegmented15)
        {
            nNodeType->bSeenFinalData7bytesRead = true;
            nNodeType->ptrIndexDetails7BytesRead(nNodeType);
            nNodeType->bSeenSDORead = false;
            /* Output File */
            fprintf(CSVO_FILE, "%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
            fprintf(CSVO_FILE, "%s;", nNodeType->cNodeType);
            fprintf(CSVO_FILE, "SDO_TX;");
            fprintf(CSVO_FILE, ";");
            fprintf(CSVO_FILE, "Read;");
            fprintf(CSVO_FILE, "Segmented;");
            fprintf(CSVO_FILE, "%d;", nNodeType->iDATA4_Size_Maximum_Read);
            fprintf(CSVO_FILE, "%s;", nNodeType->VALEUR_HEXA_ASCII_Read_INDEX);
            fprintf(CSVO_FILE, "%s;", nNodeType->VALEUR_HEXA_ASCII_Read_SUB_INDEX);
            fprintf(CSVO_FILE, "SegmentedMessageDataEndOfSegment;");
            // fprintf(O_FILE_2, "FinalSegmentValue, Index : %d Ligne : %d Chaine : %s\n",nNodeType->iNodeIndex, LINE_NB, nNodeType->VALEUR_HEXA_ASCII_FinalSegment);
            fprintf(CSVO_FILE, "Transmission SDO OK;");
            nNodeType->ptrCompareDefines(nNodeType, true, RChoice);
            fprintf(CSVO_FILE, ";");
            fprintf(CSVO_FILE, "\r");

            /* Debug File */
            fprintf(CSVD_FILE, "%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
            fprintf(CSVD_FILE, "%s;", nNodeType->cNodeType);
            fprintf(CSVD_FILE, "SDO_TX;");
            fprintf(CSVD_FILE, ";");
            fprintf(CSVD_FILE, "Read;");
            fprintf(CSVD_FILE, "Segmented;");
            nNodeType->iDATA4_Size_Actual_Read = nNodeType->iDATA4_Size_Actual_Read % 7;
            if (nNodeType->iDATA4_Size_Actual_Read == 0)
            {
                fprintf(CSVD_FILE, "7;");
            }
            else
            {
                fprintf(CSVD_FILE, "%d;", nNodeType->iDATA4_Size_Actual_Read);
            }
            fprintf(CSVD_FILE, "SegmentedMessageDataEndOfSegment;");
            fprintf(CSVD_FILE, ";");
            fprintf(CSVD_FILE, "Transmission SDO OK;");
            nNodeType->ptrCompareDefines(nNodeType, false, RChoice);
            fprintf(CSVD_FILE, ";");
            fprintf(CSVD_FILE, "\r");

            // fprintf(O_FILE,"Node : %s Etape : %d   Ligne : %d\n",nNodeType->cNodeType,nNodeType->StateRead, LINE_NB);
            nNodeType->StateRead = eEtape1;
        }
        break;
    }
}
void DetermineProtocolSDOWrite(tNode *nNodeType)
{
    /*
    strcpy(LigneEnCours.VALEUR_HEXA_ASCII_INDEX, LigneEnCours.VALEUR_HEXA_ASCII_DATA2);
    strcat(LigneEnCours.VALEUR_HEXA_ASCII_INDEX, LigneEnCours.VALEUR_HEXA_ASCII_DATA1);
    strcpy(LigneEnCours.VALEUR_HEXA_ASCII_SUB_INDEX, LigneEnCours.VALEUR_HEXA_ASCII_DATA3);
    */
    nNodeType->StateCAN.SDORx = (eNode)LigneEnCours.iDATA0;
    nNodeType->StateCAN.SDOTx = (eNode)LigneEnCours.iDATA0;

    switch (nNodeType->StateWrite)
    {
    case eEtape1:
        nNodeType->VALEUR_HEXA_ASCII_Write_FullSegment[0] = 0;
        nNodeType->bSeenFinalData7bytesWrite = false;
        nNodeType->bSeenFinalData4bytesWrite = false;

        /* Concatenation de l'index et stockage du sous index */
        concatenerNombresHexIndexWrite(nNodeType, LigneEnCours.VALEUR_HEXA_ASCII_DATA2, LigneEnCours.VALEUR_HEXA_ASCII_DATA1);
        //fprintf(O_FILE_2, "Write Index : %s Line NB : %d\r;", nNodeType->VALEUR_HEXA_ASCII_Write_INDEX, LINE_NB);
        if (nNodeType->StateCAN.SDORx == eSDORxWriteExpedited23 || nNodeType->StateCAN.SDORx == eSDORxWriteExpedited27 || nNodeType->StateCAN.SDORx == eSDORxWriteExpedited2b || nNodeType->StateCAN.SDORx == eSDORxWriteExpedited2f)
        {
            nNodeType->bSeenFinalData4bytesWrite = true;
            nNodeType->ptrIndexDetails4BytesWrite(nNodeType);

            /* Output File */
            fprintf(CSVO_FILE, "%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
            fprintf(CSVO_FILE, "%s;", nNodeType->cNodeType);
            fprintf(CSVO_FILE, "SDO_RX;");
            fprintf(CSVO_FILE, ";");
            fprintf(CSVO_FILE, "Write;");
            fprintf(CSVO_FILE, "Expedited;");
            switch (nNodeType->StateCAN.SDOTx)
            {
            case eSDORxWriteExpedited23:
                fprintf(CSVO_FILE, "4;");
                nNodeType->iDATA4_Size_Maximum_Write = 4;
                break;
            case eSDORxWriteExpedited27:
                fprintf(CSVO_FILE, "3;");
                nNodeType->iDATA4_Size_Maximum_Write = 3;
                break;
            case eSDORxWriteExpedited2b:
                fprintf(CSVO_FILE, "2;");
                nNodeType->iDATA4_Size_Maximum_Write = 2;
                break;
            case eSDORxWriteExpedited2f:
                fprintf(CSVO_FILE, "1;");
                nNodeType->iDATA4_Size_Maximum_Write = 1;
                break;
            default:
                fprintf(CSVO_FILE, "N/A;");
                break;
            }
            fprintf(CSVO_FILE, "%s;", nNodeType->VALEUR_HEXA_ASCII_Write_INDEX);
            fprintf(CSVO_FILE, "%s;", nNodeType->VALEUR_HEXA_ASCII_Write_SUB_INDEX);
            nNodeType->ptrCompareDefines(nNodeType, true, WChoice);

            /* Debug File */
            fprintf(CSVD_FILE, "%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
            fprintf(CSVD_FILE, "%s;", nNodeType->cNodeType);
            fprintf(CSVD_FILE, "SDO_RX;");
            fprintf(CSVD_FILE, ";");
            fprintf(CSVD_FILE, "Write;");
            fprintf(CSVD_FILE, "Expedited;");
            switch (nNodeType->StateCAN.SDOTx)
            {
            case eSDORxWriteExpedited23:
                fprintf(CSVD_FILE, "4;");
                nNodeType->iDATA4_Size_Maximum_Write = 4;
                break;
            case eSDORxWriteExpedited27:
                fprintf(CSVD_FILE, "3;");
                nNodeType->iDATA4_Size_Maximum_Write = 3;
                break;
            case eSDORxWriteExpedited2b:
                fprintf(CSVD_FILE, "2;");
                nNodeType->iDATA4_Size_Maximum_Write = 2;
                break;
            case eSDORxWriteExpedited2f:
                fprintf(CSVD_FILE, "1;");
                nNodeType->iDATA4_Size_Maximum_Write = 1;
                break;
            default:
                fprintf(CSVD_FILE, "N/A;");
                break;
            }
            fprintf(CSVD_FILE, "%s;", nNodeType->VALEUR_HEXA_ASCII_Write_INDEX);
            fprintf(CSVD_FILE, "%s;", nNodeType->VALEUR_HEXA_ASCII_Write_SUB_INDEX);
            nNodeType->ptrCompareDefines(nNodeType, false, WChoice);

            if (nNodeType->NbrReptitionsWrite != 1)
            {
                nNodeType->NbrReptitionsWrite++;

                /* Output File */
                fprintf(CSVO_FILE, "Repetition N: %d;", nNodeType->NbrReptitionsWrite);

                /* Debug File */
                fprintf(CSVD_FILE, "Repetition N: %d;", nNodeType->NbrReptitionsWrite);
            }
            if (nNodeType->NbrReptitionsWrite >= 2)
            {
                nNodeType->NbrReptitionsWrite = 1;
            }
            fprintf(CSVO_FILE, "\r");
            fprintf(CSVD_FILE, "\r");

            // fprintf(O_FILE_2,"Write, Cas 1, Node : %s Etape : %d Repetitions : %d Ligne : %d\n",nNodeType->cNodeType,nNodeType->StateWrite,nNodeType->NbrReptitionsRead, LINE_NB);
            if(nNodeType->iDATA4_Size_Maximum_Write != 0) {
                nNodeType->StateWrite = eEtape2;
            }
            else {
                nNodeType->StateWrite = eEtape1;
            }
        }
        if (nNodeType->StateCAN.SDORx == eSDORxWriteSegmented20 || nNodeType->StateCAN.SDORx == eSDORxWriteSegmented21)
        {
            /* Output File */

            fprintf(CSVO_FILE, "%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
            fprintf(CSVO_FILE, "%s;", nNodeType->cNodeType);
            fprintf(CSVO_FILE, "SDO_RX;");
            fprintf(CSVO_FILE, ";");
            fprintf(CSVO_FILE, "Write;");
            fprintf(CSVO_FILE, "Segmented;");


            /* Debug File */
            fprintf(CSVD_FILE, "%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
            fprintf(CSVD_FILE, "%s;", nNodeType->cNodeType);
            fprintf(CSVD_FILE, "SDO_RX;");
            fprintf(CSVD_FILE, ";");
            fprintf(CSVD_FILE, "Write;");
            fprintf(CSVD_FILE, "Segmented;");

            nNodeType->iDATA4_Size_Maximum_Write = LigneEnCours.iDATA4;
            nNodeType->iDATA4_Size_Actual_Write = LigneEnCours.iDATA4;
            if (nNodeType->iDATA4_Size_Maximum_Write <= 7)
            {
                nNodeType->bSeenSize7Write = true;
            }
            else
            {
                nNodeType->bSeenSize7Write = false;
            }
            fprintf(CSVO_FILE, "%d;", nNodeType->iDATA4_Size_Maximum_Write);
            fprintf(CSVD_FILE, "%d;", nNodeType->iDATA4_Size_Maximum_Write);

            fprintf(CSVO_FILE, "%s;", nNodeType->VALEUR_HEXA_ASCII_Write_INDEX);
            fprintf(CSVO_FILE, "%s;", nNodeType->VALEUR_HEXA_ASCII_Write_SUB_INDEX);
            fprintf(CSVD_FILE, "%s;", nNodeType->VALEUR_HEXA_ASCII_Write_INDEX);
            fprintf(CSVD_FILE, "%s;", nNodeType->VALEUR_HEXA_ASCII_Write_SUB_INDEX);

            nNodeType->ptrCompareDefines(nNodeType, true, WChoice);
            nNodeType->ptrCompareDefines(nNodeType, false, WChoice);

            if (nNodeType->NbrReptitionsWrite != 1)
            {
                nNodeType->NbrReptitionsWrite++;

                /* Output File */
                fprintf(CSVO_FILE, "Repetition N: %d;", nNodeType->NbrReptitionsWrite);

                /* Debug File */
                fprintf(CSVD_FILE, "Repetition N: %d;", nNodeType->NbrReptitionsWrite);
            }
            if (nNodeType->NbrReptitionsWrite >= 2)
            {
                nNodeType->NbrReptitionsWrite = 1;
            }

            fprintf(CSVO_FILE, "\r");
            fprintf(CSVD_FILE, "\r");

            //fprintf(O_FILE_2,"Write, Cas 2, Node : %s Etape : %d Repetitions : %d Ligne : %d\n",nNodeType->cNodeType,nNodeType->StateWrite,nNodeType->NbrReptitionsRead, LINE_NB);
            if(nNodeType->iDATA4_Size_Maximum_Write != 0) {
                nNodeType->StateWrite = eEtape2;
            }
            else {
                nNodeType->StateWrite = eEtape1;
            }
        }
        break;
    case eEtape2:
        if (nNodeType->StateCAN.SDOTx == eSDOTxWriteSegmented60)
        {
            nNodeType->NbrReptitionsWrite = 1;

            /* Output File */
            /*
            fprintf(CSVO_FILE, "%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
            fprintf(CSVO_FILE, "%s;", nNodeType->cNodeType);
            fprintf(CSVO_FILE, "SDO_TX;");
            fprintf(CSVO_FILE, ";");
            fprintf(CSVO_FILE, "Write;");
            fprintf(CSVO_FILE, "N/A;");
            fprintf(CSVO_FILE, "N/A;");
            fprintf(CSVO_FILE, "SegmentedMessageOk;");
            fprintf(CSVO_FILE, "\r");
            */

            /* Debug File */
            fprintf(CSVD_FILE, "%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
            fprintf(CSVD_FILE, "%s;", nNodeType->cNodeType);
            fprintf(CSVD_FILE, "SDO_TX;");
            fprintf(CSVD_FILE, ";");
            fprintf(CSVD_FILE, "Write;");
            fprintf(CSVD_FILE, "N/A;");
            fprintf(CSVD_FILE, "N/A;");
            fprintf(CSVD_FILE, "SegmentedMessageOk;");
            fprintf(CSVD_FILE, "\r");

            //fprintf(O_FILE_2,"Write, Cas 1, Node : %s Etape : %d Repetitions : %d Ligne : %d\n",nNodeType->cNodeType,nNodeType->StateWrite,nNodeType->NbrReptitionsRead, LINE_NB);
            if (nNodeType->bSeenFinalData4bytesWrite)
            {
                nNodeType->StateWrite = eEtape1;
            }
            else
            {
                nNodeType->StateWrite = eEtape3;
            }
        }
        if ((nNodeType->StateCAN.SDOTx != eSDOTxWriteSegmented60) && (nNodeType->StateCAN.SDORx == eSDORxWriteExpedited23 || nNodeType->StateCAN.SDORx == eSDORxWriteExpedited27 || nNodeType->StateCAN.SDORx == eSDORxWriteExpedited2b || nNodeType->StateCAN.SDORx == eSDORxWriteExpedited2f))
        {
            nNodeType->NbrReptitionsWrite = 1;
            nNodeType->NbrReptitionsWrite++;

            /* Output File */
            fprintf(CSVO_FILE, "%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
            fprintf(CSVO_FILE, "%s;", nNodeType->cNodeType);
            fprintf(CSVO_FILE, "SDO_RX;");
            fprintf(CSVO_FILE, ";");
            fprintf(CSVO_FILE, "Write;");
            fprintf(CSVO_FILE, "Expedited;");
            switch (nNodeType->StateCAN.SDOTx)
            {
            case eSDORxWriteExpedited23:
                fprintf(CSVO_FILE, "4;");
                break;
            case eSDORxWriteExpedited27:
                fprintf(CSVO_FILE, "3;");
                break;
            case eSDORxWriteExpedited2b:
                fprintf(CSVO_FILE, "2;");
                break;
            case eSDORxWriteExpedited2f:
                fprintf(CSVO_FILE, "1;");
                break;
            default:
                fprintf(CSVO_FILE, "N/A;");
                break;
            }
            fprintf(CSVO_FILE, "%s;", nNodeType->VALEUR_HEXA_ASCII_Write_INDEX);
            fprintf(CSVO_FILE, "%s;", nNodeType->VALEUR_HEXA_ASCII_Write_SUB_INDEX);
            nNodeType->ptrCompareDefines(nNodeType, true, WChoice);

            /* Debug File */
            fprintf(CSVD_FILE, "%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
            fprintf(CSVD_FILE, "%s;", nNodeType->cNodeType);
            fprintf(CSVD_FILE, "SDO_RX;");
            fprintf(CSVD_FILE, ";");
            fprintf(CSVD_FILE, "Write;");
            fprintf(CSVD_FILE, "Expedited;");
            switch (nNodeType->StateCAN.SDOTx)
            {
            case eSDORxWriteExpedited23:
                fprintf(CSVD_FILE, "4;");
                break;
            case eSDORxWriteExpedited27:
                fprintf(CSVD_FILE, "3;");
                break;
            case eSDORxWriteExpedited2b:
                fprintf(CSVD_FILE, "2;");
                break;
            case eSDORxWriteExpedited2f:
                fprintf(CSVD_FILE, "1;");
                break;
            default:
                fprintf(CSVD_FILE, "N/A;");
                break;
            }
            fprintf(CSVD_FILE, "%s;", nNodeType->VALEUR_HEXA_ASCII_Write_INDEX);
            fprintf(CSVD_FILE, "%s;", nNodeType->VALEUR_HEXA_ASCII_Write_SUB_INDEX);
            nNodeType->ptrCompareDefines(nNodeType, false, WChoice);

            fprintf(CSVO_FILE, "\r");
            fprintf(CSVD_FILE, "\r");

            // fprintf(O_FILE_2,"Write, Cas 2, Node : %s Etape : %d Repetitions : %d Ligne : %d\n",nNodeType->cNodeType,nNodeType->StateWrite,nNodeType->NbrReptitionsRead, LINE_NB);
            nNodeType->StateWrite = eEtape2;
        }
        if ((nNodeType->StateCAN.SDOTx != eSDOTxWriteSegmented60) && (nNodeType->StateCAN.SDORx == eSDORxWriteSegmented20 || nNodeType->StateCAN.SDORx == eSDORxWriteSegmented21))
        {
            nNodeType->NbrReptitionsWrite = 1;
            nNodeType->NbrReptitionsWrite++;

            /* Output File */
            fprintf(CSVO_FILE, "%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
            fprintf(CSVO_FILE, "%s;", nNodeType->cNodeType);
            fprintf(CSVO_FILE, "SDO_RX;");
            fprintf(CSVO_FILE, ";");
            fprintf(CSVO_FILE, "Write;");
            fprintf(CSVO_FILE, "Segmented;");

            /* Debug File */
            fprintf(CSVD_FILE, "%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
            fprintf(CSVD_FILE, "%s;", nNodeType->cNodeType);
            fprintf(CSVD_FILE, "SDO_RX;");
            fprintf(CSVD_FILE, ";");
            fprintf(CSVD_FILE, "Write;");
            fprintf(CSVD_FILE, "Segmented;");

            nNodeType->iDATA4_Size_Maximum_Write = LigneEnCours.iDATA4;
            nNodeType->iDATA4_Size_Actual_Write = LigneEnCours.iDATA4;
            if (nNodeType->iDATA4_Size_Maximum_Write <= 7)
            {
                nNodeType->bSeenSize7Write = true;
            }
            else
            {
                nNodeType->bSeenSize7Write = false;
            }
            fprintf(CSVO_FILE, "%d;", nNodeType->iDATA4_Size_Maximum_Write);
            fprintf(CSVD_FILE, "%d;", nNodeType->iDATA4_Size_Maximum_Write);

            fprintf(CSVO_FILE, "%s;", nNodeType->VALEUR_HEXA_ASCII_Write_INDEX);
            fprintf(CSVO_FILE, "%s;", nNodeType->VALEUR_HEXA_ASCII_Write_SUB_INDEX);
            fprintf(CSVD_FILE, "%s;", nNodeType->VALEUR_HEXA_ASCII_Write_INDEX);
            fprintf(CSVD_FILE, "%s;", nNodeType->VALEUR_HEXA_ASCII_Write_SUB_INDEX);

            nNodeType->ptrCompareDefines(nNodeType, true, WChoice);
            nNodeType->ptrCompareDefines(nNodeType, false, WChoice);

            fprintf(CSVO_FILE, "\r");
            fprintf(CSVD_FILE, "\r");

            // fprintf(O_FILE_2,"Write, Cas 3, Node : %s Etape : %d Repetitions : %d Ligne : %d\n",nNodeType->cNodeType,nNodeType->StateWrite,nNodeType->NbrReptitionsRead, LINE_NB);
            nNodeType->StateWrite = eEtape2;
        }
        break;

    case eEtape3:
        if (nNodeType->StateCAN.SDORx == eSDORxWriteSegmented0 || nNodeType->StateCAN.SDORx == eSDORxWriteSegmented10)
        {
            nNodeType->ptrIndexDetails7BytesWrite(nNodeType);
            /* Debug File */
            fprintf(CSVD_FILE, "%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
            fprintf(CSVD_FILE, "%s;", nNodeType->cNodeType);
            fprintf(CSVD_FILE, "SDO_RX;");
            fprintf(CSVD_FILE, ";");
            fprintf(CSVD_FILE, "Write;");
            fprintf(CSVD_FILE, "Segmented;");
            if (nNodeType->bSeenSize7Write)
            {
                fprintf(CSVD_FILE, "%d;", nNodeType->iDATA4_Size_Maximum_Write);
            }
            else
            {
                fprintf(CSVD_FILE, "7;");
                nNodeType->iDATA4_Size_Actual_Write = nNodeType->iDATA4_Size_Actual_Write - 7;
                if (nNodeType->iDATA4_Size_Actual_Write <= 7)
                {
                    nNodeType->bSeenFinalSegmentWrite = true;
                    nNodeType->StateWrite = eEtape5;
                }
                else
                {
                    nNodeType->bSeenFinalSegmentWrite = false;
                }
            }

            fprintf(CSVD_FILE, "SegmentedMessageData;");
            fprintf(CSVD_FILE, ";");
            fprintf(CSVD_FILE, "N/A");
            fprintf(CSVD_FILE, ";");
            fprintf(CSVD_FILE, "\r");

            //fprintf(O_FILE_2,"Write, Cas 1, Node : %s Etape : %d Repetitions : %d Ligne : %d\n",nNodeType->cNodeType,nNodeType->StateWrite,nNodeType->NbrReptitionsRead, LINE_NB);
            nNodeType->StateWrite = eEtape4;
        }
        else
        {
            /* Output File */
            fprintf(CSVO_FILE, "%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
            fprintf(CSVO_FILE, "%s;", nNodeType->cNodeType);
            fprintf(CSVO_FILE, "SDO_RX;");
            fprintf(CSVO_FILE, ";");
            fprintf(CSVO_FILE, "Write;");
            fprintf(CSVO_FILE, "Segmented;");
            fprintf(CSVO_FILE, "N/A;");
            fprintf(CSVO_FILE, "ErrorFrameInterrupted;");
            fprintf(CSVO_FILE, ";");
            fprintf(CSVO_FILE, "Transmission SDO NOK;");
            fprintf(CSVO_FILE, "\r");

            /* Debug File */
            fprintf(CSVD_FILE, "%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
            fprintf(CSVD_FILE, "%s;", nNodeType->cNodeType);
            fprintf(CSVD_FILE, "SDO_RX;");
            fprintf(CSVD_FILE, ";");
            fprintf(CSVD_FILE, "Write;");
            fprintf(CSVD_FILE, "Segmented;");
            fprintf(CSVD_FILE, "N/A;");
            fprintf(CSVD_FILE, "ErrorFrameInterrupted;");
            fprintf(CSVD_FILE, ";");
            fprintf(CSVD_FILE, "Transmission SDO NOK;");
            fprintf(CSVD_FILE, "\r");

            // fprintf(O_FILE_2,"Write, Cas 2, Node : %s Etape : %d   Ligne : %d\n",nNodeType->cNodeType,nNodeType->StateWrite, LINE_NB);
            nNodeType->StateWrite = eEtape1;
        }
        break;

    case eEtape4:
        if (nNodeType->StateCAN.SDORx != eSDORxWriteExpedited23 && nNodeType->StateCAN.SDORx != eSDORxWriteExpedited27 && nNodeType->StateCAN.SDORx != eSDORxWriteExpedited2b && nNodeType->StateCAN.SDORx != eSDORxWriteExpedited2f && nNodeType->StateCAN.SDORx != eSDORxWriteSegmented21)
        {
            if ((nNodeType->StateCAN.SDOTx == eSDOTxWriteSegmented20 || nNodeType->StateCAN.SDOTx == eSDOTxWriteSegmented30) && nNodeType->bSeenFinalSegmentWrite == true)
            {
                /* Debug File */
                fprintf(CSVD_FILE, "%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVD_FILE, "%s;", nNodeType->cNodeType);
                fprintf(CSVD_FILE, "SDO_TX;");
                fprintf(CSVD_FILE, ";");
                fprintf(CSVD_FILE, "Write;");
                fprintf(CSVD_FILE, "Segmented;");
                fprintf(CSVD_FILE, ";");
                fprintf(CSVD_FILE, "SegmentedMessageFinalOk;");
                fprintf(CSVD_FILE, "\r");

                nNodeType->StateWrite = eEtape5;
            }
            if ((nNodeType->StateCAN.SDOTx == eSDOTxWriteSegmented20 || nNodeType->StateCAN.SDOTx == eSDOTxWriteSegmented30) && nNodeType->bSeenFinalSegmentWrite == false)
            {
                /* Debug File */
                fprintf(CSVD_FILE, "%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
                fprintf(CSVD_FILE, "%s;", nNodeType->cNodeType);
                fprintf(CSVD_FILE, "SDO_TX;");
                fprintf(CSVD_FILE, ";");
                fprintf(CSVD_FILE, "Write;");
                fprintf(CSVD_FILE, "Segmented;");
                fprintf(CSVD_FILE, ";");
                fprintf(CSVD_FILE, "SegmentedMessageOkFlipped;");
                fprintf(CSVD_FILE, "\r");

                nNodeType->StateWrite = eEtape3;
            }
        }
        else
        {
            /* Output File */
            fprintf(CSVO_FILE, "%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
            fprintf(CSVO_FILE, "%s;", nNodeType->cNodeType);
            fprintf(CSVO_FILE, "SDO_TX;");
            fprintf(CSVO_FILE, ";");
            fprintf(CSVO_FILE, "Write;");
            fprintf(CSVO_FILE, "Segmented;");
            fprintf(CSVO_FILE, "N/A;");
            fprintf(CSVO_FILE, "ErrorFrameInterrupted;");
            fprintf(CSVO_FILE, ";");
            fprintf(CSVO_FILE, "Transmission SDO NOK;");
            fprintf(CSVO_FILE, "\r");

            /* Debug File */
            fprintf(CSVD_FILE, "%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
            fprintf(CSVD_FILE, "%s;", nNodeType->cNodeType);
            fprintf(CSVD_FILE, "SDO_TX;");
            fprintf(CSVD_FILE, ";");
            fprintf(CSVD_FILE, "Write;");
            fprintf(CSVD_FILE, "Segmented;");
            fprintf(CSVD_FILE, "N/A;");
            fprintf(CSVD_FILE, "ErrorFrameInterrupted;");
            fprintf(CSVD_FILE, ";");
            fprintf(CSVD_FILE, "Transmission SDO NOK;");
            fprintf(CSVD_FILE, "\r");
            nNodeType->StateWrite = eEtape1;
        }
        break;

    case eEtape5:
        nNodeType->bSeenSDOWrite = false;
        if (nNodeType->StateCAN.SDORx != eSDORxReadExpedited40 && nNodeType->StateCAN.SDORx != eSDORxWriteExpedited23 && nNodeType->StateCAN.SDORx != eSDORxWriteExpedited27 && nNodeType->StateCAN.SDORx != eSDORxWriteExpedited2b && nNodeType->StateCAN.SDORx != eSDORxWriteExpedited2f && nNodeType->StateCAN.SDORx != eSDORxWriteSegmented20 && nNodeType->StateCAN.SDORx != eSDORxWriteSegmented21)
        {
            nNodeType->bSeenFinalData7bytesWrite = true;
            nNodeType->ptrIndexDetails7BytesWrite(nNodeType);
            /* Output File */
            fprintf(CSVO_FILE, "%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
            fprintf(CSVO_FILE, "%s;", nNodeType->cNodeType);
            fprintf(CSVO_FILE, "SDO_TX;");
            fprintf(CSVO_FILE, ";");
            fprintf(CSVO_FILE, "Write;");
            fprintf(CSVO_FILE, "Segmented;");
            fprintf(CSVO_FILE, "%d;", nNodeType->iDATA4_Size_Maximum_Write);
            fprintf(CSVO_FILE, "%s;", nNodeType->VALEUR_HEXA_ASCII_Write_INDEX);
            fprintf(CSVO_FILE, "%s;", nNodeType->VALEUR_HEXA_ASCII_Write_SUB_INDEX);
            fprintf(CSVO_FILE, "SegmentedMessageDataEndOfSegment;");
            fprintf(CSVO_FILE, "Transmission SDO OK;");
            nNodeType->ptrCompareDefines(nNodeType, true, WChoice);
            fprintf(CSVO_FILE, ";");
            fprintf(CSVO_FILE, "\r");

            /* Debug File */
            fprintf(CSVD_FILE, "%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
            fprintf(CSVD_FILE, "%s;", nNodeType->cNodeType);
            fprintf(CSVD_FILE, "SDO_TX;");
            fprintf(CSVD_FILE, ";");
            fprintf(CSVD_FILE, "Write;");
            fprintf(CSVD_FILE, "Segmented;");
            nNodeType->iDATA4_Size_Actual_Write = nNodeType->iDATA4_Size_Actual_Write % 7;
            if (nNodeType->iDATA4_Size_Actual_Write == 0)
            {
                fprintf(CSVD_FILE, "7;");
            }
            else
            {
                fprintf(CSVD_FILE, "%d;", nNodeType->iDATA4_Size_Actual_Write);
            }
            fprintf(CSVD_FILE, "SegmentedMessageDataEndOfSegment;");
            fprintf(CSVD_FILE, ";");
            fprintf(CSVD_FILE, "Transmission SDO OK;");
            nNodeType->ptrCompareDefines(nNodeType, false, WChoice);
            fprintf(CSVD_FILE, ";");
            fprintf(CSVD_FILE, "\r");

            nNodeType->StateWrite = eEtape1;
        }
        else
        {
            /* Output File */
            fprintf(CSVO_FILE, "%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
            fprintf(CSVO_FILE, "%s;", nNodeType->cNodeType);
            fprintf(CSVO_FILE, "SDO_TX;");
            fprintf(CSVO_FILE, ";");
            fprintf(CSVO_FILE, "Write;");
            fprintf(CSVO_FILE, "Segmented;");
            fprintf(CSVO_FILE, "N/A;");
            fprintf(CSVO_FILE, "ErrorFrameInterrupted;");
            fprintf(CSVO_FILE, ";");
            fprintf(CSVO_FILE, "Transmission SDO NOK;");
            fprintf(CSVO_FILE, "\r");

            /* Debug File */
            fprintf(CSVD_FILE, "%d ; %f ;", LINE_NB, LigneEnCours.VALEUR_FLOAT);
            fprintf(CSVD_FILE, "%s;", nNodeType->cNodeType);
            fprintf(CSVD_FILE, "SDO_TX;");
            fprintf(CSVD_FILE, ";");
            fprintf(CSVD_FILE, "Write;");
            fprintf(CSVD_FILE, "Segmented;");
            fprintf(CSVD_FILE, "N/A;");
            fprintf(CSVD_FILE, "ErrorFrameInterrupted;");
            fprintf(CSVD_FILE, ";");
            fprintf(CSVD_FILE, "Transmission SDO NOK;");
            fprintf(CSVD_FILE, "\r");
            nNodeType->StateWrite = eEtape1;
        }
        break;
    }
}
