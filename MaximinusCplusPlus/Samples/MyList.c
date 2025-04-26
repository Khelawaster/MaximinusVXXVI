#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"My_Logo.h"
#include"MyList.h"

main()
{
	struct MyList *Start;
	int Count, N=10;
	Start=Create();
	Print(Start);
	getchar();
	for(Count=1;Count<=N;Count++)
	Append(Start,Count*Count);
	Print(Start);
	for(Count=0;Count<=N;Count++)
	printf("%d ",Get_Value(Start,Count));
	printf("\n");
	getchar();
	Remove(Start,5);Remove(Start,5);
	Print(Start);
	Exchange(Start,1,Amount(Start));
	Print(Start);
	Purge(Start,0);
		//Print(Start);
	The_End();
	
}
