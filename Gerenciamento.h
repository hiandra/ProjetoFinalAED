#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Gerenciamento : public Individuos, public Livros
{	
	public:
		list<Individuos> individuos;	//individuos é a lista com todas pessoas cadastradas
		list<Livros> livros;	//livros é a lista com todos os livros cadastrados
		vector<int> codigos_individuos;	// é usado para fazer a busca de indivíduos por código
		vector<int> codigos_livros;	//é usado para fazer a busca de livros por código
		
	Gerenciamento();	//construtor
	
	void readFromFileIndividuos();	//salva os dados de "individuos.txt" na lista individuos e inicializa o vector "codigos_individuos"
		
	void addIndividuos();	//adiciona n indivíduos na lista e os salva no arquivo "individuos.txt"
	
	int busca_binaria(int x, int N, int a[]);	//busca a chave "x" no array "a" de tamanho "N"
	
	void removeIndividuo();	//remove um indivíduo da lista e atualiza o arquivo "individuos.txt"
	
	//void editaIndividuo();	//edita algum parâmetro do indivíduo de código "x"
	
	//void readFromFileLivros();	//salva os dados de "livros.txt" na lista livros e inicializa o vector "codigos_livros"
	
	//void addLivros();	//adiciona "n" livros na lista e os salva no arquivo "livros.txt"
	
	//void removeLivro();	//remove um livro da lista e atualiza o arquivo "livros.txt"
	
	//void emprestaLivro();	//atualiza o "status" e o código do indíviduo solicitante 
			
};
