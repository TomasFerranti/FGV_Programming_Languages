#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

void print(vector<int> vec){
	for(int i=0; i<vec.size();i++){
		cout << vec[i] << " ";
	}
	cout << endl;
}

void remover(vector<int>&vec){
	vector<int>::iterator It=vec.begin();
	vec.erase(It); 	
}

vector<int> merge(vector<int>vec1,vector<int>vec2){
	vector<int> vec;
	while(!vec1.empty()&&!vec2.empty()){
		if(vec1[0]<=vec2[0]){
			vec.push_back(vec1[0]);
			remover(vec1);
		}else{
			vec.push_back(vec2[0]);
			remover(vec2);
		}
	}
	if(!vec1.empty()){
		for(int k=0;k<vec1.size();k++){
			vec.push_back(vec1[k]);
		}
	}else{
		for(int k=0;k<vec2.size();k++){
			vec.push_back(vec2[k]);
		}
	}
	return vec;
}

vector<int> mergeSort(vector<int>&vec){
	int m;
	if(vec.size()==0||vec.size()==1){
		return vec;
	}else{
		if(vec.size()%2==1){
			m=(vec.size()+1)/2;
		}else{
			m=vec.size()/2;
		}
	}
	vector<int> leftSide;
	vector<int> rightSide;
	int j=m;
	for(int i=0;i<m;i++){ 
		leftSide.push_back(vec[i]);
		if(j<vec.size()){
			rightSide.push_back(vec[j]);
			j++;
		}
	}
	return merge(mergeSort(leftSide),mergeSort(rightSide));	
}

void creatingVector(vector<int> &vec,int n){
	for(int i=0; i<n; i++){
		vec.push_back(rand());
	}
}

int main(){
	vector<int> vec;
	creatingVector(vec,10);
	print(vec);
	vec=mergeSort(vec);
	print(vec);
	return 0;
}
