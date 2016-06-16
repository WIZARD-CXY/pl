class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vset={'a','e','i','o','u','A','E','I','O','U'};
        
        int start = 0;
        int end = s.size()-1;
        
        while(start<end){
            
            while(start<end && vset.find(s[start])==vset.end()){
                start++;
            }
            
             while(start<end && vset.find(s[end])==vset.end()){
                end--;
            }
            
            //swap 
            char c = s[start];
            s[start]=s[end];
            s[end]=c;
            start++;
            end--;
        }
        
        return s;
    }
};