#include <iostream>
#include <cstdlib>
#include <list>
#include <algorithm>
#include "lab2.h"

using namespace std;

int main(){

	//problem 1 testing
	forward_list<int> mylist = { 34, 77, 16, 2 , 7, 17};
	std::cout << "mylist now contains:";
  	for ( int& x : mylist ) std::cout << ' ' << x;
  	std::cout << '\n';
	int count = primeCount(mylist);
  	std::cout << "mylist now contains:";
  	for ( int& x : mylist ) std::cout << ' ' << x;
  	std::cout << '\n';
	cout<<"Count: "<<count;
	bool ip = isPrime(17);
	cout<<"result: "<<ip<<endl;

	//problem 2 testing
	List<int> lstInt(9);
	lstInt.push_front(8);
	lstInt.push_front(7);
	lstInt.push_front(86);
	cout<<"Printing List"<<endl;
	lstInt.print();
	
	cout<<"size of list: "<<lstInt.size()<<endl;
	cout<<"attempting element swap"<<endl;
	lstInt.elementSwap(lstInt, 1);
	lstInt.print();
	
	//problem 3 testing
	forward_list<int> l1 = {1,2,3,4,5,5,6};
	forward_list<int> l2 = {2,3,4,3,2,1,2,3};
	cout<<"List1: "<<endl;
	for(int& y : l1 )cout << ' ' << y;
	cout<<"List2: "<<endl;
	for(int& y : l2 )cout << ' ' << y;
	cout.flush();
	l2 = listCopy(l1,l2);
	cout<<"List 2: "<<endl;
	for(int& z : l2 )cout<< ' ' << z;

	//problem 4 testing
	forward_list<float> list1= {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8};
	forward_list<int> list2 = {1 , 5, 7, 9};
	cout<<"testing functionality of print lots"<<endl;
	cout<<"List 1: "<<endl;
	for(float& y : list1 )cout << ' ' << y;
	cout<<endl;
	cout<<"List 2: "<<endl;
	for(int& y : list2 )cout << ' ' << y;
	cout<<endl;
	printLots(list1,list2);

	
	return 0;
}
