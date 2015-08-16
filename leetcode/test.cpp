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

class Solution {
public:
   /**
     * @param A: An integer array
     * @return: Count the number of element before this element 'ai' is 
     *          smaller than it and return count number array
     */
    struct BSTNode{
        int val;
        int count;// record the smaller number count
        BSTNode *left;
        BSTNode *right;
        BSTNode(int v):val(v),count(0){
            left=NULL;
            right=NULL;
        }
    };
    BSTNode *root=NULL;
    
    void insert(int v){
        if(root==NULL){
            root=new BSTNode(v);
            return;
        }else{
            BSTNode *cur=root;
            
            while(cur){
                if(v<cur->val){
                    //will insert in left subtree of cur
                    cur->count++;
                    if(cur->left){
                        cur=cur->left;
                    }else{
                        cur->left=new BSTNode(v);
                        return;
                    }
                }else{
                    if(cur->right){
                        cur=cur->right;
                    }else{
                        cur->right=new BSTNode(v);
                        return;
                    }
                    
                }
            }
        }
    }
    
    int query(int a){
        // return the count of number which is smaller than a
        
        BSTNode *cur=root;
        int count=0;
        while(cur){
            if(a<cur->val){
                cur=cur->left;
            }else if(a>cur->val){
                count+=1+cur->count;
                cur
            }else{
                // a==cur->val
                return count+cur->count;
            }
        }
        
        return 0;
    }
    vector<int> countOfSmallerNumberII(vector<int> &A) {
        // write your code here
        vector<int> res;
        
        for(auto a :A){
            insert(a);
            res.push_back(query(a));
        }
        
        return res;
    }
};



int main(){
    Solution sln;
    vector<int> s={1,2,7,8,5};
    
    sln.countOfSmallerNumberII(s);

}

