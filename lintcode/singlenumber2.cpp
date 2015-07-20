class Solution {
public:
	/**
	 * @param A : An integer array
	 * @return : An integer 
	 */
    int singleNumberII(vector<int> &A) {
        // write your code here
        int res=0;
        //record every bit's total count number
        int count[32]={0};
        for(int i=0; i<32; i++){
            for(auto a:A){
                if(a &(1<<i)){
                    count[i]++;
                }
            }
            res|=(count[i]%3)<<i;
        }
        
        return res;
    }
};
