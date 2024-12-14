#include "list.h"
#include <vector>
#include<iostream>
#include <stack>
using namespace std;
/*
ListNode :: ~ListNode() {
  if(this){
    ListNode* current = this;
    ListNode* following = current->next;
    while(following != nullptr){
      delete current;
      current = following;
      following = current->next;
    }
    delete following;
  }     
}
*/
ListNode :: ~ListNode(){
  delete next;
}


ListNode :: ListNode() {
	value = 0;
	next = nullptr;
}

ListNode :: ListNode(int Value, ListNode* Next) : value{Value}, next{Next} {}

ListNode :: ListNode(const ListNode &A){
	value = A.value;
	next = A.next;
}
ListNode* init(const vector<int>& v) {
    ListNode* head = nullptr;
    ListNode* current = nullptr;
    for (int i = v.size() - 1; i >= 0; --i) {
        head = new ListNode(v[i], current);
        current = head;
    }
    return head;
}

ostream& operator<<(ostream &os, const ListNode &A){
	const ListNode *B = &A;
	while(B != nullptr){
		os << B->value;
		os << " ";
		B = B->next;
	}
	return os;
}

ListNode* function(ListNode* list, unsigned a){
	ListNode* current = list; 
	ListNode* following;
	for(unsigned i = 0; i < a; i++){
		following = current->next;
		current = following;
	}
	return current;
}

unsigned int depth(ListNode* list){ 
  unsigned int n = 0;
  ListNode* current = list;
  while(current != nullptr){
    current = current->next;
    n++;
  }
  return n;
}



ListNode* Process(ListNode* list1, unsigned a, unsigned b, ListNode* list2){
      function(list2, depth(list2) - 1)->next = function(list1, b);
      if(a == 0){
          if(b > 0){
            function(list1, b - 1)->next = nullptr;
            delete list1;
          }
          return list2;
      }
      else{
        ListNode* save = function(list1, a - 1)->next;
        function(list1, a - 1)->next = list2;
        if(b > a){
           function(save, b - a - 1)->next = nullptr;
           delete save;
        }
        return list1;
    }
}
//------------------------------------------------------------------------------------

TreeNode :: TreeNode() {
	value = 0;
	left = nullptr;
	right = nullptr;
}

TreeNode :: ~TreeNode(){
      delete this->left;
      delete this->right;
}
TreeNode :: TreeNode(int Value, TreeNode* Left, TreeNode* Right) : value{Value}, left{Left}, right{Right} {}


int deepofveryright(TreeNode* root){
	if(!root){
		return 0;
	}
	TreeNode* current = root;
	int i = 0;
	while(current != nullptr){
		current = current->right;
		i++;
	}
	return i;
}

int deepofveryleft(TreeNode* root){
	if(!root){
		return 0;
	}
	TreeNode* current = root;
	int i = 0;
	while(current != nullptr){
		current = current->left;
		i++;
	}
	return i;
}

bool Process(TreeNode* root){
	if(!root){
		return true;
	}
	if(root->right == nullptr && root->left == nullptr){
		return true;
	}
	int ll = deepofveryleft(root->left);
	int lr = deepofveryright(root->left);
	int rl = deepofveryleft(root->right);
	int	rr = deepofveryright(root->right);
	return Process(root->right) &&
	Process(root->left) &&
	ll >= lr && 
	lr >= rl &&
	rl >= rr &&
	ll - rr <= 1;
}

void DepthTraversalInput(TreeNode* root){
	stack<TreeNode*> st;
	st.push(root);
	TreeNode* current;
	//int val;
	//cout << "enter value of root" << endl;
	//cin >> val;
	//root->value = val;
        bool answer1, answer2;
	while(!st.empty()){
		current = st.top();
		st.pop();
		cout << "Is left knot exist?" << endl;
                cin >> answer1;
                if(answer1){
			//cout << "enter its value" << endl;
			//cin >> val;
			TreeNode* Left = new TreeNode();
			//Left->value = val;
			current->left = Left;
			st.push(Left);
		}
		cout << "Is right knot exist?" << endl;
                cin >> answer2;
                if(answer2){
			//cout << "enter its value" << endl;
			//cin >> val;
			TreeNode* Right = new TreeNode();
			//Right->value = val;
			current->right = Right;
			st.push(Right);
		}

	}
}
