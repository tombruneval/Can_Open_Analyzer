#ifndef AUTOMATE_H
#define AUTOMATE_H
#include "Common.h"

extern tNode nRadio;
extern tNode nIO;
extern tNode nEDS;
extern tNode nGuidance;
extern tNode nLDriver;
extern tNode nRDriver;
extern tNode nRFH6x0;
extern tNode nDTM425;
extern tNode nPCU;

void DetermineProtocolSDO(tNode *nNodeType);
void DetermineProtocolSDORead(tNode *nNodeType);
void DetermineProtocolSDOWrite(tNode *nNodeType);

#endif // AUTOMATE_H_INCLUDED
