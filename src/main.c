#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include "./lexer/lexer.h"
#include "./sound/sound.h"
#include "./input/input.h"
#include "./learning/learning.h"

int main(void) {
    static struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    SDL_Init(SDL_INIT_AUDIO);

    char buffer[256];
    char challange[256];
    int challange_counter = 0;
    read_file(challange, &challange_counter);
    printf("Challange: ");
    for (int i = 0;i < challange_counter;i++) {
        printf("%c", challange[i]);
    }
    printf("\n");
    printf(">>> ");
    int counter = get_input(buffer);
    printf("\n");
    printf("\n");
    printf("You wrote: ");
    char output_buffer[counter];
    int output_counter = walk(buffer,counter,output_buffer);
    for (int i = 0;i < output_counter; i++) {
        printf("%c",output_buffer[i]);
    }
    printf("\n");
    int points = compare(challange, output_buffer, output_counter);
    printf("You've made %d/%d points\n", points,challange_counter-1);
    SDL_Quit();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return 0;
}
