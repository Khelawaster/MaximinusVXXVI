#include <iostream>
#include <locale.h>
//#include "MyList_class.h"
#include "Settings.h"
#include "MyQueue_class.h"

int main()
{
    //
	char* locale = setlocale(LC_ALL, ""); //�����������
	struct Settings* settings;
	settings=SettingsRead();//������ ������������

	//MyList_class* Suslik;
	//Suslik = settings->ArrayRandomValues==1 ?
	//	new MyList_class (settings->ListDefaultLength, settings->InfoMaxRandomValue)
	//	: new MyList_class (settings->ListDefaultLength,true);
	//Suslik->Print();
	//Suslik->Maximine();
	//Suslik->Print();
	//getchar();

	auto Oslik = settings->ArrayRandomValues==1 ? 
		new MyQueue_class(settings->ListDefaultLength, settings->InfoMaxRandomValue)
		:new MyQueue_class(settings->ListDefaultLength,true);

	/*MyQueue_class* Oslik;
	Oslik = new MyQueue_class();
	Oslik->Enqueue(85);
	Oslik->Enqueue(21);
	Oslik->Enqueue(11);
	Oslik->Enqueue(73);
	Oslik->Enqueue(90);
	Oslik->Enqueue(67);
	Oslik->Enqueue(69);
	Oslik->Enqueue(49);
	Oslik->Enqueue(52);*/

	Oslik->Print();
	getchar();
	//Oslik->Sort();

	int tmp; //���� ��������� ��������� �������� �� �������
	MyQueue_class Tmp_Queue;//��������� �������, ���� ����� �������� �������� � ��������������� �������
	int cnt; //������� ����� ��������� �� ��������� �������
	while (!Oslik->Empty())
	{
		tmp = Oslik->Pop(); //����������� �������� �� ��������� ������
		cnt = Tmp_Queue.Amount();
		if (cnt == 0) //���� �� ��������� ������� �����
			Tmp_Queue.Push(tmp); // ������ ��������� ������� �������
		else
		{
			for (int i = 1; i <= cnt; i++) //���������� ��������� �������
			{
				if (Tmp_Queue.Get_Value(i) < tmp) //���� ������� ������� ������ ����������
				{
					Tmp_Queue.Insert(i, tmp); //������ ��� �� ��������� ������� ����� ���������
					break;
				}
				if (i == Tmp_Queue.Amount()) //���� �� ����� �� ����� - ������ ������� ������� ���������� � �������
					Tmp_Queue.Append(tmp); //��������� ��� � �����
			}
		}
	} //��� �� �������� ��������� �������, ��������������� � �������� ������� � ���������� ���� ��������
	while (!Tmp_Queue.Empty())
	{
		Oslik->Push(Tmp_Queue.Pop()); // ��������� ������ �� ��������� ������� ������� � ��������
	}
	std::cout << "Queue sort!\n";
	Oslik->Print();


	//Suslik->Append(100); Suslik->Append(100); Suslik->Print(); 
	//getchar();
	//Oslik.Remove(5); Oslik.Remove(5);
	//Oslik.Print();
	//Oslik.Exchange(1, Oslik.Amount());
	//Oslik.Print();
	//delete Suslik;
}
