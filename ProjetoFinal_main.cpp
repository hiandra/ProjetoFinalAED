#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include "Individuos.h"
#include "Livros.h"
#include "Gerenciamento.h"
using namespace std;

// Para usar SetConsoleTextAttribute(), ou seja, alterar cores do plano de fundo e do texto.
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); 

int main()
{
	setlocale(LC_ALL,"portuguese");
	Gerenciamento obj1;
	int flag = 0;
	bool flagSair = 0;
	list<Livros>::iterator it;
	SetConsoleTextAttribute(console, 112); //112 = fundo cinza e letras pretas
	system("cls");
	
	while(1) {
		flagSair = obj1.menuInicial();
		if(flagSair){
			return 0;
		}
		system("cls");
	}
	
	//obj1.addIndividuos();
	
	
	
	return 0;
	
}
