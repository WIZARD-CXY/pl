#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
#include<limits.h>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<cstring>
using namespace std;
void print(vector<int> &a){
    for(auto aa : a){
        cout<<aa<<" ";
    }
    cout<<endl;
}

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseList(ListNode *head){
        ListNode *pre=NULL;
        ListNode *cur=head;
        
        while(cur){
            ListNode *next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
        return pre;
    }
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *dummy=new ListNode(-1);
        ListNode *pre=dummy;
        pre->next=head;
        
        if(m==n){
            return head;
        }
        
        ListNode *cur=dummy;
        
        while(--m){
            cur=cur->next;
        }
        //cur is lasttail
        ListNode *lasttail=cur;
        ListNode *firsthead=cur->next;
        
        //move forward the cur 
        cur=dummy;
        while(--n){
            cur=cur->next;
        }
        ListNode *nextfirst=cur->next;
        cur->next=NULL;
        ListNode *newhead=reverseList(firsthead);
        
        //splice the list
        lasttail->next=newhead;
        firsthead->next=nextfirst;
        
        return dummy->next;
    }
};


int main(){
    Solution sln;
    vector<int> ivec={1,2,2};
    ListNode *a=new ListNode(3);
    ListNode *b=new ListNode(5);
    a->next=b;

    sln.reverseBetween(a,1,2);
    int aa[10]={0};
    int index=14;

    int wordnum=index/16;
    int bitnum=index&0xf;
    int val=2;

    aa[wordnum]|=(val<<(bitnum<<1));


    cout<<aa[wordnum]<<endl;

}

