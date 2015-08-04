/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param hashTable: A list of The first node of linked list
     * @return: A list of The first node of linked list which have twice size
     */    
    vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
        // write your code here
        int m=hashTable.size();
        int n=2*m;
        
        vector<ListNode*> res(n,NULL);
        
        for(int i=0; i<m; i++){
            if(hashTable[i]!=NULL){
                ListNode *cur=hashTable[i];
                
                while(cur){
                    ListNode *next=cur->next;
                    
                    int index;
                    if(cur->val<0){
                        index=((cur->val)%n+n)%n;
                    }else{
                        index=(cur->val)%n;
                    }
                    
                    //insert it into new hash table
                    if(res[index]==NULL){
                        //set cur as head
                        res[index]=cur;
                        cur->next=NULL;
                    }else{
                        //insert it at tail
                        ListNode *p = res[index];
                        while(p->next){
                            p=p->next;
                        }
                        p->next=cur;
                        cur->next=NULL;
                    }
                    
                    cur=next;
                }
            }
        }
        return res;
    }
};

