#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int v):val(v),next(NULL){}
};
void deleteDup(ListNode *head){
	if(head==NULL){
		return;
	}

	ListNode *cur=head;

	while(cur){
		ListNode *run=cur;

		while(run->next){
			if(run->next->val==cur->val){
				//delete run->next;
				ListNode *temp=run->next;
				run->next=run->next->next;
				delete temp;
			}else{
				run=run->next;
			}
		}
		cur=cur->next;
	}
}

int main(){
	ListNode *a= new ListNode(1);
	a->next= new ListNode(2);
	a->next->next= new ListNode(1);
	a->next->next->next= new ListNode(2);
	a->next->next->next->next= new ListNode(1);
	
	deleteDup(a);
	while(a){
		cout<<a->val<<endl;
		a=a->next;
	}
}