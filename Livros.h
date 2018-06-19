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
		bool status;	//1 se o livro est� dispon�vel, 0 se o livro est� indispon�vel
		int codigoIndividuoSolicitante;
		
	Livros();
	
	void inicializa(int code);
};
