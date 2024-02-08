#ifndef BMSINDEX_H_INCLUDED
#define BMSINDEX_H_INCLUDED

/* ********************* 0x351 Bytes ********************* */
typedef struct{
    unsigned short int ChargeVLimit;
    unsigned short int ChargeILimit;
    unsigned short int DischargeVLimit;
    unsigned short int DischargeILimit;
}tBMS351Bytes;

typedef union {
    unsigned char tchar[8];
    tBMS351Bytes BMS351Bytes;
}uBMS351;
uBMS351 BMS351;

/* ********************* 0x352 Bytes ********************* */
typedef struct{
    signed short int MinTempCh;
    signed short int MaxTempCh;
    signed short int MinTempDisch;
    signed short int MaxTempDisch;
}tBMS352Bytes;

typedef union {
    unsigned char tchar[8];
    tBMS352Bytes BMS352Bytes;
}uBMS352;
uBMS352 BMS352;

/* ********************* 0x353 Bytes (Pilot 8-bit field) ********************* */
typedef struct{
    unsigned char Unused1:1;
    unsigned char Unused2:1;
    unsigned char Unused3:1;
    unsigned char Unused4:1;
    unsigned char Unused5:1;
    unsigned char Unused6:1;
    unsigned char ChargeEnable:1;
    unsigned char DischargeEnable:1;
}tBMS353Bytes;

typedef union {
    unsigned char tchar[1];
    tBMS353Bytes BMS353Bytes;
}uBMS353;
uBMS353 BMS353;

/* ********************* 0x354 Bytes ********************* */
typedef struct{
    unsigned int Alarms:24;
    unsigned int Warnings:24;
}tBMS354Bytes;

typedef union {
    unsigned char tchar[8];
    tBMS354Bytes BMS354Bytes;
}uBMS354;
uBMS354 BMS354;

/* ********************* 0x355 Bytes ********************* */
typedef struct{
    unsigned char SOC; //BatteryLevel
    unsigned char SOH; //StateOfHealth
}tBMS355Bytes;

typedef union {
    unsigned char tchar[8];
    tBMS355Bytes BMS355Bytes;
}uBMS355;
uBMS355 BMS355;

/* ********************* 0x356 Bytes ********************* */
typedef struct{
    unsigned short int BatteryVoltage;
    signed short int BatteryCurrent;
}tBMS356Bytes;

typedef union {
    unsigned char tchar[8];
    tBMS356Bytes BMS356Bytes;
}uBMS356;
uBMS356 BMS356;

/* ********************* 0x357 Bytes ********************* */
typedef struct{
    unsigned short int MinVCell;
    unsigned short int MaxVCell;
    signed short int MinTemp;
    signed short int MaxTemp;
}tBMS357Bytes;

typedef union {
    unsigned char tchar[8];
    tBMS357Bytes BMS357Bytes;
}uBMS357;
uBMS357 BMS357;

/* ********************* 0x358 Bytes ********************* */
typedef struct{
    unsigned short int CycleCount;
    unsigned short int NominalCapacity;
    unsigned short int UsableCapacity;
    unsigned short int CellNumber;
}tBMS358Bytes;

typedef union {
    unsigned char tchar[8];
    tBMS358Bytes BMS358Bytes;
}uBMS358;
uBMS358 BMS358;

/* ********************* 0x359 Bytes ********************* */
typedef struct{
    unsigned short int BMSPosition;
}tBMS359Bytes;

typedef union {
    unsigned char tchar[8];
    tBMS359Bytes BMS359Bytes;
}uBMS359;
uBMS359 BMS359;

/* ********************* 0x35B Bytes ********************* */
typedef struct{
    unsigned char BMSSerial[4];
}tBMS35BBytes;

typedef union {
    unsigned char tchar[4];
    tBMS35BBytes BMS35BBytes;
}uBMS35B;
uBMS35B BMS35B;

/* ********************* 0x35C Bytes ********************* */
typedef struct{
    unsigned char BMSManufacturer[8]
}tBMS35CBytes;

typedef union {
    unsigned char tchar[8];
    tBMS35CBytes BMS35CBytes;
}uBMS35C;
uBMS35C BMS35C;

/* ********************* 0x35D Bytes ********************* */
typedef struct{
    unsigned char ProtocolVersion;
    unsigned char Padding;
}tBMS35DBytes;

typedef union {
    unsigned char tchar[8];
    tBMS35DBytes BMS35DBytes;
}uBMS35D;
uBMS35D BMS35D;

/* ********************* 0x380-3FF Bytes ********************* */
typedef struct{
    unsigned short int VCell1;
    unsigned short int VCell2;
    unsigned short int VCell3;
    unsigned short int VCell4;
}tBMS380Bytes;

typedef union {
    unsigned char tchar[8];
    tBMS380Bytes BMS380Bytes;
}uBMS380;
uBMS380 BMS380;



#endif // INDEX_H_INCLUDED
