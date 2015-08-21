class Solution {
public:
    /**
     * @param ratings Children's ratings
     * @return the minimum candies you must give
     */
    int candy(vector<int>& ratings) {
        // Write your code here
        int n=ratings.size();
        
        vector<int> candy(n,1);
    
        int min=1;
        
        //sweep from head to tail
        for(int i=1;i<n; i++){
            if(ratings[i]>ratings[i-1]){
                candy[i]=++min;
            }else{
                min=1;
            }
        }
        
        //adjust from tail to head
        min=1;
        for(int i=n-2;i>=0; i--){
            if(ratings[i]>ratings[i+1]){
                candy[i]=max(candy[i],++min);
            }else{
                min=1;
            }
        }
        
        int ans=0;
        
        for(auto c : candy){
            ans+=c;
        }
        
        return ans;
    }
};
