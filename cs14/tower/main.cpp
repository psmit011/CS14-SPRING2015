//tower of hanoi

#include <iostream>
#include <stack>
using namespace std;

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
}

int main(){
	stack<int> A,B,C;
	A.push(5);
	A.push(4);
	A.push(3);
	A.push(2);
	A.push(1);
	showTowerStates(5, A, B, C);
	return 0;
}
