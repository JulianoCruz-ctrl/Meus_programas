#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 200


int main(void){


FILE * arq1 = fopen("texto1.txt","r");
FILE * arq2 = fopen("texto4.txt","w");
char t[1][MAX];
char l,cor;
int i,j,k, con1 = 0;
int con2 = 0;
int f;

if(arq1 == NULL || arq2 == NULL){
    puts("Nao foi possivel abrir o arquivo");
    exit(1);
}

for(i = 0, j = 0; (l = fgetc(arq1)) != EOF; j++){

    // primeira condicao

if(l != 32 && con1 < 80){
    con1++;
    con2++;
    t[i][j] = l;
}

    // segunda condicao

 else if(l == 32 && con1 < 80){
    t[i][j] = l;
    con2 = 0;
    con1++;
 }

 // terceira condicao

 if(con1 == 80){

    // terceira condicao part 1

   if(l != 32 && con2 > 0){

        for(k = 0; k < con2; k++){
            fputc(32,arq2);
        }

        for(k = j, f = 1; k > j-con2; k--,f++){
              t[i][j+f] = t[i][j-con2+f];
        }
        t[i][j-con2+1] = '\0';
        fprintf(arq2,"%s", t[i]);

        for(k = 0, f = 1; k < con2; k++,f++){
         t[i][k] = t[i][j+f];
    
        }

        j = con2-1;
        con1 = j+1;
        fputc('\n',arq2);
    }
 // terceira condicao part 2

    else if(l == 32){
        t[i][j] = '\0';
        fprintf(arq2,"%s", t[i]);
        fputc('\n',arq2);
        con1 = 0; 
        j = -1;
    }
 }

}
t[i][j] = '\0';
fprintf(arq2,"%s", t [i]);

fclose(arq1);
fclose(arq2);



}