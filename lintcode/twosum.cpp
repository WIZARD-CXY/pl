class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here
        vector<int> res;
        unordered_map<int, int> mm;
        unordered_map<int, int>::iterator iter;
        
        for(int i=0; i<nums.size(); i++){
            iter=mm.find(target-nums[i]);
            if(iter!=mm.end()){
                res.push_back(iter->second);
                res.push_back(i+1);
                return res;
            }else{
                mm[nums[i]]=i+1;
            }
        }
        return res;
    }
};

