#include <iostream>
#include <iomanip>

using namespace std;

struct Node{
    int data;
    Node *pChild[2];

    Node(int x):data(x){
    	pChild[0]=pChild[1]=0;
	}
};


class bst{
private:
    Node *pRoot;

public:
    bst(): pRoot(NULL) {}

    bool find(int x, Node **&pNode) {
        pNode = &pRoot;
        while(*pNode) {
            if ((*pNode)->data==x) return true;
            pNode = &((*pNode)->pChild[(*pNode)->data<x]);
        }
        return 0;
    }


    void insert(int x) {
        Node **pNode;
        if ((find(x, pNode))) return;
        Node *newNode = new Node(x);
        //newNode->pNext = *pNode;
        //*pNode = newNode;
        *pNode = newNode;
    }
    
    void print(){
    	print(pRoot);
    	cout << endl;
	}

    void print(Node *p, int indent=0) {
    	if (p){
    		print(p->pChild[1],indent+6);
    		cout << setw(indent) << ' ';
    		cout << p->data <<endl;
    		print(p->pChild[0],indent+6);
		}
    }

    void remove(int x) {
        //Node **pNode;
        //if(!find(x, pNode)) return;
        //*pNode = (*pNode)->pNext;
    }
};

int main() {
    bst bst1;
    bst1.insert(5);
    bst1.insert(2);
    bst1.insert(3);
    bst1.insert(4);
    bst1.insert(6);
    bst1.insert(7);
    bst1.insert(7);
    bst1.print();

    return 0;
}
