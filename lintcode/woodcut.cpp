class Solution {
public:
    /** 
     *@param L: Given n pieces of wood with length L[i]
     *@param k: An integer
     *return: The maximum length of the small pieces.
     */
    int woodCut(vector<int> L, int k) {
        // write your code here
        if(L.size()==0){
            return 0;
        }
        long long minlen=1;
        long long maxlen=*max_element(L.begin(),L.end());
      
        maxlen++;
        // actually search for the upper bound of length
        // then length-1 is answer
        while(minlen<maxlen){
            long long midlen=(maxlen+minlen)/2;
            
            long long woodnum=0;
            for(auto l:L){
                woodnum+=l/midlen;
            }
            
            if(woodnum<k){
                maxlen=midlen;
            }else{
                minlen=midlen+1;
            }
        }
        return minlen-1;
    }
};
