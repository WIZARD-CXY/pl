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
     * @param s A string
     * @return Whether the string is a valid palindrome
     */
    bool isPalindrome(string& s) {
        // Write your code here
        int n=s.size();
        if(n==0){
            return true;
        }
        
        int start=0,end=n-1;
        
        while(start<end){
            if(!isvalid(s[start])){
                start++;
                continue;
            }
            if(!isvalid(s[end])){
                end--;
                continue;
            }
            
            if(s[end]==s[start] || abs(s[end]-s[start])==abs('a'-'A')){
                start++;
                end--;
                continue;
            }
            return false;
        }
        return true;
    }
    
    bool isvalid(char c){
        if((c>='a' && c<= 'z') || (c>='A' && c <= 'Z')){
            return true;
        }
        return false;
    }
};


int main(){
    Solution sln;
    string s="aA";
    
    cout<<sln.isPalindrome(s);
}

