#include<stdio.h>
#include <termios.h>            //termios, TCSANOW, ECHO, ICANON
#include <unistd.h>     //STDIN_FILENO

int get_input(char input[256]){
    int c;   
    int counter = 0;

    while((c=getchar())!= 'e'){
        if (c == 'j') {
            printf(".");
            input[counter] = '.';
            counter++;
        }
        if (c == 'k') {
            printf("-");
            input[counter] = '-';
            counter++;
        }
        if (c == 'f' || c == ' ') {
            printf(" ");
            input[counter] = ' ';
            counter++;
        }
    }
    return counter;
}

int main(void){   
    // Troca leis do terminal
    static struct termios oldt, newt;
    tcgetattr( STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON);          
    newt.c_lflag &= ~(ECHO);          
    tcsetattr( STDIN_FILENO, TCSANOW, &newt);

    // Começa programa

    char input[256];

    // Pega o input

    int counter = get_input(input);
    printf("\n");

    for (int i = 0;i < counter;i++) {
        printf("%c",input[i]);
    }
    printf("\n");

    /*restore the old settings*/
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt);


    return 0;
}
