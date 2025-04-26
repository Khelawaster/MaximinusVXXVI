#include<stdio.h>
#include<stdlib.h>
#include"My_Logo.h"
#include"MyList_class.h"

main()
{
	
	int Count, N=10;
	MyList_class *Suslik,Oslik(N);
	Suslik= new MyList_class;
	Suslik->Print();
	Oslik.Print();
	getchar();
	
	Suslik->Append(100);Suslik->Append(100);Suslik->Print();getchar();
	Oslik.Remove(5);Oslik.Remove(5);
	Oslik.Print();
	Oslik.Exchange(1,Oslik.Amount());
	Oslik.Print();
	delete Suslik;
	//Purge(Start,0);
		//Print(Start);
	The_End();
	
}
