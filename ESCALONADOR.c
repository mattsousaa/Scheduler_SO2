#include "ESCALONADOR.h"
TCB* EscalonadorDM(STARTTCB* val){
    if(val!=PONTNULL){
        TCB* atual = getStartTCB(val);        
        int quant = 0;
        do{
            if(getType(atual)==PERIODIC){
                if(getState(atual)==READY){
                    quant++;
                }
            }
            atual=getNextTCB(atual);
        }while(atual!=PONTNULL);        
        //printf("\nQUANTIDADE EM READY: %d",quant);
        if(quant>0){
            TCB* LISTA_TCB_READY[quant];
            quant=0;
            atual=getStartTCB(val);
            do{
                if(getType(atual)==PERIODIC){
                    if(getState(atual)==READY){
                    LISTA_TCB_READY[quant]=atual;
                    quant++;
                    }
                }                
                atual=getNextTCB(atual);
            }while(atual!=PONTNULL);
            TCB* menorPrioridade = LISTA_TCB_READY[0];
            int i=0;
            for(i=0;i<quant;i++){
                if(getPriority(LISTA_TCB_READY[i])<getPriority(menorPrioridade)){
                    menorPrioridade=LISTA_TCB_READY[i];
                }
            }
            return menorPrioridade;
        }else{
            return EscalonadorAperiodic(val);           
        }
    }else{        
        return SYS_ERROR_TASK_NOT_FOUND;
    }
}
TCB* EscalonadorAperiodic(STARTTCB* val){    
    if(val!=PONTNULL){
        TCB* atual = getStartTCB(val);        
        int quant = 0;
        do{
            if(getType(atual)==APERIODIC){
                if(getState(atual)==READY){
                    quant++;
                }
            }
            atual=getNextTCB(atual);
        }while(atual!=PONTNULL);        
        //printf("\nQUANTIDADE EM READY: %d",quant);
        if(quant>0){
            TCB* LISTA_TCB_READY[quant];
            quant=0;
            atual=getStartTCB(val);
            do{
                if(getType(atual)==APERIODIC){
                    if(getState(atual)==READY){
                    LISTA_TCB_READY[quant]=atual;
                    quant++;
                    }
                }
                atual=getNextTCB(atual);
            }while(atual!=PONTNULL);
            TCB* menorPrioridade = LISTA_TCB_READY[0];
            int i=0;
            for(i=0;i<quant;i++){
                if(getPriority(LISTA_TCB_READY[i])<getPriority(menorPrioridade)){
                    menorPrioridade=LISTA_TCB_READY[i];
                }                
            }            
            return menorPrioridade;
        }else{
            return SYS_ERROR_TASK_NOT_FOUND;      
        }
    }else{
        printf("\ncaso 3\n");
        return SYS_ERROR_TASK_NOT_FOUND;
    }
}