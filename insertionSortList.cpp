class Solution{
public:
	ListNode *insertionSortedList(ListNode *head){
		ListNode *sortedHead = new ListNode(-1);

		while(head){
			//keep the head->next position
			ListNode *temp =head->next;
			ListNode *cur = sortedHead;

			while(cur->next != NULL && cur->next->val < head->val){
				cur=cur->next;
			}
			//insert head node into the list following cur node
			head->next=cur->next;
			cur->next=head;

			//restore head
			head=temp;
		}
		return sortedHead->next;
	}

}