#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED

/* Definindo a estrutura de um n� da �rvore AVL */
typedef struct NoArvore 
{
    int valor; /* Valor armazenado no n� */
    struct NoArvore *filhoEsquerdo, *filhoDireito; /* Ponteiros para os filhos esquerdo e direito */
    int altura; /* Altura do n� na �rvore */
} NoArvore;

NoArvore* criarNo(int) ;/* Fun��o para criar um novo n� */

int obterMaior(int , int ) ;/* Fun��o para obter o maior valor entre dois n�meros */

int calcularAlturaNo(NoArvore *) ;/* Fun��o para calcular a altura de um n� */

int calcularFatorBalanceamento(NoArvore *) ;/* Fun��o para calcular o fator de balanceamento de um n� */

NoArvore* rotacaoEsquerda(NoArvore *) ;/* Fun��o para realizar rota��o esquerda em um n� */

NoArvore* rotacaoDireita(NoArvore *); /* Fun��o para realizar rota��o direita em um n� */

NoArvore* rotacaoEsquerdaDireita(NoArvore *) ;/* Fun��o para realizar rota��o esquerda-direita em um n� */

NoArvore* rotacaoDireitaEsquerda(NoArvore *) ;/* Fun��o para realizar rota��o direita-esquerda em um n� */

NoArvore* balancearArvore(NoArvore *) ;/* Fun��o para balancear a �rvore  */

NoArvore* inserirNaArvore(NoArvore *, int) ;/* Fun��o para inserir um valor na �rvore */

void imprimirEspacos(int) ;/* Fun��o para imprimir espa�os */

void imprimirNivelArvore(NoArvore*, NoArvore*, int , int) ;/* Fun��o para imprimir um n�vel da �rvore */

void imprimirArvore(NoArvore*) ;/* Fun��o para imprimir a �rvore*/


#endif

