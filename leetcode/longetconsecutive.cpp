class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> vis;
        unordered_set<int> exist;
        
        for(auto &num : nums){
            exist.insert(num);
        }
        
        int res=INT_MIN;
        for(auto &num : nums){
            if(vis.find(num)!=vis.end()){
                //has visited before just continue
                continue;
            }
            
            int count=1;
            // try to visit smaller element
            int left=num;
            while(exist.find(--left)!=exist.end()){
                //mark it as visited
                vis.insert(left);
                count++;
            }
            
            // try to vis larger element
            int right=num;
            while(exist.find(++right)!=exist.end()){
                //mark as visited
                vis.insert(right);
                count++;
            }
            res=max(res,count);
        }
        
        return res;
        
    }
};