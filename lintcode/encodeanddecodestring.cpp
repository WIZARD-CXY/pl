class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ret;
        
        for(int i=0; i<strs.size(); i++){
            ret+=to_string(strs[i].size())+'@'+strs[i];
        }
        
        return ret;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
    
        vector<string> res;
        int p=0,q=0;
        while(q<s.size()){
            string tmp;
            // find first '@'
            while(q<s.size() && s[q]!='@'){
                q++;
            }
            
            //s[q]=='@'
            int len=stoi(s.substr(p,q-p));
            res.push_back(s.substr(q+1,len));
            p=q=q+len+1;
        }
       
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));