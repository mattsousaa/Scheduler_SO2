#include "CAB.h"
typedef struct Scab{
    unsigned int msg[50];
    unsigned int flagCount;
    struct Scab* next;
    struct Scab* prev;
}CAB;
/*******************   GETs    ******************/
int getMsg(CAB* cab){
    return cab->msg;
}
int getMsgAtual(CAB* cab){

}
int getFlagCounter(CAB* cab);
CAB* getNextCAB(CAB* cab);
CAB* getPrevCAB(CAB* cab);
/*******************   SETs    ******************/
int setMsg(CAB* cab,int msg);
int setFlagCounter(CAB* cab,int val);
CAB* setNextCAB(CAB* cab,CAB* NewNextCAB);
CAB* setPrevCAB(CAB* cab,CAB* NewPrevCAB);