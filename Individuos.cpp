#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include "Individuos.h"
using namespace std;

Individuos::Individuos()	//construtor da classe
{
	nome = "";
	email = "";
	telefone = "";
	endereco = "";
	RG = "";
	senha = "";
	codigo = -1;
	funcionario = "0";
}

void Individuos::inicializaCliente(int code)	//cadastro de clientes
{	
	string nada = "";
	
	cout << endl;
	cout << "Digite o RG: ";
	cin >> RG;
	cout << endl;
	
	cout << "Digite o nome completo: ";
	getline(cin,nada);
	getline(cin,nome);
	cout << endl;
	
	cout << "Digite o email: ";
	cin >> email;
	cout << endl;
	
	cout << "Digite sua senha: ";
	//A senha não aparecerá na tela, apenas * para cada caracter.
	senha = "";
	char ch;
	ch = _getch();
	while(ch != 13){ 	//O caracter 13 representa a tecla ENTER.
		senha.push_back(ch);
		cout << '*';
		ch = _getch();	
	}
	cout << endl << endl;
	
	cout << "Digite o telefone com DDD: ";
	cin >> telefone;
	cout << endl;
	
	cout << "Digite o endereco: ";
	getline(cin,nada);
	getline(cin,endereco);
	//cin >> endereco;
	cout << endl;
	
	codigo = code;
	
	cout << "Indivíduo cadastrado com sucesso." << endl;
}

//void Individuos::inicializaFuncionario(int code);	// cadastro de funcionarios	

