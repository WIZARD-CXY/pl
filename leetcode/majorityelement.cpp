class Solution {
public:
    int majorityElement(vector<int> &num) {
        unordered_map<int,int> mm;
        for(int i=0; i<num.size(); i++){
            if(mm.find(num[i]) == mm.end()){
                mm[num[i]]=1;
            }else{
                mm[num[i]]++;
            }
        }
        unordered_map<int,int>::iterator it;
        for(it=mm.begin(); it != mm.end(); it++){
            if(it->second>num.size()/2){
                return it->first;
            }
        }
        
    }
};