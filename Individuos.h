#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Individuos{
	
	public:
		string nome;
		string email;
		string telefone;
		string endereco;
		string RG;
		string senha;
		int codigo;
		bool funcionario;
		
	Individuos();	//construtor da classe
	
	void inicializa(int code);	//cadastro é feito pelo funcionário da biblioteca
	
};

