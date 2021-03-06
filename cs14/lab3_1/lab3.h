#ifndef _LAB_3_H_ 
#define _LAB_3_H_
#include <stack>
#include <iostream>

/*********************************************************************************
*Part 1 of lab 3
*********************************************************************************/
using namespace std;
template <class T>
class TwoStackFixed{
	private:
		int maxTop;
		int size;
		int topStack1, topStack2;
		T *array;
	public:
		TwoStackFixed(int , int);
		void pushStack1(T );
		void pushStack2(T );
		T popStack1();
		T popStack2();
		bool isFullStack1();
		bool isFullStack2();
		bool isEmptyStack1();
		bool isEmptyStack2();
};

template <class T>
TwoStackFixed<T>::TwoStackFixed(int i, int j):maxTop(j), size(i), topStack1(0), topStack2((i-1))
{
	array = new T[size];
	for(int k = 0; k < i; k++){
		array[k] = 0;
	}
}

template <class T>
void TwoStackFixed<T>::pushStack1(T param){
	if(topStack1 >= (maxTop-1)){
		if(array[maxTop-1] == 0){
			array[maxTop-1] = param;
			topStack1 = (maxTop-1);
		}else{
			cout<<"Error: stack 1 full"<<endl;
		}
	}
	else
	{
		topStack1++;
		array[topStack1] = param;
	}
}

template <class T>
void TwoStackFixed<T>::pushStack2(T param){
	if(topStack2 <= (maxTop - 1)){
		if(array[maxTop-1] == 0){
			array[maxTop-1] = param;
		}else{
			cout<<"Error: stack 2 full"<<endl;
		}
	}else{
		topStack2--;
		array[topStack2] = param;
	}
}
	
template <class T>
T TwoStackFixed<T>::popStack1(){
	//empty stack
	if(topStack1 == 0){
		cout<<"Error: Stack empty"<<endl;
	}else{
		cout<<"Element: "<<array[topStack1]<<endl;
		array[topStack1] = 0;
		topStack1--;
	}
	return static_cast<T>(0);
}

template <class T>
T TwoStackFixed<T>::popStack2(){
	//empty stack
	if(topStack2 == (size-1)){
		cout<<"Error: Stack empty"<<endl;
	}else{
		cout<<"Element: "<<array[topStack2]<<endl;
		array[topStack1] = 0;
		topStack2++;
	}
	return static_cast<T>(0);
}

template <class T>
bool TwoStackFixed<T>::isFullStack1(){
	return (topStack2 == (maxTop-1));
}

template <class T>
bool TwoStackFixed<T>::isFullStack2(){
	return (topStack2 == (maxTop-1));
}

template <class T>
bool TwoStackFixed<T>::isEmptyStack1(){
	return (topStack1 == (0));
}

template <class T>
bool TwoStackFixed<T>::isEmptyStack2(){
	return (topStack2 == (size-1));
}






/*********************************************************************************
*Part 2 of lab 3
*********************************************************************************/
using namespace std;
template <class T>
class TwoStackOptimal{
	private:
		int size;
		int topStack1, topStack2;
		T *array;
	public:
		TwoStackOptimal(int);
		void pushStack1(T );
		void pushStack2(T );
		T popStack1();
		T popStack2();
		bool isFullStack1();
		bool isFullStack2();
		bool isEmptyStack1();
		bool isEmptyStack2();
};

template <class T>
TwoStackOptimal<T>::TwoStackOptimal(int i): size(i), topStack1(0), topStack2((i-1))
{
	for(int i = 0; i < size; i++){
		array[i] = 0;
	}
}

template <class T>
void TwoStackOptimal<T>::pushStack1(T param){
	if(topStack1 >= (topStack2-1)){
		cout<<"Error: stack 1 full"<<endl;
	}
	else
	{
		topStack1++;
		array[topStack1] = param;
	}
}

template <class T>
void TwoStackOptimal<T>::pushStack2(T param){
	if(topStack2 <= (topStack1 - 1)){
		cout<<"Error: stack 2 full"<<endl;
	}else{
		topStack2--;
		array[topStack2] = param;
	}
}
	
template <class T>
T TwoStackOptimal<T>::popStack1(){
	//empty stack
	if(topStack1 == 0){
		cout<<"Error: Stack empty"<<endl;
	}else{
		cout<<"Element: "<<array[topStack1]<<endl;
		array[topStack1] = 0;
		topStack1--;
	}
}

template <class T>
T TwoStackOptimal<T>::popStack2(){
	//empty stack
	if(topStack2 == (size-1)){
		cout<<"Error: Stack empty"<<endl;
	}else{
		cout<<"Element: "<<array[topStack2]<<endl;
		array[topStack1] = 0;
		topStack2++;
	}
}

template <class T>
bool TwoStackOptimal<T>::isFullStack1(){
	return (topStack1 == (topStack2-1));
}

template <class T>
bool TwoStackOptimal<T>::isFullStack2(){
	return (topStack2 == (topStack1-1));
}

template <class T>
bool TwoStackOptimal<T>::isEmptyStack1(){
	return (topStack1 == (0));
}

template <class T>
bool TwoStackOptimal<T>::isEmptyStack2(){
	return (topStack2 == (size-1));
}

/*********************************************************************************
*Part 3, lab 3 - Tower of Hanoi
*********************************************************************************/

template <class T>
void showTowerStates(int n, stack<T>& A, stack<T>& B, stack<T>& C){
	//the difficulty of using the recursive implementation is maintaining the stack identity
	//this will allow me to maintain the stack identity
	if(n == A.size()){
		A.push(0x41);	//ascii A
		B.push(0x42);	//ascii B
		C.push(0x43);	//ascii C
	}

	if(n > 0){
		
		showTowerStates(n-1, A, C, B);
		char TA = A.top(), TB = B.top(), TC = C.top();
		A.pop(), B.pop(),C.pop();
		T temp = A.top();
		A.pop();
		C.push(temp);
		cout<<"Moved "<<temp<<" from "<<TA<<" to "<<TC<<endl;
		A.push(static_cast<int>(TA));B.push(static_cast<int>(TB));C.push(static_cast<int>(TC));
		showTowerStates(n-1, B, A, C);
	}
	return;
}


#endif
