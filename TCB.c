#include "DEFINES_GLOBAIS.h"
#include "IMPORTS.h"
#include "TCB.h"
typedef struct tcb{
    int Idtask; // ID Atribuido
    int type; // Hard ou Não Hard
    int state; //Estado do processo
    int relativeDeadline; //Deadline relativo
    int absoluteDeadeline;//Deadline absoluto
    int period; //período
    int executionTime;// tempo de execucao
    int flag; // Caso tenha passado do deadline será TRUE
    int flagIDLE;
    int flagWAIT;
    int priority; //prioridade
    int timeComputed; //tempo já computado
    struct tcb *  next;
    struct tcb *  prev;
}TCB;
typedef struct startTCB{
    int numberAperiodicTasks;
    int numberPeriodicTasks;
    int TotalNumberTasks;
    TCB * firstTCB;
} STARTTCB;

/*-------------------------------   FIRST   -----------------------*/
TCB* getStartTCB(STARTTCB* ConsStartTCB){
    if(!(ConsStartTCB==PONTNULL)){
        return ConsStartTCB->firstTCB;
    }else{
        return SYS_ERROR_POINT_NULL;
    }
}
int setStartTCB(STARTTCB* ConsStartTCB,TCB* FirstTCB){
    if((ConsStartTCB != PONTNULL)||(FirstTCB != PONTNULL)){
        ConsStartTCB->firstTCB = FirstTCB;
    }else{
        return SYS_ERROR_POINT_NULL;
    }
}
int setNumberAperiodicTasks(STARTTCB* ConsStartTCB,int Number){
    if(ConsStartTCB!=PONTNULL){
        ConsStartTCB->numberAperiodicTasks=Number;
    }else{
        return SYS_ERROR_POINT_NULL;
    }
}
int setNumberPeriodicTasks(STARTTCB* ConsStartTCB,int Number){
    if(ConsStartTCB!=PONTNULL){
        ConsStartTCB->numberPeriodicTasks=Number;
    }else{
        return SYS_ERROR_POINT_NULL;
    }
}
int setTotalNumberTasks(STARTTCB* ConsStartTCB,int Number){
    if(ConsStartTCB!=PONTNULL){
        ConsStartTCB->TotalNumberTasks=Number;
    }else{
        return SYS_ERROR_POINT_NULL;
    }
}
int getNumberAperiodicTasks(STARTTCB* ConsStartTCB){
    if(ConsStartTCB!=PONTNULL){
        return ConsStartTCB->numberAperiodicTasks;
    }else{
        return SYS_ERROR_POINT_NULL;
    }
}
int getNumberPeriodicTasks(STARTTCB* ConsStartTCB){
    if(ConsStartTCB!=PONTNULL){
        return ConsStartTCB->numberPeriodicTasks;
    }else{
        return SYS_ERROR_POINT_NULL;
    }
}
int getTotalNumberTasks(STARTTCB* ConsStartTCB){
    if(ConsStartTCB!=PONTNULL){
        return ConsStartTCB->TotalNumberTasks;
    }else{
        return SYS_ERROR_POINT_NULL;
    }
}
STARTTCB* createStartTCB(){
    STARTTCB* STARTTCBCreated = (STARTTCB*) malloc(sizeof(STARTTCB));
    if(STARTTCBCreated==PONTNULL){
        return SYS_ERROR_POINT_NULL;        
    }
    setStartTCB(STARTTCBCreated,PONTNULL);
    setNumberAperiodicTasks(STARTTCBCreated,0);
    setNumberPeriodicTasks(STARTTCBCreated,0);
    setTotalNumberTasks(STARTTCBCreated,0);
    return STARTTCBCreated;
}
/****************** SETs DO TCB **********************/
int setIdtask(TCB* task,int newVal){
    if(!(task==PONTNULL)){
        task->Idtask = newVal;
    }else{
        return SYS_ERROR_POINT_NULL;
    }
    return SUCESS;
}
int setType(TCB* task,int newType){
    if(!(task==PONTNULL)){
        task->type = newType;
    }else{
        return SYS_ERROR_POINT_NULL;
    }
    return SUCESS;
}
int setState(TCB* task,int newState){
    if(!(task==PONTNULL)){
        task->state = newState;
    }else{
        return SYS_ERROR_POINT_NULL;
    }
    return SUCESS;
}
int setRelativeDeadline(TCB* task,int newRelativeDeadline){
    if(!(task==PONTNULL)){
        task->relativeDeadline = newRelativeDeadline;
    }else{
        return SYS_ERROR_POINT_NULL;
    }
    return SUCESS;
}
int setAbsoluteDeadline(TCB* task,int newAbsoluteDeadline){
    if(!(task==PONTNULL)){
        task->absoluteDeadeline = newAbsoluteDeadline;
    }else{
        return SYS_ERROR_POINT_NULL;
    }
    return SUCESS;
}
int setPeriod(TCB* task,int newPeriod){
    if(!(task==PONTNULL)){
        task->period = newPeriod;
    }else{
        return SYS_ERROR_POINT_NULL;
    }
    return SUCESS;
}
int setExecutionTimer(TCB* task,int newExecutionTimer){
    if(!(task==PONTNULL)){
        task->executionTime = newExecutionTimer;
    }else{
        return SYS_ERROR_POINT_NULL;
    }
    return SUCESS;
}
int setFlag(TCB* task,int newValFlag){
    if(!(task==PONTNULL)){
        task->flag = newValFlag;
    }else{
        return SYS_ERROR_POINT_NULL;
    }
    return SUCESS;
}
int setNextTCB(TCB* task,TCB* newNextTCB){
    if(!(task==PONTNULL)){
        task->next = newNextTCB;
    }else{
        return SYS_ERROR_POINT_NULL;
    }
    return SUCESS;
}
int setPrevTCB(TCB* task,TCB* newPrevTCB){
    if(!(task==PONTNULL)){
        task->prev = newPrevTCB;
    }else{
        return SYS_ERROR_POINT_NULL;
    }
    return SUCESS;
}
int setPriority(TCB* task,int priority){
    if(!(task==PONTNULL)){
        task->priority=priority;
    }else{
        return SYS_ERROR_POINT_NULL;
    }
    return SUCESS;
}
int setTimeComputed(TCB* task,int i){
    if(!(task==PONTNULL)){
        task->timeComputed = i;
    }else{
        return SYS_ERROR_POINT_NULL;
    }
    return SUCESS;
}
int setFlagWAIT(TCB* task,int val){
    if(!(task==PONTNULL)){
        task->flagWAIT=val;
    }else{
        return SYS_ERROR_POINT_NULL;
    }
    return SUCESS;
}
int setFlagIDLE(TCB* task,int val){
    if(!(task==PONTNULL)){
        task->flagIDLE=val;
    }else{
        return SYS_ERROR_POINT_NULL;
    }
    return SUCESS;
}
/****************** GETs DO TCB **********************/
int getIdtask(TCB* task){
    if(!(task==PONTNULL)){
        return task->Idtask;
    }else{
        return SYS_ERROR_POINT_NULL;
    }
}
int getType(TCB* task){
    if(!(task==PONTNULL)){
        return task->type;
    }else{
        return SYS_ERROR_POINT_NULL;
    }
}
int getState(TCB* task){
    if(!(task==PONTNULL)){
        return task->state;
    }else{
        return SYS_ERROR_POINT_NULL;
    }
}
int getRelativeDeadline(TCB* task){
    if(!(task==PONTNULL)){
        return task->relativeDeadline;
    }else{
        return SYS_ERROR_POINT_NULL;
    }
}
int getAbsoluteDeadline(TCB* task){
    if(!(task==PONTNULL)){
        return task->absoluteDeadeline;
    }else{
        return SYS_ERROR_POINT_NULL;
    }
}
int getPeriod(TCB* task){
    if(!(task==PONTNULL)){
        return task->period;
    }else{
        return SYS_ERROR_POINT_NULL;
    }
}
int getExecutionTimer(TCB* task){
    if(!(task==PONTNULL)){
        return task->executionTime;
    }else{
        return SYS_ERROR_POINT_NULL;
    }
}
int getFlag(TCB* task){
    if(!(task==PONTNULL)){
        return task->flag;
    }else{
        return SYS_ERROR_POINT_NULL;
    }
}
TCB* getNextTCB(TCB* task){
    if(!(task==PONTNULL)){
        return task->next;
    }else{
        return SYS_ERROR_POINT_NULL;
    }
}
TCB* getPrevTCB(TCB* task){
    if(!(task==PONTNULL)){
        return task->prev;
    }else{
        return SYS_ERROR_POINT_NULL;
    }
}
getPriority(TCB* task){
    if(!(task==PONTNULL)){
        return task->priority;
    }else{
        return SYS_ERROR_POINT_NULL;
    }
}
int getTimeComputed(TCB* task){
    if(!(task==PONTNULL)){
        return task->timeComputed;
    }else{
        return SYS_ERROR_POINT_NULL;
    }
}
int getFlagWAIT(TCB* task){
    if(!(task==PONTNULL)){
        return task->flagWAIT;
    }else{
        return SYS_ERROR_POINT_NULL;
    }
}
int getFlagIDLE(TCB* task){
    if(!(task==PONTNULL)){
        return task->flagIDLE;
    }else{
        return SYS_ERROR_POINT_NULL;
    }
}
/***************************  CREATE TCB   ***********************/
TCB* createTCB(STARTTCB* Starttcb,int type,int relativeDeadline,int period,int executionTime,int priority){
    TCB* TCBCreated = (TCB*)malloc(sizeof(TCB));
    if(TCBCreated==PONTNULL){
        return SYS_ERROR_POINT_NULL;
    }
    if(type==PERIODIC){
        if(getNumberPeriodicTasks(Starttcb)>=NUM_MAX_PERIODIC_TASKS){
            return SYS_ERROR_MAX_NUM_PERIODIC;
        }else{
            setType(TCBCreated,type);
            setState(TCBCreated,READY);
            setRelativeDeadline(TCBCreated,relativeDeadline);
            setAbsoluteDeadline(TCBCreated,relativeDeadline);
            setPeriod(TCBCreated,period);
            setExecutionTimer(TCBCreated,executionTime);
            setFlag(TCBCreated,FALSE);
            setPriority(TCBCreated,priority);
            setNextTCB(TCBCreated,PONTNULL);
            setPrevTCB(TCBCreated,PONTNULL);
            setTimeComputed(TCBCreated,0);
            setFlagIDLE(TCBCreated,FALSE);
            setFlagWAIT(TCBCreated,FALSE);
        }
    }else{
        if(getNumberAperiodicTasks(Starttcb)>=NUM_MAX_APERIODIC_TASKS){
            return SYS_ERROR_MAX_NUM_APERIODIC;
        }else{
            setType(TCBCreated,type);
            setState(TCBCreated,READY);
            setRelativeDeadline(TCBCreated,relativeDeadline);
            setAbsoluteDeadline(TCBCreated,relativeDeadline);
            setPeriod(TCBCreated,period);
            setExecutionTimer(TCBCreated,executionTime);
            setFlag(TCBCreated,FALSE);
            setPriority(TCBCreated,priority);
            setNextTCB(TCBCreated,PONTNULL);
            setPrevTCB(TCBCreated,PONTNULL);
            setTimeComputed(TCBCreated,0);
            setFlagIDLE(TCBCreated,FALSE);
            setFlagWAIT(TCBCreated,FALSE);
        }
    }    
    return TCBCreated;
}
int addElementTCB(STARTTCB* ValSTARTTCB, TCB* NewTCB){
    if((ValSTARTTCB==PONTNULL)||(NewTCB==PONTNULL)){        
        return SYS_ERROR_POINT_NULL;
    }else{
        if(getStartTCB(ValSTARTTCB)!=PONTNULL){            
            TCB * atual = getStartTCB(ValSTARTTCB);
            while(getNextTCB(atual)!=PONTNULL){
                atual=getNextTCB(atual);                
            }          
            setNextTCB(atual,NewTCB);
            setPrevTCB(NewTCB,atual);                        
            setIdtask(NewTCB,ID_TASKS);
            ID_TASKS++;
            if(getType(NewTCB)==PERIODIC){
                int temp=getNumberPeriodicTasks(ValSTARTTCB);
                temp+=1;
                setNumberPeriodicTasks(ValSTARTTCB,temp);
            }else{
                int temp = getNumberAperiodicTasks(ValSTARTTCB);
                temp+=1;
                setNumberAperiodicTasks(ValSTARTTCB,temp);
            }
        }else{            
            setStartTCB(ValSTARTTCB,NewTCB);
            setIdtask(NewTCB,ID_TASKS);
            ID_TASKS++;
            if(getType(NewTCB)==PERIODIC){
                int temp=getNumberPeriodicTasks(ValSTARTTCB);
                temp+=1;
                setNumberPeriodicTasks(ValSTARTTCB,temp);
            }else{
                int temp = getNumberAperiodicTasks(ValSTARTTCB);
                temp+=1;
                setNumberAperiodicTasks(ValSTARTTCB,temp);
            }
        }
    }
    return SUCESS;
}
int removeElementTCB(STARTTCB* ValSTARTTCB, int IDTask){
    if(getStartTCB(ValSTARTTCB)!=PONTNULL){
        TCB* atual = getStartTCB(ValSTARTTCB);
        int estado = FALSE;
        if(getIdtask(atual)==IDTask){
            estado=TRUE;
            if(getNextTCB(atual)==PONTNULL){
                setStartTCB(ValSTARTTCB,PONTNULL);
            }else{
                setStartTCB(ValSTARTTCB,getNextTCB(atual));
            }
        }else{
            do{
                printf("\nID:%d\n",getIdtask(atual));
                if(getIdtask(atual)==IDTask){
                    estado=TRUE;
                    if(getNextTCB(atual)==PONTNULL){
                        setNextTCB(getPrevTCB(atual),PONTNULL);
                    }else{
                        setNextTCB(getPrevTCB(atual),getNextTCB(atual));
                        setPrevTCB(getNextTCB(atual),getPrevTCB(atual));
                    }                    
                }
                atual=getNextTCB(atual);
            }while(atual!=PONTNULL);
        }
    }else{
        return SYS_ERROR_POINT_NULL;
    }
    return SUCESS;
}