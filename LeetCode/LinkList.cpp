#include "LinkList.h"
//2017-01-25
//the operation of link list include inserting from head,inserting from nail,following pointer
ListNode* LinkList:: addTwoNumber(ListNode *l1, ListNode*l2){
	//the add of two numbers in link list
	//O(m+n) time complexity and O(1) space
	int carry=0;
	ListNode* head=new ListNode(-1);
	ListNode* cur = head;
	for (ListNode* p1 = l1, *p2 = l2; p1&&p2; p1 = p1->next, p2 = p2->next)
	{
	    cur ->next= new ListNode(p1->val + p2->val + carry);;  //doing addation
		cur = cur->next;
		carry = cur->val / 10;       //calculate carry
		cur->val %= 10;              //

	}
	if( carry){
		cur->next = new ListNode(carry);
	}
	return  head;
}
ListNode* LinkList::reverseBetween_m_n(ListNode * l, int m, int n){
	//O(n) time comllexity and O(1) space
	//l has head node with val=-1
	ListNode* follow=l,*m_pptr=nullptr,*n_nptr=nullptr,*p;
	int c;
	for ( p = l,c = 0; 
		p && c<=n;
		++c, follow = p, p = p->next){
		if (c == m) { m_pptr = follow; }
	    if (c == n) n_nptr = p->next;
		if (c > m && c<= n){
			ListNode *backup = p->next;
			p->next = follow;
			follow = p;
			p = backup;
		}
	}
	m_pptr->next->next = p;
	m_pptr->next = follow;
	return l;
}
ListNode* partitionList(ListNode * l, int x){
	//assume l has head node with val=-1
	//input: 1->4->3->2->5->2->nullptr,x=3 then 1->2->2->4->3->5->nullptr
	//O(n)--O(1)
	ListNode *p,*new_nail,*follow,*nail_follow;
	ListNode dumpy(HEAD);
	new_nail = &dumpy; 
	nail_follow = new_nail;
	for (p = l->next, follow = l; p; p = p->next){
	      
		if (p->val < x){
			follow->next = p->next;
			new_nail->next = p;
			nail_follow = new_nail;
			new_nail = new_nail->next;
		}
		else{
			follow = p;
		}
	}
	//merge
	nail_follow->next = l->next;
	l->next = dumpy.next;
	return l;
}
ListNode* RmvDuplicateEle(ListNode *l){
	//assume there is a header in l

	ListNode* p = l->next,*follow;
	if (!p) return l;
	for (follow=p,p=p->next; p;){
		if (follow->val != p->val){
			follow = p;
			p = p->next;
		
		}else{
			ListNode *temp = p;
			p = p->next;
			delete temp;
		}
	}
	return l;

}
ListNode* RmvDuplicateEle_II(ListNode *l)
{   
	ListNode * p = l->next,*follow=p,*nail=l,*temp=nullptr;
	if (!p) return l;// return if there is only one node in l or no node
	bool duplicate = false;
	p = p->next;
	while (p){
		while (p && follow->val == p->val){
			delete follow;
			follow = p;
			p = p->next;
			duplicate = true;
		}//循环结束后 p 指向下一个值
		if (duplicate){
			delete follow;
			duplicate = false;
			nail->next = p;
		}else{
			nail->next = follow;
		}
		nail = nail->next;
		follow = p;
		p = p->next;
	}
	return l;
}
ListNode* RotateList_k(ListNode * l, int k){
	// 	//assume there is a header in l 
	// intput: 1->2->3->4->5-nullptr,k=2 then 4->5->1->2->3->nullptr;
	if (!l){
		return new ListNode(0);
	}
	else{
		ListNode * temp=RotateList_k(l->next, k);
		temp->val++;
		if (temp->val == k){ //退栈时遇到了要翻转的分界
			return l;
		}
		if (temp ==l->next) l->next = nullptr; //断开处末尾指针置空
		if (l->val==HEAD)   //退到了链表头
		{
			ListNode *bkup = l->next;
			l->next = temp;
			while (temp->next)
			{
				temp = temp->next;
			}
			temp->next = nullptr;
			return l;
		}
		else{
			return temp;
		}
	

	}
	





}


//2017-01-26
ListNode* RemoveNthFromEnd(ListNode * l, int n){
	ListNode * p = nullptr, *q = nullptr;
	int c = 0;
	if (!p) return l;
	for ( p=l->next,q=l;p->next;p = p->next,++c)
	{
		if (c >= n){ q = q->next; }  
	}
	ListNode * temp=q->next;
	q->next = temp->next;
	delete temp;
	return l;
}
ListNode* SwapPair(ListNode *l){
	ListNode* p = l->next,*q=l;
	for (int i = 1; p; ++i, q = q->next,p = p->next){
		if (i % 2 == 0){
			swap(q->val, p->val); 
		}
	}
	return l;

}

//2017-01-27
ListNode * reverseKGroup( ){

	return nullptr;

}
void debug(){


}