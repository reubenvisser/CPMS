#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "vehicle_queue.h"

void queueAppend(node_t** queueHead, vehicle_t** ehicle) {
    node_t *newNode = (node_t *) malloc(sizeof(node_t));
    newNode->next = NULL;

    // check if queue is empty
    if (*queueHead == NULL) {
        *queueHead = newNode;
        return;
    }

    // locate last node in list
    node_t *last = *queueHead;
    while (last->next != NULL) {
        last = last->next;
    }

    // append new node
    last->next = newNode;
    return;
}

node_t* queuePop(node_t** queueHead) {
    node_t *first = *queueHead;
    return first->next;
}