#ifndef SDOINDEXIO_H_INCLUDED
#define SDOINDEXIO_H_INCLUDED

/* ********************* I/O SystemParameters Bytes 0x2000 ********************* */
//14 Bytes
typedef struct{
    unsigned short int IdentityNumber; //Byte 0 et 1
    unsigned char BatteryNominalVoltage; //Byte 2
    unsigned char BatteryType; //Byte 3
    unsigned short int BmsManufacturer; //Byte 4 et 5
    unsigned short int RFiDType; //Byte 6 et 7
    unsigned short int CentralActuatorType; //Byte 8 et 9
    unsigned short int RearActuatorType; //Byte 10 et 11
    unsigned short int ChargingInterface; //Byte 12 et 13
}tIOSystemParametersBytes;

typedef union {
    unsigned char tchar[20];
    tIOSystemParametersBytes IOSystemParametersBytes;
}uIOSystemParameters;
uIOSystemParameters IOSystemParameters;



/* ********************* I/O BMSParameters Bytes 0x2001 ********************* */
//3 Bytes
typedef struct{
    unsigned char Soc; //Byte 0
    unsigned char MaxCurrent; //Byte 1
    unsigned char Temperature; //Byte 2
}tIOBMSParametersBytes;

typedef union {
    unsigned char tchar[3];
    tIOBMSParametersBytes IOBMSParametersBytes;
}uIOBMSParameters;
uIOBMSParameters IOBMSParameters;


/* ********************* I/O RemoteCMD Bytes 0x2010 ********************* */
//2 Bytes
typedef struct{
    unsigned char Object; //Byte 0
    unsigned char Cmd; //Byte 1
}tIORemoteCMDBytes;

typedef union {
    unsigned char tchar[2];
    tIORemoteCMDBytes  IORemoteCMDBytes;
}uIORemoteCMD;
uIORemoteCMD IORemoteCMD;







#endif
