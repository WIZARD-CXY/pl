class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> vis;
        
        for(auto n :nums){
            vis[n]=false;
        }
        int res=1;
        for(auto n : nums){
            int len=1;
            int left=n-1;
            
            while(vis.find(left)!=vis.end() && !vis[left]){
                vis[left]=1;
                left--;
                len++;
            }
            
            int right=n+1;
            
            while(vis.find(right)!=vis.end() && !vis[right]){
                vis[right]=1;
                right++;
                len++;
            }
            res=max(res,len);
        }
        
        return res;
    }
};