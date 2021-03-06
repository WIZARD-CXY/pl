class Solution {
public:
    string shortestPalindrome(string s) {
        string r=s;
        reverse(r.begin(),r.end());
        
        string t=s+"#"+r;
        
        vector<int> prefix(t.size(),0);
        
        //calculate the bmp next array
        for(int i = 1; i < t.size(); i++) {
            int j = prefix[i-1];
            while(j > 0 && t[i] != t[j])
                j = prefix[j-1];
            if(t[i] == t[j])
                j++;
            prefix[i] = j;
        }
        
        return r.substr(0,s.size()-prefix[t.size()-1]) + s;
    }
};