#ifndef UTILITARIOS_H
#define UTILITARIOS_H

#include "trie.h"

/*---------------------------------------------------------------------------------------------
Protótipo: char ** alocaEspacoPalavrasDicionario(int nPalavrasDicionario);
Função: Aloca espaço para armazenar a ordem inicial que as palavras foram inseridas.
Entrada: O número de palavras presentes no dicionário.
Saída: Retorna o vetor de palavras.
---------------------------------------------------------------------------------------------*/
char **alocaEspacoPalavrasDicionario(int nPalavrasDicionario);

/*---------------------------------------------------------------------------------------------
Protótipo: void destroiPalavrasDicionario(int nPalavrasDicionario, char **palavras);
Função: Desaloca o espaço utilizado para armazenar a ordem incial que as palavras foram inseri-
das
Entrada: O número de palavras presentes no dicionário e o vetor de palavras.
Saída: Não retorna nada.
---------------------------------------------------------------------------------------------*/
void destroiPalavrasDicionario(int nPalavrasDicionario, char **palavras);

#endif