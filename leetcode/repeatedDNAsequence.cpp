class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        
        if(s.size()<10){
            return res;
        }
        
        int len = s.size();
        int i=0,cur=0;
        int mask = 0x3fffffff;//mask the least significant 30bits
        
        unordered_map<int,int> mm;
        
        while(i<9){
            cur = (cur<<3)|(s[i++]&0x7);
        }
        
        while(i<len){
            // let cur be the representation of sequence
            cur = ((cur<<3)|(s[i++]&0x07))&mask;
            
            if(mm.find(cur)!=mm.end()){
                //already in the hash
                if(mm[cur]==1){
                    res.push_back(s.substr(i-10,10));
                }
                mm[cur]++;
            }else{
                mm[cur]=1;
            }
        }
        
    }
};