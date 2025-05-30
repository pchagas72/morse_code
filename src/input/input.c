#include "../input/input.h"

int get_input(char input[256]) {
    int c, counter = 0;
    while ((c = getchar()) != 'e') {
        if (c == 'j') {
            printf(".");
            input[counter] = '.';
            play_tone(DOT_DURATION_MS);
            counter++;
        }
        if (c == 'k') {
            printf("-");
            input[counter] = '-';
            play_tone(DASH_DURATION_MS);
            counter++;
        }
        if (c == 'f' || c == ' ') {
            printf(" ");
            input[counter] = ' ';
            SDL_Delay(DOT_DURATION_MS); // pause between letters
            counter++;
        }
    }
    return counter;
}


