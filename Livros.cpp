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
	codigo = -1;
	status = 1;							// o livro quando cadastrado est� dispon�vel
	codigoIndividuoSolicitante = -1;	//o livro quando cadastrado n�o est� emprestado para ningu�m
}

void Livros::inicializa(int code)
{
	string nada = "";
	cout << "Digite o t�tulo do livro: ";
	getline(cin,nada);
	getline(cin,titulo);
	system("pause");
	cout << endl;
	
	cout << "Digite o autor: ";
	getline(cin,nada);
	getline(cin,autor);
	system("pause");
	cout << endl;
	
	cout << "Digite a editora: ";
	cin >> editora;
	system("pause");
	cout << endl;
	
	cout << "Digite o edicao: ";
	cin >> edicao;
	system("pause");
	cout << endl;
	
	codigo = code;
}

