#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Livros{
	
	public:
		string titulo;
		string autor;
		string editora;
		string edicao;
		string codigoIndividuosSolicitantes;	//codigos separados por v�rgulas
		int nExemplares;	//n� de exemplares dispon�veis
		
	Livros();
	
	void inicializaLivro();
};
