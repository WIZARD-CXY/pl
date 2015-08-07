#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
#include<limits.h>
#include<stack>
#include<queue>
#include<set>
#include<cstring>
using namespace std;

/**
 * class Comparator {
 *     public:
 *      int cmp(string a, string b);
 * };
 * You can use compare.cmp(a, b) to compare nuts "a" and bolts "b",
 * if "a" is bigger than "b", it will return 1, else if they are equal,
 * it will return 0, else if "a" is smaller than "b", it will return -1.
 * When "a" is not a nut or "b" is not a bolt, it will return 2, which is not valid.
*/

void display(vector<string> s){
    for(auto a:s){
        cout<<a<<" ";
    }
    cout<<endl;
}
class Solution {
public:
    /**
     * @param nuts: a vector of integers
     * @param bolts: a vector of integers
     * @param compare: a instance of Comparator
     * @return: nothing
     */
    void sortNutsAndBolts(vector<string> &nuts, vector<string> &bolts) {
        // write your code here
        
        helper(nuts,bolts,0,nuts.size()-1);
    }
    
    void swap(string &a, string &b){
        string c=a;
        a=b;
        b=c;
    }
    
    void helper(vector<string> &nuts, vector<string> &bolts, int l, int r){
        if(l<r){
            //use bolts[l] as pivot to partition nuts
            string pivot=bolts[l];
            int idx=sortnuts(nuts,pivot,l,r);
            //use nuts[idx] to partition bolts
            sortbolts(bolts,nuts[idx],l,r);

            // recursively call 
            helper(nuts,bolts,l,idx-1);
            helper(nuts,bolts,idx+1,r);
        }

    }
      
    int sortnuts(vector<string> &nuts, string pivot, int l, int r){
        int i=l-1;
        int temp;

        for(int j=l; j<=r; j++){
            if(nuts[j]==pivot){
                swap(nuts[j],nuts[r]);
                break;
            }
        }
        
        for(int j=l; j<r; j++){
            if(nuts[j]<pivot){
                //nuts[j] < pivot
                swap(nuts[++i],nuts[j]);
            }
        }
        swap(nuts[++i],nuts[r]);
        
        display(nuts);
        return i;
    }
    
    int sortbolts(vector<string> &bolts, string pivot, int l, int r){
        int i=l-1;
        int temp;

        for(int j=l; j<=r; j++){
            if(bolts[j]==pivot){
                swap(bolts[j],bolts[r]);
                break;
            }
        }
        
        for(int j=l; j<r; j++){
            if(bolts[j] < pivot){
                //bolts[j] < pivot
                swap(bolts[++i],bolts[j]);
            }
        }

        swap(bolts[++i],bolts[r]);
        display(bolts);
        return i;
    }
};


int main(){
    Solution sln;
    vector<string> nuts={"a","b","d","e","c"};
    vector<string> bolts={"b","e","c","a","d"};
    
    sln.sortNutsAndBolts(nuts,bolts);

   


}

