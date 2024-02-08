#ifndef COMMON_H
#define COMMON_H
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#define PI_CST 3.14159265358979323846

extern char *yyget_text(void);
extern int yylex(void);
extern void yyerror(const char *errormsg);
extern long LINE_NB;
extern long COLUMN;
extern FILE *O_FILE;
extern FILE *O_FILE_2;
extern FILE *CSVO_FILE;
extern FILE *CSVD_FILE;
extern bool bSeenEOF;
extern bool RChoice;
extern bool WChoice;
typedef struct tNode tNode;

typedef void (*PtrCompareDefines)(tNode *nNodeType, bool, bool);
typedef void (*PtrCompareErrorCodes)(bool);
typedef void (*PtrIndexDetails7BytesRead)(tNode *nNodeType);
typedef void (*PtrIndexDetails4BytesRead)(tNode *nNodeType);
typedef void (*PtrIndexDetails7BytesWrite)(tNode *nNodeType);
typedef void (*PtrIndexDetails4BytesWrite)(tNode *nNodeType);

typedef union
{
    uint8_t bytes[4]; // Tableau de 4 octets
    int32_t intValue; // Entier signé de 32 bits
} uOctetToInt;

#define MaxNbChar 128
#define MaxNbLigne 100
typedef struct
{
    char VALEUR_HEXA_ASCII[MaxNbChar];
    char VALEUR_HEXA_ASCII_CHANNEL[MaxNbChar];
    char VALEUR_HEXA_ASCII_FCTN[MaxNbChar];
    char VALEUR_HEXA_ASCII_COB_ID[MaxNbChar];
    char VALEUR_HEXA_ASCII_LENGTH[MaxNbChar];
    char VALEUR_HEXA_ASCII_DATA0[MaxNbChar];
    char VALEUR_HEXA_ASCII_DATA1[MaxNbChar];
    char VALEUR_HEXA_ASCII_DATA2[MaxNbChar];
    char VALEUR_HEXA_ASCII_DATA3[MaxNbChar];
    char VALEUR_HEXA_ASCII_DATA4[MaxNbChar];
    char VALEUR_HEXA_ASCII_DATA5[MaxNbChar];
    char VALEUR_HEXA_ASCII_DATA6[MaxNbChar];
    char VALEUR_HEXA_ASCII_DATA7[MaxNbChar];

    char VALEUR_HEXA_ASCII_Error_Code[MaxNbChar];

    int iCHANNEL;
    int iFCTN;
    int iCOB_ID;
    int iLENGTH;
    int iDATA0;
    int iDATA1;
    int iDATA2;
    int iDATA3;
    int iDATA4;
    int iDATA5;
    int iDATA6;
    int iDATA7;
    int iErrorCodes;
    int iErrorRegister;

    double VALEUR_FLOAT;
    int VALEUR_INT;
} tLigne;

extern tLigne LigneEnCours;
extern tLigne Ligne[MaxNbLigne];

/* *********ENUM STATE MACHINE**********/
enum eEtapes
{
    eEtape1 = 1,
    eEtape2 = 2,
    eEtape3 = 3,
    eEtape4 = 4,
    eEtape5 = 5,
    eEtape6 = 6
};

/* *********ENUM STATE CANOPEN**********/
enum eGuardState
{
    eGUARDStateBooting = 0,
    eGUARDStateStopped = 4,
    eGUARDStateOperationnal = 5,
    eGUARDStatePreOperationnal = 127
};
enum eSDORx
{
    eSDORxReadExpedited40 = 0x40,
    eSDORxReadSegmented60 = 0x60,
    eSDORxReadSegmented70 = 0x70,

    eSDORxWriteSegmented0 = 0x00,
    eSDORxWriteSegmented10 = 0x10,
    eSDORxWriteSegmented11 = 0x11,
    eSDORxWriteSegmented1d = 0x1d,
    eSDORxWriteSegmented20 = 0x20,
    eSDORxWriteSegmented21 = 0x21,
    eSDORxWriteExpedited23 = 0x23,
    eSDORxWriteExpedited27 = 0x27,
    eSDORxWriteExpedited2b = 0x2b,
    eSDORxWriteExpedited2f = 0x2f
};
enum eSDOTx
{
    eSDOTxReadSegmented0 = 0x00,
    eSDOTxReadSegmented1 = 0x01,
    eSDOTxReadSegmented3 = 0x03,
    eSDOTxReadSegmented5 = 0x05,
    eSDOTxReadSegmented0b = 0x0b,
    eSDOTxReadSegmented11 = 0x11,
    eSDOTxReadSegmented15 = 0x15,
    eSDOTxReadSegmented19 = 0x19,
    eSDOTxReadSegmented1d = 0x1d,
    eSDOTxReadSegmented40 = 0x40,
    eSDOTxReadSegmented41 = 0x41,
    eSDOTxReadExpedited42 = 0x42,
    eSDOTxReadExpedited43 = 0x43,
    eSDOTxReadExpedited47 = 0x47,
    eSDOTxReadExpedited4b = 0x4b,
    eSDOTxReadExpedited4f = 0x4f,

    eSDOTxWriteSegmented20 = 0x20,
    eSDOTxWriteSegmented30 = 0x30,
    eSDOTxWriteSegmented60 = 0x60
};
union uStateCAN
{
    enum eGuardState GuardState;
    enum eSDORx SDORx;
    enum eSDOTx SDOTx;
};

enum eNMTState
{
    eNMTStateENTOperationnal = 1,
    eNMTStateENTStop = 2,
    eNMTStateENTPreOperationnal = 128,
    eNMTStateRSTNode = 129,
    eNMTStateRSTCommunication = 130
};
enum eNMTNodeNBR
{
    eNMTLDriver = 2,
    eNMTRDriver = 3,
    eNMTGuidance = 4,
    eNMTRFH6x0_Id = 6,
    eNMTDTM425_Id = 32,
    eNMTCPU_Id = 67,
    eNMTPCU_Id = 80,
    eNMTIO_Id = 73,
    eNMTEDS_Id = 69,
    eNMTSICK_EXPANDER_Id = 83,
    eNMTRADIO_Id = 82
};
union uNMTProtocol
{
    enum eNMTState NMTState;
    enum eNMTNodeNBR NMTNodeNBR;
};
union uNMTProtocol NMTProtocol;

/* *********ENUM NODES CANOPEN**********/
typedef enum
{
    ePDO1_Radio = 0x1d2,
    eSDO_Rx_Radio = 0x652,
    eSDO_Tx_Radio = 0x5d2,
    eGuard_Radio = 0x752,
    eEMCY_Radio = 0xd2,

    ePDO1_IO = 0x1c9,
    eSDO_Rx_IO = 0x649,
    eSDO_Tx_IO = 0x5c9,
    eGuard_IO = 0x749,
    eEMCY_IO = 0xc9,

    ePDO1_EDS = 0x1c5,
    eSDO_Rx_EDS = 0x645,
    eSDO_Tx_EDS = 0x5c5,
    eGuard_EDS = 0x745,
    eEMCY_EDS = 0xc5,

    ePDO1_Guidance = 0x184,
    eSDO_Rx_Guidance = 0x604,
    eSDO_Tx_Guidance = 0x584,
    eGuard_Guidance = 0x704,
    eEMCY_Guidance = 0x84,

    ePDO1_LDriver = 0x182,
    ePDO2_LDriver = 0x282,
    ePDO3_LDriver = 0x382,
    eSDO_Rx_LDriver = 0x602,
    eSDO_Tx_LDriver = 0x582,
    eGuard_LDriver = 0x702,
    eEMCY_LDriver = 0x82,

    ePDO1_RDriver = 0x183,
    ePDO2_RDriver = 0x283,
    ePDO3_RDriver = 0x383,
    eSDO_Rx_RDriver = 0x603,
    eSDO_Tx_RDriver = 0x583,
    eGuard_RDriver = 0x703,
    eEMCY_RDriver = 0x83,

    ePDO1_RFH6x0 = 0x186,
    ePDO4_RFH6x0 = 0x486,
    eSDO_Rx_RFH6x0 = 0x606,
    eSDO_Tx_RFH6x0 = 0x586,
    eGuard_RFH6x0 = 0x706,

    ePDO1_DTM425 = 0x1A0,
    ePDO2_DTM425 = 0x2A0,
    eSDO_Rx_DTM425 = 0x620,
    eSDO_Tx_DTM425 = 0x5A0,
    eGuard_DTM425 = 0x720,

    eSDO_Rx_PCU = 0x650,
    eSDO_Tx_PCU = 0x5D0,
    eGuard_PCU = 0x750,
    eEMCY_PCU = 0xD0, 

    eBMS = 0x999,

    eSync = 0x80,
    eNMT = 0x00
} eNode;
eNode Node;

/* *********ENUM NODES CAN CH2 BMS**********/
typedef enum
{    
    e0x351 = 0x351,
    e0x352 = 0x352,
    e0x353 = 0x353,
    e0x354 = 0x354,
    e0x355 = 0x355,
    e0x356 = 0x356,
    e0x357 = 0x357,
    e0x358 = 0x358,
    e0x359 = 0x359,
    e0x35B = 0x35b,
    e0x35C = 0x35c,
    e0x35D = 0x35d,

    e0x380 = 0x380,
    e0x381 = 0x381,
    e0x382 = 0x382,
    e0x383 = 0x383,
    e0x384 = 0x384,
    e0x385 = 0x385,
    e0x386 = 0x386

} eNodeBMS;
eNodeBMS NodeBMS;

/* *********STRUCTURES FOR NODES**********/
struct tNode
{
    /* Nom De la carte */
    char cNodeType[MaxNbChar];

    /* Chaines de caractères de segments lecture SDO */
    char VALEUR_HEXA_ASCII_Read_ExpeditedSegment[1024];
    char VALEUR_HEXA_ASCII_Read_FinalSegment[1024];
    char VALEUR_HEXA_ASCII_Read_FullSegment[1024];
    char VALEUR_HEXA_ASCII_Read_IntermidiarySegment[1024];
    /* Chaines de caractères de segments ecriture SDO */
    char VALEUR_HEXA_ASCII_Write_ExpeditedSegment[1024];
    char VALEUR_HEXA_ASCII_Write_FinalSegment[1024];
    char VALEUR_HEXA_ASCII_Write_FullSegment[1024];
    char VALEUR_HEXA_ASCII_Write_IntermidiarySegment[1024];
    /* Chaines de caractères d'index SDO */
    char VALEUR_HEXA_ASCII_Read_INDEX[MaxNbChar];
    char VALEUR_HEXA_ASCII_Read_SUB_INDEX[MaxNbChar];
    char VALEUR_HEXA_ASCII_Write_INDEX[MaxNbChar];
    char VALEUR_HEXA_ASCII_Write_SUB_INDEX[MaxNbChar];
    /* SDO State Machines */
    union uStateCAN StateCAN;
    enum eEtapes StateWrite;
    enum eEtapes StateRead;
    /* Variables automate SDO Read */
    int iNodeIndexRead;
    int iNodeSubIndexRead;
    int iFinalSegmentRead;
    int iExpeditedSegmentRead;
    int iDATA4_Size_Actual_Read;
    int iDATA4_Size_Maximum_Read;
    int NbrReptitionsRead;
    bool bSeenSize7Read;
    bool bSeenFinalSegmentRead;
    bool bSeenFinalData7bytesRead;
    bool bSeenFinalData4bytesRead;
    bool bSeenSDORead;
    int nbrOfBytesRead;
    /* Variables automate SDO Write */
    int iNodeIndexWrite;
    int iNodeSubIndexWrite;
    int iFinalSegmentWrite;
    int iExpeditedSegmentWrite;
    int iDATA4_Size_Actual_Write;
    int iDATA4_Size_Maximum_Write;
    int NbrReptitionsWrite;
    bool bSeenSize7Write;
    bool bSeenFinalSegmentWrite;
    bool bSeenFinalData7bytesWrite;
    bool bSeenFinalData4bytesWrite;
    bool bSeenSDOWrite;
    int nbrOfBytesWrite;
    /* Integer of SDO Data */
    unsigned int uiDATA0;
    unsigned int uiDATA1;
    unsigned int uiDATA2;
    unsigned int uiDATA3;
    unsigned int uiDATA4;
    unsigned int uiDATA5;
    unsigned int uiDATA6;
    unsigned int uiDATA7;

    /* Chaines de caractères de data PDO */
    char VALEUR_HEXA_ASCII_DATA0_PDO[MaxNbChar];
    char VALEUR_HEXA_ASCII_DATA1_PDO[MaxNbChar];
    char VALEUR_HEXA_ASCII_DATA0_1_PDO[MaxNbChar];
    char VALEUR_HEXA_ASCII_DATA2_PDO[MaxNbChar];
    char VALEUR_HEXA_ASCII_DATA3_PDO[MaxNbChar];
    char VALEUR_HEXA_ASCII_DATA2_3_PDO[MaxNbChar];
    char VALEUR_HEXA_ASCII_DATA4_PDO[MaxNbChar];
    char VALEUR_HEXA_ASCII_DATA5_PDO[MaxNbChar];
    char VALEUR_HEXA_ASCII_DATA4_5_PDO[MaxNbChar];
    char VALEUR_HEXA_ASCII_DATA2_3_4_5_PDO[MaxNbChar];
    char VALEUR_HEXA_ASCII_DATA6_PDO[MaxNbChar];
    char VALEUR_HEXA_ASCII_DATA7_PDO[MaxNbChar];
    /* Integer of PDO Data */
    int iDATA0_PDO1;
    int iDATA1_PDO1;
    int iDATA2_PDO1;
    int iDATA3_PDO1;
    int iDATA4_PDO1;
    int iDATA5_PDO1;
    int iDATA6_PDO1;
    int iDATA7_PDO1;
    /* Signed Integer of concatenated PDO Data */
    int32_t iConcatenated_PDO1;

    /* Drivers */
    int iTargetVelocity;
    float fComputedVelocity;
    int DriversMotorRatedCurrent;
    int iProfilAcceleration;
    int iProfilDeceleration;
    int iQuickStopDeceleration;
    // Byte 0 + 1
    short int DriversActualCurrent;
    short int DriversActualCurrentComputed;
    // Byte 2 + 3 + 4 + 5
    long DriversPositionCount;

    /* IO */
    unsigned char Temperature;

    /* Guidance */
    float fComputedDeviation;
    unsigned int iGuidancePeak;

    bool bSeenHibernOn;
    bool bSeenHibernOff;

    unsigned char tchar[1024];

    /* Union structure to convert Hex Strings to Integers */
    uOctetToInt OctetToInt;

    /* Functions Pointers */
    PtrCompareDefines ptrCompareDefines;
    PtrCompareErrorCodes ptrCompareErrorCodes;

    PtrIndexDetails7BytesRead ptrIndexDetails7BytesRead;
    PtrIndexDetails4BytesRead ptrIndexDetails4BytesRead;
    PtrIndexDetails7BytesWrite ptrIndexDetails7BytesWrite;
    PtrIndexDetails4BytesWrite ptrIndexDetails4BytesWrite;
};

void concatener8BytesData(char *Data0, char *Data1, char *Data2, char *Data3, char *Data4, char *Data5, char *Data6, char *Data7, char *FullString);
void concatener7BytesData(char *Data1, char *Data2, char *Data3, char *Data4, char *Data5, char *Data6, char *Data7, char *FullString);
void concatener4BytesData(char *Data0, char *Data1, char *Data2, char *Data3, char *FullString);
void concatener2BytesData(char *Data1, char *Data2, char *FullString);
void concatener2Segments(char *SegmentSource, char *SegmentDestination);
void concatenerNombresHexIndexRead(tNode *nNodeType, char *MSB, char *LSB);
void concatenerNombresHexIndexWrite(tNode *nNodeType, char *MSB, char *LSB);
void concatenerNombresHexErrorCode(char *MSB, char *LSB, char *ErrorCode);
void hexStringToAscii(char *hexStr, bool *fChoice);
void hexStringToBinString(char *hexStr);



#endif // COMMON_H
