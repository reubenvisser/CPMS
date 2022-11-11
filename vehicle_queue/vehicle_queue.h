#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/*=============================== Nodes ==============================*/

typedef struct vehicle {
    char rego[6]; // licence plate in form 123APB

    uint8_t parkingLevel;
    uint8_t entrance;
    uint8_t exit;
} vehicle_t;

typedef struct node {
    struct vehicle* vehicle;
    struct node* next;
} node_t;

/*============================= Functions ============================*/

/**
 * @brief Appends new vehicle to end of queue
 * 
 * @param queueHead pointer to queue head pointer
 * @param vehicle pointer to vehicle pointer
 */
void queueAppend(node_t** queueHead, vehicle_t** vehicle);

/**
 * @brief Remove vehicle from front of queue
 * 
 * @param queueHead pointer to queue head pointer
 * @return node_t* new head pointer
 */
node_t* queuePop(node_t** queueHead);