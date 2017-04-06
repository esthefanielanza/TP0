#include "trie.h"
#include "utilitarios.h"

int main (int argc,char *argv[]){

	TNode *raiz;
	
	int nPalavrasDicionario, nPalavrasTexto;
	int i;

	char **palavrasDicionario;

	//Lê o número de palavras que serão inseridas no dicionário//
	scanf("%d", &nPalavrasDicionario);

	//Cria a árvore//
	raiz = criaTrie();

	//Aloca espaço para elas serem armazenadas em um vetor//
	palavrasDicionario = alocaEspacoPalavrasDicionario(nPalavrasDicionario);

	//Enquanto houverem palavras há serem inseridas//
	for(i = 0; i < nPalavrasDicionario; i++){
		scanf("%s", palavrasDicionario[i]);
		inserePalavra(raiz, palavrasDicionario[i]);
	}

	//Lê o número de palavras do texto//
	scanf("%d", &nPalavrasTexto);
		
	//Enquanto ainda houverem palavras há serem lidas//
	for(i = 0; i < nPalavrasTexto; i++){
		procuraPalavra(raiz);
	}
	
	//Pesquisa as palavras do dicionário na ordem que estas foram inseridas e as imprimem no console//
	frequenciaPalavra(raiz, palavrasDicionario, nPalavrasDicionario);

	//Desaloca espaço utilizado pelo programa//
	destroiPalavrasDicionario(nPalavrasDicionario, palavrasDicionario);
	destroiTrie(raiz);
	
	return 0;
}