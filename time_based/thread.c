#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

int input_time = 0;
int received = 0;

void *input_thread(void *arg) {
    if (received == 0){
        scanf("%d");
        printf("Sei nn man\n");
        received == 1;
    }
    return NULL;
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, input_thread, NULL);
    printf("Main thread is running.\n");
    

    while(1){
        usleep(100*1000);
        input_time++;
        if (received == 1){
            input_time = 0;
            printf("%d\n", input_time);
        }
    }
    // Perform other tasks
    pthread_join(thread, NULL); // Wait for input thread to finish
    return 0;
}
