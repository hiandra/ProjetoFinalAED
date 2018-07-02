#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <vector>
#include <conio.h>
#include <windows.h>
using namespace std;

class Livros{
	
	public:
		string titulo;
		string autor;
		string editora;
		string edicao;
		string codigoIndividuosSolicitantes;	//codigos separados por espaços
		int nExemplares;	//n° de exemplares disponíveis
		
	Livros();
	
	void inicializaLivro();
};
