#include <iostream>
#include "MyList_class.h"
class MyQueue_class : public MyList_class 
{
	public:

		MyQueue_class(void) : MyList_class()
		{
			puts("Default Constructor of Queue!!!!");	
		}

		MyQueue_class(int N, int maxRandomValue) : MyList_class(N, maxRandomValue)
		{
			puts("Random Queue!!!!");
		}

		MyQueue_class(int N, bool manualInput) : MyList_class(N, manualInput)
		{
			puts("Manual Queue!!!!");
		}
		~MyQueue_class()
		{
			puts("Destructor of Queue!!!!");
		}	

		void Enqueue(int data)
		{
			Append(data);
		}

		int Dequeue()
		{
			int ret = Get_Value(1);
			Remove(1);
			return ret;
		}

		// <это я отремил>
		int Show_Up_Stack(void)
		{
			return Get_Value(1);
		}
		
		void Push(int Num)
		{ 
			Insert(1,Num);
		}

		int Pop(void)
		{
			int tmp;
			int a = Amount();
			tmp=Get_Value(a);
			Remove(a);
			return tmp;	
		}

		void Print(void);
		void Sort();
	
};

void MyQueue_class::Print(void)
{
	if(Empty())
	{
		puts("Queue is Empty!!!");
		return;
	}
	int tmp;
	MyQueue_class Tmp_Queue;
	while(!Empty())
	{
		tmp=Pop();
		printf("%d ",tmp);
		Tmp_Queue.Push(tmp);
	}
	puts("");
	while(!Tmp_Queue.Empty())
	{
		tmp=Tmp_Queue.Pop();
		//printf("%d ",tmp);
		Push(tmp);
	}
}
// </это я отремил>
