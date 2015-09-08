class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum=0;
        int total=0;
        int n=gas.size();
        int idx=0;
        
        if(n==0){
            return 0;
        }
        
        for(int i=0; i<n; i++){
            sum+=(gas[i]-cost[i]);
            total+=(gas[i]-cost[i]);
            //change to the next gas station to start
            if(sum<0){
                sum=0;
                idx=i+1;
            }
        }
        
        if(total<0){
            return -1;
        }else{
            return idx;
        }
    }
};