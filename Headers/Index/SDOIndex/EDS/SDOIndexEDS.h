#ifndef SDOINDEXEDS_H_INCLUDED
#define SDOINDEXEDS_H_INCLUDED

/* ********************* EDS Power_Supply_Device 0x2000 ********************* */
// 1 Byte
typedef struct
{
    unsigned char Guidance;
} tEDSPowerSupplyDeviceGuidanceByte;
// 1 Byte
typedef struct
{
    unsigned char IOPowerVP;
} tEDSPowerSupplyDeviceIoVpeByte;
// 1 Byte
typedef struct
{
    unsigned char RightDriverPowerVP;
} tEDSPowerSupplyDeviceRDriverVpByte;
// 1 Byte
typedef struct
{
    unsigned char LeftDriverPowerVP;
} tEDSPowerSupplyDeviceLDriverVpByte;
// 1 Byte
typedef struct
{
    unsigned char BrakesPower;
} tEDSPowerSupplyDeviceBrakePowerByte;

#define EDS_SUB_INDEX_POWER_SUPPLY_GUIDANCE 4
#define EDS_SUB_INDEX_POWER_SUPPLY_IO_VP 7
#define EDS_SUB_INDEX_POWER_SUPPLY_R_DRIVER_VP 9
#define EDS_SUB_INDEX_POWER_SUPPLY_L_DRIVER_VP 11
#define EDS_SUB_INDEX_POWER_SUPPLY_BRAKES 13

typedef union
{
    unsigned char tchar;
    tEDSPowerSupplyDeviceGuidanceByte EDSPowerSupplyDeviceGuidanceByte;
    tEDSPowerSupplyDeviceIoVpeByte EDSPowerSupplyDeviceIoVpeByte;
    tEDSPowerSupplyDeviceRDriverVpByte EDSPowerSupplyDeviceRDriverVpByte;
    tEDSPowerSupplyDeviceLDriverVpByte EDSPowerSupplyDeviceLDriverVpByte;
    tEDSPowerSupplyDeviceBrakePowerByte EDSPowerSupplyDeviceBrakePowerByte;
} uEDSPowerSupplyDevice;
uEDSPowerSupplyDevice EDSPowerSupplyDevice;

/* ********************* EDS Index_Remote_CMD 0x2001 ********************* */
// 1 Byte
typedef struct
{
    unsigned short int SafetyRelayReset : 1;
    unsigned short int Unused1 : 7;
} tEDSRemoteCMDRelayBytes;
// 1 Byte
typedef struct
{
    unsigned char SafetyLaserArea;
} tEDSRemoteCMDLaserAreaBytes;
// 1 Byte
typedef struct
{
    unsigned char PowerMode;
} tEDSRemoteCMDPwrModeBytes;

#define EDS_POWER_MODE_INIT 1
#define EDS_POWER_MODE_NORMAL 2
#define EDS_POWER_MODE_STANDBY 3
#define EDS_POWER_MODE_HIBERNATION 4
#define EDS_POWER_MODE_POWER_OFF 0xFF

typedef union
{
    unsigned char tchar;
    tEDSRemoteCMDRelayBytes EDSRemoteCMDRelayBytes;
    tEDSRemoteCMDLaserAreaBytes EDSRemoteCMDLaserAreaBytes;
    tEDSRemoteCMDPwrModeBytes EDSRemoteCMDPwrModeBytes;
} uEDSRemoteCMD;
uEDSRemoteCMD EDSRemoteCMD;

/* ********************* EDS BMS_Device 0x2002********************* */
// 4 Byte
typedef struct
{
    unsigned int VendorId;
} tEDSBMSDeviceVendorIdByte;
// 1 Byte
typedef struct
{
    unsigned char FirmwareVersion[8];
} tEDSBMSDeviceFWVersionByte;
// 4 Byte
typedef struct
{
    unsigned int SerialNbr;
} tEDSBMSDeviceSerialByte;
// 2 Byte
typedef struct
{
    unsigned short int Status;
} tEDSBMSDeviceStatusByte;
// 4 Byte
typedef struct
{
    float MainVoltage;
} tEDSBMSDeviceMainVoltageByte;
// 4 Byte
typedef struct
{
    float MainCurrent;
} tEDSBMSDeviceMainCurrentByte;
// 4 Byte
typedef struct
{
    float SOC;
} tEDSBMSDeviceSOCByte;
// 4 Byte
typedef struct
{
    float CellTemperature;
} tEDSBMSDeviceCellTemperatureByte;
// 4 Byte
typedef struct
{
    float PDUTemperature;
} tEDSBMSDevicePDUTemperatureByte;
// 1 Byte
typedef struct
{
    unsigned char PDUStatus;
} tEDSBMSDevicePDUStatusByte;
// 4 Byte
typedef struct
{
    unsigned int Alarm;
} tEDSBMSDeviceAlarmByte;
// 4 Byte
typedef struct
{
    unsigned int Error;
} tEDSBMSDeviceErrorByte;

#define EDS_SUB_INDEX_BMS_DEVICE_VENDOR_ID 1
#define EDS_SUB_INDEX_BMS_DEVICE_FW_VERSION 2
#define EDS_SUB_INDEX_BMS_DEVICE_SERIAL 3
#define EDS_SUB_INDEX_BMS_DEVICE_STATUS 4
#define EDS_SUB_INDEX_BMS_DEVICE_MAIN_VLTG 5
#define EDS_SUB_INDEX_BMS_DEVICE_MAIN_CRT 6
#define EDS_SUB_INDEX_BMS_DEVICE_SOC 7
#define EDS_SUB_INDEX_BMS_DEVICE_CELL_TEMP 8
#define EDS_SUB_INDEX_BMS_DEVICE_PDU_TEMP 9
#define EDS_SUB_INDEX_BMS_DEVICE_PDU_STATUS 10
#define EDS_SUB_INDEX_BMS_DEVICE_ALARM 11
#define EDS_SUB_INDEX_BMS_DEVICE_ERROR 12

typedef union
{
    unsigned char tchar[8];
    tEDSBMSDeviceVendorIdByte EDSBMSDeviceVendorIdByte;
    tEDSBMSDeviceFWVersionByte EDSBMSDeviceFWVersionByte;
    tEDSBMSDeviceSerialByte EDSBMSDeviceSerialByte;
    tEDSBMSDeviceStatusByte EDSBMSDeviceStatusByte;
    tEDSBMSDeviceMainVoltageByte EDSBMSDeviceMainVoltageByte;
    tEDSBMSDeviceMainCurrentByte EDSBMSDeviceMainCurrentByte;
    tEDSBMSDeviceSOCByte EDSBMSDeviceSOCByte;
    tEDSBMSDeviceCellTemperatureByte EDSBMSDeviceCellTemperatureByte;
    tEDSBMSDevicePDUTemperatureByte EDSBMSDevicePDUTemperatureByte;
    tEDSBMSDevicePDUStatusByte EDSBMSDevicePDUStatusByte;
    tEDSBMSDeviceAlarmByte EDSBMSDeviceAlarmByte;
    tEDSBMSDeviceErrorByte EDSBMSDeviceErrorByte;
} uEDSBMSDevice;
uEDSBMSDevice EDSBMSDevice;

#endif
