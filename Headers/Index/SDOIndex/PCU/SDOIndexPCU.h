#ifndef SDOINDEXPCU_H_INCLUDED
#define SDOINDEXPCU_H_INCLUDED

//Operating Modes
#define SERVICE_MODE            1
#define MANUAL_MODE             2
#define FAULT_MODE              3
#define JOG_MODE                4
#define AUTOMATIC_MODE          5
#define RUN_MODE                6
#define MANUAL_CHARGE_MODE      7
#define STANDBY_MODE            8
#define HIBERNATION_MODE        9
#define USB_MODE                10
#define FTP_MODE                11

/* *********************PCU Index System_Parameters Bytes 0x2000 SW51 ********************* */
//62 Bytes
typedef struct{
    unsigned short int IdentityNumber;
    unsigned short int Country;
    unsigned short int CircuitNumber;
    unsigned short int Hibernation;
    unsigned short int WiFi_Enable;
    unsigned short int WegaEnable;
    unsigned short int WegaAreaSource;
    unsigned short int WegaAreaValue;
    unsigned short int WegaSlsFaultDelay;
    unsigned short int WegaProtocol;
    unsigned short int Battery;
    unsigned short int OpticalTape;
    unsigned short int BMS;
    unsigned short int RFiD;
    unsigned short int StripLeds;
    unsigned short int StopSensor;
    unsigned short int SenseOfMagneticSensor;
    unsigned short int PID_Deviation_P;
    unsigned short int PID_Deviation_I;
    unsigned short int PID_Deviation_D;
    float              DistanceBetweenWheels;
    float              WheelsDiameter;
    float              DistanceBetweenGuidanceWheels;
    unsigned short int GearRatio;
    unsigned short int DriversVP;
    unsigned short int Alarm1Speed;
    unsigned short int PowerBoard;
    unsigned short int Guidance_Board;
}tPCUSystemParametersSW51Bytes;

typedef union {
    unsigned char tchar[65];
    tPCUSystemParametersSW51Bytes PCUSystemParametersSW51Bytes;
}uPCUSystemParametersSW51;
uPCUSystemParametersSW51 PCUSystemParametersSW51;

/* *********************PCU Index System_Parameters Bytes 0x2000 SW52 ********************* */
//66 Bytes
typedef struct{
    unsigned short int IdentityNumber;
    unsigned short int Country;
    unsigned short int CircuitNumber;
    unsigned short int Hibernation;
    unsigned short int WiFi_Enable;
    unsigned short int WegaEnable;
    unsigned short int WegaAreaSource;
    unsigned short int WegaAreaValue;
    unsigned short int WegaSlsFaultDelay;
    unsigned short int WegaProtocol;
    unsigned short int TypeOfChargingInterface;
    unsigned short int OpticalTape;
    unsigned short int Reserved1;
    unsigned short int RFiD;
    unsigned short int StripLeds;
    unsigned short int StopSensor;
    unsigned short int SenseOfMagneticSensor;
    unsigned short int TypeOfCentralActuator;
    unsigned short int TypeOfRearActuator;
    unsigned short int PID_Deviation_P;
    unsigned short int PID_Deviation_I;
    unsigned short int PID_Deviation_D;
    float              DistanceBetweenWheels;
    float              WheelsDiameter;
    float              DistanceBetweenGuidanceWheels;
    unsigned short int GearRatio;
    unsigned short int DriversVP;
    unsigned short int Alarm1Speed;
    unsigned short int PowerBoard;
    unsigned short int Guidance_Board;
}tPCUSystemParametersSW52Bytes;

typedef union {
    unsigned char tchar[70];
    tPCUSystemParametersSW52Bytes PCUSystemParametersSW52Bytes;
}uPCUSystemParametersSW52;
uPCUSystemParametersSW52 PCUSystemParametersSW52;

/* *********************PCU Index System_Parameters Bytes 0x2000 SW54 ********************* */
//70 Bytes
typedef struct{
    unsigned short int IdentityNumber;
    unsigned short int Country;
    unsigned short int CircuitNumber;
    unsigned short int Hibernation;
    unsigned short int WiFi_Enable;
    unsigned short int WegaEnable;
    unsigned short int WegaAreaSource;
    unsigned short int WegaAreaValue;
    unsigned short int WegaSlsFaultDelay;
    unsigned short int WegaProtocol;
    unsigned short int TypeOfChargingInterface;
    unsigned short int OpticalTape;
    unsigned short int Reserved1;
    unsigned short int RFiD;
    unsigned short int StripLeds;
    unsigned short int StopSensor;
    unsigned short int SenseOfMagneticSensor;
    unsigned short int TypeOfCentralActuator;
    unsigned short int TypeOfRearActuator;
    unsigned short int PID_Deviation_P;
    unsigned short int PID_Deviation_I;
    unsigned short int PID_Deviation_D;
    float              DistanceBetweenWheels;
    float              WheelsDiameter;
    float              DistanceBetweenGuidanceWheels;
    unsigned short int GearRatio;
    unsigned short int DriversVP;
    unsigned short int Alarm1Speed;
    unsigned short int PowerBoard;
    unsigned short int Guidance_Board;
    float              StoppingOffset;
}tPCUSystemParametersSW54Bytes;

typedef union {
    unsigned char tchar[75];
    tPCUSystemParametersSW54Bytes PCUSystemParametersSW54Bytes;
}uPCUSystemParametersSW54;
uPCUSystemParametersSW54 PCUSystemParametersSW54;

/* *********************PCU Index APP_Parameters Bytes 0x2001********************* */
//32 Bytes
typedef struct{
    unsigned short int TagNumber;
    unsigned short int ProgramNumber;
    unsigned short int SequenceNumber;
    unsigned short int OperatingMode;
    unsigned short int BatteryLevel;
    unsigned short int ActualFieldSet;
    unsigned short int FaultNumber;
    unsigned short int FaultCode;
    unsigned short int AlarmNumber;
    unsigned short int UserFunctionType;
    unsigned short int UserFunctionP1;
    unsigned short int UserFunctionP2;
    unsigned short int WegaNumberConnected;
    unsigned short int CrossroadsBlockedBy;
    float EnergyConsumption;
}tPCUAppParametersBytes;

typedef union {
    unsigned char tchar[35];
    tPCUAppParametersBytes PCUAppParametersBytes;
}uPCUAppParameters;
uPCUAppParameters PCUAppParameters;

/* *********************PCU Index Board_Indentity Bytes 0x2001********************* */
#define BOARD_CPU              1
#define BOARD_IO               2
#define BOARD_WIRELESS         3
#define BOARD_L_DRIVER         4
#define BOARD_R_DRIVER         5
#define BOARD_GUIDANCE         6
#define BOARD_EDS              7
#define BOARD_SICK_EXPANDER    8
#define BOARD_RFID             9

//42 Bytes
typedef struct{
    unsigned short int Board_Id;
    unsigned char HardVersion[18];
    unsigned char SoftVersion[18];
    unsigned int SerialNumber;
}tPCUBoardIdentityBytes;

typedef union {
    unsigned char tchar[45];
    tPCUBoardIdentityBytes PCUBoardIdentityBytes;
}uPCUBoardIdentity;
uPCUBoardIdentity PCUBoardIdentity;


#endif
