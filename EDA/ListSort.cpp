#include <iostream>
#include <list>
#include <cstdlib>
#include <time.h>
using namespace std;

void print(list<int> &myList){
	list<int>::iterator It=myList.begin();
	for(It=myList.begin();It!=myList.end();It++){
		cout << *It << " ";
	}	
	cout << endl;
}

void insertion(list<int> &myList){
	list<int>::iterator It;
	list<int>::iterator It2;
	list<int>::iterator Comeco=myList.begin();
	myList.insert(Comeco,0);
	int cur_value;
	for(It=myList.begin();It!=myList.end();It++){
		cur_value=*It;
		It2=It;
		It2--;
		while(It2!=myList.begin()&&*It2>cur_value){
			*It=*It2;
			It--;
			It2--;
		}
		*It=cur_value;
	}	
	Comeco=myList.begin();
	myList.erase(Comeco);
}

void creatingList(list<int> &myList, int n){
	list<int>::iterator It=myList.begin();
	int i;
	for(int i=0;i<n;i++){
		myList.insert(It,rand()%1000000);
		It++;
	}
}

int main() {
	list<int> a;
	creatingList(a,100);
	insertion(a);
	print(a);
}
