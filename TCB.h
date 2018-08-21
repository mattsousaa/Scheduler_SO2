#ifndef TCB_H
#define TCB_H
typedef struct startTCB STARTTCB;
typedef struct tcb TCB;
// DEFINIÇÕES DA CABEÇA DA LISTA
STARTTCB* createStartTCB();
int setStartTCB(STARTTCB* ConsStartTCB,TCB* FirstTCB);
int setNumberAperiodicTasks(STARTTCB* ConsStartTCB,int Number);
int setNumberPeriodicTasks(STARTTCB* ConsStartTCB,int Number);
int setTotalNumberTasks(STARTTCB* ConsStartTCB,int Number);
TCB* getStartTCB(STARTTCB* ConsStartTCB);
int getNumberAperiodicTasks(STARTTCB* ConsStartTCB);
int getNumberPeriodicTasks(STARTTCB* ConsStartTCB);
int getTotalNumberTasks(STARTTCB* ConsStartTCB);
//DEFINIÇÕES DA LISTA
TCB* createTCB(STARTTCB* Starttcb,int type,int relativeDeadline,int period,int executionTime,int priority);
int addElementTCB(STARTTCB* ValSTARTTCB, TCB* NewTCB);
int removeElementTCB(STARTTCB* ValSTARTTCB, int IDTask);

int setIdtask(TCB* task,int newVal);
int setType(TCB* task,int newType);
int setState(TCB* task,int newState);
int setRelativeDeadline(TCB* task,int newRelativeDeadline);
int setAbsoluteDeadline(TCB* task,int newAbsoluteDeadline);
int setPeriod(TCB* task,int newPeriod);
int setExecutionTimer(TCB* task,int newExecutionTimer);
int setFlag(TCB* task,int newValFlag);
int setNextTCB(TCB* task,TCB* newNextTCB);
int setPrevTCB(TCB* task,TCB* newPrevTCB);
int setPriority(TCB* task,int priority);
int setTimeComputed(TCB* task,int i);
int setFlagWAIT(TCB* task,int val);
int setFlagIDLE(TCB* task,int val);

int getIdtask(TCB* task);
int getType(TCB* task);
int getState(TCB* task);
int getRelativeDeadline(TCB* task);
int getAbsoluteDeadline(TCB* task);
int getPeriod(TCB* task);
int getExecutionTimer(TCB* task);
int getFlag(TCB* task);
int getPriority(TCB* task);
TCB* getNextTCB(TCB* task);
TCB* getPrevTCB(TCB* task);
int getTimeComputed(TCB* task);
int getFlagWAIT(TCB* task);
int getFlagIDLE(TCB* task);
        
#endif /* TCB_H */