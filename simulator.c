#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

#include "config.h"
#include "sharedMemory.h"

int shm_fd;
shm_t *sharedMemory;
const char *key = "PARKING";

int main(int argc, char **argv) {
    /* OPEN SHARED MEMORY */
    // creates & opens / opens new shared memory object
    if ((shm_fd = shm_open(key, O_CREAT | O_RDWR, 0666)) < 0) { 
        perror("smh_open");
        return 1;
    }
    
    ftruncate(shm_fd, SHM_SIZE); // truncate shared memory size

    // create new mapping of memory
    if ((sharedMemory = (shm_t*)mmap(0, SHM_SIZE, PROT_WRITE | PROT_READ, 
        MAP_SHARED, shm_fd, 0)) == (void *)-1) {
        perror("mmap");
        return 1;
    }

    /* CLOSE SHARED MEMORY */
    // unmap memory
    if (munmap(sharedMemory, SHM_SIZE) != 0) {
        perror("munmap");
        return 1;
    }

    // remove shared memory object
    if (shm_unlink(key) != 0) {
        perror("shm_unlink");
    }
    
    return 0;
}