#ifndef TRIE_H
#define TRIE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PALAVRA_MAX 16
#define TAMANHO_ALFABETO 26
#define PRIMEIRA_LETRA_ASCII 97

//Estrutura para nós da árvore// 
typedef struct TNode{ 

	//Cada nó aponta para um número n de filhos, onde n é o tamanho do alfabeto//
	struct TNode *filhos[TAMANHO_ALFABETO];

	//Indica o fim de uma palavra, 0 para não é fim e 1 para é fim//
	int finalPalavra; 

	//Indica quantas vezes dada palavra presente na árvore foi encontrada no texto//
	int frequenciaPalavra;

} TNode;

/*---------------------------------------------------------------------------------------------
Protótipo: TNode *criaNode(void);
Função: Aloca espaço para um novo nó e inicializa todos os seus filhos como NULL.
Entrada: Não recebe nada.
Saída: Retorna um ponteiro para um struct do tipo Tnode.
---------------------------------------------------------------------------------------------*/
TNode *criaNode(void);

/*---------------------------------------------------------------------------------------------
Protótipo: TNode *criaTrie(void);
Função: Cria uma árvore Trie alocando um nó vazio para simbolizar a raiz.
Entrada: Não recebe nada.
Saída: Retorna um ponteiro para struct do tipo TNode.
---------------------------------------------------------------------------------------------*/
TNode *criaTrie(void);

/*---------------------------------------------------------------------------------------------
Protótipo: void inserePalavra(TNode *node, char *palavra);
Função: Insere uma palavra na árvore.
Entrada: Recebe o nó raiz e a palavra que será inserida.
Saída: Não retorna nada.
---------------------------------------------------------------------------------------------*/
void inserePalavra(TNode *node, char *palavra);

/*---------------------------------------------------------------------------------------------
Protótipo: void procuraPalavra(TNode *node);
Função: Procura se palavras do texto estão presentes no dicionário e incrementa sua frequência.
Entrada: O nó raiz.
Saída: Não retorna nada.
---------------------------------------------------------------------------------------------*/
void procuraPalavra(TNode *node);

/*---------------------------------------------------------------------------------------------
Protótipo: void frequenciaPalavra(TNode *raiz, char **palavras, int nPalavrasDicionario);
Função: Imprime a frequência de cada palavra no texto de acordo com a ordem que elas foram 
inseridas.
Entrada: O nó raiz, a ordem incial das palavras e o número de palavras presentes no dicionário.
Saída: Não retorna nada.
---------------------------------------------------------------------------------------------*/
void frequenciaPalavra(TNode *raiz, char **palavras, int nPalavrasDicionario);

/*---------------------------------------------------------------------------------------------
Protótipo: void destroiTrie(TNode *node);
Função: Desaloca o espaço utilizado pela árvore Trie.
Entrada: O nó raiz.
Saída: Não retorna nada.
---------------------------------------------------------------------------------------------*/
void destroiTrie(TNode *node);

#endif 