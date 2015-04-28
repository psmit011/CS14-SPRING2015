#include <iostream>
#include "MyList.H"

using namespace std;

int main(){

	MyList List("Hello?");
	List.print();	
	
	//create object list1 to verify default constructor
	MyList List1;
	cout<<"List 1 Initialized"<<endl;
	cout<<"Prnting list 1"<<endl;
	List1.print();
	List1.push_front('a');
	List1.push_front('b');
	List1.push_front('c');
	cout<<"reprinting list 1"<<endl;
	List1.print();
	cout<<endl;

	//create object mylist3 to verify name pointer constructor
	const char* name = "Patrick";
	MyList List3(name);
	cout<<"List 3 Initialized"<<endl;
	cout<<"Printing List 3"<<endl;
	List3.print();
	cout<<endl;
	
	
	//create object mylist4 to verify string constructor
	const string name1 = "Patrick";
	MyList List4(name1);
	cout<<"List 4 Initialized"<<endl;
	List4.print();
	cout<<endl;
	
	//create object mylist5 to verify copy constructor
	MyList List5(List3);
	cout<<"List 5 Initialized"<<endl;
	cout<<"Printing List 5"<<endl;
	List5.print();
	cout<<endl;

	//test push front
	cout<<"Pushing 'd' to the front of list 4"<<endl;
	List4.push_front('d');
	List4.print();
	cout<<endl;

	cout<<"Popping front of list 4"<<endl;
	List4.pop_front();
	List4.print();
	cout<<endl;

	cout<<"Testing insert at position 3 List3"<<endl;
	List3.insert_at_pos( 3, 'x');
	cout<<"Reprinting List 3: ";
	List3.print();
	cout<<endl;

	cout<<"Adding some push_backs(a,c,d,s,f,g,h) list 1"<<endl;
	List1.push_back('a');
	List1.push_back('c');
	List1.push_back('d');
	List1.push_back('s');
	List1.push_back('f');
	List1.push_back('g');
	List1.push_back('h');
	cout<<"Reprinting after multiple push_backs"<<endl;
	List1.print();
	cout<<endl;
	
	cout<<"Testing push_back List3"<<endl;
	List3.push_back('x');
	cout<<"Reprinting List 3: ";
	List3.print();
	cout<<endl;
	
	cout<<"Testing find(x) List 3"<<endl;
	int found = List3.find('x');
	cout<<"Found: "<<found<<" Reprnting List 3: ";
	List3.print();
	cout<<endl;
	
	cout<<"Testing find(e) List 3"<<endl;
	found = List3.find('e');
	cout<<"Found: "<<found<<" Reprnting List 3: ";
	List3.print();
	cout<<endl;

	cout<<"Testing size() List 3"<<endl;
	int size = List3.size();
	cout<<"size: "<<size<<" Reprinting List 3: ";
	List3.print();
	cout<<endl;

	cout<<"Testing pop_back List 3"<<endl;
	List3.pop_back();
	size = List3.size();
	cout<<"size: "<<size<<" Reprinting List 3: ";
	List3.print();
	cout<<endl;
	
	cout<<"Testing the fnctionality of [3] List 3"<<endl;
	char val = List3[3];
	cout<<"Value: "<<val<<endl;
	size = List3.size();
	cout<<"size: "<<size<<" Reprinting List 3: "<<endl;
	List3.print();
	cout<<endl;

	//Code below issues a seg fault for trying to access element in an empty list
	/*
	cout<<"Testing the fnctionality of [3] List2, Should report error"<<endl;
	val = List2[3];
	cout<<"Value: "<<val<<endl;
	size = List2.size();
	cout<<"size: "<<size<<" Reprinting List 2: "<<endl;
	List2.print();
	*/

	cout<<"testing the funcionality of reverse List3"<<endl;
	List3.reverse();
	List3.print();
	cout<<endl;

	cout<<"testing the funcionality of overloaded = operator"<<endl;
	MyList List6 = List3;
	List6.print();
	List6.reverse();
	List6.print();
	List3.print();
	cout<<endl;
	
	cout<<"testing the funcionality of copy construtor after reverse"<<endl;
	MyList List7(List3);
	List7.print();
	cout<<endl;

	cout<<"testing the funcionality of reverse List3"<<endl;
	List3.print();
	List6.print();
	cout<<endl;
	
	cout<<"testing the swap of position 1, 2 List7"<<endl;
	cout<<"Just to refresh here is list7: ";
	List7.print();
	List7.swap(1,7);
	List7.print();
	cout<<endl;

	const char *a = "ick";
	MyList List8(a);
	cout<<"List6: ";
	List6.print();
	List8.print();
	int check = List6.find(List8);
	cout<<"The substring [ick] is found in list 6 at position: "<<check<<endl;	


	const char *b = "klck";
	MyList List9(b);
	cout<<"List6: ";
	List6.print();
	List9.print();
	check = List6.find(List9);
	cout<<"The substring [klck] is found in list 6 at position: "<<check<<endl;	
	return 0;
}
