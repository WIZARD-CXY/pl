#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
#include<limits.h>
#include<stack>
#include<queue>
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        string r=s;
        reverse(r.begin(),r.end());
        
        string t=s+"#"+r;
        
        vector<int> prefix(t.size(),0); //partial matching table
        for(int i = 1; i < t.size(); i++) {
            int j = prefix[i-1];
            while(j > 0 && t[i] != t[j])
                j = prefix[j-1];

            if(t[i] == t[j])
                j++;
            prefix[i] = j;
        }

        for(int i=0; i<prefix.size(); i++){
            cout<<prefix[i]<<" ";
        }
        cout<<endl;
        
        return r.substr(0,s.size()-prefix[t.size()-1]) + s;
    }
};

int main(){
    Solution sln;
    cout<<sln.shortestPalindrome("abcd")<<endl;
}