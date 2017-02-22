#include"stdafx.h"
#define HEAD INT_MIN 
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(nullptr){}
};
class LinkList{

	ListNode* addTwoNumber(ListNode *l1,ListNode*l2);
	LinkList(vector<float> &nums){

	
	}
	void debug();
	ListNode* reverseBetween_m_n(ListNode * l, int m, int n);



};