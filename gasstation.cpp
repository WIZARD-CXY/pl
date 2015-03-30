//reference http://www.cnblogs.com/felixfang/p/3814463.html

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        
        int total=0,sum=0,start=0;
        
        for(int i=0; i<gas.size(); i++){
            total+=(gas[i]-cost[i]);
            
            if(sum<0){
                sum=gas[i]-cost[i];
                start=i;
            }else{
                sum+=(gas[i]-cost[i]);
            }
            
        }
        return total<0?-1:start;     
    }
};