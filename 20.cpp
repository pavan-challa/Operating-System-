#include <stdio.h> 
#include <pthread.h> 
#include 
<semaphore.h> 
sem_t mutex, writeBlock; 
int data = 0, readersCount = 0; 
void 
*reader(void 
*arg) { int i=0; 
while (i<10) { 
sem_wait(&mute
 x);readersCount
 ++; 
if (readersCount == 1) 
{ 
sem_wait(&writeBloc
 k); 
} 
sem_post(&mutex); 
printf("Reader reads data: %d\n", data); 
sem_wait(&mute
 x); 
readersCount--; 
if (readersCount == 0) 
{ 
sem_post(&writeBloc
 k); 
} 
sem_post(&mutex); 
i++; 
} 
} 
void 
*writer(void 
*arg) { int i=0; 
while (i<10) { 
sem_wait(&writeBloc
 k); 
operation 
data++; 
printf("Writer writes data: %d\n", data); 
sem_post(&writeBloc
 k); i++; 
} 
} 
int main() { 
pthread_t readers, 
writers; 
sem_init(&mutex, 0,1); 
sem_init(&writeBlock, 0, 1); 
pthread_create(&readers, NULL, reader, NULL); 
pthread_create(&writers, NULL, writer, 
NULL);pthread_join(readers, NULL); 
pthread_join(writers, 
NULL);sem_destroy(&mutex); 
sem_destroy(&writeBlock
 ); return 0; 
} 
