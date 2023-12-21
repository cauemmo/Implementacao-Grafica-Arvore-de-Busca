#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED

/* Definindo a estrutura de um nó da árvore AVL */
typedef struct NoArvore 
{
    int valor; /* Valor armazenado no nó */
    struct NoArvore *filhoEsquerdo, *filhoDireito; /* Ponteiros para os filhos esquerdo e direito */
    int altura; /* Altura do nó na árvore */
} NoArvore;

NoArvore* criarNo(int) ;/* Função para criar um novo nó */

int obterMaior(int , int ) ;/* Função para obter o maior valor entre dois números */

int calcularAlturaNo(NoArvore *) ;/* Função para calcular a altura de um nó */

int calcularFatorBalanceamento(NoArvore *) ;/* Função para calcular o fator de balanceamento de um nó */

NoArvore* rotacaoEsquerda(NoArvore *) ;/* Função para realizar rotação esquerda em um nó */

NoArvore* rotacaoDireita(NoArvore *); /* Função para realizar rotação direita em um nó */

NoArvore* rotacaoEsquerdaDireita(NoArvore *) ;/* Função para realizar rotação esquerda-direita em um nó */

NoArvore* rotacaoDireitaEsquerda(NoArvore *) ;/* Função para realizar rotação direita-esquerda em um nó */

NoArvore* balancearArvore(NoArvore *) ;/* Função para balancear a árvore  */

NoArvore* inserirNaArvore(NoArvore *, int) ;/* Função para inserir um valor na árvore */

void imprimirEspacos(int) ;/* Função para imprimir espaços */

void imprimirNivelArvore(NoArvore*, NoArvore*, int , int) ;/* Função para imprimir um nível da árvore */

void imprimirArvore(NoArvore*) ;/* Função para imprimir a árvore*/


#endif

