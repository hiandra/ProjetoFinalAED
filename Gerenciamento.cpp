#include <iostream>
#include <algorithm>
#include <list>
#include <string>
#include <fstream>
#include <vector>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <sstream>
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
		cout << "Não foi possível abrir o arquivo." << endl;
	
}

//-------------------------------------------------------------------------------------------------------------------------------------
	
void Gerenciamento::addIndividuos()	//adiciona n indivíduos (clientes) na lista.
{
	int n,i,code;
	list<Individuos>::iterator it;
	string arquivo = "individuos.txt";
	
//	Gerenciamento::readFromFileIndividuos();
	
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
					
		it = individuos.end();
		it--;			
		cout << endl << "Seu código de usuário para login é: " << (*it).codigo << endl << endl; 
	}
	
	//Gerenciamento::writeFileIndividuos();
}

//-------------------------------------------------------------------------------------------------------------------------------------

void Gerenciamento::addFuncionarios()	//adiciona n funcionários na lista.
{
	int n,i,code;
	list<Individuos>::iterator it;
	string arquivo = "individuos.txt";
	
//	Gerenciamento::readFromFileIndividuos();
	
	cout << "Digite quantos funcionários vai cadastrar: ";
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
					
		it = individuos.end();
		it--;
		(*it).funcionario = "1";			
		cout << endl << "Seu código de usuário para login é: " << (*it).codigo << endl << endl;
		 
	}
	
	//Gerenciamento::writeFileIndividuos();
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
	
	if(x==a[R]){	
		//cout << "R: " << R << " a[R]: " << a[R] << endl;
		//system("pause");
		return R;
	}
	else
		return -1;				
}

//-------------------------------------------------------------------------------------------------------------------------------------

//atualiza o iterator para a posição buscada. Se a flag de saída for 0, não encontrou o indivíduo, se for 1, encontrou
void Gerenciamento::buscaIndividuo(int& flag, list<Individuos>::iterator& it)	// flag inicialmente é 0
{
	int pos_individuo;	//posicao do individuo com código fornecido
	int code,j;
	string arquivo = "individuos.txt";
	vector<int>::size_type i;
	
	//Gerenciamento::readFromFileIndividuos();
	
	it = individuos.begin();
	
	int size = static_cast<int>(codigos_individuos.size());
	int a[size];
	
	for(i=0;i<codigos_individuos.size();i++){	//carrega o array com os elementos de codigos_individuos
		a[static_cast<int>(i)] = codigos_individuos[i];
		//cout << "i: " << i << "a[i]: "<< a[i] << endl;
	}
	
	
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
	
	if(flag == 1){	// se o individuo está cadastrado, apaga ele
		it = individuos.erase(it);
	}
	
	cout << "indivíduo removido com sucesso." << endl;
	//Gerenciamento::writeFileIndividuos();
}

//-------------------------------------------------------------------------------------------------------------------------------------

void Gerenciamento::editaIndividuo()	//edita n parâmetros de um dado indivíduo
{
	int flag = 0;
	list<Individuos>::iterator it;
	list<Individuos>::size_type i,j,k;
	int opcao = 1;
	string nada="";
	
	//if(individuos.size()==0)	//garante que o arquivo não será lido caso esteja vazio
	//	Gerenciamento::readFromFileIndividuos();	
			
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
		cout << "6.Senha: " <<  (*it).senha << endl;
		cout << "7.Funcionário: " << (*it).funcionario << endl;
		cout << endl;
	
		cout << "Digite o número correspondente ao campo que deseja editar. Se já terminou de editar, digite '0': ";
		cin >> opcao;
		
		switch(opcao)
		{
			case 0 : break;
			
			case 1 : cout << "Digite o nome atualizado: ";
					 getline(cin,nada);
					 getline(cin,nome);
					 k = individuos.size();
					 if(k > i)
					 {
					 	for(j=0;j<(k-i);j++)
					 		individuos.pop_back();
					 }
					 
					 break;
					 
			case 2 : cout << "Digite o e-mail atualizado: ";
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
					 
			case 4 : cout << "Digite o endereço atualizado: ";
					 getline(cin,nada);
					 getline(cin,endereco);
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

			case 6 : cout << "Digite a senha atualizada: ";
					 cin >> (*it).senha;
					 k = individuos.size();
					 if(k > i)
					 {
					 	for(j=0;j<(k-i);j++)
					 		individuos.pop_back();
					 }
					 break;
			
			case 7 : cout << "Digite o cargo do indivíduo atualizado (0 se não é funcionário, 1 se é funcionário): ";
					 cin >> (*it).funcionario;
					 k = individuos.size();
					 if(k > i)
					 {
					 	for(j=0;j<(k-i);j++)
					 		individuos.pop_back();
					 }
					 break;
					 
			default:  cout << "Você digitou uma opção inválida." << endl << endl;
					  break;			   
					  		 		 		 		 	 		 		 		 		 		 		 
		}
	}
	
	//Gerenciamento::writeFileIndividuos();
	
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
		
	if(all.size()<6)	//se o txt está vazio, não há o que carregar dele
		return;	
		
	all.pop_back();		// esse popback é necessário pois o último termo do arquivo sempre é um "endl"
	
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
		cout << "Não foi possível abrir o arquivo." << endl;
	
}

//-------------------------------------------------------------------------------------------------------------------------------------

void Gerenciamento::addLivros()	//adiciona n livros na lista.
{
	int n,i;
	list<Livros>::iterator it;
	string arquivo = "livros.txt";
	
//	Gerenciamento::readFromFileIndividuos();
	
	cout << endl << "Digite quantos livros vai cadastrar: ";
	cin >> n;
		
	
	for(i=0;i<n;i++)
	{
		Livros livro;	// cria um objeto da classe Livros
		livro.inicializaLivro();
		livros.push_back(livro);
	}
	
	//Gerenciamento::mostraLivros();system("pause");
	
	//Gerenciamento::writeFileLivros();
}

//-------------------------------------------------------------------------------------------------------------------------------------

void Gerenciamento::buscaLivro(int& flag, list<Livros>::iterator& it)
{
	string arquivo = "livros.txt";
	string title,edition;
	string nada = "";
	
	//Gerenciamento::readFromFileLivros();
	
	it = livros.begin();
	
	cout << "Digite o título do livro: ";
	getline(cin,nada);
	getline(cin,title);
	cout << endl;
	
	cout << "Digite a edição do livro: ";
	getline(cin,edition);
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
	
	if(flag == 1)	// se o individuo está cadastrado, apaga ele
		it = livros.erase(it);
	
	cout << "Livro removido com sucesso." << endl;
//	Gerenciamento::writeFileLivros();
	
}

//-------------------------------------------------------------------------------------------------------------------------------------

void Gerenciamento::editaLivro()
	{
	
	int flag = 0;
	list<Livros>::iterator it;
	list<Livros>::size_type i,j,k;
	int opcao = 1;
	string nada = "";
	
	//
	if(livros.size()==0)	//garante que o arquivo não será lido caso esteja vazio
	//	Gerenciamento::readFromFileLivros();	
	
	i = livros.size();
		Gerenciamento::buscaLivro(flag,it);
	
	if(flag == 0)	//se não achou o livro, não tem o que editar
		return;
	
	while(opcao != 0)
	{
		cout << "1.Titulo: " << (*it).titulo << endl;
		cout << "2.Autor: " <<  (*it).autor << endl;
		cout << "3.Editora: " <<  (*it).editora << endl;
		cout << "4.Edição: " <<  (*it).edicao << endl; 
		cout << "5.Códigos dos indivíduos solicitantes: " <<  (*it).codigoIndividuosSolicitantes << endl;
		cout << "6.Número de exemplares disponíveis: " << (*it).nExemplares << endl;
		cout << endl;
	
		cout << "Digite o número correspondente ao campo que deseja editar. Se já terminou de editar, digite '0': ";
		cin >> opcao;
	
		switch(opcao)
		{
			case 0 : break;
		
			case 1 : cout << "Digite o título atualizado: ";					 
					 getline(cin,nada);
					 getline(cin,(*it).titulo);	
					 k = livros.size();
				 	if(k > i)
				 	{
				 		for(j=0;j<(k-i);j++)
				 			livros.pop_back();
				 	}
				 
				 	break;
				 
			case 2 : cout << "Digite o autor atualizado: ";
					 getline(cin,nada);
					 getline(cin,(*it).autor);
					 k = livros.size();
					 if(k > i)
				 	{
				 		for(j=0;j<(k-i);j++)
				 			livros.pop_back();
				 	}
				 	break;
		
			case 3 : cout << "Digite a editora atualizada: ";
					 getline(cin,nada);
					 getline(cin,(*it).editora);
					 k = livros.size();
					 if(k > i)
				 	{
				 		for(j=0;j<(k-i);j++)
				 			livros.pop_back();
				 	}
					 break;
				 
			case 4 : cout << "Digite a edição atualizada: ";
					 getline(cin,nada);
					 getline(cin,(*it).edicao);
					 k = livros.size();
					 if(k > i)
				 	{
				 		for(j=0;j<(k-i);j++)
				 			livros.pop_back();
				 	}
				 	break;
		
			case 5 : cout << "Digite os códigos dos indivíduos solicitantes atualizados (digite separando-os por vírgulas): ";
					 getline(cin,nada);
					 getline(cin,(*it).codigoIndividuosSolicitantes);
					 k = livros.size();
				 	if(k > i)
					{
				 		for(j=0;j<(k-i);j++)
				 			livros.pop_back();
				 	}
				 	break;	
		
			case 6 : cout << "Digite o número de exemplares disponíveis atualizado: ";
					 cin >> (*it).nExemplares;
					 k = livros.size();
					 if(k > i)
				 	{
				 		for(j=0;j<(k-i);j++)
				 			livros.pop_back();
				 	}
				 	break;
				 
			default:  cout << "Você digitou uma opção inválida." << endl << endl;
					  break;			   
				  		 		 		 		 	 		 		 		 		 		 		 
		}
	}
	
//	Gerenciamento::writeFileLivros();
	}

//-------------------------------------------------------------------------------------------------------------------------------------

void Gerenciamento::emprestaLivro()
{	
	string name, edition, str;
	int code;
	int flag1 = 0,flag2 = 0;
	list<Individuos>::iterator it;
	list<Livros>::iterator li;
	
	//Gerenciamento::readFromFileIndividuos();
	//Gerenciamento::readFromFileLivros();
	
	cout << endl << "Insira seu código de usuário: ";
	cin >> code;
	cout << endl;
	
	Gerenciamento::buscaLogin(flag1, it, code);	// encontra o indivíduo com código "code", flag = 1 se encontrou o indivíduo
	
	if(flag1 == 0)
		return;
	
	cout << endl << "Informe os dados do livro que deseja alugar." << endl;
	
	Gerenciamento::buscaLivro(flag2,li);
	
	stringstream ss;
	ss << code;
	string code2 = ss.str();
	
	if(flag2 == 0)
		return;
		
	if((*li).nExemplares==0)
	{
		cout << "Este livro não está disponível no momento, aguarde sua devolução." << endl;
	}
	else
	{	
		if((*li).codigoIndividuosSolicitantes=="-"){
			(*li).codigoIndividuosSolicitantes=code2;
		}
		else{
			str=(*li).codigoIndividuosSolicitantes;
			str=str+" "+code2;
			(*li).codigoIndividuosSolicitantes=str;
		}
		
		(*li).nExemplares--;
		cout << "O livro " << (*li).titulo << " da " << (*li).edicao << " edição foi emprestado com sucesso." << endl;
	}		
} 

//-------------------------------------------------------------------------------------------------------------------------------------

void Gerenciamento::devolveLivro()
{	
	string name, edition, str;
	int code;
	int flag1 = 0,flag2 = 0;
	list<Individuos>::iterator it;
	list<Livros>::iterator li;
	
	//Gerenciamento::readFromFileIndividuos();
	//Gerenciamento::readFromFileLivros();
	
	cout << endl << "Insira seu código de usuário: ";
	cin >> code;
	cout << endl;
	
	Gerenciamento::buscaLogin(flag1, it, code);	// encontra o indivíduo com código "code", flag = 1 se encontrou o indivíduo
	
	if(flag1 == 0)
		return;
	
	cout << endl << "Informe os dados do livro que deseja devolver." << endl;
	
	Gerenciamento::buscaLivro(flag2,li);
	
	stringstream ss;
	ss << code;
	string code2 = ss.str();
	
	if(flag2 == 0)
		return;
			
		
		if((*li).codigoIndividuosSolicitantes=="-"){
			cout << "O livro não está emprestado." << endl;
		}
		else{
			string str, str3, str4;
			str=(*li).codigoIndividuosSolicitantes;
			str3=code2;
			str4="";	
		
			size_t found = str.find(str3);
			while (found != std::string::npos) {
			    str.replace(found,str3.length(),str4);
			    found=str.find(str3,found+1);
			} 
			
			if(str=="" || str==" "){
				str="-";	
			}
			(*li).codigoIndividuosSolicitantes=str;
			(*li).nExemplares++;
			cout << "O livro " << (*li).titulo << " da " << (*li).edicao << " edição foi devolvido com sucesso." << endl;
		}
		
		
		
} 

//-------------------------------------------------------------------------------------------------------------------------------------

void Gerenciamento::mostraIndividuos()	//mostra todos indivíduos cadastrados
{
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
			cout << "Senha: " <<  (*it).senha << endl;
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
//	Gerenciamento::readFromFileLivros();
	
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
			cout << "Códigos dos indivíduos solicitantes: " << (*it).codigoIndividuosSolicitantes << endl;
			cout << "Número de exemplares disponíveis: " <<  (*it).nExemplares << endl;
			cout << endl;
		}
	}
}

//-------------------------------------------------------------------------------------------------------------------------------------

void Gerenciamento::menuLogin()
{
	string nada,senhaV;
	int code,flagOK=-1,flag=0;
	list<Individuos>::iterator it;
	bool voltar=0;
	
	while(flagOK==-1){
		system("cls");
		cout << "\t\t\t" << "#################### Login ##################"<< endl;
		cout << "\t\t\t" << "#                                           #"<< endl;
		cout << "\t\t\t" << "# 1. Informe o Código de Usuário: ";cin>>code;
		cout << "\t\t\t" << "#                                           #"<< endl;
		cout << "\t\t\t" << "# 2. Informe a Senha de Usuário: ";
		//A senha não aparecerá na tela, apenas * para cada caracter.
		senhaV = "";
		char ch;
		ch = _getch();
		while(ch != 13){ 	//O caracter 13 representa a tecla ENTER.
			senhaV.push_back(ch);
			cout << '*';
			ch = _getch();	
		}
		cout << "\t\t\t" << "#                                           #"<< endl;
		cout << "\t\t\t" << "#############################################"<< endl;
		cout << endl;
		
		Gerenciamento::buscaLogin(flag,it,code);		
		
		if(flag != 0) {
			if(senhaV == (*it).senha) {
				if((*it).funcionario == "1") {
					Gerenciamento::menuFuncionario(flagOK);
					flagOK = -2;
				}
				else {
					Gerenciamento::menuCliente(flagOK);
				}
			}
			else {
				cout << "\t\t\t" << "Senha inválida!" << endl;
				cout << "\t\t\t" << "Digite 1 para voltar ao menu inicial ou" << endl; 
				cout << "\t\t\t" << "digite 0 para tentar o login novamente." << endl;
				cout << "\t\t\t"; cin >> voltar;
				
				if(voltar==1){				
					flagOK = -2;
				}
				else{
					flagOK = -1;
				}				
				cout << "\t\t\t";
				system("pause");
			}
		}
		else {
			cout << "\t\t\t" << "Código de usuário inválido!" << endl;
			cout << "\t\t\t" << "Digite 1 para voltar ao menu inicial ou" << endl; 
			cout << "\t\t\t" << "digite 0 para tentar o login novamente." << endl;
			cout << "\t\t\t"; cin >> voltar;
			
			if(voltar==1){				
				flagOK = -2;
			}
			else{
				flagOK = -1;
			}	
			cout << "\t\t\t";
			system("pause");
		}
	}

}

//-------------------------------------------------------------------------------------------------------------------------------------

bool Gerenciamento::menuInicial()
{
	int op;
	list<Individuos>::iterator it;
	
	Gerenciamento::atualiza();  //atualiza arquivos e listas/vetores	
	
	cout << "\t\t\t" << "######Bem Vindo à Biblioteca########"<<endl;
	cout << "\t\t\t" << "#                                  #"<<endl;
	cout << "\t\t\t" << "# 1. Fazer Login.                  #"<<endl;
	cout << "\t\t\t" << "#                                  #"<<endl;
	cout << "\t\t\t" << "# 2. Fazer Cadastro na plataforma. #"<<endl;
	cout << "\t\t\t" << "#                                  #"<<endl;
	cout << "\t\t\t" << "# 3. Sair do Programa              #"<<endl;
	cout << "\t\t\t" << "#                                  #"<<endl;
	cout << "\t\t\t" << "####################################"<<endl;
	cout << "\t\t\t" << "# Escolha uma das opções: ";cin >> op;cout<<endl;
	
	switch(op){
		case 1:
			Gerenciamento::menuLogin();
			break;
		case 2:
			Gerenciamento::addIndividuos();	
			
			Gerenciamento::atualiza();
					
			system("pause");system("cls");
			break;
		case 3:
			Gerenciamento::writeFileIndividuos();
			Gerenciamento::writeFileLivros();
			return 1;
			break;
		default:
			break;
	}
	return 0;
}

//----------------------------------------------------------------------------------------------------------------------

void Gerenciamento::buscaLogin(int& flag, list<Individuos>::iterator& it, int code)
{
	int pos_individuo;	//posição do indivíduo com código fornecido
	int j;
	vector<int>::size_type i;
	
	//Gerenciamento::readFromFileIndividuos();
	
	it = individuos.begin();
	
	int size = static_cast<int>(codigos_individuos.size());
	int a[size];
	
	for(i=0;i<codigos_individuos.size();i++) {	//carrega o array com os elementos de codigos_individuos
		a[static_cast<int>(i)] =  codigos_individuos[i];
		//cout << a[static_cast<int>(i)] << endl;
	}
	
	pos_individuo = Gerenciamento::busca_binaria(code,size,a);
	
	if(pos_individuo == -1)
		cout << "\t\t\t" << "O indivíduo não está cadastrado." << endl;
	else
	{
		flag = 1;
		for(j=0;j<pos_individuo;j++)	
			it++;
	}
	
}

//-------------------------------------------------------------------------------------------------------------------------------------

void Gerenciamento::menuCliente(int& flagOK){
	
	int op=0,flag=0;
	list<Livros>::iterator itb;
	
	while(op != 2) {
		system("cls");
		cout << "\t\t\t" << "################# Menu Cliente ###############"<< endl;
		cout << "\t\t\t" << "#                                            #"<< endl;
		cout << "\t\t\t" << "# 1. Buscar Livro.                           #"<< endl;
		cout << "\t\t\t" << "#                                            #"<< endl;
		cout << "\t\t\t" << "# 2. Sair.                                   #"<< endl;
		cout << "\t\t\t" << "#                                            #"<< endl;
		cout << "\t\t\t" << "##############################################"<< endl;
		cout << endl;
		
		cout << "\t\t\t" << "Escolha uma das opções: ";
		cin >> op;
		
		switch(op){
			case 1:
				//Gerenciamento::readFromFileIndividuos();
				itb = livros.begin();
				Gerenciamento::buscaLivro(flag,itb);
				
				cout << "\t\t\t" << "Título: " << (*itb).titulo << endl;
				cout << "\t\t\t" << "Autor: " <<  (*itb).autor << endl;
				cout << "\t\t\t" << "Editora: " <<  (*itb).editora << endl;
				cout << "\t\t\t" << "Edição: " <<  (*itb).edicao << endl; 
				cout << "\t\t\t" << "Códigos dos indivíduos solicitantes: " << (*itb).codigoIndividuosSolicitantes << endl;
				cout << "\t\t\t" << "Número de exemplares disponíveis: " <<  (*itb).nExemplares << endl;
				cout << endl;
				system("pause");
				break;
			case 2:
				flagOK = -2;
				break;
			default:
				break;
		}
	}
	
}


//-------------------------------------------------------------------------------------------------------------------------------------
void Gerenciamento::atualiza(){
	Gerenciamento::writeFileIndividuos();
	Gerenciamento::writeFileLivros();
	
	individuos.clear();
	codigos_individuos.clear();
	livros.clear();
	titulos_livros.clear();
	
	Gerenciamento::readFromFileIndividuos();
	Gerenciamento::readFromFileLivros();
}
//-------------------------------------------------------------------------------------------------------------------------------------

void Gerenciamento::menuFuncionario(int& flagOK){
	int op,flag=0;
	bool flagOUT=1;
	list<Livros>::iterator itb;
	list<Individuos>::iterator itInd;
	
	while(flagOUT) {
		system("cls");
		cout << "\t\t\t" << "############### Menu Funcionário #############"<< endl;
		cout << "\t\t\t" << "#                                            #"<< endl;
		cout << "\t\t\t" << "# 1. Buscar Cliente ou Funcionário.          #"<< endl;
		cout << "\t\t\t" << "#                                            #"<< endl;
		cout << "\t\t\t" << "# 2. Adicionar Cliente.                      #"<< endl;
		cout << "\t\t\t" << "#                                            #"<< endl;
		cout << "\t\t\t" << "# 3. Adicionar Funcionário.                  #"<< endl;
		cout << "\t\t\t" << "#                                            #"<< endl;
		cout << "\t\t\t" << "# 4. Mostrar as pessoas cadastradas.         #"<< endl;
		cout << "\t\t\t" << "#                                            #"<< endl;
		cout << "\t\t\t" << "# 5. Remover pessoa cadastrada.              #"<< endl;
		cout << "\t\t\t" << "#                                            #"<< endl;
		cout << "\t\t\t" << "# 6. Editar dados de pessoa cadastrada.      #"<< endl;
		cout << "\t\t\t" << "#                                            #"<< endl;
		cout << "\t\t\t" << "# 7. Buscar Livro.                           #"<< endl;
		cout << "\t\t\t" << "#                                            #"<< endl;
		cout << "\t\t\t" << "# 8. Adicionar Livro.                        #"<< endl;
		cout << "\t\t\t" << "#                                            #"<< endl;
		cout << "\t\t\t" << "# 9. Emprestar Livro.                        #"<< endl;
		cout << "\t\t\t" << "#                                            #"<< endl;
		cout << "\t\t\t" << "# 10. Devolver Livro.                        #"<< endl;
		cout << "\t\t\t" << "#                                            #"<< endl;
		cout << "\t\t\t" << "# 11. Remover Livro.                         #"<< endl;
		cout << "\t\t\t" << "#                                            #"<< endl;
		cout << "\t\t\t" << "# 12. Editar dados de livro do acervo.       #"<< endl;
		cout << "\t\t\t" << "#                                            #"<< endl;
		cout << "\t\t\t" << "# 13. Mostrar os livros cadastrados.         #"<< endl;
		cout << "\t\t\t" << "#                                            #"<< endl;
		cout << "\t\t\t" << "# 14. Sair.                                  #"<< endl;
		cout << "\t\t\t" << "#                                            #"<< endl;
		cout << "\t\t\t" << "##############################################"<< endl;
		cout << endl;
		
		cout << "\t\t\t" << "Escolha uma das opções: ";
		cin >> op;
		
		switch(op){
			case 1:
				Gerenciamento::buscaIndividuo(flag,itInd);
				
				if(flag==1){
				cout << "Nome: " << (*itInd).nome << endl;
				cout << "Email: " <<  (*itInd).email << endl;
				cout << "Telefone: " <<  (*itInd).telefone << endl;
				cout << "Endereço: " <<  (*itInd).endereco << endl; 
				cout << "RG: " <<  (*itInd).RG << endl;
				cout << "Código: " <<  (*itInd).codigo << endl;
				cout << "Funcionário: " << (*itInd).funcionario << endl;
				}
				
				flag=0;
				system("pause");system("cls");
				break;
			case 2:
				Gerenciamento::addIndividuos();
					
				Gerenciamento::atualiza();
						
				system("pause");system("cls");			
				break;
			case 3:
				Gerenciamento::addFuncionarios();
				
				Gerenciamento::atualiza();
						
				system("pause");system("cls");
				break;
			case 4:
				Gerenciamento::mostraIndividuos();
				
				Gerenciamento::atualiza();
				break;
			case 5:
				Gerenciamento::removeIndividuo();
				
				Gerenciamento::atualiza();
				
				break;
			case 6:
				Gerenciamento::editaIndividuo();
				
				Gerenciamento::atualiza();				
				break;
			case 7:
				Gerenciamento::buscaLivro(flag, itb);
				if(flag==1){				
				cout << "Título: " << (*itb).titulo << endl;
				cout << "Autor: " <<  (*itb).autor << endl;
				cout << "Editora: " <<  (*itb).editora << endl;
				cout << "Edição: " <<  (*itb).edicao << endl; 
				cout << "Códigos dos indivíduos solicitantes: " << (*itb).codigoIndividuosSolicitantes << endl;
				cout << "Número de exemplares disponíveis: " <<  (*itb).nExemplares << endl;
				}
				
				flag=0;
				system("pause");system("cls");
				break;
			case 8:
				Gerenciamento::addLivros();
				
				Gerenciamento::atualiza();
				
				system("pause");system("cls");
				break;
			case 9:
				Gerenciamento::emprestaLivro();
				
				Gerenciamento::atualiza();
				system("pause");system("cls");
				break;				
			case 10:
				Gerenciamento::devolveLivro();
				
				Gerenciamento::atualiza();
				system("pause");system("cls");
				break;				
			case 11:
				Gerenciamento::removeLivro();
				
				Gerenciamento::atualiza();
				system("pause");system("cls");
				break;
			case 12:
				Gerenciamento::editaLivro();
				
				Gerenciamento::atualiza();
				system("pause");system("cls");
				break;
			case 13:
				Gerenciamento::mostraLivros();
				system("pause");system("cls");
				break;
			case 14:				
				Gerenciamento::atualiza();				
				flagOUT = 0;
				flagOK = -2;
				break;
			default:
				break;
		}
	}

}

