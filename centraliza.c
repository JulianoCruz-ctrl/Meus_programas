#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 200

/*
Programa que pega um texto de um
arquivo, limita o numero de col
a 80, e centraliza o texto



*/


int main(){

FILE * a1 = fopen("texto1.txt","r");
FILE * a2 = fopen("texto5.txt","w");
char t[1][MAX],le;
int i = 0,j,k,l,c1 = 0,c2 = 0,aux = 0;

if(a1 == NULL || a2 == NULL){
    puts("Nao foi possivel abrir o arquivo");
    exit(1);
}

for(j = 0; (le = fgetc(a1)) != EOF; j++){


    // primeira condicao

    if(le != 32 && c1 < 81){
        t[i][j] = le;
        c1++,c2++;

    }

    // Segunda condicao

    else if(le == 32 && c1 < 81){
        t[i][j] = le;
        c1++,c2 = 0;
    }

    if(c1 == 81){
      if(l != 32){

        for(k = 0; k < ((c2 / 2)+1); k++){
            fputc(32,a2);

        }
        aux = c2 - (c2 / 2);

        for(k = j, l = 1; k > j-c2; k--,l++){

            t[i][j+l] = t[i][j-c2+l];

        }
        t[i][j-c2+1] = '\0';
        fprintf(a2,"%s", t[i]);
        for(k = 0, l = 1; k < c2; k++,l++){
            t[i][k] = t[i][j+l];
        }
        
        for(k = 0; k < aux; k++){
            fputc(32,a2);
        }
        j = c2-1;
        c1 = j+1;
        fputc('\n',a2);



        }
        else if(le == 32){
        t[i][j] = '\0';
        fprintf(a2,"%s", t[i]);
        fputc('\n',a2);
        c1 = 0;
        j = -1;
    }
    }

    

}
for(k = j; k < c1; k++){
    putc(32,a2);

}

t[i][j] = '\0';
fprintf(a2,"%s", t[i]);
fclose(a1);
fclose(a2);



    
}