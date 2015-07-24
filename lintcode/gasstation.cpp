class Solution {
public:
    /**
     * @param gas: a vector of integers
     * @param cost: a vector of integers
     * @return: an integer 
     */
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // write your code here
        int total=0,sum=0,start=0;
        
        for(int i=0; i<gas.size(); i++){
            sum+=(gas[i]-cost[i]);
            total+=(gas[i]-cost[i]);
            if(sum<0){
                //if the current sum<0, change to next start point
                start=i+1;
                sum=0;
            }
        }
        
        return total>=0?start:-1;
        
        
    }
};
