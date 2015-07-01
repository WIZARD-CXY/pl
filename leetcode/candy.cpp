class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        
        vector<int> candy(ratings.size(), 1);
        
        int min=1;
        
        for(int i=1; i<n; i++){
            if(ratings[i]>ratings[i-1]){
                candy[i]=++min;
            }else{
                min=1;
            }
        }
        min=1;
        
        for(int i=n-2; i>=0; i--){
            if(ratings[i]>ratings[i+1]){
                candy[i]=max(++min,candy[i]);
            }else{
                min=1;
            }
        }
        
        int ans=0;
        
        for(int i=0; i<n; i++){
            ans+=candy[i];
        }
        return ans;
        
    }
};