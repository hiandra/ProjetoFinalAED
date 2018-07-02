#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include "Livros.h"
using namespace std;
	
Livros::Livros()
{
	titulo = "";
	autor = "";
	editora = "";
	edicao = "";
	nExemplares = 0;						// o livro quando cadastrado está disponível
	codigoIndividuosSolicitantes = "-";	//o livro quando cadastrado não está emprestado para ninguém
}

void Livros::inicializaLivro()
{
	string nada = "";
	cout << "Digite o título do livro: ";
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
	
	cout << "Digite qual a edição do livro: ";
	getline(cin,edicao);
	cout << endl;
	
	cout << "Digite o número de exemplares disponíveis do livro: ";
	cin >> nExemplares;	
	
	cout << "Livro cadastrado com sucesso." << endl << endl;
}

