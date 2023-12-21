#include "avl.h" /*NoArvore ,NoArvore* criarNo,obterMaior, calcularAlturaNo,calcularFatorBalanceamento,NoArvore* rotacaoEsquerda,NoArvore* rotacaoDireita,NoArvore* rotacaoEsquerdaDireita,NoArvore* rotacaoDireitaEsquerda,NoArvore* balancearArvore,NoArvore* inserirNaArvore,imprimirEspacos,imprimirNivelArvore,imprimirArvore*/
#include <stdio.h>/*printf,scanf,system(cls)*/
#include <stdlib.h>/*malloc,free*/


/* Função para criar um novo nó */
NoArvore* criarNo(int valor) 
{
    NoArvore *novoNo = malloc(sizeof(NoArvore)); /* Alocando memória para o novo nó */
    if (novoNo) /* Verificando se a memória foi alocada com sucesso */
    {
        /* Inicializando os valores do nó */
        novoNo->valor = valor;
        novoNo->filhoEsquerdo = NULL;
        novoNo->filhoDireito = NULL;
        novoNo->altura = 0;
    } 
    else 
    {
        printf("\nErro ao alocar memória para novo nó!\n");
    }
    return novoNo;
}

/* Função para obter o maior valor entre dois números */
int obterMaior(int a, int b) 
{
    return (a > b) ? a : b;
}

/* Função para calcular a altura de um nó */
int calcularAlturaNo(NoArvore *no) 
{
    if (no == NULL) /* Se o nó for NULL, retorna -1 */
    {
        return -1;
    } 
    else 
    {
        return no->altura; /* Retorna a altura armazenada no nó */
    }
}

/* Função para calcular o fator de balanceamento de um nó */
int calcularFatorBalanceamento(NoArvore *no) 
{
    if (no) /* Se o nó não for NULL */
    {
        return (calcularAlturaNo(no->filhoEsquerdo) - calcularAlturaNo(no->filhoDireito));
    } 
    else 
    {
        return 0;
    }
}

/* Função para realizar rotação esquerda em um nó */
NoArvore* rotacaoEsquerda(NoArvore *raiz) 
{
    NoArvore *direito = raiz->filhoDireito;
    NoArvore *esquerdoDireito = direito->filhoEsquerdo;

    /* Realizando a rotação */
    direito->filhoEsquerdo = raiz;
    raiz->filhoDireito = esquerdoDireito;

    /* Atualizando as alturas dos nós afetados */
    raiz->altura = obterMaior(calcularAlturaNo(raiz->filhoEsquerdo), calcularAlturaNo(raiz->filhoDireito)) + 1;
    direito->altura = obterMaior(calcularAlturaNo(direito->filhoEsquerdo), calcularAlturaNo(direito->filhoDireito)) + 1;

    return direito;
}

/* Função para realizar rotação direita em um nó */
NoArvore* rotacaoDireita(NoArvore *raiz) 
{
    NoArvore *esquerdo = raiz->filhoEsquerdo;
    NoArvore *direitoEsquerdo = esquerdo->filhoDireito;

    /* Realizando a rotação */
    esquerdo->filhoDireito = raiz;
    raiz->filhoEsquerdo = direitoEsquerdo;

    /* Atualizando as alturas dos nós afetados */
    raiz->altura = obterMaior(calcularAlturaNo(raiz->filhoEsquerdo), calcularAlturaNo(raiz->filhoDireito)) + 1;
    esquerdo->altura = obterMaior(calcularAlturaNo(esquerdo->filhoEsquerdo), calcularAlturaNo(esquerdo->filhoDireito)) + 1;

    return esquerdo;
}

/* Função para realizar rotação esquerda-direita em um nó */
NoArvore* rotacaoEsquerdaDireita(NoArvore *raiz) 
{
    raiz->filhoEsquerdo = rotacaoEsquerda(raiz->filhoEsquerdo);
    return rotacaoDireita(raiz);
}

/* Função para realizar rotação direita-esquerda em um nó */
NoArvore* rotacaoDireitaEsquerda(NoArvore *raiz) 
{
    raiz->filhoDireito = rotacaoDireita(raiz->filhoDireito);
    return rotacaoEsquerda(raiz);
}

/* Função para balancear a árvore  */
NoArvore* balancearArvore(NoArvore *raiz) 
{
    int fatorBal = calcularFatorBalanceamento(raiz);

    /* Realizando as rotações necessárias para balancear a árvore */
    if (fatorBal < -1 && calcularFatorBalanceamento(raiz->filhoDireito) <= 0) 
    {
        raiz = rotacaoEsquerda(raiz);
        printf("\nRotacao esquerda realizada\n");
    } 
    else 
		if (fatorBal > 1 && calcularFatorBalanceamento(raiz->filhoEsquerdo) >= 0) 
		{
			raiz = rotacaoDireita(raiz);
			printf("\nRotacao direita realizada\n");
		} 
    else 
		if (fatorBal > 1 && calcularFatorBalanceamento(raiz->filhoEsquerdo) < 0) 
		{
			raiz = rotacaoEsquerdaDireita(raiz);
			printf("\nRotacao esquerda-direita realizada\n");
		} 
    else 
		if (fatorBal < -1 && calcularFatorBalanceamento(raiz->filhoDireito) > 0) 
		{
			raiz = rotacaoDireitaEsquerda(raiz);
			printf("\nRotacao direita-esquerda realizada\n");
		}
		
    return raiz;
}

/* Função para inserir um valor na árvore */
NoArvore* inserirNaArvore(NoArvore *raiz, int valor) 
{
   
    if (raiz == NULL) 
    {
        return criarNo(valor);
    } 
    else 
    {
        if (valor < raiz->valor) 
        {
            raiz->filhoEsquerdo = inserirNaArvore(raiz->filhoEsquerdo, valor);
        } 
        else 
		if (valor > raiz->valor) 
        {
            raiz->filhoDireito = inserirNaArvore(raiz->filhoDireito, valor);
        } 
        else 
        {
            printf("\nInsercao nao realizada! O no ja existe!\n");
        }

        /* Atualizando a altura e balanceando a árvore */
        raiz->altura = obterMaior(calcularAlturaNo(raiz->filhoEsquerdo), calcularAlturaNo(raiz->filhoDireito)) + 1;
        return balancearArvore(raiz);
    }
}

/* Função para imprimir espaços */
void imprimirEspacos(int quantidade) 
{
    int i;
    for (i = 0; i < quantidade; i++) 
    {
        printf(" ");
    }
}

/* Função para imprimir um nível da árvore */
void imprimirNivelArvore(NoArvore* no, NoArvore* noPai, int nivel, int largura) 
{
    if (no == NULL) 
    {
        imprimirEspacos(largura);
        return;
    }

    if (nivel == 1) 
    {
        imprimirEspacos((largura - 5) / 2);

        if (noPai != NULL) 
        {
            if (no->valor < noPai->valor) 
            {
                printf("[_%d_]/", no->valor);
            } 
            else 
            {
                printf("\\[_%d_]", no->valor);
            }
        } 
        else 
        {
            printf("[_%d_]", no->valor);
        }

        imprimirEspacos((largura - 5) / 2);
    } 
    else 
	if (nivel > 1) 
    {
        imprimirNivelArvore(no->filhoEsquerdo, no, nivel - 1, largura / 2);
        imprimirNivelArvore(no->filhoDireito, no, nivel - 1, largura / 2);
    }
}

/* Função para imprimir a árvore*/
void imprimirArvore(NoArvore* raiz) 
{
    int altura = calcularAlturaNo(raiz); /* Calcula a altura da árvore */
	int larguraMax;/* Determina a largura máxima da árvore para formatação */
	int i;
	
	larguraMax= (1 << (altura + 1)) * 5; 

    /* Percorre cada nível da árvore para impressão */
    for (i = 1; i <= altura + 1; i++) 
    {
        /* Chama a função imprimirNivelArvore para imprimir o nível atual */
        imprimirNivelArvore(raiz, NULL, i, larguraMax);
        printf("\n"); /* Quebra de linha após imprimir cada nível */
    }
}
