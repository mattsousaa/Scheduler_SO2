#ifndef DEFINES_GLOBAIS_H
#define DEFINES_GLOBAIS_H
/*DIFINICOES PRIMITIVAS DO KERNEL*/
#define FALSE     0
#define TRUE      1
#define NHARD     0
#define HARD      1
#define HIGH      1
#define LOW       0
/*ERROS*/
#define SYS_ERROR                   -1
#define SYS_ERROR_MAX_NUM_PERIODIC  -2
#define SYS_ERROR_MAX_NUM_APERIODIC -3
#define SYS_ERROR_MAX_NUM_TASK      -4
#define SYS_ERROR_POINT_NULL        -5
#define SYS_ERROR_MAX_LIFETIMER     -6
#define SYS_ERROR_TASK_NOT_FOUND    -7
#define SYS_ERROR_EQUAL_PRIORITY    -8
#define SUCESS    0
#define PONTNULL NULL
#define LIFESYSTEM 4294967296
#define NUM_MAX_PERIODIC_TASKS 7
#define NUM_MAX_APERIODIC_TASKS 4
#define NUM_MAX_TASKS 11
/*Estados possíveis*/
#define READY   0
#define RUN     1
#define WAIT    2
#define IDLE    3
#define DEFAULT 4
/*Prioridades, nesse sistema será suportado prioridades entre 0 a 3*/
/*As prioridades serão quanto menor maior será a prioridade*/
#define PRIORITY_SUPER    0
#define PRIORITY_NIVEL1   1
#define PRIORITY_NIVEL2   2
#define PRIORITY_NIVEL3   3
#define PRIORITY_NIVEL4   4
#define PRIORITY_NIVEL5   5
#define PRIORITY_NIVEL6   6
#define PRIORITY_NIVEL7   7
#define PRIORITY_NIVEL8   8
#define PRIORITY_NIVEL9   9
#define PRIORITY_NIVEL10 10
#define PRIORITY_APERIODIC_SUPER 100
#define PRIORITY_APERIODIC_0 101
#define PRIORITY_APERIODIC_1 102
#define PRIORITY_APERIODIC_2 103
#define PRIORITY_APERIODIC_3 104

/*TIPOS DE TASKS*/
#define PERIODIC  0
#define APERIODIC 1

/*ENDERECAMENTO TASKS*/
static unsigned int ID_TASKS=0;
/*SISTEMA*/
#endif /* DEFINES_GLOBAIS_H */

