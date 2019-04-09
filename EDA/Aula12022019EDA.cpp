#include <iostream>
#include <vector>

using namespace std;
void insertion(vector<int> vec) {
	
}

void print(vector<int> v){
	for(int i=0; i<v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

int main() {
	vector<int> a;
	a.push_back(3);
	a.push_back(2);
	a.push_back(1);
	print(a);
    //string myString = "Hello";
	//string myOtherString = " World!!";
	//cout << myString + myOtherString;
	//cout << "Hello World!!";
	return 0;
}
