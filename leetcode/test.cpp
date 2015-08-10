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
     * @param s : A string
     * @return : The length of the longest substring 
     *           that contains at most k distinct characters.
     */
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        // write your code here
        //dict[i] records ith occur count
        unordered_map<char,int> dict;
        int start=0;
        int res=0;
        
        for(int i=0; i<s.size(); i++){
            dict[s[i]]++;

            cout<<"dict size "<<s[i]<<" "<<dict.size()<<endl;
            
            if(dict.size()<=k){
                cout<<"in update res"<<endl;
                res=max(res,i-start+1);
            }else if(dict.size()>k){
                //need to remove the s[start]
                dict[s[start]]--;
                if(dict[s[start]]==0){
                    dict.erase(s[start]);
                }
                start++;
            }
        }
        return res;
    }
};


int main(){
    Solution sln;
    string s="nfhiexxjrtvpfhkrxcutexxcodfioburrtjefrgwrnqtyzelvtpvwdvvpsbudwtiryqzzy";
    
    cout<<sln.lengthOfLongestSubstringKDistinct(s,25);

}

