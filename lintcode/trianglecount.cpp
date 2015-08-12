class Solution {
public:
    /**
     * @param S: A list of integers
     * @return: An integer
     */
    int triangleCount(vector<int> &S) {
        // write your code here
        sort(S.begin(),S.end());
        
        //fix largest edge 
        int count=0;
        for(int k=S.size()-1; k>=2; k--){
            int i=0;
            int j=k-1;
            
            while(i<j){
                if(S[i]+S[j]<=S[k]){
                    i++;
                }else{
                    count+=j-i;
                    j--;
                }
            }
        }
        
        return count;
    }
};
