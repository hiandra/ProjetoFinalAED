#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <vector>
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
	cin >> senha;
	cout << endl;
	
	cout << "Digite o telefone com DDD: ";
	cin >> telefone;
	cout << endl;
	
	cout << "Digite o endereco: ";
	cin >> endereco;
	cout << endl;
	
	codigo = code;
	
	cout << "Indivíduo cadastrado com sucesso!";
}

//void Individuos::inicializaFuncionario(int code);	// cadastro de funcionarios	

