#include "./translator.h"

void define_table (){
    int a = walk(".-", 2);
    int b = walk("-...", 4);
    int c = walk("-.-.", 4);
    int d = walk("-..", 3);
    int e = walk(".", 1);
    int f = walk("..-.", 4);
    int g = walk("--.", 3);
    int h = walk("....", 4);
    int i = walk("..", 2);
    int j = walk(".---", 4);
    int k = walk("-.-", 3);
    int l = walk(".-..", 4);
    int m = walk("--", 2);
    int n = walk("-.", 2);
    int o = walk("---", 3);
    int p = walk(".--.", 4);
    int q = walk("--.-", 4);
    int r = walk(".-.", 3);
    int s = walk("...", 3);
    int t = walk("-", 1);
    int u = walk("..-", 3);
    int v = walk("...-", 4);
    int w = walk(".--", 3);
    int x = walk("-..-", 4);
    int y = walk("-.--", 4);
    int z = walk("--..", 4);
    int codigos[26]={a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z};
    int vercod[26];
    int scco;
    for (int counter=0;counter <26;counter++) {
        printf("%d, ",codigos[counter]);
        for (int sec = 0;sec <= scco;sec++) {
            if (codigos[counter] == vercod[sec]) {
                printf("Falhou em %d\n",codigos[counter]);
                break;
            }
        }
        vercod[counter] = codigos[counter];
        scco++;
    }
}

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
    printf("\n");
    for (int i = 0;i<size;i++) {
        if (input[i] == ' ') {
            printf("Espaço\n");
        }
        if ((int)input[i] == 45 && i == 0) {
            code += 1;
        }
        code += (int)input[i]*(i+4);
    }
}
