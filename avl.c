#include "avl.h" /*NoArvore ,NoArvore* criarNo,obterMaior, calcularAlturaNo,calcularFatorBalanceamento,NoArvore* rotacaoEsquerda,NoArvore* rotacaoDireita,NoArvore* rotacaoEsquerdaDireita,NoArvore* rotacaoDireitaEsquerda,NoArvore* balancearArvore,NoArvore* inserirNaArvore,imprimirEspacos,imprimirNivelArvore,imprimirArvore*/
#include <stdio.h>/*printf,scanf,system(cls)*/
#include <stdlib.h>/*malloc,free*/


/* Fun��o para criar um novo n� */
NoArvore* criarNo(int valor) 
{
    NoArvore *novoNo = malloc(sizeof(NoArvore)); /* Alocando mem�ria para o novo n� */
    if (novoNo) /* Verificando se a mem�ria foi alocada com sucesso */
    {
        /* Inicializando os valores do n� */
        novoNo->valor = valor;
        novoNo->filhoEsquerdo = NULL;
        novoNo->filhoDireito = NULL;
        novoNo->altura = 0;
    } 
    else 
    {
        printf("\nErro ao alocar mem�ria para novo n�!\n");
    }
    return novoNo;
}

/* Fun��o para obter o maior valor entre dois n�meros */
int obterMaior(int a, int b) 
{
    return (a > b) ? a : b;
}

/* Fun��o para calcular a altura de um n� */
int calcularAlturaNo(NoArvore *no) 
{
    if (no == NULL) /* Se o n� for NULL, retorna -1 */
    {
        return -1;
    } 
    else 
    {
        return no->altura; /* Retorna a altura armazenada no n� */
    }
}

/* Fun��o para calcular o fator de balanceamento de um n� */
int calcularFatorBalanceamento(NoArvore *no) 
{
    if (no) /* Se o n� n�o for NULL */
    {
        return (calcularAlturaNo(no->filhoEsquerdo) - calcularAlturaNo(no->filhoDireito));
    } 
    else 
    {
        return 0;
    }
}

/* Fun��o para realizar rota��o esquerda em um n� */
NoArvore* rotacaoEsquerda(NoArvore *raiz) 
{
    NoArvore *direito = raiz->filhoDireito;
    NoArvore *esquerdoDireito = direito->filhoEsquerdo;

    /* Realizando a rota��o */
    direito->filhoEsquerdo = raiz;
    raiz->filhoDireito = esquerdoDireito;

    /* Atualizando as alturas dos n�s afetados */
    raiz->altura = obterMaior(calcularAlturaNo(raiz->filhoEsquerdo), calcularAlturaNo(raiz->filhoDireito)) + 1;
    direito->altura = obterMaior(calcularAlturaNo(direito->filhoEsquerdo), calcularAlturaNo(direito->filhoDireito)) + 1;

    return direito;
}

/* Fun��o para realizar rota��o direita em um n� */
NoArvore* rotacaoDireita(NoArvore *raiz) 
{
    NoArvore *esquerdo = raiz->filhoEsquerdo;
    NoArvore *direitoEsquerdo = esquerdo->filhoDireito;

    /* Realizando a rota��o */
    esquerdo->filhoDireito = raiz;
    raiz->filhoEsquerdo = direitoEsquerdo;

    /* Atualizando as alturas dos n�s afetados */
    raiz->altura = obterMaior(calcularAlturaNo(raiz->filhoEsquerdo), calcularAlturaNo(raiz->filhoDireito)) + 1;
    esquerdo->altura = obterMaior(calcularAlturaNo(esquerdo->filhoEsquerdo), calcularAlturaNo(esquerdo->filhoDireito)) + 1;

    return esquerdo;
}

/* Fun��o para realizar rota��o esquerda-direita em um n� */
NoArvore* rotacaoEsquerdaDireita(NoArvore *raiz) 
{
    raiz->filhoEsquerdo = rotacaoEsquerda(raiz->filhoEsquerdo);
    return rotacaoDireita(raiz);
}

/* Fun��o para realizar rota��o direita-esquerda em um n� */
NoArvore* rotacaoDireitaEsquerda(NoArvore *raiz) 
{
    raiz->filhoDireito = rotacaoDireita(raiz->filhoDireito);
    return rotacaoEsquerda(raiz);
}

/* Fun��o para balancear a �rvore  */
NoArvore* balancearArvore(NoArvore *raiz) 
{
    int fatorBal = calcularFatorBalanceamento(raiz);

    /* Realizando as rota��es necess�rias para balancear a �rvore */
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

/* Fun��o para inserir um valor na �rvore */
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

        /* Atualizando a altura e balanceando a �rvore */
        raiz->altura = obterMaior(calcularAlturaNo(raiz->filhoEsquerdo), calcularAlturaNo(raiz->filhoDireito)) + 1;
        return balancearArvore(raiz);
    }
}

/* Fun��o para imprimir espa�os */
void imprimirEspacos(int quantidade) 
{
    int i;
    for (i = 0; i < quantidade; i++) 
    {
        printf(" ");
    }
}

/* Fun��o para imprimir um n�vel da �rvore */
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

/* Fun��o para imprimir a �rvore*/
void imprimirArvore(NoArvore* raiz) 
{
    int altura = calcularAlturaNo(raiz); /* Calcula a altura da �rvore */
	int larguraMax;/* Determina a largura m�xima da �rvore para formata��o */
	int i;
	
	larguraMax= (1 << (altura + 1)) * 5; 

    /* Percorre cada n�vel da �rvore para impress�o */
    for (i = 1; i <= altura + 1; i++) 
    {
        /* Chama a fun��o imprimirNivelArvore para imprimir o n�vel atual */
        imprimirNivelArvore(raiz, NULL, i, larguraMax);
        printf("\n"); /* Quebra de linha ap�s imprimir cada n�vel */
    }
}
