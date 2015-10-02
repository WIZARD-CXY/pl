class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for(auto &w : dictionary){
            mm[getAbbr(w)].push_back(w);
        }
    }

    bool isUnique(string word) {
        string abbr=getAbbr(word);
        if(mm.find(abbr)==mm.end()){
            return true;
        }else if(mm[abbr].size()==1 && mm[abbr][0]==word){
            return true;
        }else{
            return false;
        }
    }
    
    string getAbbr(string &s){
        if(s.size()<=2){
            return s;
        }else{
            return s[0]+to_string(s.size()-2)+s.back();
        }
    }
    unordered_map<string,vector<string> > mm;
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");