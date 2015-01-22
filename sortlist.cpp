/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if(!head || !head->next){
            return head;
        }

        return mergeSort(head);
    }

    ListNode* mergeSort(ListNode* head){
        if(!head || !head->next){
            return head;
        }

        // find the middle element

        ListNode *p=head, *q=head, *pre=NULL;

        while(q && q->next){
            q=q->next->next;
            pre=p;
            p=p->next;
        }

        pre->next=NULL; //split as two list

        ListNode* lh=mergeSort(head);
        ListNode* rh=mergeSort(p);
        return merge(lh,rh);
    }
    ListNode* merge(ListNode *lh, ListNode* rh){
        ListNode *temp=new ListNode(0);
        ListNode *p=temp;

        while(lh && rh){
            if(lh->val<=rh->val){
                p->next=lh;
                lh=lh->next;
            }else{
                p->next=rh;
                rh=rh->next;
            }
            p=p->next;
        }

        if(!lh){
            p->next=rh;
        }else{
            p->next=lh;
        }

        p=temp->next;
        delete temp;
        return p;

    }
};
