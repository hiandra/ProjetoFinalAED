#include <iostream>
#include <list>
#include <string>
#include <fstream>
using namespace std;

class Individuos{
	
	public:
		string nome;
		string email;
		string telefone;
		string endereco;
		string RG;
		
	Individuos()	//construtor da classe
	{
		nome = "";
		email = "";
		telefone = "";
		endereco = "";
		RG = "";
	}
	
	public: void inicializa()	//cadastro � feito pelo funcion�rio da biblioteca
	{	
		string nada = "";
		
		cout << "Digite o RG: ";
		cin >> RG;
		system("pause");
		cout << endl;
		
		cout << "Digite o nome completo: ";
		getline(cin,nada);
		getline(cin,nome);
		system("pause");
		cout << endl;
		
		cout << "Digite o email: ";
		cin >> email;
		system("pause");
		cout << endl;
		
		cout << "Digite o telefone com DDD: ";
		cin >> telefone;
		system("pause");
		cout << endl;
		
		cout << "Digite o endereco: ";
		cin >> endereco;
		system("pause");
		cout << endl;
		
	}	
};

class Livros{
	
	public:
		string titulo;
		string autor;
		string editora;
		int edicao;
		
	Livros()
	{
		titulo = "";
		autor = "";
		editora = "";
		edicao = -1;
	}
	
	public: void inicializa()
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
	}
};

class Gerenciamento : public Individuos, public Livros{
	
	public:
		list<Individuos> individuos;	//individuos � a lista com todas pessoas cadastradas
		list<Livros> livros;	//livros � a lista com todos os livros cadastrados
		
	Gerenciamento()	
	{
		individuos.clear();
		livros.clear();		
	}	
		
	void addIndividuos()	//adiciona n indiv�duos na lista
	{
		int n,i;
		list<Individuos>::iterator it;
		string arquivo = "individuos.txt";
		cout << "Digite quantas pessoas vai cadastrar: ";
		cin >> n;
		
		for(i=0;i<n;i++)
		{
			Individuos pessoa;	// cria um objeto da classe Individuos
			pessoa.inicializa();
			individuos.push_back(pessoa);
		}
		
		ofstream meuarquivo(arquivo.c_str(),fstream::app);
		if (meuarquivo.is_open())
		{
    		for(it=individuos.begin();it!=individuos.end();++it)
			{
				meuarquivo << (*it).nome << endl;
				meuarquivo << (*it).email << endl;
				meuarquivo << (*it).telefone << endl;
				meuarquivo << (*it).endereco << endl; 
				meuarquivo << (*it).RG << endl;
				meuarquivo << endl;
			}
    		
			
			meuarquivo.close();
		}
		else 
 			cout << "N�o foi poss�vel abrir o arquivo\n";
	}
			
};

int main()
{
	setlocale(LC_ALL,"portuguese");
	Gerenciamento obj1;
	obj1.addIndividuos();
	
	
	return 0;
	
}










