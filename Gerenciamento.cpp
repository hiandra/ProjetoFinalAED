#include <iostream>
#include <algorithm>
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
		
	if(all.size()<8)	//se o txt está vazio, não há o que carregar dele
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
		
		pessoa.senha = all[j];
		j++;
		
		pessoa.funcionario = all[j];
		j++;
	
		pessoa.codigo = stoi(all[j]);	
		codigos_individuos.push_back(pessoa.codigo);
					
		individuos.push_back(pessoa);			
	}
}	

//-------------------------------------------------------------------------------------------------------------------------------------

void Gerenciamento::writeFileIndividuos()
{
	string arquivo = "individuos.txt";
	list<Individuos>::iterator it;
	
	if(individuos.size() == 0)
		return;
	
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
			meuarquivo2 <<  (*it).senha << endl;
			meuarquivo2 <<  (*it).funcionario << endl;
			meuarquivo2 <<  (*it).codigo << endl;
		}
		
		meuarquivo2.close();
	}
	else 
		cout << "Não foi possível abrir o arquivo\n";
	
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
		pessoa.inicializaCliente(code);
		individuos.push_back(pessoa);
		code++;
	}
	
	Gerenciamento::writeFileIndividuos();
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

void Gerenciamento::buscaIndividuo(int& flag, list<Individuos>::iterator& it)	// flag inicialmente é 0
{
	int pos_individuo;	//posicao do individuo com código fornecido
	int code,j;
	string arquivo = "individuos.txt";
	vector<int>::size_type i;
	
	Gerenciamento::readFromFileIndividuos();
	
	it = individuos.begin();
	
	int size = static_cast<int>(codigos_individuos.size());
	int a[size];
	
	for(i=0;i<codigos_individuos.size();i++)	//carrega o array com os elementos de codigos_individuos
		a[static_cast<int>(i)] =  codigos_individuos[i];
	
	cout << "Digite o código da pessoa: ";
	cin >> code;
	cout << endl;
	
	pos_individuo = Gerenciamento::busca_binaria(code,size,a);
	
	
	if(pos_individuo == -1)
		cout << "O indivíduo não está cadastrado." << endl;
	else
	{
		flag = 1;
		for(j=0;j<pos_individuo;j++)	
			it++;	
	}
	
	
}

//-------------------------------------------------------------------------------------------------------------------------------------

void Gerenciamento::removeIndividuo()	//remove um indivíduo da lista
{
	string arquivo = "individuos.txt";
	list<Individuos>::iterator it;
	int flag = 0;
	
	Gerenciamento::buscaIndividuo(flag,it);
	
	if(flag == 1)	// se o individuo está cadastrado, apaga ele
		it = individuos.erase(it);
	
	Gerenciamento::writeFileIndividuos();
}

//-------------------------------------------------------------------------------------------------------------------------------------

void Gerenciamento::editaIndividuo()	//edita n parâmetros de um dado indivíduo
{
	int flag = 0;
	list<Individuos>::iterator it;
	list<Individuos>::size_type i,j,k;
	int opcao = 1;
	
	if(individuos.size()==0)	//garante que eu não vou ficar lendo o arquivo à toa
		Gerenciamento::readFromFileIndividuos();	
			
	i = individuos.size();
	
	Gerenciamento::buscaIndividuo(flag,it);

	if(flag == 0)	//se não achou o indivíduo, não tem o que editar
		return;
	
	while(opcao != 0)
	{
		cout << "1.Nome: " << (*it).nome << endl;
		cout << "2.Email: " <<  (*it).email << endl;
		cout << "3.Telefone: " <<  (*it).telefone << endl;
		cout << "4.Endereço: " <<  (*it).endereco << endl; 
		cout << "5.RG: " <<  (*it).RG << endl;
		cout << "6.Funcionário: " << (*it).funcionario << endl;
		cout << endl;
	
		cout << "Digite o número correspondente ao campo que deseja editar. Se já terminou de editar digite '0': ";
		cin >> opcao;
		
		switch(opcao)
		{
			case 0 : break;
			
			case 1 : cout << "Digite o nome atualizado: ";
					 cin >> (*it).nome;	
					 k = individuos.size();
					 if(k > i)
					 {
					 	for(j=0;j<(k-i);j++)
					 		individuos.pop_back();
					 }
					 
					 break;
					 
			case 2 : cout << "Digite o email atualizado: ";
					 cin >> (*it).email;
					 k = individuos.size();
					 if(k > i)
					 {
					 	for(j=0;j<(k-i);j++)
					 		individuos.pop_back();
					 }
					 break;
			
			case 3 : cout << "Digite o telefone atualizado: ";
					 cin >> (*it).telefone;
					 k = individuos.size();
					 if(k > i)
					 {
					 	for(j=0;j<(k-i);j++)
					 		individuos.pop_back();
					 }
					 break;
					 
			case 4 : cout << "Digite o endereco atualizado: ";
					 cin >> (*it).endereco;
					 k = individuos.size();
					 if(k > i)
					 {
					 	for(j=0;j<(k-i);j++)
					 		individuos.pop_back();
					 }
					 break;
			
			case 5 : cout << "Digite o RG atualizado: ";
					 cin >> (*it).RG;
					 k = individuos.size();
					 if(k > i)
					 {
					 	for(j=0;j<(k-i);j++)
					 		individuos.pop_back();
					 }
					 break;	
			
			case 6 : cout << "Digite o cargo do indivíduo atualizado (0 se não é funcionário, 1 se é funcionário): ";
					 cin >> (*it).funcionario;
					 k = individuos.size();
					 if(k > i)
					 {
					 	for(j=0;j<(k-i);j++)
					 		individuos.pop_back();
					 }
					 break;
					 
			default:  cout << "Você digitou uma opção inválida.";
					  break;			   
					  		 		 		 		 	 		 		 		 		 		 		 
		}
	}
	
	Gerenciamento::writeFileIndividuos();
	
}

//-------------------------------------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------------------------------

void Gerenciamento::mostraIndividuos()	//mostra todos indivíduos cadastrados
{
	string arquivo = "individuos.txt";
	list<Individuos>::iterator it;
	
	
	cout << endl;
	if(individuos.size() == 0)
	{
		cout << "Não há nenhum indivíduo cadastrado." << endl;
		return;
	}
	else
	{
		for(it=individuos.begin();it!=individuos.end();++it)
		{
			cout << "Nome: " << (*it).nome << endl;
			cout << "Email: " <<  (*it).email << endl;
			cout << "Telefone: " <<  (*it).telefone << endl;
			cout << "Endereço: " <<  (*it).endereco << endl; 
			cout << "RG: " <<  (*it).RG << endl;
			cout << "Código: " <<  (*it).codigo << endl;
			cout << "Funcionário: " << (*it).funcionario << endl;
			cout << endl;
		}
	}
	
	system("pause");system("cls");
	
}

//-------------------------------------------------------------------------------------------------------------------------------------

void Gerenciamento::mostraLivros()	//mostra todos os livros cadastrados
{
	string arquivo = "livros.txt";
	list<Livros>::iterator it;
	Gerenciamento::readFromFileLivros();
	
	cout << endl;
	if(livros.size() == 0)
		cout << "Não há nenhum livro cadastrado." << endl;
	else
	{
		for(it=livros.begin();it!=livros.end();++it)
		{
			cout << "Título: " << (*it).titulo << endl;
			cout << "Autor: " <<  (*it).autor << endl;
			cout << "Editora: " <<  (*it).editora << endl;
			cout << "Edição: " <<  (*it).edicao << endl; 
			cout << "Número de exemplares: " <<  (*it).nExemplares << endl;
			cout << endl;
		}
	}
}

//-------------------------------------------------------------------------------------------------------------------------------------
