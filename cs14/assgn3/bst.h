#ifndef _BST_H_
#define _BST_H_

/******************************************************************************
*List of include's
*******************************************************************************/
#include <cassert>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <list>
#include <math.h>

using namespace std;

//nil defined as a MACRO, nil = 0
#define nil 0

int max(int a, int b){
	return((a >= b)?a:b);
}

/*******************************************************************************
*Create a class called bstNode which will contain all the necessary information 
*about what is contained in each node and how to access the remaining nodes 
********************************************************************************/

template <class T>
class Node{
	public:
		Node *left;	//left pointer at node
		Node *right;	//right pointer at node
		T value;	//value of node
		Node( const T v = T() ): value(v), left(nil), right(nil){} //constructor
		T& content() { return value; }
		bool isInternal() { return left != nil && right != nil; }
		bool isExternal() { return left != nil || right != nil; }
		bool isLeaf() { return left == nil && right == nil; }
		int height() {
			/*to return the height of the subtree, traverse the subtree and find the longest path*/
			if(this == nil){
				return 0;	//base case
			}
				
			if(isInternal()){
				return (1 + max(left->height(), right->height()));
			}else{
				if(left == nil){
					return 1 + right->height();
				}else{
					return 1 + left->height();
				}
			}
		}
		int size() {
			/*depending on what size means, but if it means what I think traverse the nodes and count them*/
			if(this == nil){
				return 1;	//base case
			}
				
			if(isInternal()){
				return (1 + left->height() + right->height());
			}else{
				if(left == nil){
					return 1 + right->height();
				}else{
					return 1 + left->height();
				}
			}
		}
};

template <class T>
class bst{
	Node<T> *root;
	int count;
	
	public:
		int size(){root->size();}
		bool empty(){return size() == 0;};
		void printNode(const Node<T>* N){
			if(N != nil){
				cout<N->value<<endl;
			}
		}
		bool search(T key){
			Node<T> *N = root;
			while(N != nil){
				if(key == N->value){
					return true;
				}else if(key < N->value){
					N = N->left;
				}else{
					N = N->right;
				}
		
			}
			return false;
		}
		void inorder()const{inorder(root);}
		void inorder(Node<T>*N)const{
			if(N != nil){
				inorder(N->left);
				cout<<N->value<<endl;
				inorder(N->right);
			}	
		}
		void preorder()const{preorder(root);}
		void preorder(Node<T>*N)const{
			if(N != nil){
				cout<<N->value<<endl;
				preorder(N->left);
				preorder(N->right);
			}	
		}	
		void postorder()const{postorder(root);}
		void postorder(Node<T>*N)const{
			if(N != nil){
				postorder(N->left);
				postorder(N->right);
				cout<<N->value<<endl;
			}	
		}
		int height()const{return root->height();}
		//void dfsOrder()const{dfsOrder(root);}
		T dfsOrder(Node<T>*N)const{
			
			if(N != nil){
				dfsOrder(N->left);
				return N->value;
				dfsOrder(N->right);
			}
	
		}
		T & operator[](int i){
			//create a temporary buffer
			vector<T> temp = dfsOrder(root);
			cout<<"s: "<<temp.size()<<endl;
			if(temp.size() > 0){
				if(i > temp.size()){
					cout<<"The element is not in the vector"<<endl;
					cout.flush();
					assert(i > temp.size());
				}
				return temp[i];
			}
		}
		bst() : count(0), root(nil) {}
		void insert( T X ) { root = insert( X, root ); }
		Node<T>* insert( T X, Node<T>* N ) {
			// The normal binary-tree insertion procedure ...
			if ( N == nil ) {
				N = new Node<T>( X ); // the only place that T gets updated.
			} else if ( X < N->value ) {
				N->left = insert( X, N->left );
			} else if ( X > N->value ) {
				N->right = insert( X, N->right );
			} else {
				N->value = X;
			}
			// later, rebalancing code will be installed here
			
			return N;
		}
		void remove( T X ) { root = remove( X, root ); }
		Node<T>* remove( T X, Node<T>*& N ) {
			// The normal binary-tree removal procedure ...
			// Weiss’s code is faster but way more intricate.
			if ( N != nil ) {
				if ( X > N->value ) {
					N->right = remove( X, N->right );
				} else if ( X < N->value ) {
					N->left = remove( X, N->left );
				} else { // X == T->value
					if ( N->right != nil ) {
						Node<T>* x = N->right;
						while ( x->left != nil ) x = x->left;
						N->value = x->value; // successor’s value
						N->right = remove( N->value, N->right );
					} else if ( N->left != nil ) {
						Node<T>* x = N->left;
						while ( x->right != nil ) x = x->right;
						N->value = x->value; // predecessor’s value
						N->left = remove( N->value, N->left );
					} else { // *T is external
						delete N;
						N = nil; // the only updating of T
					}
				}
			}
			return N;
		}
		void okay( ) { okay( root ); }
		void okay( Node<T>* N ) {
			// diagnostic code can be installed here
		return;
		}


};

#endif
