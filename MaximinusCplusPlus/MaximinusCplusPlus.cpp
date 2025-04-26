#include <iostream>
#include <locale.h>
#include "MyList_class.h"
#include "Settings.h"

int main()
{
    //std::cout << "Hello World!\n";
	char* locale = setlocale(LC_ALL, ""); //локализация
	struct Settings* settings;
	settings=SettingsRead();//чтение конфигурации
	int Count, N = 10;
	MyList_class* Suslik, Oslik(N);
	Suslik = settings->ArrayRandomValues==1 ?
		new MyList_class (settings->ListDefaultLength, settings->InfoMaxRandomValue)
		: new MyList_class (settings->ListDefaultLength,true);
	Suslik->Print();
	Suslik->Maximine();
	Suslik->Print();
	getchar();
	//Suslik->Append(100); Suslik->Append(100); Suslik->Print(); 
	//getchar();
	//Oslik.Remove(5); Oslik.Remove(5);
	//Oslik.Print();
	//Oslik.Exchange(1, Oslik.Amount());
	//Oslik.Print();
	//delete Suslik;
}
