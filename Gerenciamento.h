#include <iostream>
#include <algorithm>
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
		vector<string> titulos_livros;	// é usado para fazer a busca de livros por titulo
		
	Gerenciamento();	//construtor
	
	void readFromFileIndividuos();	//salva os dados de "individuos.txt" na lista individuos e inicializa o vector "codigos_individuos"
	
	void writeFileIndividuos();	//salva os dados da lista individuos no arquivo "individuos.txt"
		
	void addIndividuos();	//adiciona n indivíduos na lista e os salva no arquivo "individuos.txt"
	
	int busca_binaria(int x, int N, int a[]);	//busca a chave "x" no array "a" de tamanho "N"
	
	void buscaIndividuo(int& flag, list<Individuos>::iterator& it);	//retorna a posicao do indivíduo com código "code" na lista de individuos
	
	void removeIndividuo();	//remove um indivíduo da lista e atualiza o arquivo "individuos.txt"
	
	void editaIndividuo();	//edita algum parâmetro do indivíduo de código "x"
	
	void readFromFileLivros();	//salva os dados de "livros.txt" na lista livros e inicializa o vector "codigos_livros"		
	
	void writeFileLivros();	//salva os dados da lista livros no arquivo "livros.txt"		-- Apagar o conteúdo antes de escrever
	
	void addLivros();	//adiciona "n" livros na lista e os salva no arquivo "livros.txt"				
	
	void buscaLivro(int& flag, list<Livros>::iterator& it);	//retorna a posicao do livro com titulo "title" na lista de livros
	
	void removeLivro();	//remove um livro da lista e atualiza o arquivo "livros.txt"				
	
	void editaLivro();	//edita algum parâmetro do livro de nome "name"
	
	//void emprestaLivro();	//atualiza o "nExemplares" e o código do indíviduo solicitante 				GABRIEL
	
	void mostraIndividuos();	//mostra todos indivíduos cadastrados
	
	void mostraLivros();	//mostra todos os livros cadastrados
	
	bool menuInicial();	//mostra opcoes de login e cadastro de usuário
	
	void menuLogin();	//login da pessoa já cadastrada
	
	void buscaLogin(int& flag, list<Individuos>::iterator& it, int code);	//Checa se login é válido ou não
	
	void menuCLiente();	//mostra as funções acessáveis por clientes									HIANDRA
	
	void menuFuncionario();	//mostra as funções acessáveis por funcionários
	
};
