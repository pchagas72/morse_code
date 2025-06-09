#include "./learning.h"

void read_file(char *challange, int *challange_counter) {
    FILE *fptr;
    char myString[100];
    int line_count = 0;
    char *homeDir = getenv("HOME");
    strcat(homeDir, "/.local/phrases.txt");

    // Conta quantas linhas tem
    
    fptr = fopen(homeDir, "r");
    if (fptr == NULL) {
        perror("Error reading file: does $HOME/.local/phrases.txt exist?");
        *challange_counter = -1;
        return;
    }

    while (fgets(myString, sizeof(myString), fptr) != NULL) {
        line_count++;
    }
    fclose(fptr);

    if (line_count == 0) {
        printf("There are no challanges.\n");
        *challange_counter = -1;
        return;
    }

    // Gera uma linha aleatória
    srand(time(NULL));
    int random_line = rand() % line_count;

    // Lê novamente até a linha sorteada
    fptr = fopen(homeDir, "r");
    int current_line = 0;
    while (fgets(myString, sizeof(myString), fptr) != NULL) {
        if (current_line == random_line) {
            break;
        }
        current_line++;
    }
    fclose(fptr);

    // Escreve challange e answer para os buffers
    int printing = 0;
    for (int i = 0; i < strlen(myString); i++) {
        challange[*challange_counter] = myString[i];
        (*challange_counter)++;
    }

    // Finaliza strings
    challange[*challange_counter] = '\0';
}


int compare(char *answer, char *input, int input_size){
    int pontos = 0;
    for (int i = 0;i < input_size;i++) {
        if (answer[i] == input[i]) {
            pontos++;
        }
    } 
    return pontos;

}
