#include "IMPORTS.h"
#include "DEFINES_GLOBAIS.h"
#include "TCB.h"
#include "ESCALONADOR.h"
#include "Fator_de_utilizacao_DM.h"
#include "SIMULADOR_AREA_DE_APLICACAO.h"
#include "DISPATCH.h"
/*Lembrar de criar duas funcoes, uma pra ser executada sempre que ligar o Sistema, outra para executar a todo clock*/
void printUnidade(TCB* UTCB){
    printf("\n\n\n\nAQUITOUNI\n\n\n\n");
    printf("************************************\n");
    printf("ID_TASK: %d\n",getIdtask(UTCB));
    printf("TYPE: %d\n",getType(UTCB));
    printf("STATE: %d\n",getState(UTCB)); 
    printf("RELATIVE DEADLINE: %d\n",getRelativeDeadline(UTCB));
    printf("ABSOLUTE DEADLINE: %d\n",getAbsoluteDeadline(UTCB));
    printf("PERIOD: %d\n",getPeriod(UTCB));
    printf("EXECUTION TIMER: %d\n",getExecutionTimer(UTCB));
    printf("FLAG: %d\n",getFlag(UTCB));
    printf("PRIORITY: %d\n",getPriority(UTCB));    
}
void printTCBCompleto(STARTTCB* cabeca){
    printf("AQUITO\n");
    TCB* atual = getStartTCB(cabeca);    
    printf("\nPERIODIC: %d: ",getNumberPeriodicTasks(cabeca));
    printf("\nAPERIODIC: %d: ",getNumberAperiodicTasks(cabeca));
    do{
        printUnidade(atual);
        atual=getNextTCB(atual);
    }while((atual)!=PONTNULL);
     
}
void testeTCB(){
    STARTTCB * cabeca1 = createStartTCB();
    int periodo,prioridade,Tempoexecucao,deadline,tipo,id;
    int esc;    
    while(TRUE){
        printf("1:ADD\n2:DELL\n3:PRINT\n0:SAIR\n");
        scanf("%d",&esc);        
        switch(esc){
            case 1:
                printf("TIPO: ");
                scanf("%d",&tipo);
                printf("deadline: ");
                scanf("%d",&deadline);
                printf("periodo: ");
                scanf("%d",&periodo);
                printf("tempo de execucao: ");
                scanf("%d",&Tempoexecucao);
                printf("prioridade: ");
                scanf("%d",&prioridade);
                addElementTCB(cabeca1,createTCB(cabeca1,tipo,deadline,periodo,Tempoexecucao,prioridade));
                break;
            case 2:
                printf("\nID DA TASK: \n");
                scanf("%d",&id);
                removeElementTCB(cabeca1,id);
                break;
            case 3:
                printTCBCompleto(cabeca1);
                break;
            case 0:
                exit(0);
                break;
        }
    }
}
STARTTCB *init(){
    STARTTCB* cabeca1 = createStartTCB();    
    TCB* Tasks[7];
    Tasks[0]=createTCB(cabeca1,PERIODIC,10,10,1,PRIORITY_NIVEL7);
    Tasks[1]=createTCB(cabeca1,PERIODIC,15,15,2,PRIORITY_NIVEL5);
    Tasks[2]=createTCB(cabeca1,PERIODIC,5,5,1,PRIORITY_NIVEL10);
    Tasks[3]=createTCB(cabeca1,APERIODIC,5,5,1,PRIORITY_APERIODIC_SUPER);    
    Tasks[4]=createTCB(cabeca1,PERIODIC,20,20,4,PRIORITY_SUPER);        
    Tasks[5]=createTCB(cabeca1,PERIODIC,7,7,1,PRIORITY_NIVEL3);    
    Tasks[6]=createTCB(cabeca1,APERIODIC,10,10,2,PRIORITY_APERIODIC_0);    
    
//    Tasks[0]=createTCB(cabeca1,HARD,73,1,20,PRIORITY_SUPER);
//    Tasks[1]=createTCB(cabeca1,HARD,60,1,30,PRIORITY_NIVEL1);
//    Tasks[2]=createTCB(cabeca1,HARD,85,1,20,PRIORITY_NIVEL2);
//    Tasks[3]=createTCB(cabeca1,HARD,91,1,20,PRIORITY_NIVEL3);
//    Tasks[4]=createTCB(cabeca1,HARD,83,1,10,PRIORITY_NIVEL4);    
    int i;
    for (i = 0; i < 7; i++) {
        addElementTCB(cabeca1,Tasks[i]);
    }
    printf("\nNUMERO PERI:%d\n",getNumberPeriodicTasks(cabeca1));
    printf("\nNUMERO APERI:%d\n",getNumberAperiodicTasks(cabeca1));
    //printf("IDTASK: %d:",getIdtask(getTCBForDispatchingDM(cabeca1)));
    //printTCBCompleto(cabeca1);
    if(calcFatordeUltilizacao(cabeca1)){        
        return cabeca1;
    }else{ 
        printf("NAO E ESCALONAVEL PELO DM");
        exit(0);
    }
    return PONTNULL;
}
void wake_up(STARTTCB * val,unsigned int clock){
    if(clock!=0){
        TCB* atual = getStartTCB(val);
        int result;
        do{
            result= clock % getPeriod(atual);
            if(result==0){
                //printf("\nTASK %d fechou um periodo\n",getIdtask(atual));
                if(getState(atual)== IDLE || getState(atual)==WAIT){
                    setState(atual,READY);
                }
            }
            atual=getNextTCB(atual);
        }while(atual!=PONTNULL);
    }
}
int main(){
    STARTTCB* MainList;
    TCB* PontTCB;
    MainList=init();
    unsigned int clockPassado=0;    
    int ret;
    while(TRUE){
        printf("\nCLOCK: %d",clockPassado);        
        if(LIFESYSTEM>=clockPassado){
            PontTCB=EscalonadorDM(MainList);
            if(PontTCB!=SYS_ERROR_TASK_NOT_FOUND){                
                //printf("ERROR: %d ",PontTCB);                
                ret = DISPATCH(PontTCB);
                if(ret!=SUCESS){
                    printf("\nret deu pont null\n");
                }   
            }else{                
                printf("\nProcessador Ocioso\n");
            }                        
            sleep(1);
        }else{
            printf("\nACABOU");
            exit(0);
        }
        wake_up(MainList,clockPassado);
        clockPassado++;
    }
}