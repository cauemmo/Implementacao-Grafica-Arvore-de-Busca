/* Programa: Visualiza��o de uma �rvore AVL.
   Descri��o: Esse programa realiza a Visualiza��o de uma �rvore AVL.
   Programador: Cau� Mendon�a Magela do �.
   RGM: 43558.
   Data da ultima modifica��o: 01/12/2023 */
  
/* LINHA DE EXECU��O: 
gcc main.c avl.c  -o main.exe -Wall -Wextra -pedantic -Werror*/

#include "avl.h" /*NoArvore ,NoArvore* criarNo,obterMaior, calcularAlturaNo,calcularFatorBalanceamento,NoArvore* rotacaoEsquerda,NoArvore* rotacaoDireita,NoArvore* rotacaoEsquerdaDireita,NoArvore* rotacaoDireitaEsquerda,NoArvore* balancearArvore,NoArvore* inserirNaArvore,imprimirEspacos,imprimirNivelArvore,imprimirArvore*/
#include <stdio.h>/*printf,scanf,system(cls)*/
#include <stdlib.h>/*malloc,free*/

int main(int argc, char *argv[])
{
    int opcaoSelecionada, valorInserido;
    NoArvore *raizArvore = NULL;
	argc = argc;
    argv = argv;

    while (1) 
    {
        printf("\nMENU\n1-Inserir: ");
        scanf("%d", &opcaoSelecionada);

        if (opcaoSelecionada == 1) 
        {
            printf("\nDigite o valor a ser inserido: ");
            scanf("%d", &valorInserido);

            system("cls"); 
            printf("\n\nAntes:\n"); /*Imprime a arvore antes da inser��o*/
            imprimirArvore(raizArvore);
            raizArvore = inserirNaArvore(raizArvore, valorInserido);
            
            printf("\nDepois:\n\n");/*Imprime a arvore depois da inser��o*/
            imprimirArvore(raizArvore); 
        } 
        else 
        {
            break;
        }
    }

    printf("Programa encerrado.\n");
    return 0;
}