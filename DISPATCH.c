#include "DISPATCH.h"
int DISPATCH(TCB* task){
    if(task!=PONTNULL){        
        setState(task,RUN);
        SimuladorDeUmaTask(task);
        if(getTimeComputed(task)>=(getExecutionTimer(task)-1)){
            setState(task,IDLE);
            setTimeComputed(task,0);
            //printf("\nAQUI 1,ID:%d, Time Computed: %d, Computacao: %d",getIdtask(task),getTimeComputed(task),getExecutionTimer(task));
        }else{
            setState(task,READY);            
            setTimeComputed(task,(getTimeComputed(task)+1));
            //printf("\nAQUI 2,ID:%d, Time Computed: %d, Computacao: %d",getIdtask(task),getTimeComputed(task),getExecutionTimer(task));
        } 
        return SUCESS;
    }else{
        return SYS_ERROR_POINT_NULL;
    }   
}