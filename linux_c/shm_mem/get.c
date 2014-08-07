#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define MY_SHM_ID 67483

int main(int argc, char* argv[]){
    //int shmid = atof(argv[1]);
    FILE *file;
    file = fopen("shmid", "r");
    int shmid;
    fread(&shmid, 4, 1, file);
    printf("shmid is %d:\n", shmid);
    /**
     *  shmget create 
     *  shmctl control 
     *  shmat get 
     */
    //char* ss;
    //ss = shmat(shmid, (const char*)0, 0);
    int *num;
    num = shmat(shmid, (const int*)0, 0);
    //printf("ss is : %s \n", ss);
    printf("num is : %d \n", *num);
    return 0;
}
