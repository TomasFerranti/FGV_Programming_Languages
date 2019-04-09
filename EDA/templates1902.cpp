#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>
#include <time.h>

using namespace std;

template<class T>
void insertion_sort(vector<T> &vec){
	for(int i=0;i<vec.size();i++){
		T cur_value = vec[i];
		int j = i - 1;
		while(j>=0 && vec[j] > cur_value){
			vec[j+1] = vec[j];
			j = j - 1;			
		}
		vec[j+1] = cur_value;
	}
}

/*
template<class T>
void bubble_sort(vector<T> &vec){
	for(int i=0;i<vec.size();i++){
		
	}
}
*/

template<class T>
void print(vector<T> &vec){
	std::copy(vec.begin(),vec.end(),ostream_iterator<T>(cout, " "));
	cout << endl;
}

template<class T>
void aleatorio(vector<T> &vec,int n){
	for(int i=0;i<n;i++){
		vec.push_back(rand());
	}
}

int main(){
	vector<float> vec;
	aleatorio<float>(vec,1000);
	insertion_sort<float>(vec);
	print(vec);
}
