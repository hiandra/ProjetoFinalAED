#include <iostream>
#include <algorithm>
#include <list>
#include <string>
#include <fstream>
#include <vector>
#include <conio.h>
#include <windows.h>

using namespace std;

class Gerenciamento : public Individuos, public Livros
{	
	public:
		list<Individuos> individuos;	//individuos � a lista com todas pessoas cadastradas
		list<Livros> livros;	//livros � a lista com todos os livros cadastrados
		vector<int> codigos_individuos;	// � usado para fazer a busca de indiv�duos por c�digo
		vector<string> titulos_livros;	// � usado para fazer a busca de livros por titulo
		
	Gerenciamento();	//construtor
	
	void atualiza(); //escreve dados no arquivo, apaga vetores e l� novamente
	
	void readFromFileIndividuos();	//salva os dados de "individuos.txt" na lista individuos e inicializa o vector "codigos_individuos"
	
	void writeFileIndividuos();	//salva os dados da lista individuos no arquivo "individuos.txt"
		
	void addIndividuos();	//adiciona n indiv�duos na lista
	
	void addFuncionarios();  //adiciona n funcion�rios na lista
	
	int busca_binaria(int x, int N, int a[]);	//busca a chave "x" no array "a" de tamanho "N"
	
	void buscaIndividuo(int& flag, list<Individuos>::iterator& it);	//retorna a posicao do indiv�duo com c�digo "code" na lista de individuos
	
	void removeIndividuo();	//remove um indiv�duo da lista e atualiza o arquivo "individuos.txt"
	
	void editaIndividuo();	//edita algum par�metro do indiv�duo de c�digo "x"
	
	void readFromFileLivros();	//salva os dados de "livros.txt" na lista livros e inicializa o vector "titulos_livros"		
	
	void writeFileLivros();	//salva os dados da lista livros no arquivo "livros.txt"
	
	void addLivros();	//adiciona "n" livros na lista e os salva no arquivo "livros.txt"				
	
	void buscaLivro(int& flag, list<Livros>::iterator& it);	//retorna a posicao do livro com titulo "title" na lista de livros
	
	void removeLivro();	//remove um livro da lista e atualiza o arquivo "livros.txt"				
	
	void editaLivro();	//edita algum par�metro do livro de nome "name"
	
	void mostraIndividuos();	//mostra todos indiv�duos cadastrados
	
	void mostraLivros();	//mostra todos os livros cadastrados
	
	void buscaLogin(int& flag, list<Individuos>::iterator& it, int code);
	
	bool menuInicial();	//mostra opcoes de login e cadastro de usu�rio
	
	void menuLogin();	//login da pessoa j� cadastrada
	
	void emprestaLivro();	//atualiza o "nExemplares" e o c�digo do ind�viduo solicitante 
	
	void devolveLivro();			
	
	void menuCliente(int& flagOK);	//mostra as fun��es acess�veis por clientes								
	
	void menuFuncionario(int& flagOK);	//mostra as fun��es acess�veis por funcion�rios
			
};
