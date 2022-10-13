# proto-ex04

1.  Máquinas de Estados Finitos (MEF)
    - Considere a seguinte expressão regular `^[a-c]k+[mn]$`
    - Ela pode ser traduzida como: "uma string que está no começo da linha, tendo como primeiro caracter uma letra entre _a_ e _c_, seguida da repetição de 1 ou mais vezes da letra _k_, que, por sua vez, vem seguido de uma caracter que pode ser _m_ ou _n_,finalizando a linha.
    - Confira o arquivo `data2regex.txt`, e execute o comando `egrep "^[a-c]k+[mn]$" data2regex.txt` para constatar o funcionamento
    -   Legenda:
        -   `^` indica que esse ponto corresponde ao início da linha
        -   `$` idem, mas para o fim de linha
        -   \[...\] indica uma classe de caracteres 
            -   Exemplo - \[tcwz\] indica a classe que contém _t_, _c_, _w_, _z_
            -   Exemplo - \[f-h\] indica uma _faixa_ (_f_,_g_,_h_)
    - Faça um programa que abre um arquivo texto e mostra apenas as linhas que satisfazem à expressão regular `^[a-c]k+[mn]$` (ou seja, o mesmo comportamento observado com `egrep "^[a-c]k+[mn]$ <arquivo>`)
        -   Desenhe a MEF

2. Formatando texto
    -   Faça um programa que imprime o arquivo na tela, limitando cada linha a 80 colunas
    -   Se a última palavra na linha não couber nas 80 colunas, ela deve aparecer na linha seguinte
    -   Isso corresponde à formatação alinhada à esquerda em um editor de texto
    -   DICA: monte uma MEF que considera também a largura de 80 colunas, e avança buscando o fim da palavra antes de começar a imprimir
    -   Faça programas similares com outras regras de formatação:
        -   Texto alinhado à direita
        -   Texto centralizado
        -   Texto justificado 
        -   DICA: Para esses 3 casos, adapte a MEF para começar a imprimir a linha somente quando tiver vasculhado onde fica o final

3. Ordenação de strings

Considere um arquivo com strings curtas, uma por linha. Gere um novo arquivo com as strings em ordem alfabética.

```
Genoveva
Venceslau
Aristides
Ludovico
Adamastor
```
