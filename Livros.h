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
		int edicao;
		int codigo;
		bool status;	//1 se o livro está disponível, 0 se o livro está indisponível
		int codigoIndividuoSolicitante;
		
	Livros();
	
	void inicializa(int code);
};
