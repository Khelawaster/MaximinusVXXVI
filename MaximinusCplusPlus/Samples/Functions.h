 
void Put_Array_Int_Hand(int Amount,int Array_I[Amount])
{int Count;
for(Count=0;Count<Amount;Count++){//count+=1  count=count+1
printf("input Array_i[%d] ===>",Count);
 scanf("%d",&Array_I[Count]);         }	
}
void Put_Array_Int_Rand(int Amount,int Array_I[Amount])
{int Count;

srand(time(NULL));

for(Count=0;Count<Amount;Count++){//count+=1  count=count+1

 Array_I[Count]=rand()%101-50;        }	
}
void Put_Array2D_Int_Rand(int Rows,int Columns,int Array_I[Rows][Columns])
{int CountR,CountC;
srand(time(NULL));
for(CountR=0;CountR<Rows;CountR++)
{
for(CountC=0;CountC<Columns;CountC++)
{  Array_I[CountR][CountC]=rand()%101-50;}	
}
}

void Get_Array_Int(int Amount,int Array_I[Amount])
{ int Count;
		for(Count=0;Count<Amount;Count++)//for(Count=0;;Count++)
{  printf("%d ",Array_I[Count]);  }
printf("\n");
} 
void Get_Array2D_Int(int Rows,int Columns,int Array_I[Rows][Columns])
{ int CountR,CountC;
for(CountR=0;CountR<Rows;CountR++)
{
for(CountC=0;CountC<Columns;CountC++)
{  printf("%4d ",Array_I[CountR][CountC]);}
printf("\n");	
}

} 
int Nomer_Max_in_Array(int Amount,int Array_I[Amount],int Start)
{ int Count,Nomer_Max=Start;
for(Count=Start;Count<Amount;Count++)
{if(Array_I[Count]>Array_I[Nomer_Max]) Nomer_Max=Count;}
return Nomer_Max;
}


int Nomer_Min_in_Array(int Amount,int Array_I[Amount],int Start)
{ int Count,Nomer_Min=Start;
for(Count=Start;Count<Amount;Count++)
{if(Array_I[Count]<Array_I[Nomer_Min]) Nomer_Min=Count;}
return Nomer_Min;
}



int Ascend_Array(int Amount,int Array_I[Amount])
{int Count;
for(Count=0;Count<Amount-1;Count++)
{if(Array_I[Count]>Array_I[Count+1])return 0;
	}	
return 1;	
}
int Descend_Array(int Amount,int Array_I[Amount])
{
int Count;
for(Count=0;Count<Amount-1;Count++)
{if(Array_I[Count]<Array_I[Count+1])return 0;
	}	
return 1;	
	
}

void Replace(int Amount,int Array_I[Amount],int N1,int N2)
{
	int tmp;
	tmp=Array_I[N1];
	Array_I[N1]=Array_I[N2];
	Array_I[N2]=tmp;
	
}

