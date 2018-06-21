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
	edicao = "";
	nExemplares = 0;						// o livro quando cadastrado est� dispon�vel
	codigoIndividuosSolicitantes = "-";	//o livro quando cadastrado n�o est� emprestado para ningu�m
}

void Livros::inicializaLivro()
{
	string nada = "";
	cout << "Digite o t�tulo do livro: ";
	getline(cin,nada);
	getline(cin,titulo);
	cout << endl;
	
	cout << "Digite o autor: ";
	//getline(cin,nada);
	getline(cin,autor);
	cout << endl;
	
	cout << "Digite a editora: ";
	getline(cin,editora);
	cout << endl;
	
	cout << "Digite o edicao: ";
	getline(cin,edicao);
	cout << endl;
	
	cout << "Digite o n�mero de exemplares dispon�veis do livro: ";
	cin >> nExemplares;	
}

