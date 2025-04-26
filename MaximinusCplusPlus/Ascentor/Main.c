#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "Settings.h"
#include "List.h"
#include "MyFunctions.h"


void MaximineListByValue(struct MyList* list) {
	int min = INT_MAX;	int max = INT_MIN;
	struct MyList* tmp = list->Next; //ищем, начиная с первого элемента
	while (1) {
		if (tmp->Info <= min)
			min = tmp->Info;
		if (tmp->Info >= max)
			max = tmp->Info;
		if (tmp->Next == NULL)
			break;
		tmp = tmp->Next;
	}
	int Maximinus = (min + max) / 2;
	printf("Максимум %d, минимум %d, полусумма %d\n\n", max, min, Maximinus);
	//теперь проходим по второму разу и меняем значения элементов
	tmp = list->Next;
	while (tmp->Next != NULL) {
		if (tmp->Info != min && tmp->Info != max)
			tmp->Info = Maximinus;
		tmp = tmp->Next;
	}
}

void MaximineListByPositionAlpha(struct MyList* list) {
	int min = GetValue(list, 1);
	int max = min;
	int cnt; int temp; 
	cnt = GetValue(list, 0);
	for (int i = 1; i < cnt; i++) {
		temp = GetValue(list, i);
		min = temp < min ? temp : min;
		max = temp > max ? temp : max;
	}
	int Maximinus = (min + max) / 2;
	printf("Максимум %d, минимум %d, полусумма %d\n\n", max, min, Maximinus);
	//проходим второй раз - меняем элементы
	char OnOff = 0;
	for (int i = 1; i < cnt; i++) {
		temp = GetValue(list, i);
		if (temp ==min || temp == max) {
			OnOff = abs(OnOff - 1);
		}
		else if (OnOff == 1)
			SetValue(list,i, Maximinus);
	}
}




int main() 
{
	char* locale = setlocale(LC_ALL, ""); //локализация
	settings=SettingsRead();//чтение конфигурации

	Croco();
	struct MyList* lst;
	if (settings->ArrayRandomValues == 1)
		lst = CreateWithLengthRandom(settings->ListDefaultLength);
	else
		lst = CreateManual();
	
	Print(lst);
	//MaximineListByValue(lst);
	MaximineListByPositionAlpha(lst);
	printf("В списке целых чисел все элементы между Max и Min заменить полусуммой Max и Min\n");
	Print(lst);
	freeList(lst);

	/*printf("Создание стека\n");
	struct MyStack* st = CreateStack();
	st->Push(st, 13);
	Append(st->base, 26);
	Append(st->base, 39);
	EnqueueHead(st->base, 7);
	Print(st->base);

	int i = Dequeue(st->base);
	printf("\n%d\n",i);
	i= st->Pop(st);
	printf("\n%d\n", i);
	i = Pop(st->base);
	printf("\n%d\n",i);
	Print(st->base);*/
	Exit();
}