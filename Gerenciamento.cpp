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
}

//-------------------------------------------------------------------------------------------------------------------------------------

void Gerenciamento::readFromFileIndividuos()	// este m�todo l� o arquivo dos individuos e coloca as informa��es na lista individuos
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
		
	if(all.size()<8)	//se o txt est� vazio, n�o h� o que carregar dele
		return;	
		
	all.pop_back();		// esse popback � necess�rio pois o ultimo termo do arquivo sempre � um "endl"
		
	
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
		cout << "N�o foi poss�vel abrir o arquivo\n";
	
}

//-------------------------------------------------------------------------------------------------------------------------------------
	
void Gerenciamento::addIndividuos()	//adiciona n indiv�duos (clientes) na lista.
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

int Gerenciamento::busca_binaria(int x, int N, int a[])	//este m�todo recebe um array e uma chave e retorna a posicao da chave no array. Se a sa�da � -1,
{														//a chave n�o foi encontrada
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

//atualiza o iterator para a posi��o buscada. Se a flag de sa�da for 0, n�o encontrou o indiv�duo, se for 1, encontrou
void Gerenciamento::buscaIndividuo(int& flag, list<Individuos>::iterator& it)	// flag inicialmente � 0
{
	int pos_individuo;	//posicao do individuo com c�digo fornecido
	int code,j;
	string arquivo = "individuos.txt";
	vector<int>::size_type i;
	
	Gerenciamento::readFromFileIndividuos();
	
	it = individuos.begin();
	
	int size = static_cast<int>(codigos_individuos.size());
	int a[size];
	
	for(i=0;i<codigos_individuos.size();i++)	//carrega o array com os elementos de codigos_individuos
		a[static_cast<int>(i)] =  codigos_individuos[i];
	
	cout << "Digite o c�digo da pessoa: ";
	cin >> code;
	cout << endl;
	
	pos_individuo = Gerenciamento::busca_binaria(code,size,a);
	
	
	if(pos_individuo == -1)
		cout << "O indiv�duo n�o est� cadastrado." << endl;
	else
	{
		flag = 1;
		for(j=0;j<pos_individuo;j++)	
			it++;	
	}
	
	
}

//-------------------------------------------------------------------------------------------------------------------------------------

void Gerenciamento::removeIndividuo()	//remove um indiv�duo da lista
{
	string arquivo = "individuos.txt";
	list<Individuos>::iterator it;
	int flag = 0;
	
	Gerenciamento::buscaIndividuo(flag,it);
	
	if(flag == 1)	// se o individuo est� cadastrado, apaga ele
		it = individuos.erase(it);
	
	Gerenciamento::writeFileIndividuos();
}

//-------------------------------------------------------------------------------------------------------------------------------------

void Gerenciamento::editaIndividuo()	//edita n par�metros de um dado indiv�duo
{
	int flag = 0;
	list<Individuos>::iterator it;
	list<Individuos>::size_type i,j,k;
	int opcao = 1;
	
	if(individuos.size()==0)	//garante que eu n�o vou ficar lendo o arquivo � toa
		Gerenciamento::readFromFileIndividuos();	
			
	i = individuos.size();
	
	Gerenciamento::buscaIndividuo(flag,it);

	if(flag == 0)	//se n�o achou o indiv�duo, n�o tem o que editar
		return;
	
	while(opcao != 0)
	{
		cout << "1.Nome: " << (*it).nome << endl;
		cout << "2.Email: " <<  (*it).email << endl;
		cout << "3.Telefone: " <<  (*it).telefone << endl;
		cout << "4.Endere�o: " <<  (*it).endereco << endl; 
		cout << "5.RG: " <<  (*it).RG << endl;
		cout << "6.Funcion�rio: " << (*it).funcionario << endl;
		cout << endl;
	
		cout << "Digite o n�mero correspondente ao campo que deseja editar. Se j� terminou de editar digite '0': ";
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
			
			case 6 : cout << "Digite o cargo do indiv�duo atualizado (0 se n�o � funcion�rio, 1 se � funcion�rio): ";
					 cin >> (*it).funcionario;
					 k = individuos.size();
					 if(k > i)
					 {
					 	for(j=0;j<(k-i);j++)
					 		individuos.pop_back();
					 }
					 break;
					 
			default:  cout << "Voc� digitou uma op��o inv�lida.";
					  break;			   
					  		 		 		 		 	 		 		 		 		 		 		 
		}
	}
	
	Gerenciamento::writeFileIndividuos();
	
}

//-------------------------------------------------------------------------------------------------------------------------------------

void Gerenciamento::readFromFileLivros() //salva os dados de "livros.txt" na lista livros
{
	string linha;
	vector<string> all;
	vector<string>::size_type j;
	string arquivo = "livros.txt";
	
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
		
	if(all.size()<6)	//se o txt est� vazio, n�o h� o que carregar dele
		return;	
		
	all.pop_back();		// esse popback � necess�rio pois o ultimo termo do arquivo sempre � um "endl"
	
	for(j=0;j<all.size();j++)	// separa os elementos de all e os insere corretamente em livros
	{
		Livros objLivro;
		
		objLivro.titulo = all[j];
		j++;
		
		objLivro.autor = all[j];
		j++;
		
		objLivro.editora = all[j];
		j++;	
		
		objLivro.edicao = all[j];
		j++;
		
		objLivro.codigoIndividuosSolicitantes = all[j];
		j++;
			
		objLivro.nExemplares = stoi(all[j]);
		
		livros.push_back(objLivro);	
		titulos_livros.push_back(objLivro.titulo);		
	}
	
}

//-------------------------------------------------------------------------------------------------------------------------------------

void Gerenciamento::writeFileLivros()
{
	string arquivo = "livros.txt";
	list<Livros>::iterator it;
	
	if(livros.size() == 0)
		return;
	
	ofstream meuarquivo2(arquivo);
	if (meuarquivo2.is_open())
	{
		for(it=livros.begin();it!=livros.end();++it)
		{
			meuarquivo2 <<  (*it).titulo << endl;
			meuarquivo2 <<  (*it).autor << endl;
			meuarquivo2 <<  (*it).editora << endl;
			meuarquivo2 <<  (*it).edicao << endl; 
			meuarquivo2 <<  (*it).codigoIndividuosSolicitantes << endl;
			meuarquivo2 <<  (*it).nExemplares << endl;
		}
		
		meuarquivo2.close();
	}
	else 
		cout << "N�o foi poss�vel abrir o arquivo\n";
	
}

//-------------------------------------------------------------------------------------------------------------------------------------

void Gerenciamento::addLivros()	//adiciona n livros na lista.
{
	int n,i;
	list<Livros>::iterator it;
	string arquivo = "livros.txt";
	
	Gerenciamento::readFromFileIndividuos();
	
	cout << "Digite quantos livros vai cadastrar: ";
	cin >> n;
		
	
	for(i=0;i<n;i++)
	{
		Livros livro;	// cria um objeto da classe Livros
		livro.inicializaLivro();
		livros.push_back(livro);
	}
	
	Gerenciamento::mostraLivros();system("pause");
	
	Gerenciamento::writeFileLivros();
}

//-------------------------------------------------------------------------------------------------------------------------------------

void Gerenciamento::buscaLivro(int& flag, list<Livros>::iterator& it)
{
	string arquivo = "livros.txt";
	string title,edition;
	
	Gerenciamento::readFromFileLivros();
	
	it = livros.begin();
	
	cout << "Digite o t�tulo do livro: ";
	cin >> title;
	cout << endl;
	
	cout << "Digite a edi��o do livro: ";
	cin >> edition;
	cout << endl;
	
	for(it = livros.begin();it != livros.end();++it)
	{
		if (((*it).titulo == title) && ((*it).edicao == edition))
		{
			flag = 1;
			break;
		}
	}	
}

//-------------------------------------------------------------------------------------------------------------------------------------

void Gerenciamento::removeLivro()
{
	string arquivo = "livros.txt";
	list<Livros>::iterator it;
	int flag = 0;
	
	Gerenciamento::buscaLivro(flag,it);
	
	if(flag == 1)	// se o individuo est� cadastrado, apaga ele
		it = livros.erase(it);
	
	Gerenciamento::writeFileLivros();
	
}

//-------------------------------------------------------------------------------------------------------------------------------------

void Gerenciamento::editaLivro()
	{
	
	int flag = 0;
	list<Livros>::iterator it;
	list<Livros>::size_type i,j,k;
	int opcao = 1;
	
	if(livros.size()==0)	//garante que eu n�o vou ficar lendo o arquivo � toa
		Gerenciamento::readFromFileLivros();	
	
	i = livros.size();
		Gerenciamento::buscaLivro(flag,it);
	
	if(flag == 0)	//se n�o achou o livro, n�o tem o que editar
		return;
	
	while(opcao != 0)
	{
		cout << "1.Titulo: " << (*it).titulo << endl;
		cout << "2.Autor: " <<  (*it).autor << endl;
		cout << "3.Editora: " <<  (*it).editora << endl;
		cout << "4.Edi��o: " <<  (*it).edicao << endl; 
		cout << "5.C�digos dos indiv�duos solicitantes: " <<  (*it).codigoIndividuosSolicitantes << endl;
		cout << "6.N�mero de exemplares dispon�veis: " << (*it).nExemplares << endl;
		cout << endl;
	
		cout << "Digite o n�mero correspondente ao campo que deseja editar. Se j� terminou de editar digite '0': ";
		cin >> opcao;
	
		switch(opcao)
		{
			case 0 : break;
		
			case 1 : cout << "Digite o t�tulo atualizado: ";
					 cin >> (*it).titulo;	
					 k = livros.size();
				 	if(k > i)
				 	{
				 		for(j=0;j<(k-i);j++)
				 			livros.pop_back();
				 	}
				 
				 	break;
				 
			case 2 : cout << "Digite o autor atualizado: ";
					 cin >> (*it).autor;
					 k = livros.size();
					 if(k > i)
				 	{
				 		for(j=0;j<(k-i);j++)
				 			livros.pop_back();
				 	}
				 	break;
		
			case 3 : cout << "Digite a editora atualizada: ";
					 cin >> (*it).editora;
					 k = livros.size();
					 if(k > i)
				 	{
				 		for(j=0;j<(k-i);j++)
				 			livros.pop_back();
				 	}
					 break;
				 
			case 4 : cout << "Digite a edi��o atualizada: ";
					 cin >> (*it).edicao;
					 k = livros.size();
					 if(k > i)
				 	{
				 		for(j=0;j<(k-i);j++)
				 			livros.pop_back();
				 	}
				 	break;
		
			case 5 : cout << "Digite os c�digos dos indiv�duos solicitantes atualizado (digite separando-os por v�rgulas): ";
					 cin >> (*it).codigoIndividuosSolicitantes;
					 k = livros.size();
				 	if(k > i)
					{
				 		for(j=0;j<(k-i);j++)
				 			livros.pop_back();
				 	}
				 	break;	
		
			case 6 : cout << "Digite o n�mero de exemplares dispon�veis atualizado: ";
					 cin >> (*it).nExemplares;
					 k = livros.size();
					 if(k > i)
				 	{
				 		for(j=0;j<(k-i);j++)
				 			livros.pop_back();
				 	}
				 	break;
				 
			default:  cout << "Voc� digitou uma op��o inv�lida.";
					  break;			   
				  		 		 		 		 	 		 		 		 		 		 		 
		}
	}
	
	Gerenciamento::writeFileLivros();
	}

//-------------------------------------------------------------------------------------------------------------------------------------
/*
void Gerenciamento::emprestaLivro()
{	
	string name;
	int code;
	int flag1 = 0,flag2 = 0;
	list<Individuos>::iterator it;
	list<Livros>::iterator li;
	
	Gerenciamento::readFromFileIndividuos();
	Gerenciamento::readFromFileLivros();
	
	cout << "Insira seu c�digo de usu�rio: ";
	cin >> code;
	cout << endl;
	
	Gerenciamento::buscaIndividuo(flag1,it);	// encontra o indiv�duo com c�digo "code", flag = 1 se encontrou o indiv�duo
	
	if(flag1 == 0)
		return;
	
	cout << "Digite o nome do livro que deseja alugar: ";
	cin >> name;
	cout << endl;
	
	//Gerenciamento::buscaLivro(flag2,li);
	
	if(flag2 == 0)
		return;
		
	//Gerenciamento::editaLivro();		
} 
*/
//-------------------------------------------------------------------------------------------------------------------------------------

void Gerenciamento::mostraIndividuos()	//mostra todos indiv�duos cadastrados
{
	string arquivo = "individuos.txt";
	list<Individuos>::iterator it;
	
	
	cout << endl;
	if(individuos.size() == 0)
	{
		cout << "N�o h� nenhum indiv�duo cadastrado." << endl;
		return;
	}
	else
	{
		for(it=individuos.begin();it!=individuos.end();++it)
		{
			cout << "Nome: " << (*it).nome << endl;
			cout << "Email: " <<  (*it).email << endl;
			cout << "Telefone: " <<  (*it).telefone << endl;
			cout << "Endere�o: " <<  (*it).endereco << endl; 
			cout << "RG: " <<  (*it).RG << endl;
			cout << "C�digo: " <<  (*it).codigo << endl;
			cout << "Funcion�rio: " << (*it).funcionario << endl;
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
		cout << "N�o h� nenhum livro cadastrado." << endl;
	else
	{
		for(it=livros.begin();it!=livros.end();++it)
		{
			cout << "T�tulo: " << (*it).titulo << endl;
			cout << "Autor: " <<  (*it).autor << endl;
			cout << "Editora: " <<  (*it).editora << endl;
			cout << "Edi��o: " <<  (*it).edicao << endl; 
			cout << "C�digo dos indiv�duos solicitantes" << (*it).codigoIndividuosSolicitantes << endl;
			cout << "N�mero de exemplares dispon�veis: " <<  (*it).nExemplares << endl;
			cout << endl;
		}
	}
}

//-------------------------------------------------------------------------------------------------------------------------------------
