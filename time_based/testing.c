#include<stdio.h>
#include <termios.h>            //termios, TCSANOW, ECHO, ICANON
#include <unistd.h>     //STDIN_FILENO
#include <pthread.h>
#include <string.h>

int input_time = 0;

void *time_thread(void *arg){
    while(1){
        usleep(100 * 1000);
        if (input_time < 10){
            input_time += 1;
        }
    }
    return NULL;
}

int main(void){   
    int c;   
    static struct termios oldt, newt;

    tcgetattr( STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON);          
    tcsetattr( STDIN_FILENO, TCSANOW, &newt);

    pthread_t thread;
    pthread_create(&thread, NULL, time_thread, NULL);

    while((c=getchar()) != 'e'){
        if (c){
                if (input_time != 0){
                    printf("Received at %d\n", input_time);
                    input_time = 0;
            }
        }
    }

    pthread_join(thread, NULL); // Wait for input thread to finish



    tcsetattr( STDIN_FILENO, TCSANOW, &oldt);
    return 0;
}
