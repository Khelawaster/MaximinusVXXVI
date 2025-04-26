struct Settings* settings;

struct MyList {
	int Info; //� ������� ����� ��� �������� ����� ����� ���� ��������� ���������
	struct MyList* Next;
};

void Append(struct MyList* start, int data);



struct MyList* Create() {
	struct MyList* ret;
	ret = (struct MyList*)malloc(sizeof(struct MyList));
	ret->Info = 0;
	ret->Next = NULL;
	//printf("�� ������ %p ����������� ����� �����. �������� �� ���������.\n", ret);
	return ret;
}

struct MyList* CreateWithValue(int value) {
	struct MyList* ret;
	ret = Create();
	ret->Info = value;
	//printf("����������� �������� ����� �� ������ %p : %d\n", ret, value);
	return ret;
}

//��������� ������ �������� ����� �� ��������� ����������.
struct MyList* CreateWithLengthRandom(int length) {
	printf("��������� ������ ��������� ����� ������ %d\n", length);
	srand(time(NULL));
	int max = settings->InfoMaxRandomValue + 1;
	struct MyList* ret = CreateWithValue(0);
	for (int i = 0; i < length; i++)
		Append(ret, rand() % max);
	printf("��������� ������ ���������\n\n");
	return ret;
}

//������ ���� ������.
struct MyList* CreateManual() {
	printf("������ ���� ������\n������� ���������� ���������\n");
	int n = 0; int tmp;
	scanf("%d" , &n);
	struct MyList* ret = CreateWithValue(0);
	for (int i = 0; i < n; i++)
	{
		printf("������� ������� %d �� %d: ", i+1,n);
		scanf("%d", &tmp);
		Append(ret, tmp);
	}
	printf("��������� ������ ���������\n\n");
	return ret;
}


//��������� ������ �������� ����� �� ��������� �� ���������.
struct MyList* CreateWithLengthDefault(int length) {
	printf("��������� ������ ����� ������ %d �� ��������� %�\n", length, settings->ListElementDefaultInfo);
	struct MyList* ret = CreateWithValue(0);
	for (int i = 0; i < length; i++)
		Append(ret, settings->ListElementDefaultInfo);
	printf("��������� ������ ���������\n\n");
	return ret;
}





struct MyList* GetAddress(struct MyList* start, int num) {
	if (num < 1) return start;
	if (num > start->Info) num = start->Info; //���� ����� ������� �� ������� ������ - ������������ ���������
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

//���������� �������� ��������� ��������. ����� ������������ ��� Pop � Dequeue
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
	struct MyList* tmp = Start; //� ���������� ��� ���������� ��������� �� ������ ������� ��������� �����
	if (Start->Info == 0) //��������� �� ������� ��������� � ������ 
	{
		puts("������ ����!");
		return;
	}
	printf("[%d]->%p ", Start->Info, Start->Next);
	while (1)
	{
		tmp = tmp->Next;//������ �������� ���������� �� ������� ������� � ������� � ���
		printf("%d  -> %p ", tmp->Info, tmp->Next);//%d int %p ������ ���������
		if (tmp->Next == NULL) //���� ��������� �����
			break;
	}
	printf("\n");
	return;
}

//�������� ������� ������ �� ������.
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
		printf("������: �������� � �������� %d �� ����������!\n", Num);
		return 0;  // ��� ������ �������� �� ���������
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




// ������������ ������ ������
void freeList(struct MyList* start) {
	//printf("�������� ������ %p\n", &start);
	struct MyList* tmp = start;
	struct MyList* next;
	int i = 0;
	while (tmp != NULL) {
		//printf("�������� ����� %d �� ������ %p\n", i, tmp);
		next = tmp->Next;
		free(tmp);
		tmp = next;
		i++;
	}
	start = NULL;
	printf("%p = %p", &start, start);
	//printf("\n������� ������ ���������\n\n");
}


