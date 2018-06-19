#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <vector>
#include "Livros.h"
using namespace std;
	
Livros::Livros()
{
	titulo = "";
	autor = "";
	editora = "";
	edicao = -1;
	nExemplares = 0;						// o livro quando cadastrado est� dispon�vel
	codigoIndividuosSolicitantes.clear();	//o livro quando cadastrado n�o est� emprestado para ningu�m
}

void Livros::inicializa()
{
	string nada = "";
	cout << "Digite o t�tulo do livro: ";
	getline(cin,nada);
	getline(cin,titulo);
	cout << endl;
	
	cout << "Digite o autor: ";
	getline(cin,nada);
	getline(cin,autor);
	cout << endl;
	
	cout << "Digite a editora: ";
	cin >> editora;
	cout << endl;
	
	cout << "Digite o edicao: ";
	cin >> edicao;
	cout << endl;
	
	cout << "Digite o n�mero de exemplares do livro: ";
	cin >> nExemplares;
	cout << endl;
	
}

