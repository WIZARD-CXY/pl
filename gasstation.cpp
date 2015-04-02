//reference http://www.cnblogs.com/felixfang/p/3814463.html

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        
        int total=0,sum=0,j=-1;
        
        for(int i=0; i<gas.size(); i++){
            total+=(gas[i]-cost[i]);
            sum+=(gas[i]-cost[i]);            
            if(sum<0){
                sum=0;
                j=i;
            } 
        }
        return total<0?-1:j+1;     
    }
};
