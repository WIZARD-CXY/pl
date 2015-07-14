#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
#include<limits.h>
#include<stack>
#include<queue>
#include<set>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
{
    if (head == NULL)
        return head;

    ListNode* pFast=head, *pSlow=head, *pre;

    while(n!=0)
    {   
        pFast= pFast->next;
        n--;
    }
    while(pFast != NULL)
    {
        pFast = pFast->next;
        pre = pSlow;
        pSlow = pSlow ->next;

    }
    if(pSlow == head)
        head = head->next;
        return head;
   
    pre->next = pSlow->next;
    delete(pSlow);

    return head;
}
};

int main(){
    Solution sln;
    ListNode *head= new ListNode(1);
    ListNode *next= new ListNode(2);
    head->next=next;

    sln.removeNthFromEnd(head,1);
}