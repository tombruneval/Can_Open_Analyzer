#ifndef INDEX_H_INCLUDED
#define INDEX_H_INCLUDED
#include "Common.h"
#include "ErrorIndex.h"
#include "PDOIndex.h"
#include "SDOIndex.h"
#include "BMSIndex.h"

void CompareWithDefinesRadio(tNode *nNodeType, bool fChoice, bool RWChoice);
void CompareWithDefinesIO(tNode *nNodeType, bool fChoice, bool RWChoice);
void CompareWithDefinesEDS(tNode *nNodeType, bool fChoice, bool RWChoice);
void CompareWithDefinesGuidance(tNode *nNodeType, bool fChoice, bool RWChoice);
void CompareWithDefinesDrivers(tNode *nNodeType, bool fChoice, bool RWChoice);
void CompareWithDefinesRFH6x0(tNode *nNodeType, bool fChoice, bool RWChoice);
void CompareWithDefinesDTM425(tNode *nNodeType, bool fChoice, bool RWChoice);
void CompareWithDefinesPCU(tNode *nNodeType, bool fChoice, bool RWChoice);

void AnalyzeBMS();

void PDODetailsEDS (tNode *nNodeType, bool fChoice);
void PDODetailsIO (tNode *nNodeType, bool fChoice);
void PDODetailsRadio (tNode *nNodeType, bool fChoice);
void PDODetailsGuidance (tNode *nNodeType, bool fChoice);
void PDO1DetailsDrivers (tNode *nNodeType, bool fChoice);
void PDO2DetailsDrivers (tNode *nNodeType, bool fChoice);
void PDO3DetailsDrivers (tNode *nNodeType, bool fChoice);

void IndexDetails7BytesRead(tNode *nNodeType);
void IndexDetails4BytesRead(tNode *nNodeType);
void IndexDetails7BytesWrite(tNode *nNodeType);
void IndexDetails4BytesWrite(tNode *nNodeType);

void CompareErrorCodesRadio(bool fChoice);
void CompareErrorCodesIO(bool fChoice);
void CompareErrorCodesEDS(bool fChoice);
void CompareErrorCodesGuidance(bool fChoice);
void CompareErrorCodesDrivers(bool fChoice);
void CompareErrorCodesPCU(bool fChoice);
void CompareErrorRegistersAll(bool fChoice);
void AnalyzeEMCYContent(tNode *nNodeType, bool fChoice);

void CompareFaultAlarmCodes(bool fChoice, int FaultNbr);
void CompareObjCmd(bool fChoice, char Obj, char Cmd);

#endif 
