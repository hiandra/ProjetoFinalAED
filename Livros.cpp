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
	nExemplares = 0;						// o livro quando cadastrado está disponível
	codigoIndividuosSolicitantes.clear();	//o livro quando cadastrado não está emprestado para ninguém
}

void Livros::inicializa()
{
	string nada = "";
	cout << "Digite o título do livro: ";
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
	
	cout << "Digite o número de exemplares do livro: ";
	cin >> nExemplares;
	cout << endl;
	
}

