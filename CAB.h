#ifndef CAB_H
#define CAB_H
#include "IMPORTS.h"
typedef struct Scab CAB;
CAB* createCAB();
/*******************   GETs    ******************/
int getMsg(CAB* cab);
int getMsgAtual(CAB* cab);
int getFlagCounter(CAB* cab);
CAB* getNextCAB(CAB* cab);
CAB* getPrevCAB(CAB* cab);
/*******************   SETs    ******************/
int setMsg(CAB* cab,int msg);
int setFlagCounter(CAB* cab,int val);
CAB* setNextCAB(CAB* cab,CAB* NewNextCAB);
CAB* setPrevCAB(CAB* cab,CAB* NewPrevCAB);
#endif /* CAB_H */

