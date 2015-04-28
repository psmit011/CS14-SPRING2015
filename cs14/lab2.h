#ifndef _LAB_2_H_
#define _LAB_2_H_


#include <forward_list>
using namespace std;

//declarations of functions
bool isPrime(int n);
int primeCount(forward_list<int> lst);

//templated functions
template <class T>
struct Node{
	Node(){
		next = NULL;
	}
	Node(T val, Node* nodePtr = NULL){
		value = val;
		next = nodePtr;
	}
	
	T value;	//holds a single character of type T	
	Node *next;	//holds a pointer to the next item in the list
};

template <class T>
class List{
	public:
		List(T val);
		void push_front(T val);
		void print();
		List elementSwap(List<T> lst, int position);
		int size();
	private:
		T value;
		Node<T> *head;
};





template <class T>
int List<T>::size(){
	int counter = 0;
	if(head == NULL){
		return counter;
	}
	else{
		Node<T> *temp = head;
		while(temp != NULL){
			counter++;
			temp = temp->next;
		}

	}
	return counter;
}

template <class T>
List<T>::List(T val){
	head = new Node<T>(val, head);
	head->next = NULL;
}

template <class T>
void List<T>::print(){
	if(head != NULL){
		Node<T> *temp = head;
		while(temp != NULL){
			cout<<temp->value<<" "<<endl;
			temp = temp->next;
		}
	}
}

template <class T>
void List<T>::push_front(T val){
	head = new Node<T>(val, head);
}

template <class T>
List<T> List<T>::elementSwap(List<T> lst, int position){
	if(position >= (this->size() - 1)){
		cout<<"Out of bounds"<<endl;
		return (*this);
	}
	else
	{
		Node<T> *temp = lst.head;
		for(int i = 1; i < position; i++, temp = temp->next);
		Node<T> *temp2 = temp->next;
		Node<T> *temp3 = temp->next->next;
		temp2->next = temp2->next->next;
		temp3->next = temp2;
		temp->next = temp3;
	}
	return lst;
			
}



template <class T>
forward_list<T> listCopy( forward_list<T> l, forward_list<T> p ){
	if(l.empty()){
		cout<<" array1 is empty cannot copy"<<endl;
		return p;
	}	

	//copy elements by inserting them into the front of the container
	l.reverse();
	p.merge(l);
	return p;
}

template <class T>
void printLots (forward_list <T> l, forward_list <int> p){
	if(l.empty()){
		cout<<"List empty returning";
		return;
	}
	else
	{
		auto l_it  = l.begin();
		auto p_it  = p.begin();
		for(int i = 0; l_it != l.end() ; i++, l_it++){
			int t = *p_it;
			if(i == t){
				cout<<(*l_it)<<' ';
				if(p_it != p.end()){
					p_it++;
				}
			}
		}
	}
}

#endif
