#ifndef LIST_H
#define LIST_H
#include <vector>
#include<iostream>
using namespace std;


struct ListNode{
	~ListNode();
	ListNode();
	ListNode(int value, ListNode* next);
	ListNode(const ListNode &A);
//private:
	int value; 
	ListNode* next;
};
ostream& operator<<(ostream &os, const ListNode &A);
ListNode* init(const vector<int>& v);
ListNode* function(ListNode* list, unsigned a);
ListNode* Process(ListNode* list1, unsigned a, unsigned b, ListNode* list2);
unsigned int depth(ListNode* list);

struct TreeNode{
	int value;
	TreeNode* left;
	TreeNode* right;
    ~TreeNode();
	TreeNode();
	TreeNode(int value, TreeNode* left, TreeNode* right);
};

int deepofveryright(TreeNode* root);
int deepofveryleft(TreeNode* root);
bool Process(TreeNode* root);
void DepthTraversalInput(TreeNode* root);



#endif
