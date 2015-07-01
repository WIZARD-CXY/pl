class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> res;
        unordered_map<int, int> mm;
        unordered_map<int, int>::iterator iter;
        
        for(int i=0; i<numbers.size(); i++){
            iter=mm.find(target-numbers[i]);
            if(iter!=mm.end()){
                res.push_back(iter->second);
                res.push_back(i+1);
                return res;
            }else{
                mm[numbers[i]]=i+1;
            }
        }
        return res;
    }
};