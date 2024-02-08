#ifndef PDOINDEX_H_INCLUDED
#define PDOINDEX_H_INCLUDED

/* ********************* EDS Board Status Bytes ********************* */
typedef struct {
    // Byte 0 + 1
    struct{
        unsigned short int SLS            :1;
        unsigned short int SafetyRelay    :1;
        unsigned short int IO_VL          :1;
        unsigned short int IO_VP          :1;
        unsigned short int Guidance       :1;
        unsigned short int Wireless       :1;
        unsigned short int HMI            :1;
        unsigned short int LDriverVP      :1;
        unsigned short int RDriverVP      :1;
        unsigned short int LDriverVL      :1;
        unsigned short int RDriverVL      :1;
        unsigned short int Brakes         :1;
        unsigned short int External       :1;
        unsigned short int RFid           :1;
        unsigned short int Auxiliary      :1;
        unsigned short int reserved       :1;
    }PowerDevice;
    // Byte 2 + 3
    struct{
        unsigned short int LDriverVP_Ok       :1;
        unsigned short int RDriverVP_Ok       :1;
        unsigned short int IO_VP_Ok           :1;
        unsigned short int LeftBrakeOk        :1;
        unsigned short int RightBrakeOk       :1;
        unsigned short int SLS_OSSDs          :1;
        unsigned short int SLS_Alarm1         :1;
        unsigned short int SLS_Alarm2         :1;
        unsigned short int InstantEmcyCh      :1;
        unsigned short int DelayedEmcyCh      :1;
        unsigned short int PwrPushButton      :1;
        unsigned short int ErrorDetected      :1;
        unsigned short int VPState            :1;
        unsigned short int BmsDetected        :1;
        unsigned short int Reserved           :1;
        unsigned short int PDOToggleBit       :1;
    }OtherStatus;
    // Byte 4
    enum {
        EDS_POWER_MODE_INIT         = 1,
        EDS_POWER_MODE_NORMAL       = 2,
        EDS_POWER_MODE_STANDBY      = 3,
        EDS_POWER_MODE_HIBERNATION  = 4,
        EDS_POWER_MODE_POWER_OFF    = 0xFF
    }PowerMode;
}tStatusBitsEDSBytes;

typedef union {
    unsigned char tchar[5];
    tStatusBitsEDSBytes StatusBitsEDSBytes;
}uStatusBitsEDS;
uStatusBitsEDS StatusBitsEDS;


/* ********************* Drivers Status Bytes ********************* */
/* ********** Drivers PDO1 Bytes ********** */
typedef struct {
// Byte 0 + 1
    struct{
        unsigned char ReadyToSwitchOn         :1;
        unsigned char SwitchedOn              :1;
        unsigned char OperationEnabled        :1;
        unsigned char Fault                   :1;
        unsigned char VoltageEnabled          :1;
        unsigned char QuickStop               :1;
        unsigned char SwitchOnDisabled        :1;
        unsigned char Warning                 :1;

        unsigned char ManufacturerSpecific    :1;
        unsigned char Remote                  :1;
        unsigned char TargetReached           :1;
        unsigned char InternalLimitActive     :1;
        unsigned char OperationModeSpecific   :2;
        unsigned char Specific                :2;
    }ElmoCommonStatusBits;
    // Byte 2 + 3
    struct{
        unsigned short int Unused1                 :10;
        unsigned short int TargetReached           :1;
        unsigned short int Unused2                 :1;
        unsigned short int NullSpeed               :1;
        unsigned short int MaxSlippage             :1;  // Not Implemented
        unsigned short int Unused3                 :2;
    }ElmoProfiledVelocitySpecificStatusBits;
    // Byte 4 + 5
    struct{
        unsigned short int Unused1                 :10;
        unsigned short int TargetReached           :1;
        unsigned short int Unused2                 :1;
        unsigned short int SetNewPointAcknowledge  :1;
        unsigned short int FollowingError          :1;
        unsigned short int Unused3                 :2;
    }ElmoProfiledPositionSpecificStatusBits;
}tStatusBitsDriversBytes;

typedef union {
    unsigned char tchar[6];
    tStatusBitsDriversBytes StatusBitsDriversBytes;
}uStatusBitsDrivers;
uStatusBitsDrivers StatusBitsDrivers;
/* ********** Drivers PDO2 Bytes ********** */
/* ********** Drivers PDO3 Bytes ********** */
//See Common.h


/* ********************* I/O Status Bytes ********************* */
typedef enum{
    BUZZER_OFF           = 0,
    BUZZER_500ms         = 1,
    BUZZER_100ms_600ms   = 2,
    BUZZER_100ms         = 3,
    BUZZER_CONTINUOUS_ON = 4,
    BUZZER_50ms          = 5
}tTypeOfBuzzer;

typedef struct {
    // Byte 0 + 1
    struct{
        unsigned short int Input1             :1;
        unsigned short int Input2             :1;
        unsigned short int Input3             :1;
        unsigned short int Input4             :1;
        unsigned short int Input5             :1;
        unsigned short int Input6             :1;
        unsigned short int Input7             :1;
        unsigned short int Input8             :1;

        unsigned short int Output1            :1;
        unsigned short int Output2            :1;
        unsigned short int Output3            :1;
        unsigned short int Output4            :1;
        unsigned short int Output5            :1;
        unsigned short int Output6            :1;
        unsigned short int Output7            :1;
        unsigned short int Output8            :1;
    }IOStatusBitsInputOutputs;
    // Byte 2 + 3
    struct{
        unsigned short int CenterActuatorIsMoving     :1;
        unsigned short int RearActuatorIsMoving       :1;
        unsigned short int CenterUpPositionSensor     :1;
        unsigned short int CenterDownPositionSensor   :1;
        unsigned short int RearUpPositionSensor       :1;
        unsigned short int RearDownPositionSensor     :1;
        unsigned short int Unused1                    :1;
        unsigned short int Unused2                    :1;

        unsigned short int Left_Receiver      :1;
        unsigned short int Left_Sender        :1;
        unsigned short int Right_Receiver     :1;
        unsigned short int Right_Sender       :1;
        unsigned short int AccuracyStopSensor :1;
        unsigned short int EmergencyStop      :1;
        unsigned short int ChargeInProgress   :1;
        unsigned short int Unused3            :1;
    }IOStatusBitsOthers;
    // Byte 4 + 5 + 6 + 7
    struct{
        unsigned short int Buzzer_mode        :8;
        unsigned short int Temperature        :8;
        
        unsigned short int Unused1            :8;
        unsigned short int Unused2            :5;
        unsigned short int ErrorDetected      :1;
        unsigned short int ParametersOk       :1;
        unsigned short int Toggle             :1;
    }IOStatusBitsMisc;
}tStatusBitsIOBytes;

typedef union {
    unsigned char tchar[8];
    tStatusBitsIOBytes StatusBitsIOBytes;
}uStatusBitsIO;
uStatusBitsIO StatusBitsIO;



/* ********************* Guidance Status Bytes ********************* */
#define GOTTING_DEVIATION_LEFT_LIMIT        20.0
#define GOTTING_DEVIATION_RIGHT_LIMIT       -GOTTING_DEVIATION_LEFT_LIMIT
#define SICK_MLS200_DEVIATION_LEFT_LIMIT    50.0
#define SICK_MLS200_DEVIATION_RIGHT_LIMIT   -SICK_MLS200_DEVIATION_LEFT_LIMIT

#define NO_RELEASE      0b00
#define DIRECTION_RIGHT 0b01
#define DIRECTION_LEFT  0b10
#define STRAIGHT_ON     0b11
#pragma pack(1)
typedef struct{
    struct {
        unsigned char EEProm_Param_Error                 :1;
        unsigned char Parallele_Outputs_Short_Circuit    :1;
        unsigned char Another_Track_Found_To_The_Left    :1;
        unsigned char Another_Track_Found_To_The_Right   :1;
        unsigned char Current_Direction                  :2;
        unsigned char Auxiliary_Cam_Selected             :1;
        unsigned char Parameter_2_or_4_Active            :1;

        unsigned char Deviation_T2_Right                 :1;
        unsigned char Deviation_T1_Right                 :1;
        unsigned char Deviation_T1_Left                  :1;
        unsigned char Deviation_T2_Left                  :1;
        unsigned char Decoding_Barcode                   :1;
        unsigned char Bad_Track_Quality                  :1;
        unsigned char Track_Detected                     :1;
        unsigned char PDO_Toggle_Bit                     :1;
    }fullstatus;
    float deviation;
    unsigned short int peak;
}tGuidanceStatusBitsGoettingBytes;
#pragma pack()

typedef union {
    unsigned char tchar[6];
    tGuidanceStatusBitsGoettingBytes   GuidanceStatusBitsGoettingBytes;
}uStatusBitsGuidanceGoetting;
uStatusBitsGuidanceGoetting StatusBitsGuidanceGoetting;

#define FIELD_LEVEL_750     0
#define FIELD_LEVEL_1000    1
#define FIELD_LEVEL_1250    2
#define FIELD_LEVEL_1500    3
#define FIELD_LEVEL_1750    4
#define FIELD_LEVEL_2000    5
#define FIELD_LEVEL_2500    6
#define FIELD_LEVEL_2750    7

#define NO_LINE_FOUND                   0
#define ONE_LINE_FOUND                  2
#define TWO_LINES_FOUND_RIGHT_DIVERTER  3
#define TWO_LINES_FOUND_LEFT_DIVERTER   6
#define THREE_LINES_FOUND               7

#pragma pack(1)
typedef struct {
    short int LCP1;
    short int LCP2;
    short int LCP3;
    struct{
        unsigned char NbElement :3;
        unsigned char MarkerChar:1;
        unsigned char MarkerCode:4;
    }GuidanceSharpBitsSickMls;
    struct{
        unsigned char LineGood       :1;
        unsigned char LineLevel      :3;
        unsigned char SensorFlipped  :1;
        unsigned char Polarity       :1;
        unsigned char ReadingCode    :1;
        unsigned char reserved       :1;
    }GuidanceStatusBitsSickMls;
}tGuidanceStatusBitsSickMlsBytes;
#pragma pack()

typedef union {
    unsigned char tchar[8];
    tGuidanceStatusBitsSickMlsBytes    GuidanceStatusBitsSickMlsBytes;
}uStatusBitsGuidanceMLS;
uStatusBitsGuidanceMLS StatusBitsGuidanceMLS;



/* ********************* Radio Status Bytes ********************* */
typedef struct{
    unsigned char ActualWEGA_Nb;
    unsigned char WegaFifoAvailablity;

    unsigned short int NewCrossroadsStatus:1;
    unsigned short int NewWegaProcessCmd:1;
    unsigned short int NewWegaRemoteCmd:1;
    unsigned short int NewRemoteCtrlCmd:1;
    unsigned short int reserved:3;
    unsigned short int RemoteCtrlConnected:1;
    unsigned short int ModemStarted:1;
    unsigned short int ParametersOk:1;
    unsigned short int reserved2:5;
    unsigned short int Toggle:1;

    unsigned char PlcCmdNumber;
    unsigned char Reserved[3];
}tRadioStatusBits;

typedef union {
    unsigned char tchar[8];
    tRadioStatusBits RadioStatusBits;
}uStatusBitsRadio;
uStatusBitsRadio StatusBitsRadio;




#endif // INDEX_H_INCLUDED
