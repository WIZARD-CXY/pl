class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return an integer
     */
    int longestConsecutive(vector<int> &num) {
        // write you code here
        int res=0;
        // visited element set
        unordered_set<int> vis;
        unordered_set<int> exist;
        
        for(auto x : num){
            exist.insert(x);
        }
        
        for(auto x: num){
           if(vis.find(x)!=vis.end()){
               //if visited before just skip
               continue;
           }
           
           int count=1;
           
           int left=x;
           while(exist.find(--left)!=exist.end()){
               vis.insert(left);
               count++;
           }
           
           int right=x;
           
           while(exist.find(++right)!=exist.end()){
               vis.insert(right);
               count++;
           }
           
           res=max(res,count);
        }
        
        return res;
    }
};
