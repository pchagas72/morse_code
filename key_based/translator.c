#include "./translator.h"

char table_translate(int code){
    int letras[26] = {
        409, 1009, 1003, 687,
        184, 1006, 682, 1012,
        414, 994, 681, 1007,
        406, 411, 676, 1001,
        997, 685, 690, 181,
        684, 1005, 679, 1002,
        996, 1004};
    char alfabeto[26] = {
        'a','b','c','d',
        'e','f','g','h',
        'i','j','k','l',
        'm','n','o','p',
        'q','r','s','t',
        'u','v','w','x',
        'y','z'
    };
    for (int i = 0;i < 26; i++) {
        if (code == letras[i]) {
            return alfabeto[i];
        }
    }
}

void walk(char *input, int size){
    int code = 0;
    int counter = 0;
    printf("\n");
    for (int i = 0;i<size;i++) {
        if (input[i] == ' ' ) {
            printf("%c", table_translate(code));
            code = 0;
            counter = 0;
        } else{
            if ((int)input[i] == 45 && counter == 0) {
                code += 1;
            }
            code += (int)input[i]*(counter+4);
            counter++;
        }
        if (i == size-1){
            printf("%c\n", table_translate(code));
        }
    }
}
