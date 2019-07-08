#ifndef PTHREAD_PRACTICE_H
#define PTHREAD_PRACTICE_H

void* readerFunc(void* arg);
void* writerFunc(void* arg);
void ExecuteThreadFunc();

#endif