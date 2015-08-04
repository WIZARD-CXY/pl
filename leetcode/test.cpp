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

class Solution {
public:
    /**
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string>> partition(string s) {
        // write your code here
        vector<vector<string> > res;
        vector<string> tmp;
        
        // use a dfs helper
        dfs(res,tmp,s,0);
        
        return res;

    }
    void dfs(vector<vector<string> > &res, vector<string> &tmp, string &s, int index){
        if(index==s.size()){
            res.push_back(tmp);
            return;
        }
        
        for(int len=1; index+len<=s.size(); len++){
            string ss=s.substr(index,len);
            if(isPalin(ss)){
                tmp.push_back(ss);
                dfs(res,tmp,s,index+len);
                tmp.pop_back();
            }
        }
    }
    
    bool isPalin(string &s){
        int l=0;
        int r=s.size()-1;
        
        while(l<r){
            if(s[l++]!=s[r--]){
                return false;
            }
        }
        return true;
    }
};



int main(){
    Solution sln;
    string s="bb";
    
    sln.partition(s);
}

