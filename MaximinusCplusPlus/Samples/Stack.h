#include"MyList_class.h"
class MyStack : public MyList_class {
	public:
		MyStack(void){
		puts("Default Constructor of Stack!!!!");	
		}
		//MyStack(int N);
		//MyStack(int N,int Range);
		~MyStack(){
		puts("Destructor of Stack!!!!");
		}	
		void Print(void);
		int Show_Up_Stack(void){
			return Get_Value(1);
		}
		void Push(int Num)
		{ Insert(1,Num);
		}
		int Pop(void){
		int tmp;
		tmp=Get_Value(1);
		Remove(1);
		return tmp;	
		}
	
};
void MyStack::Print(void){
	if(Empty()){
		puts("Stack is Empty!!!");
		return;
	}
	int tmp; MyStack Tmp_Stack;
	while(!Empty()){
		tmp=Pop();
		printf("%d ",tmp);
		Tmp_Stack.Push(tmp);
	}
	puts("");
	while(!Tmp_Stack.Empty()){
		tmp=Tmp_Stack.Pop();
		//printf("%d ",tmp);
		Push(tmp);
	}
}
	
	
	
	

