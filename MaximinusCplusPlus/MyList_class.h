struct MyList 
{
	int Info;
	struct MyList *Next;	
};

class MyList_class
{

	struct MyList *Get_Address( int Num)
	{
		int Count;
		if(Num<1)return Start;
		if(Num>Start->Info)Num=Start->Info;
		struct MyList *tmp=Start;
		for(Count=1;Count<=Num;Count++)
			tmp=tmp->Next;
		return tmp;	
	}

protected:
	struct MyList *Start;

public:
	MyList_class(void)
	{
		puts("This is MyList_class default constructor");
		Start=new MyList;
		Start->Info=0;
		Start->Next=NULL;
	}

	MyList_class(int N)
	{
		puts("This is MyList_class constructor with filling");
		Start=new MyList;
		Start->Next=NULL;
		Start->Info=0;
		for(int Count=1;Count<=N;Count++)
			Append(Count*Count);
	}

	MyList_class(int N, int maxRandomValue)
	{
		Start = new MyList;
		Start->Next = NULL;
		Start->Info = 0;
		puts("This is MyList_class constructor random generation");
		srand(time(NULL));
		for (int Count = 1; Count <= N; Count++)
			Append(rand() % maxRandomValue);
	}

	MyList_class(int N, bool manualInput)
	{
		Start = new MyList;
		Start->Next = NULL;
		Start->Info = 0;
		puts("This is MyList_class constructor manual input");
		int tmp;
		for (int Count = 1; Count <= N; Count++)
		{
			printf("Введите элемент %d из %d: ", Count, N);
			scanf("%d", &tmp);
			Append(tmp);
		}
	}

	~MyList_class()
	{
		while (!Empty())
			Remove(1);
		puts("My List_class DESTROYED!!! ");
		delete Start;
		Start = NULL;
	}

	int Get_Value(int Num)
	{ 
		struct MyList *tmp;
		tmp=Get_Address(Num);
		return tmp->Info;
	}

	void Set_Value(int Num, int Data)
	{ 
		struct MyList *tmp;
		tmp=Get_Address(Num);
		tmp->Info=Data;
		return;	
	}

	int Empty(void)
	{
		if(Start->Info) return 0;
		return 1;
	}

	int Amount(void)
	{
		return Start->Info;
	}

	void Remove(int Num)
	{ 
		struct MyList *Before,*Out;
		Before=Get_Address(Num-1);
		Out=Get_Address(Num);
		Before->Next=Out->Next;
		delete (Out);
		Start->Info--;
		return;
	}

	void Append( int Data)
	{
		struct MyList *tmp,*Last;
		tmp=new (struct MyList);
		tmp->Info=Data;
		tmp->Next=NULL;
			Last=Get_Address(Amount());
			Last->Next=tmp;
		Start->Info++;	
	}

	void Insert( int Num, int Data)
	{
		if(Empty())
		{
			Append(Data);
			return;	
		}
		struct MyList *Fresh, *Before;
		Before=Get_Address(Num-1);
		Fresh=new (struct MyList );
		Fresh->Info=Data;
		Fresh->Next=Before->Next;
		Before->Next=Fresh;
		Start->Info++;
	}

	void Print(void)
	{
		struct MyList *tmp;
		tmp=Start;
		if(Empty())
		{
			puts("My List is EMPTY! ");
			return;
		}
		printf("[%d]->%p ",Start->Info,Start->Next);
		while(1)
		{
			tmp=tmp->Next;
			printf("%d -> %p ",tmp->Info,tmp->Next);
			if(tmp->Next==NULL) break;
		}
		printf("\n"); return;	
	}

	void Exchange( int N1, int N2);

	void Maximine() 
	{
		int min = Get_Value(1);
		int max = min;
		int cnt; int temp;
		cnt = Get_Value(0);
		for (int i = 1; i <= cnt; i++) {
			temp = Get_Value(i);
			min = temp < min ? temp : min;
			max = temp > max ? temp : max;
		}
		int Maximinus = (min + max) / 2;
		printf("Максимум %d, минимум %d, полусумма %d\n\n", max, min, Maximinus);
		//проходим второй раз - меняем элементы
		bool OnOff = false;
		for (int i = 1; i < cnt; i++) {
			temp = Get_Value(i);
			if (temp == min || temp == max) {
				OnOff = !OnOff;
			}
			else if (OnOff)
				Set_Value( i, Maximinus);
		}
	}

	void Sort()
	{
		int n = Amount();
		if (n == 1) return;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n - i; j++)
			{
				if (Get_Value(j) >= Get_Value(j + 1))
					Exchange(j, j + 1);
			}
		}

	}

};

void MyList_class::Exchange( int N1, int N2)
{
	struct MyList *Before1, *Before2, *Sam1, *Sam2, *tmp;
	Before1=Get_Address(N1-1);
	Before2=Get_Address(N2-1);
	Sam1=Get_Address(N1);
	Sam2=Get_Address(N2);
	tmp=Before1->Next;
	Before1->Next=Before2->Next;
	Before2->Next=tmp;
	tmp=Sam1->Next;
	Sam1->Next=Sam2->Next;
	Sam2->Next=tmp;
	return;
}

