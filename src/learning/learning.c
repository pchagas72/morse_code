#include "./learning.h"

void read_file(){
    FILE *fptr;
    fptr = fopen("phrases.txt", "r");
    char myString[100];
    fgets(myString, 100, fptr);
    fclose(fptr);
    int printing = 0;
    for (int i = 0;i < strlen(myString);i++) {
        if (myString[i] == '/') {
            printing = 1;
            printf("\n");
            continue;
        }
        if (printing == 1){
            printf("%c",myString[i]);
        }
        if (printing == 0){
            printf("%c",myString[i]);
        }
    }
}
