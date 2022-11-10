#include <stdint.h>

/*=============================== Nodes ==============================*/

typedef struct vehicle {
    char rego[6]; // licence plate in form 123APB

    uint8_t parking_level;
    uint8_t entrance;
    uint8_t exit;
} vehicle_t;

typedef struct node {
    struct vehicle* vehicle;
    struct node* next;
} node_t;

/*============================= Functions ============================*/

void queue_append(node_t** queue_head, char* rego) {

}