/*
FILENAME...   ethercatmcController.h
*/

#ifndef ETHERCATMCCONTROLLER_H
#define ETHERCATMCCONTROLLER_H

#include "asynDriver.h"
#include "asynMotorController.h"
#include "asynMotorAxis.h"
#include "ethercatmcAxis.h"
#include "ethercatmcADSdefs.h"

#ifndef VERSION_INT
#  define VERSION_INT(V,R,M,P) ( ((V)<<24) | ((R)<<16) | ((M)<<8) | (P))
#endif

#define VERSION_INT_4_38            VERSION_INT(4,38,0,0)
#define ETHERCATMC_ASYN_VERSION_INT VERSION_INT(ASYN_VERSION,ASYN_REVISION,ASYN_MODIFICATION,0)
#if ETHERCATMC_ASYN_VERSION_INT >= VERSION_INT_4_38
#define ETHERCATMC_ASYN_ASYNPARAMINT64
#endif

#define MAX_AUX_BIT_SHOWN 24
#define MAX_REASON_AUX_BIT_SHOW (MAX_AUX_BIT_SHOWN+2)

#ifdef asynParamMetaMask
#define ETHERCATMC_ASYN_PARAMMETA
#else
#define asynParamMetaMask 0
#define setParamMeta(a,b,c,d)
#endif

#ifndef motorRecResolutionString
#define CREATE_MOTOR_REC_RESOLUTION
#define motorRecDirectionString         "MOTOR_REC_DIRECTION"
#define motorRecOffsetString            "MOTOR_REC_OFFSET"
#define motorRecResolutionString        "MOTOR_REC_RESOLUTION"
#endif

#define ethercatmcMcuErrString               "MCUErr"
#define ethercatmcErrIdString                "ErrorID"
#define ethercatmcStatusCodeString           "StatusCode"
#define ethercatmcStatusBitsString           "StatusBits"
#define ethercatmcAuxBits07_String           "AuxBits07"
#define ethercatmcNamAux0_String             "NamAuxBit0"
#define ethercatmcNamAux1_String             "NamAuxBit1"
#define ethercatmcNamAux2_String             "NamAuxBit2"
#define ethercatmcNamAux3_String             "NamAuxBit3"
#define ethercatmcNamAux4_String             "NamAuxBit4"
#define ethercatmcNamAux5_String             "NamAuxBit5"
#define ethercatmcNamAux6_String             "NamAuxBit6"
#define ethercatmcNamAux7_String             "NamAuxBit7"
#define ethercatmcNamAux8_String             "NamAuxBit8"
#define ethercatmcNamAux9_String             "NamAuxBit9"
#define ethercatmcNamAux10_String            "NamAuxBit10"
#define ethercatmcNamAux11_String            "NamAuxBit11"
#define ethercatmcNamAux12_String            "NamAuxBit12"
#define ethercatmcNamAux13_String            "NamAuxBit13"
#define ethercatmcNamAux14_String            "NamAuxBit14"
#define ethercatmcNamAux15_String            "NamAuxBit15"
#define ethercatmcNamAux16_String            "NamAuxBit16"
#define ethercatmcNamAux17_String            "NamAuxBit17"
#define ethercatmcNamAux18_String            "NamAuxBit18"
#define ethercatmcNamAux19_String            "NamAuxBit19"
#define ethercatmcNamAux20_String            "NamAuxBit20"
#define ethercatmcNamAux21_String            "NamAuxBit21"
#define ethercatmcNamAux22_String            "NamAuxBit22"
#define ethercatmcNamAux23_String            "NamAuxBit23"
#define ethercatmcNamBit24_String            "NamBit24"
#define ethercatmcNamBit25_String            "NamBit25"
#define ethercatmcFoffVisString              "FoffVis"
#define ethercatmcHomeVisString              "HomeVis"
#define ethercatmcHomProc_RBString           "HomProc-RB"
#define ethercatmcHomPos_RBString            "HomPos-RB"
#define ethercatmcHomProcString              "HomProc"
#define ethercatmcHomPosString               "HomPos"
#define ethercatmcVelToHomString             "VelToHom"
#define ethercatmcVelFrmHomString            "VelFrmHom"
#define ethercatmcRawEncStepString           "RawEncStep"
#define ethercatmcRawMtrStepString           "RawMtrStep"
#define ethercatmcRawMtrVeloString           "RawMtrVelo"
#define ethercatmcErrRstString               "ErrRst"
#define ethercatmcVelActString               "VelAct"
#define ethercatmcVel_RBString               "Vel-RB"
#define ethercatmcAcc_RBString               "Acc-RB"
#define ethercatmcPTPStateString             "PTPState"
#define ethercatmcPTPOffsetString            "PTPOffset"
#define ethercatmcPTPSyncSeqNumString        "PTPSyncSeqNum"
#define ethercatmcSystemUTCtimeString        "SystemUTCtime"
#define ethercatmcDCTIMEString               "DCTIME"
#define ethercatmcRBV_TSEString              "RBV-TSE"
#define pilsLonginActualString               "pilsLonginActual"
#define pilsLonginTargetString               "pilsLonginTarget"
#define pilsLongoutRecordString              "pilsLongoutRecord"
#define pilsBoMinMaxString                   "pilsBoMinMax"
#define pilsBiAtMaxString                    "pilsBiAtMax"
#define pilsBiAtMinString                    "pilsBiAtMin"
#define ethercatmcCfgAxisID_RBString         "CfgAxisID-RB"
#define ethercatmcCfgVELO_RBString           "CfgVELO-RB"
#define ethercatmcCfgVMAX_RBString           "CfgVMAX-RB"
#define ethercatmcCfgJVEL_RBString           "CfgJVEL-RB"
#define ethercatmcCfgHVEL_RBString           "CfgHVEL-RB"
#define ethercatmcCfgACCS_RBString           "CfgACCS-RB"
#define ethercatmcCfgDHLMRBString            "CfgDHLM-RB"
#define ethercatmcCfgDLLMRBString            "CfgDLLM-RB"
#define ethercatmcCfgDHLM_EnRBString         "CfgDHLM-En-RB"
#define ethercatmcCfgDLLM_EnRBString         "CfgDLLM-En-RB"
#define ethercatmcCfgDHLMString              "CfgDHLM"
#define ethercatmcCfgDLLMString              "CfgDLLM"
#define ethercatmcCfgDHLM_EnString           "CfgDHLM-En"
#define ethercatmcCfgDLLM_EnString           "CfgDLLM-En"
#define ethercatmcCfgSREV_RBString           "CfgSREV-RB"
#define ethercatmcCfgUREV_RBString           "CfgUREV-RB"
#define ethercatmcCfgPMIN_RBString           "CfgPMIN-RB"
#define ethercatmcCfgPMAX_RBString           "CfgPMAX-RB"
#define ethercatmcCfgSPDB_RBString           "CfgSPDB-RB"
#define ethercatmcCfgRDBD_RBString           "CfgRDBD-RB"
#define ethercatmcCfgRDBD_Tim_RBString       "CfgRDBD-Tim-RB"
#define ethercatmcCfgRDBD_En_RBString        "CfgRDBD-En-RB"
#define ethercatmcCfgPOSLAG_RBString         "CfgPOSLAG-RB"
#define ethercatmcCfgPOSLAG_Tim_RBString     "CfgPOSLAG-Tim-RB"
#define ethercatmcCfgPOSLAG_En_RBString      "CfgPOSLAG-En-RB"
#define ethercatmcCfgDESC_RBString           "CfgDESC-RB"
#define ethercatmcCfgEGU_RBString            "CfgEGU-RB"


#define ethercatmcMCUErrMsgString            "MCUErrMsg"
#define ethercatmcDbgStrToMcuString          "StrToMCU"
#define ethercatmcDbgStrToLogString          "StrToLOG"

#define HOMPROC_MANUAL_SETPOS    15

extern const char *modNamEMC;


/**********************************************************************/
#define ethercatmchexdump(pasynUser, tracelevel, help_txt, bufptr, buflen)\
{\
  const void* buf = (const void*)bufptr;\
  int len = (int)buflen;\
  uint8_t *data = (uint8_t *)buf;\
  int count;\
  unsigned pos = 0;\
  while (len > 0) {\
    struct {\
      char asc_txt[8];\
      char space[2];\
      char hex_txt[8][3];\
      char nul;\
    } print_buf;\
    memset(&print_buf, ' ', sizeof(print_buf));\
    print_buf.nul = '\0';\
    for (count = 0; count < 8; count++) {\
      if (count < len) {\
        unsigned char c = (unsigned char)data[count];\
        if (c >= 0x20 && c < 0x7F)\
          print_buf.asc_txt[count] = c;\
        else\
          print_buf.asc_txt[count] = '.';\
        snprintf((char*)&print_buf.hex_txt[count],\
                 sizeof(print_buf.hex_txt[count]),\
                 "%02x", c);\
        /* Replace NUL with ' ' after snprintf */\
        print_buf.hex_txt[count][2] = ' ';\
      }\
    }\
    asynPrint(pasynUser, tracelevel,\
              "%s%s [%02x]%s\n",\
              modNamEMC, help_txt, pos, (char*)&print_buf);\
    len -= 8;\
    data += 8;\
    pos += 8;\
  }\
}\
/**********************************************************************/


extern "C" {
  /* Struct to handle additional (PILS) devices.
     Create a conversion table, to map the PILS devices
     into the asynParameter library and vice-versa */
  typedef struct {
    int            axisNo;      /* 0 is the controller */
    unsigned       inputOffset; /* offset inside the "plc memory bytes" */
    unsigned       outputOffset; /* offset inside the "plc memory bytes" */
    unsigned       statusOffset; /* offset inside the "plc memory bytes" */
    unsigned       lenInPLC;    /* len  inside the "plc memory bytes" */
    int            function;    /* asyn: "function" */
    asynParamType  myEPICSParamType; /* asynParamType.h */
    unsigned       iTypCode;
    int            isSystemUTCtime:1;
  } pilsAsynDevInfo_type;
}
extern "C" {
  unsigned   netToUint(const void *data, size_t lenInPlc);
  int        netToSint(const void *data, size_t lenInPlc);
  double     netToDouble(const void *data, size_t lenInPlc);
  uint64_t   netToUint64(const void *data, size_t lenInPlc);
  int64_t    netToSint64(const void *data, size_t lenInPlc);
  void       doubleToNet(const double value, void *data, size_t lenInPlc);
  void       uintToNet(const unsigned value, void *data, size_t lenInPlc);
  int ethercatmcCreateAxis(const char *ethercatmcName, int axisNo,
                           int axisFlags, const char *axisOptionsStr);

  asynStatus ethercatmcADSgetPlcMemoryUintFL(asynUser *pasynUser,
                                             unsigned indexOffset,
                                             unsigned *value,
                                             size_t lenInPlc,
                                             const char *fileName,
                                             int lineNo);
  asynStatus disconnect_C(asynUser *pasynUser);
  asynStatus writeReadOnErrorDisconnect_C(asynUser *pasynUser,
                                          const char *outdata, size_t outlen,
                                          char *indata, size_t inlen);
  asynStatus checkACK(const char *outdata, size_t outlen, const char *indata);
  const char *plcUnitTxtFromUnitCode(unsigned unitCode);
  const char *plcParamIndexTxtFromParamIndex(unsigned paramIndex);
  int paramIndexIsIntegerV2(unsigned paramIndex);
  int paramIndexIsMovingFunction(unsigned paramIndex);
  int paramIndexIsParameterToPoll(unsigned paramIndex);
  const char *ethercatmcstrStatus(asynStatus status);
  const char *errStringFromErrId(int nErrorId);
  const char *stringFromAsynParamType(asynParamType);
  double calcSleep(int counter);
  int paramIndexIsReadLaterInBackground(unsigned paramIndex);
}
#define NETTOUINT(n)       netToUint((const void*)&n, sizeof(n))
#define NETTODOUBLE(n)     netToDouble((const void*)&n, sizeof(n))
#define UINTTONET(val,n)   uintToNet((val), (&n), sizeof(n))
#define DOUBLETONET(val,n) doubleToNet((val), (&n), sizeof(n))

class ethercatmcIndexerAxis;

class epicsShareClass ethercatmcController : public asynMotorController {
public:
#define PARAM_IDX_OPMODE_AUTO_UINT            1
#define PARAM_IDX_MICROSTEPS_UINT             2
#define PARAM_IDX_ABS_MIN_FLOAT              30
#define PARAM_IDX_ABS_MAX_FLOAT              31
#define PARAM_IDX_USR_MIN_FLOAT              32
#define PARAM_IDX_USR_MAX_FLOAT              33
#define PARAM_IDX_WRN_MIN_FLOAT              34
#define PARAM_IDX_WRN_MAX_FLOAT              35
#define PARAM_IDX_FOLLOWING_ERR_WIN_FLOAT    55
#define PARAM_IDX_HYTERESIS_FLOAT            56
#define PARAM_IDX_REFSPEED_FLOAT             58
#define PARAM_IDX_VBAS_FLOAT                 59
#define PARAM_IDX_SPEED_FLOAT                60
#define PARAM_IDX_ACCEL_FLOAT                61
#define PARAM_IDX_IDLE_CURRENT_FLOAT         62
#define PARAM_IDX_MOVE_CURRENT_FLOAT         64
#define PARAM_IDX_MICROSTEPS_FLOAT           67
#define PARAM_IDX_STEPS_PER_UNIT_FLOAT       68
#define PARAM_IDX_HOME_POSITION_FLOAT        69

#define PARAM_IDX_FUN_REFERENCE             133
#define PARAM_IDX_FUN_SET_POSITION          137
#define PARAM_IDX_FUN_MOVE_VELOCITY         142

/* Implementation defined, integer */
#define PARAM_IDX_USR_MIN_EN_UINT           192
#define PARAM_IDX_USR_MAX_EN_UINT           193
#define PARAM_IDX_HOMPROC_UINT              194
/* Implementation defined, floating point */
#define PARAM_IDX_USR_MIN_EN_FLOAT          218
#define PARAM_IDX_USR_MAX_EN_FLOAT          219
#define PARAM_IDX_HOMPROC_FLOAT             220
#define PARAM_IDX_UNITS_PER_REV_FLOAT       221
#define PARAM_IDX_STEPS_PER_REV_FLOAT       222
#define PARAM_IDX_MAX_VELO_FLOAT            223

#define FEATURE_BITS_V1               (1)
#define FEATURE_BITS_V2               (1<<1)
#define FEATURE_BITS_V3               (1<<2)
#define FEATURE_BITS_V4               (1<<3)

#define FEATURE_BITS_ADS              (1<<4)
#define FEATURE_BITS_ECMC             (1<<5)
#define FEATURE_BITS_SIM              (1<<6)

  ethercatmcController(const char *portName, const char *ethercatmcPortName,
                       int numAxes, double movingPollPeriod,
                       double idlePollPeriod,
                       const char *optionStr);
  /* Note: the motor/master version does not have it, so we need it here */
  asynStatus writeOctet(asynUser *pasynUser, const char *value,
                        size_t nChars, size_t *nActual);
  void report(FILE *fp, int level);
  asynStatus configController(int needOk, const char *value);
  asynStatus ethercatmcCreateParam(const char *paramName,
                                   asynParamType myEPICSParamType,
                                   int *function);
  asynStatus ethercatmcStartPoller(double movingPollPeriod,
                                   double idlePollPeriod);
  asynStatus writeReadOnErrorDisconnect(void);
  void setAlarmStatusSeverityAllReadbacks(asynStatus status);
  void setAlarmStatusSeverityAllAxes(int function, asynStatus status);
  void setAlarmStatusSeverityWrapper(int axisNo, int function,
                                     asynStatus status);
  ethercatmcAxis* getAxis(asynUser *pasynUser);
  ethercatmcAxis* getAxis(int axisNo);
  int features_;

  protected:
  void udateMotorLimitsRO(int axisNo);
  void udateMotorLimitsRO(int axisNo, int enabledHighAndLow,
                          double fValueHigh, double fValueLow);
  void handleStatusChangeFL(asynStatus status,
                            const char *fileName,
                            int lineNo);
#define  handleStatusChange(a) handleStatusChangeFL(a, __FILE__, __LINE__);
  asynStatus writeReadControllerADS(asynUser *pasynUser,
                                    const char *outdata,
                                    size_t outlen,
                                    char *indata, size_t inlen,
                                    size_t *pnread,
                                    const char *fileName,
                                    int lineNo);

  /* memory bytes via ADS */
  asynStatus writeReadAds(asynUser *pasynUser,
                          AmsHdrType *amsHdr_p, size_t outlen,
                          uint16_t targetAdsport,
                          uint32_t invokeID,
                          uint32_t ads_cmdID,
                          void *indata, size_t inlen,
                          size_t *pnread,
                          const char *fileName,
                          int lineNo);
  asynStatus getPlcMemoryViaADSFL(unsigned indexOffset,
                                  void *data, size_t lenInPlc,
                                  const char *fileName,
                                  int lineNo);
  asynStatus setMemIdxGrpIdxOffFL(unsigned indexGroup,
                                  unsigned indexOffset,
                                  unsigned targetAdsport,
                                  const void *data,
                                  size_t lenInPlc,
                                  const char *fileName,
                                  int lineNo);
  asynStatus setPlcMemoryViaADSFL(unsigned indexOffset,
                                  const void *data, size_t lenInPlc,
                                  const char *fileName,
                                  int lineNo);

/* Re-definition */
#define setMemIdxGrpIdxOff(a,b,c,d,e) setMemIdxGrpIdxOffFL(a,b,c,d,e,__FILE__, __LINE__)
#define getPlcMemoryViaADS(a,b,c)           getPlcMemoryViaADSFL(a,b,c,__FILE__, __LINE__)
#define setPlcMemoryViaADS(a,b,c)           setPlcMemoryViaADSFL(a,b,c,__FILE__, __LINE__)

  /* Wrapper  */
  asynStatus getPlcMemoryOnErrorStateChangeFL(unsigned indexOffset,
                                              void *data, size_t lenInPlc,
                                              const char *fileName,
                                              int lineNo);
  asynStatus setPlcMemoryOnErrorStateChangeFL(unsigned indexOffset,
                                              const void *data, size_t lenInPlc,
                                              const char *fileName,
                                              int lineNo);

  asynStatus getSymbolInfoViaADS(const char *symbolName,
                                 void *data,
                                 size_t lenInPlc);
  asynStatus getSymbolHandleByNameViaADS(const char *symbolName,
                                         uint32_t *handle);

  asynStatus setSAFIntegerOnAxisViaADSFL(unsigned indexGroup,
                                         unsigned indexOffset,
                                         int      value,
                                         size_t   lenInPlc,
                                         const char *fileName,
                                         int lineNo);

#define setSAFIntegerOnAxisViaADS(a,b,c,d) setSAFIntegerOnAxisViaADSFL(a,b,c,d,__FILE__, __LINE__)

  asynStatus setSAFDoubleOnAxisViaADSFL(unsigned indexGroup,
                                        unsigned indexOffset,
                                        double   value,
                                        size_t   lenInPlc,
                                        const char *fileName,
                                        int lineNo);
#define setSAFDoubleOnAxisViaADS(a,b,c,d) setSAFDoubleOnAxisViaADSFL(a,b,c,d,__FILE__, __LINE__)

  /* Indexer */
  asynStatus readDeviceIndexerFL(unsigned devNum, unsigned infoType,
                                 const char *fileName,
                                 int lineNo);
#define readDeviceIndexer(a,b) readDeviceIndexerFL(a,b,__FILE__, __LINE__)
  asynStatus readMailboxV3FL(unsigned mbxNum, void *bufptr, size_t buflen,
                             const char *fileName, int lineNo);
#define readMailboxV3(a,b,c) readMailboxV3FL(a,b,c, __FILE__, __LINE__)

asynStatus indexerV3readParameterEnums(ethercatmcIndexerAxis *pAxis,
                                       unsigned parameterIndex,
                                       unsigned enumparam_read_id,
                                       unsigned defaultLenInPlcPara);

  asynStatus indexerV3readParameterDescriptors(ethercatmcIndexerAxis *pAxis,
                                               unsigned descID,
                                               unsigned target_param_descriptor_id,
                                               unsigned defaultLenInPlcPara);
  asynStatus indexerV3readAuxbits(ethercatmcIndexerAxis *pAxis,
                                  unsigned descID);
  asynStatus indexerV3addDevice(unsigned devNum,
                                int axisNo,
                                unsigned iOffsBytes,
                                unsigned string_description_id,
                                unsigned target_param_descriptor_id,
                                unsigned auxbits_bitfield_flag_descriptor_id,
                                unsigned parameters_descriptor_id,
                                unsigned enum_errorId_descriptor_id,
                                unsigned type_code,
                                unsigned device_offset,
                                unsigned device_flags,
                                const char *device_name);

  int paramIndexToFunction(unsigned paramIndex);
  void parameterFloatReadBack(unsigned axisNo,
                              int initial,
                              unsigned paramIndex,
                              double fValue);
  asynStatus indexerReadAxisParameters(ethercatmcIndexerAxis *pAxis,
                                       unsigned devNum);
  asynStatus indexerReadAxisParametersV2(ethercatmcIndexerAxis *pAxis,
                                         unsigned devNum);
  asynStatus poll(void);
  asynStatus newIndexerAxisAuxBitsV2(ethercatmcIndexerAxis *pAxis,
                                     unsigned axisNo,
                                     unsigned devNum,
                                     unsigned iAllFlags,
                                     double   fAbsMin,
                                     double   fAbsMax,
                                     unsigned iOffset);
  asynStatus newIndexerAxisV3(ethercatmcIndexerAxis *pAxis,
                              unsigned target_param_descriptor_id,
                              unsigned auxbits_bitfield_flag_descriptor_id,
                              unsigned parameters_descriptor_id);
  asynStatus updateCfgValue(int axisNo_, int function,
                            double newValue, const char *name);
  asynStatus updateCfgValue(int axisNo_, int function,
                            int newValue, const char *name);
  asynStatus getFeatures(int *pRet);
  asynStatus indexerInitialPoll(void);
  asynStatus indexerInitialPollv2(void);
  asynStatus indexerInitialPollv3(void);
  asynStatus indexerPoll(void);
  void        indexerDisconnected(void);
  asynStatus writeReadControllerPrint(int traceMask);
  asynStatus writeReadACK(int traceMask);
  asynStatus getPlcMemoryUintFL(unsigned indexOffset,
                                unsigned *value, size_t lenInPlc,
                                const char *fileName,
                                int lineNo);
#define getPlcMemoryUint(a,b,c)   getPlcMemoryUintFL(a,b,c,__FILE__, __LINE__)
  asynStatus setPlcMemoryInteger(unsigned indexOffset,
                                 int value, size_t lenInPlc);
  asynStatus getPlcMemoryDouble(unsigned indexOffset,
                                double *value, size_t lenInPlc);
  asynStatus setPlcMemoryDouble(unsigned indexOffset,
                                double value, size_t lenInPlc);

  asynStatus indexerWaitSpecialDeviceIdle(unsigned indexOffset);
  asynStatus indexerParamReadFL(ethercatmcIndexerAxis *pAxis,
                                unsigned paramIfOffset,
                                unsigned paramIndex,
                                double *value,
                                const char *fileName,
                                int lineNo);
#define indexerParamRead(a,b,c,d) indexerParamReadFL(a,b,c,d,__FILE__, __LINE__)
  asynStatus indexerParamWrite(ethercatmcIndexerAxis *pAxis,
                               unsigned paramIndex,
                               double value,
                               double *pValueRB);

  asynStatus getPlcMemoryFromProcessImage(unsigned indexOffset,
                                          void *data, size_t lenInPlc);
  int  addPilsAsynDevLst(int           axisNo,
                         const char    *paramName,
                         unsigned      lenInPLC,
                         unsigned      inputOffset,
                         unsigned      outputOffset,
                         unsigned      statusOffset,
                         asynParamType myEPICSParamType,
                         unsigned      iTypCode);

  int newPilsAsynDevice(int      axisNo,
                        unsigned indexOffset,
                        unsigned iTypCode,
                        const char *paramName);

  pilsAsynDevInfo_type *findIndexerOutputDevice(int axisNo,
                                                int function,
                                                asynParamType myEPICSParamType);

  void changedAuxBits_to_ASCII(int         axisNo,
                               epicsUInt32 statusReasonAux,
                               epicsUInt32 oldStatusReasonAux);

  struct {
    uint8_t      *pIndexerProcessImage;
    asynStatus   oldStatus;
    unsigned int cntADSstatus;
    unsigned int local_no_ASYN_;
    unsigned int hasConfigError;
    unsigned int initialPollDone;
    unsigned int indexerOffset;
    unsigned int firstDeviceStartOffset;
    unsigned int lastDeviceEndOffset;
    unsigned int specialDbgStrToMcuDeviceLength;
    unsigned int specialDbgStrToMcuDeviceOffset;
    unsigned int systemUTCtimeOffset;

    AmsNetidAndPortType remote;
    AmsNetidAndPortType local;
    unsigned adsport;
    int useADSbinary;
    struct {
      unsigned int stAxisStatus_V1  :1;
      unsigned int stAxisStatus_V2  :1;
      unsigned int bSIM             :1;
      unsigned int bECMC            :1;
      unsigned int bADS             :1;
      unsigned int bPILSv2          :1;
      unsigned int bPILSv3          :1;
    } supported;
    pilsAsynDevInfo_type pilsAsynDevInfo[50]; /* TODO: dynamic allocation */
    unsigned numPilsAsynDevInfo;
    int lockADSlineno;
    char changedAuxBits[MAX_REASON_AUX_BIT_SHOW][36];
  } ctrlLocal;


  /* First parameter */
  int ethercatmcMcuErr_;            /* Motion Control Unit reports an error */
  int ethercatmcStatusCode_;        /* PILS status code (BUSY/START/IDLE...) */
  int ethercatmcStatusBits_;        /* PILS Bit 25+24 and Aux bits 23..0 */
  int ethercatmcAuxBits07_;
  int ethercatmcNamAux0_;           /* Name of the AUX bits */
  int ethercatmcNamAux1_;
  int ethercatmcNamAux2_;
  int ethercatmcNamAux3_;
  int ethercatmcNamAux4_;
  int ethercatmcNamAux5_;
  int ethercatmcNamAux6_;
  int ethercatmcNamAux7_;
  int ethercatmcNamAux8_;
  int ethercatmcNamAux9_;
  int ethercatmcNamAux10_;
  int ethercatmcNamAux11_;
  int ethercatmcNamAux12_;
  int ethercatmcNamAux13_;
  int ethercatmcNamAux14_;
  int ethercatmcNamAux15_;
  int ethercatmcNamAux16_;
  int ethercatmcNamAux17_;
  int ethercatmcNamAux18_;
  int ethercatmcNamAux19_;
  int ethercatmcNamAux20_;
  int ethercatmcNamAux21_;
  int ethercatmcNamAux22_;
  int ethercatmcNamAux23_;
  int ethercatmcNamBit24_;
  int ethercatmcNamBit25_;
  int ethercatmcFoffVis_;           /* FOFF visible in GUI: motor can be calibrated with setPosition() */
  int ethercatmcHomeVis_;           /* HOMF/HOMR visible in GUI (motor can be calibrated with a homing sequence */
  int ethercatmcHomProc_RB_;        /* Homing procedure (even called homing sequence) from MCU */
  int ethercatmcHomPos_RB_;         /* Position of home sensor/switch, debug only */
  int ethercatmcHomProc_;           /* Homing procedure towards the MCU, for testing only, to be removed ? */
  int ethercatmcHomPos_;            /* Homing position towards the MCU, for testing only, to be removed ?  */
  int ethercatmcVelToHom_;          /* Homing velocity towards CAM, ethercatmcAxis only, to be removed ? */
  int ethercatmcVelFrmHom_;         /* Homing velocity from CAM, ethercatmcAxis only, to be removed ? */
  int ethercatmcRawEncStep_;        /* Raw encoder steps on the terminal, debug only */
  int ethercatmcRawMtrStep_;        /* Raw motor steps on the terminal, debug only */
  int ethercatmcRawMtrVelo_;        /* Raw motor veloclty on the terminal, debug only */

#ifdef CREATE_MOTOR_REC_RESOLUTION
  int motorRecResolution_;
  int motorRecDirection_;
  int motorRecOffset_;
#endif

  /* Add parameters here */
  int ethercatmcErrRst_;            /* Soft reset of an axis */
  int ethercatmcDbgStrToMcu_;       /* Messages to the simulator or MCU ?. To be reviewed */
  int ethercatmcDbgStrToLog_;       /* Message to show up in the IOC log, test and debug only */
  int ethercatmcVelAct_;            /* Actual velocity. Measured in the MCU (typically with Jitter */
  int ethercatmcVel_RB_;            /* Velocity used in MCU */
  int ethercatmcAcc_RB_;            /* Acceleration used in MCU */
  int ethercatmcPTPState_;          /* PTP */
  int ethercatmcPTPOffset_;
  int ethercatmcPTPSyncSeqNum_;
  int ethercatmcSystemUTCtime_;
  int ethercatmcDCTIME_;            /* "Distributed Clock time" */
  int ethercatmcRBV_TSE_;           /* motor position (RBV in motorRecord) MCU time stamped */
  int pilsLonginActual_;
  int pilsLonginTarget_;
  int pilsLongoutRecord_;
  int pilsBoMinMax_;                /* bo record: Binary Out, driving to minimum/maximum */
  int pilsBiAtMax_;                 /* bi record: Binary In, is at the maximum (e.g. shutter) */
  int pilsBiAtMin_;                 /* bi record: Binary In, is at the minimum (e.g. shutter) */
  int ethercatmcCfgVELO_RB_;        /* configuration values from the MCU */
  int ethercatmcCfgVMAX_RB_;
  int ethercatmcCfgJVEL_RB_;
  int ethercatmcCfgHVEL_RB_;
  int ethercatmcCfgACCS_RB_;
  int ethercatmcCfgSREV_RB_;
  int ethercatmcCfgUREV_RB_;
  int ethercatmcCfgPMIN_RB_;        /* "PILS Min", AKA AbsMin */
  int ethercatmcCfgPMAX_RB_;        /* "PILS Max", AKA AbsMax */
  int ethercatmcCfgSPDB_RB_;
  int ethercatmcCfgRDBD_RB_;
  int ethercatmcCfgRDBD_Tim_RB_;
  int ethercatmcCfgRDBD_En_RB_;
  int ethercatmcCfgPOSLAG_RB_;
  int ethercatmcCfgPOSLAG_Tim_RB_;
  int ethercatmcCfgPOSLAG_En_RB_;
  int ethercatmcCfgDHLM_RB_;
  int ethercatmcCfgDLLM_RB_;
  int ethercatmcCfgDHLM_En_RB_;
  int ethercatmcCfgDLLM_En_RB_;
  int ethercatmcCfgDHLM_;
  int ethercatmcCfgDLLM_;
  int ethercatmcCfgDHLM_En_;
  int ethercatmcCfgDLLM_En_;
  int ethercatmcCfgDESC_RB_;
  int ethercatmcCfgEGU_RB_;

  int ethercatmcErrId_;
  /* Last parameter */


#define EMC_ENTER_ADS_CHECK_LOCK(LINENO) do {                           \
    if (ctrlLocal.lockADSlineno) {                                      \
      asynPrint(this->pasynUserSelf, ASYN_TRACE_ERROR,                  \
                "%s lockADSlineno=%d\n",                                \
                "ethercatmcADS", ctrlLocal.lockADSlineno);              \
    }                                                                   \
    ctrlLocal.lockADSlineno = LINENO;                                   \
  } while (0)


#define EMC_LEAVE_ADS_CHECK_LOCK(LINENO) do {   \
    if (!ctrlLocal.lockADSlineno) {                                     \
      asynPrint(this->pasynUserSelf, ASYN_TRACE_ERROR,                  \
                "%s lockADSlineno=%d\n",                                \
                "ethercatmcADS", LINENO);                               \
    }                                                                   \
    ctrlLocal.lockADSlineno = 0;                                        \
  } while (0)

  friend class ethercatmcAxis;
  friend class ethercatmcIndexerAxis;
};

#endif
