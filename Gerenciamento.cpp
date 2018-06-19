#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <vector>
#include "Individuos.h"
#include "Livros.h"
#include "Gerenciamento.h"
using namespace std;

	
Gerenciamento::Gerenciamento()	
{
	individuos.clear();
	livros.clear();		
	codigos_individuos.clear();
	codigos_livros.clear();
}

//-------------------------------------------------------------------------------------------------------------------------------------

void Gerenciamento::readFromFileIndividuos()	// este método lê o arquivo dos individuos e coloca as informações na lista individuos
{	
	string linha;
	vector<string> all;
	vector<string>::size_type j;
	string arquivo = "individuos.txt";
	
	ifstream meuarquivo1(arquivo); 
	if (meuarquivo1.is_open())
	{
		while (! meuarquivo1.eof() ) 
		{
  			getline (meuarquivo1,linha);
			all.push_back(linha);                    //guarda todos os elementos do arquivo em linha reta                               
		}
		meuarquivo1.close();
	}
	else
		return;
		
	if(all.size()<5)	//se o txt está vazio, não há o que carregar dele
		return;	
		
	all.pop_back();		// esse popback é necessário pois o ultimo termo do arquivo sempre é um "endl"
		
	
	for(j=0;j<all.size();j++)	// separa os elementos de all e os insere corretamente em individuos
	{
		Individuos pessoa;
		
		pessoa.nome = all[j];
		j++;
		
		pessoa.email = all[j];
		j++;
		
		pessoa.telefone = all[j];
		j++;	
					
		pessoa.endereco = all[j];
		j++;
			
		pessoa.RG = all[j];
		j++;	
	
		pessoa.codigo = stoi(all[j]);	
		codigos_individuos.push_back(pessoa.codigo);
					
		individuos.push_back(pessoa);			
	}
}	

//-------------------------------------------------------------------------------------------------------------------------------------
	
void Gerenciamento::addIndividuos()	//adiciona n indivíduos (clientes) na lista.
{
	int n,i,code;
	list<Individuos>::iterator it;
	string arquivo = "individuos.txt";
	
	Gerenciamento::readFromFileIndividuos();
	
	cout << "Digite quantas pessoas vai cadastrar: ";
	cin >> n;
	
	if(individuos.size() == 0)
		code = 1;
	else
	{
		it = individuos.end();
		it--;
		code = (*it).codigo + 1;	
	}	
	
	for(i=0;i<n;i++)
	{
		Individuos pessoa;	// cria um objeto da classe Individuos
		pessoa.inicializa(code);
		individuos.push_back(pessoa);
		code++;
	}
	
	ofstream meuarquivo2(arquivo);
	if (meuarquivo2.is_open())
	{
		for(it=individuos.begin();it!=individuos.end();++it)
		{
			meuarquivo2 <<  (*it).nome << endl;
			meuarquivo2 <<  (*it).email << endl;
			meuarquivo2 <<  (*it).telefone << endl;
			meuarquivo2 <<  (*it).endereco << endl; 
			meuarquivo2 <<  (*it).RG << endl;
			meuarquivo2 <<  (*it).codigo << endl;
		}
		
		meuarquivo2.close();
	}
	else 
		cout << "Não foi possível abrir o arquivo\n";
}

//-------------------------------------------------------------------------------------------------------------------------------------

int Gerenciamento::busca_binaria(int x, int N, int a[])	//este método recebe um array e uma chave e retorna a posicao da chave no array. Se a saída é -1,
{														//a chave não foi encontrada
	int L=0;
	int R = N-1;
	int m;
	
	while(L<R)
	{
		m = (L+R)/2;
		
		if(a[m] < x)
			L = m+1;
		else
			R = m;	
	}
	
	if(x==a[R])
		return R;
	else
		return -1;				
}

//-------------------------------------------------------------------------------------------------------------------------------------

void Gerenciamento::removeIndividuo()	//remove um indivíduo da lista
{
	int code,j;
	string arquivo = "individuos.txt";
	vector<int>::size_type i;
	int pos_individuo;	//posicao do individuo com código fornecido
	list<Individuos>::iterator it;
	
	Gerenciamento::readFromFileIndividuos();
	
	
	it = individuos.begin();
	
	int size = static_cast<int>(codigos_individuos.size());
	int a[size];
	
	for(i=0;i<codigos_individuos.size();i++)	//carrega o array com os elementos de codigos_individuos
		a[static_cast<int>(i)] =  codigos_individuos[i];
	
	cout << "Digite o código da pessoa que deseja remover: ";
	cin >> code;
	cout << endl;
	
	pos_individuo = Gerenciamento::busca_binaria(code,size,a);
	
	
	if(pos_individuo == -1)
		cout << "O indivíduo não está cadastrado." << endl;
	else
	{
		for(j=0;j<pos_individuo;j++)	
			it++;
			
		it = individuos.erase(it);	
	}	
	
	
	
	ofstream meuarquivo2(arquivo);
	if (meuarquivo2.is_open())
	{
		for(it=individuos.begin();it!=individuos.end();++it)
		{
			meuarquivo2 <<  (*it).nome << endl;
			meuarquivo2 <<  (*it).email << endl;
			meuarquivo2 <<  (*it).telefone << endl;
			meuarquivo2 <<  (*it).endereco << endl; 
			meuarquivo2 <<  (*it).RG << endl;
			meuarquivo2 <<  (*it).codigo << endl;
		}	
	}
}
