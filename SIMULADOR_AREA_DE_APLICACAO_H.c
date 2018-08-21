#include "SIMULADOR_AREA_DE_APLICACAO.h"
#include "TCB.h"
void SimuladorDeUmaTask(TCB* task){    
/*Como é apenas uma silumação, essa task irá apenas esperar um período de clock
 como se fosse uma aplicação do usuário em execução executando um código qualquer,
 mas sempre em um período de clocl, depois irá ser escolhido novamente pelo escalonador
 quem irá executar*/    
    printf("\nTASK EXECUTANDO%d\n",getIdtask(task));    
}
