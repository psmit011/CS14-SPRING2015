#include <forward_list>
#include <iostream>
#include "lab2.h"
using namespace std;
bool isPrime(int n){
	if(n < 0){	
		return false;	
	}
	if( n <= 3){
		return n > 1;
	}
	if(n % 2 == 0 || n % 3 == 0){
		return false;
	}
	for (unsigned short i = 5; i * i <= n; i += 6) {
		if (n % i == 0 || n % (i + 2) == 0) {
			return false;
		}
	} 
	return true;
}


int primeCount(forward_list<int> lst){
	if(lst.empty()){
		return 0;
	}else{ 
		bool prime = isPrime(lst.front());
		lst.pop_front();
		if(prime){
			return 1 + primeCount(lst);
		}else{
			return primeCount(lst);
		}
	}
}
