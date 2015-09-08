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
        if(head==NULL){
            return NULL;
        }
        RandomListNode *cur=head;
        RandomListNode *newhead=NULL;
        
        //copy the node and after the old node
        while(cur){
            RandomListNode *newnode=new RandomListNode(cur->label);
            if(newhead==NULL){
                newhead=newnode;
            }
    
            newnode->next=cur->next;
            cur->next=newnode;
            cur=newnode->next;
        }
        
        //link the random pointer
        
        cur=head;
        
        while(cur && cur->next){
            if(cur->random){
                cur->next->random=cur->random->next;
            }
            cur=cur->next->next;
        }
        
        //split the two list
        RandomListNode* newcur=newhead;
        cur=head;
        
        while(newcur && newcur->next){
           RandomListNode* nextnode=newcur->next;
           newcur->next=nextnode->next;
           cur->next=nextnode;
           cur=nextnode;
           newcur=nextnode->next;
        }
        //newcur->next=NULL;
        cur->next=NULL;
        
        return newhead;
    }
};