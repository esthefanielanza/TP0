#include "trie.h"

TNode *criaNode(void){

	int i;

	TNode *newNode;

	//Aloca espaço para o novo nó//
	newNode = (TNode*) malloc(sizeof(TNode));
	if(!newNode) { perror(NULL); exit(EXIT_FAILURE); }

	//Inicializa a variável do struct final como zero, quando em 1 representa o fim de uma palavra//
	newNode->finalPalavra = 0;

	//Inicializa o número de vezes que a palavra foi encontrada como zero//
	newNode->frequenciaPalavra = 0;

	//Inicializa todos os filhos do nó, correspondentes a tamanho do alfabeto, como NULL//
	for(i = 0; i < TAMANHO_ALFABETO; i++)
		newNode->filhos[i] = NULL;
	
	return newNode;
}

TNode *criaTrie(void){

	//Cria um nó para a raiz
	return criaNode();
}

void inserePalavra(TNode *node, char *palavra){

	int i;
	int tamanhoPalavra, indiceLetra;
	
	//Calcula o tamanho da palavra lida//
	tamanhoPalavra = strlen(palavra);

	//Enquanto não chegar ao fim da palavra//
	for(i = 0; i < tamanhoPalavra; i++){

		//Calculamos o indice correspondente a letra//
		indiceLetra = (int)palavra[i] - PRIMEIRA_LETRA_ASCII;
		
		//Se não existe um nó para o caractere correspondente, criamos o nó//
		if(node->filhos[indiceLetra] == NULL)
			node->filhos[indiceLetra] = criaNode();

		//Caminhamos para o nó criado//
		node = node->filhos[indiceLetra];
	}

	//Indicamos que é o final de uma palavra//
	node->finalPalavra = 1;
}

void procuraPalavra(TNode *node){

	int i;
	int tamanhoPalavra, indiceLetra;

	//Vetor temporário para armazenar a palavra do texto lida//
	char palavra[PALAVRA_MAX];

	//Lê uma palavra do texto e calcula seu tamanho//
	scanf("%s", palavra);
	tamanhoPalavra = strlen(palavra);

	for(i = 0; i < tamanhoPalavra; i++){

		//Calculamos o indice correspondente a letra//
		indiceLetra = (int)palavra[i] - PRIMEIRA_LETRA_ASCII;
		
		//Se ainda não existe um nó criado para determinado indice, retornamos pois a palavra não foi encontrada//
		if(node->filhos[indiceLetra] == NULL){
			return;
		}	

		//Caminhamos para o próximo nó//
		node = node->filhos[indiceLetra];
	}

	//Encontramos a palavra, logo incrementamos sua frequência//
	if(node->finalPalavra){
		node->frequenciaPalavra++;
	}
}

void frequenciaPalavra(TNode *raiz, char **palavras, int nPalavrasDicionario){

	int i, j;
	int tamanhoPalavra, indiceLetra;

	TNode *node;	

	//Enquanto não percorrer todas as palavras do dicionário//
	for(i = 0; i < nPalavrasDicionario; i++){
		
		//Sempre voltamos para raiz ao procurar uma nova palavra//		
		node = raiz;

		//Calculamos o tamanho da palavra//
		tamanhoPalavra = strlen(palavras[i]);

		//Caminhamos até o finalPalavra da palavra//
		for(j = 0; j < tamanhoPalavra; j++){

			indiceLetra = (int)palavras[i][j] - PRIMEIRA_LETRA_ASCII;
			node = node->filhos[indiceLetra];
		}

		//Imprimimos sua frequência no texto//
		if(node->finalPalavra)
			printf("%d", node->frequenciaPalavra);

		//Condição apenas para não imprimir espaço após o ultimo número//
		if(i != nPalavrasDicionario - 1)
			printf(" ");
	}
	
	printf("\n");
}

void destroiTrie(TNode *node){

	int i;
	
	//Verifica os 26 filhos, correspondentes aos caracteres, de cada nó//
	for(i = 0; i < TAMANHO_ALFABETO; i++){
		if(node->filhos[i] != NULL){
			//Chama a função recursivamente para o próximo filho que não é nulo//
			destroiTrie(node->filhos[i]);
		}
	}

	//Libera o nó que não é nulo//
	if(node != NULL)
		free(node);
}