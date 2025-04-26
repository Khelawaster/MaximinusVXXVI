#include<stdio.h>
#include<stdlib.h>
#include"My_Logo.h"
#include"Stack.h"
main(void)
{
	MyStack Suslik, *Oslik;
	Oslik=new MyStack;
	Suslik.Print();
	Oslik->Print();
	for(int Count=1;Count<=10;Count++){
		Suslik.Push(Count);
		Oslik->Push(11-Count);
	}
		Suslik.Print();
		Suslik.MyList_class::Print();
	Oslik->Print();
	Oslik->MyList_class::Print();
	getchar();
	Suslik.Pop();
	Suslik.Pop();
	Suslik.Pop();
	Suslik.Print();
return 0;	
	
}
