#include <stdio.h>
#include <pthread.h>

void *myFunction2 (void *arg)
{
    printf("Hello World from func2!*********************************************\n");

}

void *myFunction1 (void *arg) 
{
    while(1) {
        printf("Hello World from func1\n");
	usleep(1000);
    }
}

int main()
{
    pthread_t tid;
    pthread_create(&tid, NULL, myFunction1, NULL);
    //pthread_join(tid, NULL);

    int isDetached = -10;
    isDetached = pthread_detach(tid);
    printf("Is my thread detached: %d\n", isDetached);

    int i;

    pthread_create(&tid, NULL, myFunction2, NULL);
    pthread_join(tid, NULL);

    for (i = 0; i<1500; i++)
        printf("%d\n", i);

    return 0;
}

