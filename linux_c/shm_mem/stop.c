#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define MY_SHM_ID 67483

int main(int argc, char* argv[]){
    int shmid = atof(argv[1]);
    /**
     *  shmget create 
     *  shmctl control 
     *  shmat get 
     */
    char* ss;
    ss = shmat(shmid, (const char*)0, 0);
    printf("ss is : %s \n", ss);
    int ret;
    ret = shmctl(shmid, IPC_RMID, 0); 
    if( ret==0 )
        printf( "Shared memory removed \n" );
    else
        printf( "Shared memory remove failed \n" );
    return 0;
}
