class Solution {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of 
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySumII(vector<int>& A) {
        // Write your code here
        // first get A max continuous sum
        vector<int> res;
        int n=A.size();
        
        if(n==0){
            return res;
        }
        
        int sum=A[0];
        int start=0;
        int end=0;
        
        int maxsum=A[0];
        int totalsum=A[0];
        
        int st=0;// res left
        int en=0;// res right
        
        for(int i=1; i<n; i++){
            totalsum+=A[i];
            if(sum>0){
                sum+=A[i];
                end=i;
            }else{
                // start a new subarray
                sum=A[i];
                start=i;
                end=i;
            }
            
            if(sum>maxsum){
                st=start;
                en=end;
                maxsum=sum;
            }
            
        }
        
        bool flag=false;// get res from first part or last part
        
        // find the continuous min subarray
        sum=A[0];
        int minsum=A[0];
        int minstart=0;
        int minend=0;
        int minst=0;
        int minen=0;
        
        for(int i=1; i<n; i++){
            if(sum<0){
                sum+=A[i];
                minend=i;
            }else{
                // start a new subarray
                sum=A[i];
                minstart=i;
                minend=i;
            }
            if(minsum>sum){
                minsum=sum;
                minst=minstart;
                minen=minend;
            }
        }
        
        if((totalsum-minsum)>maxsum){
            if(minst==0 && minend==(n-1)){
                //if all pick to get smallest ,do nothing
            }else{
                flag=true;
                st=minst;
                en=minen;
            }
        }
        
        if(flag){
            return {(en+1)%n,(st-1+n)%n};
        }else{
            return {st,en};
        }
    }
};
