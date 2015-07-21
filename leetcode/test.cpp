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
     * @param p: A string includes "?" and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s, const char *p) {
        // write your code here
        int sp=0;//record the current matching pos
        int pp=0;//record the p current maching pos
        int slen=strlen(s);
        int plen=strlen(p);
        //record p's star pos ,initially we don't know if it exists
        //so set to the end
        int pstar=plen;
        
        while(sp<slen){
            if(s[sp]==p[pp] || p[pp]=='?'){
                //exact match or match with "?"
                cout<<"1 "<<sp << " "<<pp<<endl;
                sp++;
                pp++;
                continue;
            }else if(p[pp]=='*'){
                // try to match * with zero char like `ab and a*b`
                // just move pp forward and record start pos
                cout<<"2 "<<sp <<" "<<pp<<endl;
                pstar=pp;
                pp++;
                continue;
            }
            
            if(pstar<plen){
                // try to match with 1 or more chars
                // like abcd a*d
                cout<<"3 "<<sp << " "<<pp<<endl;
                sp++;
                //pp=pstar+1;
                continue;
            }
            
            return false;
        }

        
        while(pp <plen && p[pp]=='*'){
            pp++;
        }
        return pp==plen;
        
    }
};


int main(){
    Solution sln;
    cout<<sln.isMatch("acaabbaccbbacaabbbb","a*?*b*?*a*aa*a*");
}

