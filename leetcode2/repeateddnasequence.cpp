class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        //mm store the string and its specific count
        unordered_map<char,int> mm;
        // every char is encoded into two bit, so a length ten sequence is
        // 20 bit and can store it in a int 
        mm['A']=0;
        mm['C']=1;
        mm['G']=2;
        mm['T']=3;
        
        unordered_map<int,int> cnt;
        
        int cur=0;
        int i=0;
        while(i<s.size()){
            cur=(cur<<2 | mm[s[i++]])&0xfffff; // only use 20bit
            if(i<10){
                continue;
            }
            //use cur to represent string s[i-10,i-1]
            if((++cnt[cur])==2){
                res.push_back(s.substr(i-10,10));
            }
        }
        return res;
    }
};