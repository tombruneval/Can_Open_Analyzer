#ifndef SDOINDEX_H_INCLUDED
#define SDOINDEX_H_INCLUDED
#include "SDOIndexDrivers.h"
#include "SDOIndexEDS.h"
#include "SDOIndexGuidance.h"
#include "SDOIndexRadio.h"
#include "SDOIndexIO.h"
#include "SDOIndexPCU.h"


/* ********************* DS401 Driver Index ********************* */
#define INDEX_AbortConnectionOptionCode        0x6007   // R/W     // N
#define INDEX_ErrorCode                        0x603F   // R       // N
#define INDEX_ControlWord                      0x6040   // R/W     // Y
#define INDEX_StatusWord                       0x6041   // R       // Y
#define INDEX_QuickStopOptionCode              0x605A   // R/W     // N
#define INDEX_ShutDownOptionCode               0x605B   // R/W     // N
#define INDEX_DisableOperationOptionCode       0x605C   // R/W     // N
#define INDEX_HaltOptionCode                   0x605D   // R/W     // N
#define INDEX_FaultReactionOptionCode          0x605E   // R/W     // N
#define INDEX_ModesOfOperation                 0x6060   // R/W     // Y
#define INDEX_ModesOfOperationDisplay          0x6061   // R       // N
#define INDEX_PositionDemandValueProfilerOut   0x6062   // R       // Y
#define INDEX_PositionActualValue              0x6063   // R       // Y
#define INDEX_ActualPositionInternalUnit       0x6064   // R       // Y
#define INDEX_PositionFollowingErrorWindow     0x6065   // R/W     // N
#define INDEX_PositionFollowingErrorWindowTime 0x6066   // R/W     // N
#define INDEX_PositionWindow                   0x6067   // R/W     // N
#define INDEX_PositionWindowTime               0x6068   // R/W     // N
#define INDEX_VelocitySensorActualValue        0x6069   // R       // Y
#define INDEX_VelocitySensorSelectionCode      0x606A   // R/W     // N
#define INDEX_VelocityDemandValue              0x606B   // R       // Y
#define INDEX_VelocityActualSensor             0x606C   // R       // Y
#define INDEX_VelocityWindow                   0x606D   // R/W     // N
#define INDEX_VelocityWindowTime               0x606E   // R/W     // N
#define INDEX_VelocityThreshold                0x606F   // R/W     // N
#define INDEX_VelocityThresholdTime            0x6070   // R/W     // N
#define INDEX_TargetTorque                     0x6071   // R       // Y
#define INDEX_MaxTorque                        0x6072   // R/W     // N
#define INDEX_MaxCurrent                       0x6073   // R/W     // N
#define INDEX_TorqueDemandValue                0x6074   // R/W     // N
#define INDEX_MotorRatedCurrent                0x6075   // R/W     // N
#define INDEX_MotorRatedTorque                 0x6076   // R/W     // N
#define INDEX_MotorActualTorque                0x6077   // R       // Y
#define INDEX_CurrentActualValue               0x6078   // R       // Y
#define INDEX_ProfilTargetPosition             0x607A   // R/W     // Y
#define INDEX_PositionRangeLimit               0x607B   // R/W     // N
#define INDEX_HomingOffset                     0x607C   // R/W     // N
#define INDEX_SoftwarePositionLimit            0x607D   // R/W     // N
#define INDEX_Polarity                         0x607E   // R/W     // Y
#define INDEX_MaxProfilVelocity                0x607F   // R/W     // N
#define INDEX_ProfilVelocity                   0x6081   // R/W     // Y
#define INDEX_ProfilAcceleration               0x6083   // R/W     // Y
#define INDEX_ProfilDeceleration               0x6084   // R/W     // N
#define INDEX_QuickStopDeceleration            0x6085   // R/W     // N
#define INDEX_MotionProfilType                 0x6086   // R/W     // N
#define INDEX_TorqueSlope                      0x6087   // R/W     // Y
#define INDEX_TorqueProfilType                 0x6088   // R/W     // N
#define INDEX_PositionNotationIndex            0x6089   // R/W     // N
#define INDEX_PositionDimensionIndex           0x608A   // R/W     // N
#define INDEX_VelocityNotationIndex            0x608B   // R/W     // N
#define INDEX_VelocityDimensionIndex           0x608C   // R/W     // N
#define INDEX_AccelerationNotationIndex        0x608D   // R/W     // N
#define INDEX_AccelerationDimensionIndex       0x608E   // R/W     // N
#define INDEX_PositionEncoderResolution        0x608F   // R/W     // N
#define INDEX_VelocityEncoderResolution        0x6090   // R/W     // N
#define INDEX_PositionFactor                   0x6093   // R/W     // N
#define INDEX_VelocityEncoderFactor            0x6094   // R/W     // N
#define INDEX_VelocityFactor1                  0x6095   // R/W     // N
#define INDEX_VelocityFactor2                  0x6096   // R/W     // N
#define INDEX_AccelerationFactor               0x6097   // R/W     // N
#define INDEX_HomingMethod                     0x6098   // R/W     // N
#define INDEX_HomingSpeed                      0x6099   // R/W     // N
#define INDEX_HomingAcceleration               0x609A   // R/W     // N
#define INDEX_InterpolatedPositionSubMode      0x60C0   // R/W     // N
#define INDEX_InterpolatedDataRecord           0x60C1   // R/W     // Y
#define INDEX_InterpolatedPositionTimePeriod   0x60C2   // R/W     // Y
#define INDEX_InterpolatedDataConfiguration    0x60C4   // R/W     // Y: Buffer Position / N: All other entries
#define INDEX_PositionDemandValue              0x60FC   // R       // Y
#define INDEX_DigitalInput                     0x60FD   // R       // Y
#define INDEX_TargetVelocity                   0x60FF   // R/W     // Y
#define INDEX_MotorType                        0x6402   // R/W     // N
#define INDEX_MotorCatalogNumber               0x6403   // R/W     // N
#define INDEX_MotorManufacturer                0x6404   // R/W     // N
#define INDEX_HttpMotorCatalogAddress          0x6405   // R/W     // N
#define INDEX_HttpCalibrationDate              0x6406   // R/W     // N
#define INDEX_MotorServicePeriod               0x6407   // R/W     // N
#define INDEX_DriveModes                       0x6502   // R/W     // N
#define INDEX_DriveManufacturer                0x6504   // R       // N
#define INDEX_DriveManufacturerWebSite         0x6505   // R       // N

/* ********************* DS301 Driver Index Board ********************* */
#define INDEX_CANControllerType                0x1000   // R       // N
#define INDEX_ErrorRegister                    0x1001   // R       // N
#define INDEX_ManufacturerStatusRegister       0x1002   // R       // Y
#define INDEX_PreDefinedErrorField             0x1003   // R       // N
#define INDEX_COBIDforSYNCmessage              0x1005   // R       // N
#define INDEX_CommunicationCyclePeriod         0x1006   // R/W     // N
#define INDEX_ManufacturerDeviceName           0x1008   // R       // N
#define INDEX_HardwareVersion                  0x1009   // R       // N
#define INDEX_SoftwareVersion                  0x100A   // R       // N
#define INDEX_NodeID                           0x100B   // R       // N
#define INDEX_RebootDevice                     0x100F   // R/W     // N
#define INDEX_StoreParameters                  0x1010   // R/W     // N
#define INDEX_RestoreParameters                0x1011   // R/W     // N
#define INDEX_COBIDTimeStampMessage            0x1012   // R       // N
#define INDEX_HighResolutionTimeStamp          0x1013   // R/W     // N
#define INDEX_COBIDEmergencyMessage            0x1014   // R       // N
#define INDEX_ConsumerHeartbitTime             0x1016   // R/W     // N
#define INDEX_ProducerHeartbitTime             0x1017   // R/W     // N
#define INDEX_IdentityObject                   0x1018   // R       // N
#define INDEX_OSInterpreter                    0x1023   // R/W     // N
#define INDEX_OSCommandMode                    0x1024   // R/W     // N
#define INDEX_ErrorBehaviour                   0x1029   // R/W     // N
#define INDEX_SDO1Server                       0x1200   // R       // N
#define INDEX_PDO1RxComm                       0x1400   // R/W     // N
#define INDEX_PDO2RxComm                       0x1401   // R/W     // N
#define INDEX_PDO3RxComm                       0x1402   // R/W     // N
#define INDEX_PDO4RxComm                       0x1403   // R/W     // N
#define INDEX_PDO1RxMap                        0x1600   // R/W     // N
#define INDEX_PDO2RxMap                        0x1601   // R/W     // N
#define INDEX_PDO3RxMap                        0x1602   // R/W     // N
#define INDEX_PDO4RxMap                        0x1603   // R/W     // N
#define INDEX_PDO1TxComm                       0x1800   // R/W     // N
#define INDEX_PDO2TxComm                       0x1801   // R/W     // N
#define INDEX_PDO3TxComm                       0x1802   // R/W     // N
#define INDEX_PDO4TxComm                       0x1803   // R/W     // N
#define INDEX_PDO1TxMap                        0x1A00   // R/W     // N
#define INDEX_PDO2TxMap                        0x1A01   // R/W     // N
#define INDEX_PDO3TxMap                        0x1A02   // R/W     // N
#define INDEX_PDO4TxMap                        0x1A03   // R/W     // N
#define INDEX_PVTData                          0x2001   // W       // Y
#define INDEX_PTData                           0x2002   // W       // Y
#define INDEX_ECAMData                         0x2004   // W       // Y
#define INDEX_BinaryInterpreterInput           0x2012   // W       // Y
#define INDEX_BinaryInterpreterOutput          0x2013   // R       // Y
#define INDEX_RecordedDataOutput               0x2030   // R       // N
#define INDEX_GroupID                          0x2040   // R/W     // N
#define INDEX_AmplifierFreeRunningTimer        0x2041   // R       // Y
#define INDEX_CANControllerStatus              0x2082   // R       // Y
#define INDEX_BeginOnTime                      0x208A   // R/W     // N
#define INDEX_FirmwareDownload                 0x2090   // W       // N
#define INDEX_AuxiliaryPositionActualValue     0x20A0   // R       // Y
#define INDEX_PositionError                    0x20A1   // R       // Y
#define INDEX_DigitalInputIP                   0x2200   // R       // Y
#define INDEX_DigitalInputLowByte              0x2201   // R       // Y
#define INDEX_UserInteger                      0x2F00   // R?      // Y
#define INDEX_UserFloatArray                   0x2F01   // R/W     // Y
#define INDEX_ETArray                          0x2F02   // R/W     // Y
#define INDEX_PVTBufferHeadPointer             0x2F11   // R       // Y
#define INDEX_PVTBufferTailPointer             0x2F12   // R       // Y
#define INDEX_BufferedPTPRemainedPoint         0x2F15   // R       // Y
#define INDEX_AsynchronousPDOEvent             0x2F20   // R/W     // N
#define INDEX_EmergencyEvent                   0x2F21   // R/W     // N
#define INDEX_BusOffTimeout                    0x2F22   // R/W     // N
#define INDEX_DigitalInputTPDOEvent            0x2F23   // R/W     // N
#define INDEX_LastTimeStampCorrection          0x2F30   // R       // Y
#define INDEX_InternalCounterLastSYNCuSec      0x2F31   // R       // Y
#define INDEX_ConfigurationObject              0x2F40   // R/W     // N
#define SUBINDEX_IdentityObject_VendorID       0x01
#define SUBINDEX_IdentityObject_ProductCode    0x02
#define SUBINDEX_IdentityObject_RevisionNumber 0x03
#define SUBINDEX_IdentityObject_SerialNumber   0x04

/* ********************* Radio Board Index ********************* */
#define INDEX_SYSTEM_PARAMETERS     0x2000
#define INDEX_WEGA_PARAMETERS       0x2001
#define INDEX_APP_PARAMETERS        0x2002
#define INDEX_CROSSROADS_CMD        0x2010
#define INDEX_WEGA_PROCESS_CMD      0x2011
#define INDEX_WEGA_REMOTE_CMD       0x2012
#define INDEX_REMOTE_CTRL_CMD       0x2013
#define SUBINDEX_ALL                1
#define SUBINDEX_CROSSROADS_TYPE    2
#define SUBINDEX_CROSSROADS_ID      3

/* ********************* IO Board Index ********************* */
#define IO_INDEX_SYSTEM_PARAMETERS     0x2000
#define IO_INDEX_BMS_PARAMETERS        0x2001
#define IO_INDEX_REMOTE_CMD            0x2010
#define IO_SUBINDEX_ALL                1

/* ********************* EDS Board Index ********************* */
#define EDS_INDEX_POWER_SUPPLY  0x2000
#define EDS_INDEX_REMOTE_CMD    0x2001
#define EDS_INDEX_BMS_DEVICE    0x2002
#define EDS_INDEX_TYVA_BMS_DEVICE    0x2003
#define EDS_INDEX_ENIX_BMS_DEVICE    0x2004
#define EDS_SUB_INDEX_SAFETY_RELAY_RESET    0x01
#define EDS_SUB_INDEX_SAFETY_LASER_AREA     0x02
#define EDS_SUB_INDEX_POWER_MODE            0x03
#define EDS_SUB_INDEX_POWER_SUPPLY_BRAKES       13
#define EDS_SUB_INDEX_BMS_VENDOR_ID     1
#define EDS_SUB_INDEX_BMS_FW_VERSION    2
#define EDS_SUB_INDEX_BMS_SERIAL_NUMBER 3
#define EDS_SUB_INDEX_POWER_SUPPLY_GUIDANCE     4
#define EDS_SUB_INDEX_POWER_SUPPLY_IO_VP        7
#define EDS_SUB_INDEX_POWER_SUPPLY_R_DRIVER_VP  9
#define EDS_SUB_INDEX_POWER_SUPPLY_L_DRIVER_VP  11

#define eEDS_CMD_NONE               0
#define eEDS_CMD_MODE_NORMAL        1
#define eEDS_CMD_MODE_STANDBY       2
#define eEDS_CMD_MODE_HIBERNATION   3
#define eEDS_CMD_MODE_POWER_OFF     4
#define eEDS_CMD_SAFETY_RELAY       5
#define eEDS_CMD_SAFETY_LASER_AREA  6
#define eEDS_CMD_BRAKES             7
#define eEDS_CMD_FAULT_RESET        8
#define eEDS_CMD_L_DRIVER_VP        9
#define eEDS_CMD_R_DRIVER_VP        10

#define eEDS_MODE_INIT              0
#define eEDS_MODE_NORMAL            1
#define eEDS_MODE_STANDBY           2
#define eEDS_MODE_HIBERNATION       3
#define eEDS_MODE_POWER_OFF         4

/* ********************* Guidance Board Index ********************* */
#define INDEX_GOTTING_PARAMETERS    0x2000
#define SUBINDEX_GOTTING_PARAMETERS 0x03
#define INDEX_SICK_VARIANT_TPDO1    0x2006
#define INDEX_SICK_SENSOR_FLIPPED   0x2027
#define INDEX_SICK_MIN_LEVEL        0x2025
#define INDEX_SICK_MARKERS          0x2028

/* ********************* PCU Board Index ********************* */
#define HMI_INDEX_SYSTEM_PARAMETERS     0x2000
#define HMI_INDEX_APP_PARAMETERS        0x2001
#define INDEX_BOARD_IDENTITY            0x2002
#define INDEX_UPDATE_INFOS              0x2003
#define HMI_INDEX_PROCESS_CMD           0x2010
#define HMI_INDEX_CPU_PROCESS_CMD       0x2011

/* ********************* Parameters ********************* */
//Battery_Voltage
#define BATTERY_VOLTAGE_UNKNOWN 0
#define BATTERY_VOLTAGE_24V     1
#define BATTERY_VOLTAGE_48V     2
//Battery_Type
#define BATTERY_UNKNOWN         0
#define BATTERY_VRLA            1
#define BATTERY_LITHIUM_NMC     2
#define BATTERY_LITHIUM_LIFEPO4 3
//BMS_Vendor
#define BMS_VENDOR_ID_NONE     0
#define BMS_VENDOR_ID_VICTRON  203
#define BMS_VENDOR_ID_TYVA     'T'
#define BMS_VENDOR_ID_ENIX     'E'
//Country
#define COUNTRY_EUROPE                      1
#define COUNTRY_JAPAN                       2
//Wega Area
#define WEGA_AREA_FROM_CONFIG               3
#define WEGA_AREA_FROM_TAG                  4
#define WEGA_AREA_FROM_FUNCTION             5
//Wega Protocol
#define WEGA_PROTOCOL_V2                    6
#define WEGA_PROTOCOL_V4                    7
#define WEGA_PROTOCOL_V5                    8
//Optical Tape
#define OPTICAL_TAPE_WHITE_ON_BLACK         10
#define OPTICAL_TAPE_BLACK_ON_WHITE         11
#define NO_OPTICAL_TAPE                     12
//Charging Interface
#define CONNECTOR_CHARGING_INTERFACE        13
#define FRICTION_CHARGING_INTERFACE         14
//RFID Type
#define RFID_MRD2                           15
#define RFID_RFH620                         16
//LED Strip
#define LEDS_MAX16824                       17
#define LEDS_LT3746                         18
//Magnetic Sensor Sense
#define NORMAL_SENSE_FOR_MAGNETIC_SENSOR    19
#define OPPOSITE_SENSE_FOR_MAGNETIC_SENSOR  20
//Actuator Types
#define ACTUATOR_NONE                       21
#define ACTUATOR_PIN                        22
#define ACTUATOR_LIFTER                     23
#define ACTUATOR_ROLLER                     24

/* ********************* OBJ/CMD ********************* */
#define    OBJ_WATCHDOG                0
#define    OBJ_CENTRAL_ACTUATOR        1
#define    OBJ_REAR_ACTUATOR           2
#define    OBJ_ACTUATORS               3
#define    OBJ_JOG                     4
#define    OBJ_MODE                    5
#define    OBJ_FAULT                   6
#define    OBJ_POWER                   7
#define    OBJ_NO_ORDER                8
#define    OBJ_DISCONNECTED            9
#define    OBJ_TIME                    10
#define    OBJ_USB                     11
#define    OBJ_USER_OUTPUT_SET         12
#define    OBJ_USER_OUTPUT_RESET       13
#define    OBJ_LEFT_OPTICAL_SET        14
#define    OBJ_LEFT_OPTICAL_RESET      15
#define    OBJ_RIGHT_OPTICAL_SET       16
#define    OBJ_RIGHT_OPTICAL_RESET     17
#define    OBJ_START_CHARGE            18
#define    OBJ_STOP_CHARGE             19
#define    OBJ_BUZZER                  20
#define    OBJ_E_STOP                  21
#define    OBJ_PARAMETERS              22
#define    OBJ_LAMP                    23
#define    OBJ_SEQUENCE                24

#define    CMD_ACTUATOR_DOWN           0
#define    CMD_ACTUATOR_UP             1
#define    CMD_ROLLER_SENSE_B          2
#define    CMD_ROLLER_SENSE_A          3
#define    CMD_ROLLER_STOP             4
#define    CMD_JOG_LEFT                0x55
#define    CMD_JOG_RIGHT               0xAA
#define    CMD_JOG_FORWARD             0x5A
#define    CMD_JOG_LEFT_NO_TAPE        0x44
#define    CMD_JOG_RIGHT_NO_TAPE       0xCC
#define    CMD_JOG_FORWARD_NO_TAPE     0x4C
#define    CMD_JOG_BACKWARD            0xA5
#define    CMD_JOG_STOP                0xBB
#define    CMD_MANU                    'M'
#define    CMD_AUTO                    'A'
#define    CMD_RUN                     'R'
#define    CMD_FAULT_RESET             'O'
#define    CMD_SHUTDOWN_NO_SAVE        12
#define    CMD_SHUTDOWN_SAVE           13
#define    CMD_WAKEUP                  14
#define    CMD_TIME_GET                15
#define    CMD_TIME_SET                16
#define    CMD_USB_IMPORT              17
#define    CMD_USB_EXPORT              18
#define    CMD_USB_CANCEL              19
#define    CMD_USB_START_TRANSFER      20
#define    CMD_FAULT_RESET_CHARGER     21
#define    CMD_SERVICE_MODE            22
#define    CMD_UPDATE_ONE_PARAMETER    23
#define    CMD_STORE_ALL_PARAMETERS    24
#define    CMD_NEXT_SEQUENCE           25
#define    CMD_PREVIOUS_SEQUENCE       26
#define    CMD_USB_OK                  27
#define    CMD_USB_KO                  28
#define    CMD_EXIT_SERVICE_MODE       29







#endif
