#ifndef _WORD_LADDER_H_
#define _WORD_LADDER_H_

#include <list>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;
class wordLadder{
	public:
		wordLadder(const string );
		void outputLadder(const string, const string);
	private:
		bool OneDifferent(const string, const string);
		bool isEqual(const string, const string);
		list<string> wordList;
};

wordLadder::wordLadder(const string file){
	
	string line;		//will temporarily store contents from file
	ifstream file1;		//file declaration
	file1.open(file);	
	if(!file1.is_open()){	//if file is not around will explode
		cout<<"Error opening file: "<<file<<endl;
		cout<<"check syntax and try again"<<endl;
		return;
	}
	else
	{
		//able to open file
		while(getline(file1, line)){
			wordList.push_back(line);	//build list with file contents
		}	
		file1.close();				//close file
		
		cout<<"List of words successfully created"<<endl;		//verifies the file was properly created
		
	}
}


bool wordLadder::OneDifferent(const string A, const string B){

	int counter = 0;//will help to determine the difference between two diffrent words

	//traverse the two strings simultaneously
	for(int i = 0; i < 5; i++){
		//letter A1 = letter B1 ....letter Ai = letter Bi
		if(A[i] == B[i]){
			counter++;	//increment the counter to determine the number of occurrences
		}
	}
	//counter should contain atleast 4
	if(counter >= 4){
		return true;
	}
	return false;
}

//could just use compare but to me this makes it more intuitive
bool wordLadder::isEqual(const string A, const string B){
	return !(A.compare(B));
}

void wordLadder::outputLadder(const string startWord, const string endWord){

	stack <string> primary_stack;		//stack of strings
	primary_stack.push(startWord);		//push starting word onto stack

	queue <stack<string>> primary_queue;	//create a queue of stacks
	primary_queue.push(primary_stack);	//push stack onto queue

	while(!primary_queue.empty()){
		list<string>::iterator it = wordList.begin();
		for( ; it != wordList.end(); it++){
			if(OneDifferent(primary_queue.front().top(), *it)){
				//cout<<"word1: "<<primary_queue.front().top()<<" Word2: "<<*it<<endl;
				if(isEqual(*it, endWord)){
					stack<string> temp(primary_queue.front());
					stack<string> outputStack;
					while(!temp.empty()){
						outputStack.push(temp.top());
						temp.pop();
					}
					while(!outputStack.empty()){
						cout<<outputStack.top()<<' ';
						outputStack.pop();
					}
					cout<<*it<<endl;
					return;
				}else{
					stack<string> newStack(primary_queue.front());
					newStack.push(*it);
					primary_queue.push(newStack);
					*it = "";
					//return;
				}
			}
		}	
		primary_queue.pop();		
	}
		
	cout<<"There is no word ladder from /"<<startWord<<"/ to /"<<endWord<<"/"<<endl;
	return;
}
#endif
