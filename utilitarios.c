#include "utilitarios.h"

char **alocaEspacoPalavrasDicionario(int nPalavrasDicionario){
	
	int i;
	char **palavra;

	//Aloca espaço para cada palavra//
	palavra = (char**) malloc(nPalavrasDicionario * sizeof(char*));
	if(!palavra) { perror(NULL); exit(EXIT_FAILURE); }

	//Aloca espaço para cada caractere de cada palavra//
	for(i = 0; i < nPalavrasDicionario; i++){
		palavra[i] = (char*) malloc(PALAVRA_MAX * sizeof(char));
		if(!palavra[i]) { perror(NULL); exit(EXIT_FAILURE); }
	}

	return palavra;
}

void destroiPalavrasDicionario(int nPalavrasDicionario, char **palavras){

	int i;

	//Libera espaço alocado para os caracteres de cada palavra//
	for(i = 0; i < nPalavrasDicionario; i++){
		free(palavras[i]);
	}

	//Libera espaço alocado para as palavras//
	free(palavras);
}