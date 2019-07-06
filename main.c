#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
 
#define NUM_OF_OPER 10
#define NUM_OF_THREADS 5

//The project for OS class
int sharedVal = 0;
int gWaitingReaders = 0, gReaders = 0;

pthread_mutex_t pReadWriteMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t pReadCond = PTHREAD_COND_INITIALIZER;
pthread_cond_t pWriterCond = PTHREAD_COND_INITIALIZER;

void* readerFunc(void* arg){
    int threadID = *((int*)(arg));
    int numOfReads = 0;
    
    for(int i = 0; i < NUM_OF_OPER; ++i){
        usleep(1000 * (rand()%NUM_OF_THREADS));
        
        pthread_mutex_lock(&pReadWriteMutex);
        gWaitingReaders++;
        //We are writing the shared memory... Need while loop here
        while(gReaders == -1)
            pthread_cond_wait(&pReadCond, &pReadWriteMutex);
        gWaitingReaders--;
        numOfReads = ++gReaders; //We can now read the value
        pthread_mutex_unlock(&pReadWriteMutex);
        
        fprintf(stdout, "Reader thread %d is reading data %d (the total number of reader: %d)\n", threadID, sharedVal, numOfReads);
        
        pthread_mutex_lock(&pReadWriteMutex);
        --gReaders;
        if(gReaders == 0){
            pthread_cond_signal(&pWriterCond);
        }
        pthread_mutex_unlock(&pReadWriteMutex);
    }
    pthread_exit(0);
}

void* writerFunc(void* arg){
    int threadID = *((int*)arg);
    int numOfReads = 0;
    
    for(int i = 0; i < NUM_OF_OPER; i++){
        usleep(1000* (rand()%NUM_OF_THREADS));
        
        pthread_mutex_lock(&pReadWriteMutex);
        //while(gWaitingReaders > 0) You made an error here, note we need to check gReaders
        //Even while(gReaders > 0) is not correct, you should consider the situation that multiple writing threads write to shared memory location
        while(gReaders != 0)
            pthread_cond_wait(&pWriterCond, &pReadWriteMutex);
        gReaders = -1;
        numOfReads = 0;
        pthread_mutex_unlock(&pReadWriteMutex);
        
        fprintf(stdout, "Writer thread %d is writing data %d (the number of reader: %d)\n", threadID, ++sharedVal, numOfReads);
        
        pthread_mutex_lock(&pReadWriteMutex);
        gReaders++;
        if(gWaitingReaders > 0)
            pthread_cond_broadcast(&pReadCond);
        else
            pthread_cond_signal(&pReadCond);
        pthread_mutex_unlock(&pReadWriteMutex);
    }
    pthread_exit(0);    
}

int main(int argc, char *argv[])
{
    pthread_t readerThread[NUM_OF_THREADS];
    pthread_t writerThread[NUM_OF_THREADS];
    srand((unsigned int)time(NULL));
    
    int numThreads[NUM_OF_THREADS];
    for(int i = 0; i < NUM_OF_THREADS; ++i){
        numThreads[i] = i;
        if(!pthread_create(&readerThread[i], NULL, readerFunc, &numThreads[i]))
            printf("Read thread %d created!\n", numThreads[i]);
    }
    
    for(int i = 0; i < NUM_OF_THREADS; ++i){
        numThreads[i] = i;
        if(!pthread_create(&writerThread[i], NULL, writerFunc, &numThreads[i]))
            printf("Writer thread %d created!\n", numThreads[i]);
    }
    
    for(int i = 0; i < NUM_OF_THREADS; i++){
        numThreads[i] = i;
        if(!pthread_join(readerThread[i], NULL))
            printf("Reader thread %d joined!\n", numThreads[i]);
    }
    for(int i = 0; i < NUM_OF_THREADS; i++){
        numThreads[i] = i;
        if(!pthread_join(writerThread[i], NULL))
            printf("Writer thread %d joined!\n", numThreads[i]);
    }
    
    //int x = rand();
    //printf("Testing random generated number: %d \n", x);
    
    printf("Our threads exit normally!\n");
    return 0;
}




























