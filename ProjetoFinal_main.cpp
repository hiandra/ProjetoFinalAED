#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <vector>
#include "Individuos.h"
#include "Livros.h"
#include "Gerenciamento.h"
using namespace std;


int main()
{
	setlocale(LC_ALL,"portuguese");
	Gerenciamento obj1;
	int flag = 0;
	bool flagSair = 0;
	list<Livros>::iterator it;
	
	while(1) {
		flagSair = obj1.menuInicial();
		if(flagSair){
			return 0;
		}
		system("cls");
	}
	
	//obj1.addIndividuos();
	//obj1.removeIndividuo();
	//obj1.editaIndividuo();
	//obj1.addLivros();
	//obj1.buscaLivro(flag,it);
	//obj1.removeLivro();
	
	return 0;
	
}
