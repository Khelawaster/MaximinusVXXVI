struct Settings* settings;

struct MyList {
	int Info; //у первого звена это значение равно числу всех остальных элементов
	struct MyList* Next;
};

void Append(struct MyList* start, int data);



struct MyList* Create() {
	struct MyList* ret;
	ret = (struct MyList*)malloc(sizeof(struct MyList));
	ret->Info = 0;
	ret->Next = NULL;
	//printf("По адресу %p расположено новое звено. Значение по умолчанию.\n", ret);
	return ret;
}

struct MyList* CreateWithValue(int value) {
	struct MyList* ret;
	ret = Create();
	ret->Info = value;
	//printf("Установлено значение звена по адресу %p : %d\n", ret, value);
	return ret;
}

//Генерация списка заданной длины со случайныи значениями.
struct MyList* CreateWithLengthRandom(int length) {
	printf("Генерация списка случайных чисел длиной %d\n", length);
	srand(time(NULL));
	int max = settings->InfoMaxRandomValue + 1;
	struct MyList* ret = CreateWithValue(0);
	for (int i = 0; i < length; i++)
		Append(ret, rand() % max);
	printf("Генерация списка завершена\n\n");
	return ret;
}

//Ручной ввод списка.
struct MyList* CreateManual() {
	printf("Ручной ввод списка\nВведите количество элементов\n");
	int n = 0; int tmp;
	scanf("%d" , &n);
	struct MyList* ret = CreateWithValue(0);
	for (int i = 0; i < n; i++)
	{
		printf("Введите элемент %d из %d: ", i+1,n);
		scanf("%d", &tmp);
		Append(ret, tmp);
	}
	printf("Генерация списка завершена\n\n");
	return ret;
}


//Генерация списка заданной длины со значением по умолчанию.
struct MyList* CreateWithLengthDefault(int length) {
	printf("Генерация списка чисел длиной %d со значением %в\n", length, settings->ListElementDefaultInfo);
	struct MyList* ret = CreateWithValue(0);
	for (int i = 0; i < length; i++)
		Append(ret, settings->ListElementDefaultInfo);
	printf("Генерация списка завершена\n\n");
	return ret;
}





struct MyList* GetAddress(struct MyList* start, int num) {
	if (num < 1) return start;
	if (num > start->Info) num = start->Info; //если адрес выходит за пределы списка - возврашается последний
	struct MyList* tmp = start;
	for (int i = 0; i < num; i++) tmp = tmp->Next;
	return tmp;
}

void Append(struct MyList* start, int data) {
	struct MyList* tmp, * last;
	tmp = CreateWithValue(data);
	last = start;
	while (1) {
		if (last->Next == NULL) break;
		last = last->Next;
	}
	last->Next = tmp;
	start->Info++;
}

//возвращает значение удалённого элемента. Можно использовать как Pop и Dequeue
int Remove(struct MyList* start, int num) {
	struct MyList* before, * out;
	before = GetAddress(start, num - 1);
	out = before->Next;
	before->Next = out->Next;
	int ret = out->Info;
	free(out);
	start->Info--;
	return ret;
}

void Insert(struct MyList* start, int num, int data) {
	struct MyList* before, * new;
	before = GetAddress(start, num - 1);
	new = CreateWithValue(data);
	new->Next = before->Next;
	before->Next = new;
	start->Info++;
}

void Purge(struct MyList* start) {
	while (start->Info > 0) Remove(start, 1);
	return;
}

void Print(struct MyList* Start)
{
	struct MyList* tmp = Start; //в переменную тмп складываем указатель на первый элемент структуры нашей
	if (Start->Info == 0) //проверяем на наличие элементов в списке 
	{
		puts("список ПУСТ!");
		return;
	}
	printf("[%d]->%p ", Start->Info, Start->Next);
	while (1)
	{
		tmp = tmp->Next;//адресс элемента следующего за текущим начиная с первого в тмп
		printf("%d  -> %p ", tmp->Info, tmp->Next);//%d int %p адресс указателя
		if (tmp->Next == NULL) //если последний выход
			break;
	}
	printf("\n");
	return;
}

//Вытащить элемент списка по номеру.
struct MyList* GetItem(struct MyList* list, int number) {
	struct MyList* tmp = list->Next;
	int i = 0;
	while (tmp->Next != NULL) {
		if (i == number)
			return tmp;
		i++;
	}
	return NULL;
}
void Swap(struct MyList* Start, int N1, int N2)
{
	struct MyList* Before1, * Before2, * Sam1, * Sam2, * tmp;
	Before1 = GetAddress(Start, N1 - 1);
	Before2 = GetAddress(Start, N2 - 1);
	Sam1 = GetAddress(Start, N1);
	Sam2 = GetAddress(Start, N2);
	tmp = Before1->Next;
	Before1->Next = Before2->Next;
	Before2->Next = tmp;
	tmp = Sam1->Next;
	Sam1->Next = Sam2->Next;
	Sam2->Next = tmp;
	return;
}
int GetValue(struct MyList* Start, int Num) {
	struct MyList* tmp = GetAddress(Start, Num);
	if (tmp == NULL) {
		printf("Ошибка: элемента с индексом %d не существует!\n", Num);
		return 0;  // или другое значение по умолчанию
	}
	return tmp->Info;
}

void SetValue(struct MyList* Start, int Num, int Data)
{
	struct MyList* tmp;
	tmp = GetAddress(Start, Num);
	tmp->Info = Data;
	return;
}
int Empty(struct MyList* Start)
{
	if (Start->Info)
		return 0;
	return 1;
}

int Amount(struct MyList* Start)
{
	return Start->Info;
}




// Освобождение памяти списка
void freeList(struct MyList* start) {
	//printf("Удаление списка %p\n", &start);
	struct MyList* tmp = start;
	struct MyList* next;
	int i = 0;
	while (tmp != NULL) {
		//printf("Удаление звена %d из ячейки %p\n", i, tmp);
		next = tmp->Next;
		free(tmp);
		tmp = next;
		i++;
	}
	start = NULL;
	printf("%p = %p", &start, start);
	//printf("\nОчистка памяти завершена\n\n");
}


