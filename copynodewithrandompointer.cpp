/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *newhead=NULL;
        RandomListNode *cur=head;
        
        while(cur){
            RandomListNode *newnode = new RandomListNode(cur->label);
            // insert after the original node
            if(newhead==NULL){
                newhead=newnode;
            }
            newnode->next=cur->next;
            cur->next=newnode;
            cur=newnode->next;
        }
        
        cur=head;
        
        while(cur){
            if(cur->random){
                cur->next->random=cur->random->next;
            }
            cur=cur->next;
        }
        
        //split two list
        cur=head;
        RandomListNode *temp=newhead;
        while(cur){
            cur->next=newhead->next;
            cur=cur->next;
            temp->next=cur->next;
            temp=temp->next;
        }
        return newhead;
        
    }
};