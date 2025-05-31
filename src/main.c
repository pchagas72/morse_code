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
    int counter = get_input(buffer);
    walk(buffer,counter);
    read_file();
    SDL_Quit();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return 0;
}
