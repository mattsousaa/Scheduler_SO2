#include "Fator_de_utilizacao_DM.h"
int calcFatordeUltilizacao(STARTTCB* ValStartTCB){
    TCB* primeiro = getStartTCB(ValStartTCB);
    TCB* aux = primeiro;
    int quant=1,periodo=0,tempoExec=0;
    do{        
        if(getType(aux)==PERIODIC){
        quant++;
        }
        aux=getNextTCB(aux);                
    }while(getNextTCB(aux)!=PONTNULL);
    float frac[quant],totalEsquerdo=0;
    int i;
    aux=primeiro;
    for(i=0;i<quant-1;i++){
        if(getType(aux)==PERIODIC){
            frac[i]=((getExecutionTimer(aux))/(getPeriod(aux)));            
        }
        aux=getNextTCB(aux);        
    }
    for(i=0;i<quant-1;i++){
        totalEsquerdo+=frac[i];
    }    
    double totalDireita = quant*(pow(2,1/quant)-1);    
    if(totalEsquerdo<=totalDireita){
        return TRUE;
    }else{
        return FALSE;
    }    
}
