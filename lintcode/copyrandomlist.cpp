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
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here
        clone(head);
        connectrandom(head);
        
        return cutlist(head);
    }
    
    void clone(RandomListNode *head){
        RandomListNode *cur=head;
        while(cur){
            RandomListNode *nn= new RandomListNode(cur->label);
            nn->next=cur->next;
            cur->next=nn;
            cur=nn->next;
        }
    }
    
    void connectrandom(RandomListNode *head){
        RandomListNode *cur=head;
        
        while(cur){
            if(cur->random){
                cur->next->random=cur->random->next;
            }
            cur=cur->next->next;
        }
    }
    
    RandomListNode* cutlist(RandomListNode *head){
        RandomListNode *copyhead,*copynode;
        RandomListNode *cur=head;
        if(head==NULL){
            return NULL;
        }
        
        copyhead=copynode=head->next;
        
        cur->next=copynode->next;
        cur=cur->next;
        
        while(cur){
            copynode->next=cur->next;
            copynode=copynode->next;
            cur->next=copynode->next;
            cur=cur->next;
        }
        
        
        return copyhead;
    }
    
};
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
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here
        clone(head);
        connectrandom(head);
        
        return cutlist(head);
    }
    
    void clone(RandomListNode *head){
        RandomListNode *cur=head;
        while(cur){
            RandomListNode *nn= new RandomListNode(cur->label);
            nn->next=cur->next;
            cur->next=nn;
            cur=nn->next;
        }
    }
    
    void connectrandom(RandomListNode *head){
        RandomListNode *cur=head;
        
        while(cur){
            if(cur->random){
                cur->next->random=cur->random->next;
            }
            cur=cur->next->next;
        }
    }
    
    RandomListNode* cutlist(RandomListNode *head){
        RandomListNode *copyhead,*copynode;
        RandomListNode *cur=head;
        if(head==NULL){
            return NULL;
        }
        
        copyhead=copynode=head->next;
        
        cur->next=copynode->next;
        cur=cur->next;
        
        while(cur){
            copynode->next=cur->next;
            copynode=copynode->next;
            cur->next=copynode->next;
            cur=cur->next;
        }
        
        
        return copyhead;
    }
    
};
