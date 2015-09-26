class Solution {
public:
    bool canPermutePalindrome(string s) {
        bitset<256> bset;
        
        for(auto c:s){
            bset.flip(c);
        }
        
        return bset.count()<2;
    }
};