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
		//void Print(void);
		//int Show_Up_Stack(void){
		//	return Get_Value(1);
		//}
		//void Push(int Num)
		//{ Insert(1,Num);
		//}
		//int Pop(void){
		//int tmp;
		//tmp=Get_Value(1);
		//Remove(1);
		//return tmp;	
		//}
	
};
//void MyQueue::Print(void){
//	if(Empty()){
//		puts("Stack is Empty!!!");
//		return;
//	}
//	int tmp; MyQueue Tmp_Stack;
//	while(!Empty()){
//		tmp=Pop();
//		printf("%d ",tmp);
//		Tmp_Stack.Push(tmp);
//	}
//	puts("");
//	while(!Tmp_Stack.Empty()){
//		tmp=Tmp_Stack.Pop();
//		//printf("%d ",tmp);
//		Push(tmp);
//	}
//}
