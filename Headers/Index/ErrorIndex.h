#ifndef ERRORINDEX_H_INCLUDED
#define ERRORINDEX_H_INCLUDED

#define NoErrorCode                  0x0000u

/* ********************* Radio Board Error Codes********************* */
#define ErrorEepromAccessCode        0x5001u
#define ErrorI2CAccessCode           0x5002u
#define ErrorModemRpm3bCode          0x5003u
#define ErrorBufferAccessCode        0x6101u
#define ErrorCrossroadsExistCode     0x6201u
#define ErrorMaxCrossroadsCode       0x6202u
#define ErrorParametersCode          0x6302u
#define ErrorSerialNumberCode        0x6303u
#define ErrorHardwareVersionCode     0x9001


/* ********************* IO Board Error Codes********************* */
// Current, CANopen device output side
#define ErrorCPinIMaxCode            0x2301u
#define ErrorRPinIMaxCode            0x2302u
#define ErrorSysOuputsCode           0x2303u
#define ErrorSysInputsCode           0x2304u
#define ErrorUserInputsCode          0x2305u
#define ErrorChargeRelayCode         0x2306u
#define ErrorOutput1Code             0x2307u
#define ErrorOutput2Code             0x2308u
#define ErrorOutput3Code             0x2309u
#define ErrorOutput4Code             0x230Au
#define ErrorOutput5Code             0x230Bu
#define ErrorOutput6Code             0x230Cu
#define ErrorOutput7Code             0x230Du
#define ErrorOutput8Code             0x230Eu
#define ErrorRFIdCode                0x230Fu
// CANOpen device temperature
#define ErrorOverTemperatureCode     0x4200u
// CANopen device hardware
#define ErrorEepromAccessCode        0x5001u
#define ErrorI2CAccessCode           0x5002u
// CANopen device software, Data Set
#define ErrorHardVersionCode         0x6301u
#define ErrorParametersCode          0x6302u
#define ErrorSerialNumberCode        0x6303u
// Monitoring
#define ErrorCPinPositionCode        0x8300u
#define ErrorRPinPositionCode        0x8301u
// External error
#define ErrorCommandCode             0x9001u
#define ErrorOutput8NotExistingCode  0x9002u
// Charger errors
#define ErrorChargerInitModuleCode               0x9100u
#define ErrorChargerBadModelCode                 0x9101u
#define ErrorChargerNotAvailableCode             0x9102u
#define ErrorChargerConnectInDigitalModeCode     0x9103u
#define ErrorChargerConnectInSerialModeCode      0x9104u
#define ErrorChargerAckConfigCode                0x9105u
#define ErrorChargerAckStatusCode                0x9106u

/* ********************* EDS Board Error Codes ********************* */
// Current, CANopen device output side
#define ErrorHMISupplyCode           0x2301u
#define ErrorWirelessSupplyCode      0x2302u
#define ErrorGuidanceSupplyCode      0x2303u
#define ErrorIOLogSupplyCode         0x2304u
#define ErrorIOPowSupplyCode         0x2305u
#define ErrorLDriverPowSupplyCode    0x2306u
#define ErrorRDriverPowSupplyCode    0x2307u
#define ErrorCPUSupplyCode           0x2308u
#define ErrorBrakesSupplyCode        0x2309u
#define ErrorSLSSupplyCode           0x230Au
#define ErrorSafetyRelaySupplyCode   0x230Bu
#define ErrorAuxiliarySupplyCode     0x230Cu
#define ErrorExternalSupplyCode      0x230Du
#define ErrorRFiDSupplyCode          0x230Eu
#define ErrorPwrPushButtonLedCode    0x230Fu
#define ErrorLDriverLogicSupplyCode  0x2310u
#define ErrorRDriverLogicSupplyCode  0x2311u
// CANOpen device temperature
#define ErrorOverTemperatureCode     0x4200u
// CANopen device hardware
#define ErrorEepromAccessCode        0x5001u
#define ErrorI2CAccessCode           0x5002u
// CANopen device software, Data Set
#define ErrorHardVersionCode         0x6301u
#define ErrorParametersCode          0x6302u
#define ErrorSerialNumberCode        0x6303u
// CANopen Monitoring
#define ErrorBmsNoResponseCode       0x8000
#define ErrorPdoTransmissionCode     0x8210

/* ********************* Guidance Board Error Codes********************* */
#define ErrorEepromAccessCode        0x8011u
#define ErrorI2CAccessCode           0x8021u
#define ErrorGuidanceManagementCode  0x8052u
#define ErrorGuidanceSupplyCode      0x8084u

/* ********************* Drivers Board Error Codes********************* */
//See Chapter 6-2 (EMCY Messages) Related to PVT/PT Motion
#define PVT_QUEUE_LOW           0x56
#define BAD_HEAD_POINTER        0x5B
#define PVT_QUEUE_FULL          0x34
#define BAD_MODE_INIT_DATA      0x7
#define MOTION_TERMINATED       0x8
#define OUT_OF_MODULU           0x16

//See Chapter 13-24 Object 0x2F21
#define CAN_MESSAGE_LOST                        0x8110
#define PROTOCOL_ERROR                          0x8200
#define BAD_READING_ATTEMPT_RPDO_UNCONFIGURED   0x8210
#define HEARTBEAT_EVENT                         0x8130
#define STACK_OVERFLOW                          0x6180
#define PROGRAM_ABORTED                         0x6200
#define REQUEST_EMIT_FUNCTION                   0xFF01
#define MOTOR_SHTDN_BY_ERROR                    '?'
#define OBJECT_MAPPED_RPDO_ERROR                0x6300
#define DS_402_IP_UNDERFLOW                     0xFF02

/* ********************* Drivers Board Error Codes********************* */
#define Hmi_NoErrorCode               0x0000u
#define Hmi_ErrorEepromAccessCode     0x8011u
#define Hmi_ErrorI2CAccessCode        0x8021u
#define Hmi_ErrorBufferAccessCode     0x8041u
#define Hmi_ErrorParametersCode       0x8051u
#define Hmi_ErrorSerialNumberCode     0x9000u

/* ********************* Error Registers ********************* */
#define ErrorTypeGeneric                 0x01
#define ErrorTypeCurrent                 0x02
#define ErrorTypeVoltage                 0x04
#define ErrorTypeTemperature             0x08
#define ErrorTypeCommunication           0x10
#define ErrorTypeDeviceProfileSpecific   0x20
#define ErrorTypeImpossibleStuckToZero   0x40
#define ErrorTypeManufacturerSpecific    0x80

#endif // INDEX_H_INCLUDED
