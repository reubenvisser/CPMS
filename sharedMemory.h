#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>

#include "config.h"

/* =========================== COMPONENTS ============================*/

/* licence plate reader */
typedef struct lpr {
    pthread_mutex_t lock;
    pthread_cond_t condition;
    char rego[6]; // licence plate in form 123APB
} lpr_t;

/* boom gate */
typedef struct boom_gate {
    pthread_mutex_t lock;
    pthread_cond_t condition;
    char status; 
} boom_gate_t;

/* information sign */
typedef struct info_sign {
    pthread_mutex_t lock;
    pthread_cond_t condition;
    char display; // displays one letter at a time
} info_sign_t;

/* ===================================================================*/

typedef struct entrance {
    lpr_t lpr;
    boom_gate_t boomGate;
    info_sign_t infoSign;
} entrance_t;

typedef struct exit {
    lpr_t lpr;
    boom_gate_t boomGate;
} exit_t;

typedef struct level {
    lpr_t lpr;
    short tempSensor;
    bool alarm;
} level_t;

/* ========================== Shared Memory ==========================*/

typedef struct shm {
    entrance_t entrances[NUM_ENTRANCES];
    exit_t exits[NUM_EXITS];
    level_t levels[NUM_LEVELS];
} shm_t;