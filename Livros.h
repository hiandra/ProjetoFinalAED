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
		vector<int> codigoIndividuosSolicitantes;
		int nExemplares;	//n� de exemplares dispon�veis
		
	Livros();
	
	void inicializa(int code);
};
