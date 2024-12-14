#include "list.h"
#include <vector>
#include <iostream>
using namespace std;

void test_of_listnode(){
    int value;
    unsigned n1, n2;
    vector<int> v1{};
    vector<int> v2{};
    cout << "enter the length of first list: "; 
    cin >> n1;
    cout << "enter the list" << endl;
    for(unsigned i = 0; i < n1; i++){
        cin >> value;
        v1.push_back(value);
    }
    cout << "enter the length of second list: "; 
    cin >> n2;
    cout << "enter the list" << endl;
    for(unsigned i = 0; i < n2; i++){
        cin >> value;
        v2.push_back(value);
    }
    ListNode* A = init(v1);
    ListNode* B = init(v2);
    unsigned a, b;
    cout << "enter a and b" << endl;
    cin >> a >> b;
    if(a > b || b > depth(A)){
      cout << "incorrect data" << endl;
      delete A;
      delete B;
    }
    else{
      ListNode *C = Process(A, a, b, B);
      cout << *C << endl;
      delete C;
    }
}    
void test_of_treenode(){
    TreeNode* A = new(TreeNode);
    DepthTraversalInput(A);
    if(Process(A)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    delete A;
}


int main(){
    test_of_listnode();
    //test_of_treenode();
}
