#include <iostream>
#include "bst.h"

using namespace std;

int main(){
	
	bst<int> tree1;
	tree1.insert(1);
	tree1.insert(2);
	tree1.insert(3);
	tree1.insert(4);
	tree1.insert(5);
	cout<<"tree successfully created!"<<endl;
		
	cout<<"testing the inorder traversal"<<endl;
	tree1.inorder();
	
	cout<<"testing pre order traversal: "<<endl;
	tree1.preorder();

	cout<<"testing post order traversal: "<<endl;
	tree1.postorder();	
	
	cout<<"testing search: 2"<<endl;
	if(tree1.search(2)){
		cout<<"found the element"<<endl;
	}else{
		cout<<"did not find"<<endl;
	}
	

	tree1.insert(7);
	tree1.insert(8);

	cout<<"testing the inorder traversal"<<endl;
	tree1.inorder();
	
	cout<<"testing pre order traversal: "<<endl;
	tree1.preorder();
	
	cout<<"testing post order traversal: "<<endl;
	tree1.postorder();
	

	cout<<"testing search: 7"<<endl;
	if(tree1.search(7)){
		cout<<"found the element"<<endl;
	}else{
		cout<<"did not find"<<endl;
	}
	
	cout<<"testing the height of the root"<<endl;
	cout<<"should return 5 result: "<<tree1.height()<<endl;

	cout<<"testing search: 7"<<endl;
	if(tree1.search(7)){
		cout<<"found the element"<<endl;
	}else{
		cout<<"did not find"<<endl;
	}
	
	cout<<"testing search: 13(Should not find)"<<endl;
	if(tree1.search(13)){
		cout<<"found the element"<<endl;
	}else{
		cout<<"did not find"<<endl;
	}
	
	cout<<"testing size root should return 7 result: "<<tree1.size()<<endl;
	
	cout<<"testing the remove node containing 7"<<endl;
	tree1.remove(7);
	cout<<"testing size root should return 6 result: "<<tree1.size()<<endl;

	cout<<"testing the operator tree1[4], should return 5: "<<tree1[5]<<endl;
		
}
