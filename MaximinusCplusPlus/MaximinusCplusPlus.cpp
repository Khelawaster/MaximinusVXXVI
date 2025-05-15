#include <iostream>
#include <locale.h>
//#include "MyList_class.h"
#include "Settings.h"
#include "MyQueue_class.h"

int main()
{
    //
	char* locale = setlocale(LC_ALL, ""); //локализация
	struct Settings* settings;
	settings=SettingsRead();//чтение конфигурации

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

	int tmp; //сюда извлекаем очередное значение из очереди
	MyQueue_class Tmp_Queue;//временная очередь, куда будем помещать значения в отсортированном порядке
	int cnt; //текущее число элементов во временной очереди
	while (!Oslik->Empty())
	{
		tmp = Oslik->Pop(); //вытаскиваем значение из исходного списка
		cnt = Tmp_Queue.Amount();
		if (cnt == 0) //если во временной очереди пусто
			Tmp_Queue.Push(tmp); // просто добавляем текущий элемент
		else
		{
			for (int i = 1; i <= cnt; i++) //перебираем временную очередь
			{
				if (Tmp_Queue.Get_Value(i) < tmp) //если текущий элемент больше очередного
				{
					Tmp_Queue.Insert(i, tmp); //ставим его во временную очередь перед очередным
					break;
				}
				if (i == Tmp_Queue.Amount()) //если мы дошли до конца - значит текущий элемент наименьший в очереди
					Tmp_Queue.Append(tmp); //добавляем его в конец
			}
		}
	} //так мы получили временную очередь, отсортированную в обратном порядке и опустошили нашу исходную
	while (!Tmp_Queue.Empty())
	{
		Oslik->Push(Tmp_Queue.Pop()); // переносим данные из временной очереди обратно в исходную
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
