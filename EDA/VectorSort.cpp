#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>

using namespace std;
void insertion(vector<int> &vec, int n) {
	int i,j,tmp;
	for(int i=1; i<n; i++){
		j=i;
		tmp=vec[i];
		while (j>0 && tmp<vec[j-1]){
			vec[j]=vec[j-1];
			j--;
		}
		vec[j]=tmp;
	}
}

void creatingVector(vector<int> &vec, int n){
	int i,k;
	for(int i=1; i<n; i++){
		vec.push_back(rand());
	}
}

int main() {
	vector<int> a;
	int i,j;
	clock_t t;
	for(int i=1;i<11;i++){
		int average;
		average = 0;
		t=clock();
		for(int j=1;j<3;j++){
			creatingVector(a,i*10000);
			insertion(a,a.size());
			a.clear();
		}
		average = (clock()-t)/(2*CLOCKS_PER_SEC);
		cout << "The average time for " << i*10000 << " elements in a vector is " << average;
		cout << endl;
	}
	return 0;
}
