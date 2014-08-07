#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define MY_SHM_ID 67483

int main(){
    int num = 0;
    struct shared_use_st *shared_stuff;
    int shmid;
    shmid = shmget(MY_SHM_ID, 4096, 0666|IPC_CREAT);
    if(shmid == -1){
        printf("shmid is : %d", shmid);
    }

    struct shmid_ds shmds; // mem content
    int ret;
    ret = shmctl(shmid, IPC_STAT, &shmds);
    if(ret == 0){
        printf("size of mem segment is %d :\n", shmds.shm_segsz);
        printf("Numbre of attaches %d \n",( int )shmds.shm_nattch);
        printf("shmid is : %d\n", shmid);
    } else {
        printf("shmctl() call fail \n");
    }
    void* mem;
    mem = shmat(shmid, (const void*)0, 0);
    //strcpy((char*)mem, "this is test string;");
    *((int *)mem) = 131;
    /**
     *  shmget create 
     *  shmctl control 
     *  shmat get 
     */
    //char* ss;
    //ss = shmat(shmid, (const char*)0, 0);
    //printf("=== %s \n", ss);
    int* qs;
    qs = shmat(shmid, (const int*)0, 0);
    printf("=== %d \n", *qs);
    FILE *file;
    file = fopen("shmid", "w");
    int shmidList[] = {shmid};
    fwrite(shmidList, 4, 1, file);
    fclose(file);
    return 0;
    ret = shmctl(shmid, IPC_RMID, 0);
    if( ret==0 )
        printf( "Shared memory removed \n" );
    else
        printf( "Shared memory remove failed \n" );
    return 0;
}
