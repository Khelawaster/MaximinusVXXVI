struct MyList {
int Info;
struct MyList *Next;	
};

struct MyList *Create(void)
{
struct MyList *tmp;
tmp=(struct MyList *)malloc(sizeof(struct MyList));
tmp->Info=0;
tmp->Next=NULL;
return tmp;	
}

struct MyList *Get_Address(struct MyList* Start, int Num)
{int Count;
	if(Num<1)return Start;
	if(Num>Start->Info)Num=Start->Info;
struct MyList *tmp=Start;
for(Count=1;Count<=Num;Count++)
tmp=tmp->Next;
return tmp;	
}

int Get_Value(struct MyList* Start, int Num)
{ struct MyList *tmp;
tmp=Get_Address(Start,Num);
return tmp->Info;
}

void Set_Value(struct MyList* Start, int Num, int Data)
{ struct MyList *tmp;
tmp=Get_Address(Start,Num);
tmp->Info=Data;
return;	
}

int Empty(struct MyList* Start)
{
	if(Start->Info)return 0;
	return 1;
}

int Amount(struct MyList* Start)
{return Start->Info;
}

void Remove(struct MyList* Start, int Num)
{ struct MyList *Before,*Out;
Before=Get_Address(Start,Num-1);
Out=Get_Address(Start,Num);
Before->Next=Out->Next;
free(Out);
Start->Info--;
return;
	
}
void Purge(struct MyList* Start, int Test)
{ while(!Empty(Start))
Remove(Start,1);
if(Test)puts("My List DESTROYED!!! Use Create function! ");
free(Start); Start=NULL;
}

void Append(struct MyList* Start, int Data)
{
	struct MyList *tmp,*Last;
tmp=(struct MyList *)malloc(sizeof(struct MyList));
tmp->Info=Data;
tmp->Next=NULL;
	Last=Start;
	while(1)
	{ if(Last->Next==NULL)break;
	Last=Last->Next;
	}
Last->Next=tmp;
Start->Info++;	
}

void Insert(struct MyList* Start, int Num, int Data)
{
if(Empty(Start)){
Append(Start,Data);return;	}

struct MyList *Fresh, *Before;
Before=Get_Address(Start,Num-1);
Fresh=(struct MyList *)malloc(sizeof(struct MyList));
Fresh->Info=Data;
Fresh->Next=Before->Next;
Before->Next=Fresh;
Start->Info++;

}
void Print(struct MyList* Start)
{
struct MyList *tmp=Start;
if(Start->Info<1){
	puts("My List is EMPTY! ");
	return;}
	printf("[%d]->%p ",Start->Info,Start->Next);
	while(1)
	{tmp=tmp->Next;
	printf("%d -> %p ",tmp->Info,tmp->Next);
	if(tmp->Next==NULL)break;
	}
	printf("\n"); return;	
}
	
void Exchange(struct MyList* Start, int N1, int N2)
{
	struct MyList *Before1, *Before2, *Sam1, *Sam2, *tmp;
	Before1=Get_Address(Start,N1-1);
	Before2=Get_Address(Start,N2-1);
	Sam1=Get_Address(Start,N1);
	Sam2=Get_Address(Start,N2);
	tmp=Before1->Next;
	Before1->Next=Before2->Next;
	Before2->Next=tmp;
	tmp=Sam1->Next;
	Sam1->Next=Sam2->Next;
	Sam2->Next=tmp;
	return;
	}
	
