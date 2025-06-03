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
        if (c == 't'){
            printf("\n");
            printf("\n");
            printf("a : .-\n");
            printf("b : -...\n");
            printf("c : -.-.\n");
            printf("d : -..\n");
            printf("e : .\n");
            printf("f : ..-.\n");
            printf("g : --.\n");
            printf("h : ....\n");
            printf("i : ..\n");
            printf("j : .---\n");
            printf("k : -.-\n");
            printf("l : .-..\n");
            printf("m : --\n");
            printf("n : -.\n");
            printf("o : ---\n");
            printf("p : .--.\n");
            printf("q : --.-\n");
            printf("r : .-.\n");
            printf("s : ...\n");
            printf("t : -\n");
            printf("u : ..-\n");
            printf("v : ...-\n");
            printf("w : .--\n");
            printf("x : -..-\n");
            printf("y : -.--\n");
            printf("z : --..\n");
            printf("\n");
            printf(">>> ");
            for (int i = 0;i < counter;i++) {
                printf("%c", input[i]);
            }
        }
    }
    return counter;
}
