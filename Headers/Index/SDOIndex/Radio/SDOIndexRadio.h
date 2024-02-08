#ifndef SDOINDEXRADIO_H_INCLUDED
#define SDOINDEXRADIO_H_INCLUDED


/* *********************Radio Index Manufacturer_Status_Register Bytes 0x1002 ********************* */
//Appears during Pre-op initialisation because you can't have PDO status in Pre-op mode
//Collects only the firsy byte of the PDO status which is the Wega Nbr
//Waits for the Modem to start and checks every 200 uS the Wega Nbr

//1 Bytes
typedef union {
    unsigned char tchar[1];
    unsigned char WegaNbr;
}uRadioManufacturerStatusRegister;
uRadioManufacturerStatusRegister RadioManufacturerStatusRegister;


/* *********************Radio Index System_Parameters Bytes 0x2000 SW52 ********************* */
//3 Bytes
typedef struct{
    unsigned short int IdentityNumber;
    unsigned char CircuitNumber;
}tRadioSystemParametersSW52Bytes;

typedef union {
    unsigned char tchar[5];
    tRadioSystemParametersSW52Bytes RadioSystemParametersSW52Bytes;
}uRadioSystemParametersSW52;
uRadioSystemParametersSW52 RadioSystemParametersSW52;


/* *********************Radio Index System_Parameters Bytes 0x2000 SW53 ********************* */
#define Europe 1
#define Japan  2
//44 Bytes
typedef struct{
    unsigned short int SerialNumber;
    unsigned char CountrySpec;
    unsigned char CircuitNumber;
    unsigned char Hibernation;
    unsigned char WiFi_Enable;
    unsigned char WegaEnable;
    unsigned char WegaAreaSource;
    unsigned char WegaAreaValue;
    unsigned char WegaSlsFault;
    unsigned char WegaProtocol;
    unsigned char WegaConnectionMode;
    unsigned char WegaFavoriteNumber;
    unsigned char Reserved;
    unsigned short int P_DeviationController;
    unsigned short int I_DeviationController;
    unsigned short int D_DeviationController;
    float DistanceBetweenWheels;
    float WheelsDiameter;
    float DistanceBetweenGuidanceWheels;
    unsigned char GearRatio;
    unsigned char AreDriversVoltageGreaterThan24V;
    unsigned short int SlsAlarm1Speed;
    unsigned char TypeOfChargingInterface;
    unsigned char OpticalTape;
    unsigned char Rfid;
    unsigned char StripLeds;
    unsigned char StopSensor;
    unsigned char SenseMagneticSensor;
    unsigned char TypeOfCentralActuator;
    unsigned char TypeOfRearActuator;
}tRadioSystemParametersSW53Bytes;

typedef union {
    unsigned char tchar[50];
    tRadioSystemParametersSW53Bytes RadioSystemParametersSW53Bytes;
}uRadioSystemParametersSW53;
uRadioSystemParametersSW53 RadioSystemParametersSW53;

/* *********************Radio Index Wega_Parameters Bytes 0x2001 SW52 ********************* */
//6 Bytes
typedef struct{
    unsigned char Enable;
    unsigned char ProtocolType;
    unsigned char AreaNumber;
    unsigned char FavoriteNumber;
    unsigned char SLSFaultDelay;
    unsigned char ConnectionMode;
}tRadioWegaParametersSW52Bytes;

typedef union {
    unsigned char tchar[10];
    tRadioWegaParametersSW52Bytes RadioWegaParametersSW52Bytes;
}uRadioWegaParametersSW52;
uRadioWegaParametersSW52 RadioWegaParametersSW52;

//ProtocolType
#define WEGA_V2                             6
#define WEGA_V4                             7
#define WEGA_V5                             8
//Charging Interface
#define CONNECTOR_CHARGING_INTERFACE        13
#define FRICTION_CHARGING_INTERFACE         14

/* *********************Radio Index APP_Parameters Bytes 0x2002 SW52 ********************* */
//30 Bytes

typedef struct{
    struct{
        unsigned short int Fault:1;
        unsigned short int Alarm:1;
        unsigned short int IsSwitchingOff:1;
        unsigned short int ManualMode:1;

        unsigned short int AutoMode:1;
        unsigned short int RunMode:1;
        unsigned short int ChargingMode:1;
        unsigned short int AckCmdStart:1;

        unsigned short int WaitingRadioStart:1;
        unsigned short int Obstacle:1;
        unsigned short int TagPass:1;
        unsigned short int WaitingIrStart:1;

        unsigned short int StandbyMode:1;
        unsigned short int BusyMode:1;
        unsigned short int SequenceChg:1;
        unsigned short int Res15:1;
    }RadioAPPStatus1Bits;
    struct{
        unsigned short int AckCmdStop:1;
        unsigned short int AckCmdPowerOff:1;
        unsigned short int AckCmdHibernationOn:1;
        unsigned short int AckCmdTimeSync:1;

        unsigned short int AckCmdSpeed:1;
        unsigned short int HibernationMode:1;
        unsigned short int CenterActuatorUpPosition:1;
        unsigned short int CenterActuatorDownPosition:1;

        unsigned short int RearActuatorUpPosition:1;
        unsigned short int RearActuatorDownPosition:1;
        unsigned short int TagIn:1;
        unsigned short int TagOut:1;

        unsigned short int AckCmdSequence:1;
        unsigned short int Res12_15:3;
    }RadioAPPStatus2Bits;
    unsigned short int ProgramNumber;
    unsigned short int SequenceNumber;
    unsigned short int FaultNumber;
    unsigned short int BatteryLevel;
    unsigned short int TagNumber;
    unsigned char LocalisationData[4];
    unsigned short int RefSpeed;
    unsigned short int ActualSpeed;
    unsigned short int DistWithLastTag;
    unsigned short int ActualFieldSet;
    unsigned short int UserInputs;
    unsigned short int UserOutputs;
}tRadioAPPStatusParametersSW52Bytes;

typedef union {
    unsigned char tchar[35];
    tRadioAPPStatusParametersSW52Bytes RadioAPPStatusParametersSW52Bytes;
}uRadioAPPStatusParametersSW52;
uRadioAPPStatusParametersSW52 RadioAPPStatusParametersSW52;

/* *********************Radio Index APP_Parameters Bytes 0x2002 SW53 ********************* */
//36 Bytes
typedef struct{
    struct{
        unsigned short int Service:1;
        unsigned short int Manual:1;
        unsigned short int Fault:1;
        unsigned short int Jog:1;
        unsigned short int Automatic:1;
        unsigned short int Run:1;
        unsigned short int ManualCharge:1;
        unsigned short int AutomaticCharge:1;
        unsigned short int Standby:1;
        unsigned short int Hibernation:1;
        unsigned short int Usb:1;
        unsigned short int Ftp:1;
        unsigned short int Bit12:1;
        unsigned short int Bit13:1;
        unsigned short int Bit14:1;
        unsigned short int Bit15:1;
    }OperatingModeBit;
    struct{
        unsigned short int Alarm:1;
        unsigned short int Obstacle:1;
        unsigned short int Busy:1;
        unsigned short int CenterActuatorUpPosition:1;
        unsigned short int CenterActuatorDownPosition:1;
        unsigned short int RearActuatorUpPosition:1;
        unsigned short int RearActuatorDownPosition:1;
        unsigned short int Bit7:1;
        unsigned short int Bit8:1;
        unsigned short int Bit9:1;
        unsigned short int Bit10:1;
        unsigned short int Bit11:1;
        unsigned short int Bit12:1;
        unsigned short int Bit13:1;
        unsigned short int Bit14:1;
        unsigned short int IsSwitchingOff:1;
    }SystemStatusBit;
    struct{
        unsigned short int TagIn:1;
        unsigned short int TagOut:1;
        unsigned short int WaitingRadioStart:1;
        unsigned short int WaitingIrStart:1;
        unsigned short int SequenceChg:1;
        unsigned short int SensitiveArea:1;
        unsigned short int Bit6:1;
        unsigned short int Bit7:1;
        unsigned short int Bit8:1;
        unsigned short int Bit9:1;
        unsigned short int Bit10:1;
        unsigned short int Bit11:1;
        unsigned short int Bit12:1;
        unsigned short int Bit13:1;
        unsigned short int Bit14:1;
        unsigned short int IsSwitchingOff:1;
    }AppStatusBit;
    struct{
        unsigned short int Start:1;
        unsigned short int Stop:1;
        unsigned short int Program:1;
        unsigned short int Sequence:1;
        unsigned short int Speed:1;
        unsigned short int TimeSync:1;
        unsigned short int PowerOff:1;
        unsigned short int HibernationOn:1;
        unsigned short int HibernationOff:1;
        unsigned short int Bit9:1;
        unsigned short int Bit10:1;
        unsigned short int Bit11:1;
        unsigned short int Bit12:1;
        unsigned short int Bit13:1;
        unsigned short int Bit14:1;
        unsigned short int Bit15:1;
    }AppAckCmdBit;

    unsigned short int FaultNumber;
    unsigned short int AlarmNumber;
    unsigned short int ProgramNumber;
    unsigned short int SequenceNumber;
    unsigned short int ActualSpeed;
    unsigned short int RefSpeed;
    unsigned short int DistWithLastTag;
    unsigned short int TagNumber;
    unsigned char LocalisationData[4];
    unsigned short int ActualFieldSet;
    unsigned short int BatteryLevel;
    unsigned short int UserInputs;
    unsigned short int UserOutputs;
}tRadioAPPStatusParametersSW53Bytes;

typedef union {
    unsigned char tchar[40];
    tRadioAPPStatusParametersSW53Bytes RadioAPPStatusParametersSW53Bytes;
}uRadioAPPStatusParametersSW53;
uRadioAPPStatusParametersSW53 RadioAPPStatusParametersSW53;

/* *********************Radio Index CrossRoad CMD Bytes 0x2010 ********************* */
//CrossRoad Type
#define PRIORITY              0
#define NO_PRIORITY           1
#define AUTO                  2
#define EXIT                  6
#define NO_STOP               7
#define WEGA_NO_STOP          8

//CrossRoadStatus
#define CROSSROADS_NO_CMD     0
#define CROSSROADS_START      14  

//8 Bytes
typedef struct{
    unsigned short int Type;
    unsigned short int Id;
    unsigned short int Status;
    unsigned short int BlockerNumber;
}tRadioCrossRoadCmdBytes;

typedef union {
    unsigned char tchar[10];
    tRadioCrossRoadCmdBytes RadioCrossRoadCmdBytes;
}uRadioCrossRoadCmd;
uRadioCrossRoadCmd RadioCrossRoadCmd;

/* *********************Radio Index Wega Process CMD Bytes 0x2011 ********************* */
//16 Bytes
#pragma pack(1)
typedef struct{
    struct{
        unsigned short int START          :1;
        unsigned short int POWEROFF       :1;
        unsigned short int STOP           :1;
        unsigned short int SEQ_CHG        :1;
        unsigned short int PRG_CHG        :1;
        unsigned short int SPEED_CHANGE   :1;
        unsigned short int HIBERN_ON      :1;
        unsigned short int HIBERN_OFF     :1;
        
        unsigned short int TIME_SYNC      :1;
        unsigned short int RES_07_15      :7;
    }CommandBits;
    unsigned short int ProgramNumber;
    unsigned short int RefSpeed;
    unsigned short int TagNumber;
    unsigned short int SequenceNumber;
    unsigned char Year;
    unsigned char Month;
    unsigned char Day;
    unsigned char Hours;
    unsigned char Minutes;
    unsigned char Seconds;
}tRadioWegaProcessCmdBytes;
#pragma pack()

typedef union {
    unsigned char tchar[18];
    tRadioWegaProcessCmdBytes RadioWegaProcessCmdBytes;
}uRadioWegaProcessCmd;
uRadioWegaProcessCmd RadioWegaProcessCmd;

/* *********************Radio Index Wega Remote CMD Bytes 0x2012 ********************* */
//10 Bytes
typedef struct{
    unsigned char Object;
    unsigned char Cmd;
    unsigned char Data[8];
}tRadioWegaRemoteCmdBytes;

typedef union {
    unsigned char tchar[12];
    tRadioWegaRemoteCmdBytes RadioWegaRemoteCmdBytes;
}uRadioWegaRemoteCmd;
uRadioWegaRemoteCmd RadioWegaRemoteCmd;

/* *********************Radio Index Remote Controller CMD Bytes 0x2013 ********************* */
//10 Bytes
#pragma pack(1)
typedef struct{
    struct {
        unsigned RemoteIsConnected:1;
        unsigned C_FORWARD:1;
        unsigned C_BACKWARD:1;
        unsigned C_RIGHT:1;
        unsigned C_LEFT:1;
        unsigned C_FAULTRESET:1;
        unsigned C_TRACKING_TAPE:1;
        unsigned RESERVED:1;
    }RemoteControllerBits;
    unsigned short int Order;
    unsigned char Data[6];
}tRadioRemoteControllerCmdBytes;
#pragma pack()

typedef union {
    unsigned char tchar[12];
    tRadioRemoteControllerCmdBytes RadioRemoteControllerCmdBytes;
}uRadioRemoteControllerCmd;
uRadioRemoteControllerCmd RadioRemoteControllerCmd;


/* *********************Radio Fault/Alarm Codes ********************* */

#define FrontEmcyButton         98
#define SafetyLaserEmcy         99
#define BackEmcyButton          100
#define TrackLost               101
#define RFID                    102
#define DischargedBattery       104
#define LeftDriverTimeout       107
#define RightDriverTimeout      108
#define RightWheelBlocked       109
#define LeftWheelBlocked        110
#define LeftDriverError         111
#define RightDriverError        112
#define TagProgramming          117
#define AcuracyStop             118
#define RadioBoard              121
#define ProtectedSystem         122
#define GuidanceBoard           123
#define CentralActuatorTimeout  124
#define RearActuatorTimeout     125
#define CentralActuatorOverLoad 126
#define RearActuatorOverload    127
#define Rotation                128
#define SdCardAccessError       130
#define SdCardUnfoundError      131
#define UnknownTag              132
#define System_Parameters       133
#define InternalClockTimeout    135
#define IOBoard                136
#define CrossRoadError          137
#define EmcyChainReset          138
#define TagOrder                139
#define ChargerCommunication    140
#define IHM                     141
#define EDSBoard                142
#define ApiCmdNotAuthorized     143
#define UsbAccessError          147
#define WatchDogError           148
#define SickExpanderBoard       149
#define FlexiSoftError          150
#define BMSError                151

#define ObstacleFound           200
#define SafetyLaserAreaError    201
#define LowBattery              202
#define RightDriverCurrent      209
#define LeftDriverCurrent       210


#endif
