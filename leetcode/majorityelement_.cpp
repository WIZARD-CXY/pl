class Solution {
public:
    int majorityElement(vector<int> &num) {
        int candidate=0;
        int count=0;
        
        for(int i=0; i<num.size(); i++){
            if(count == 0){
                count=1;
                candidate=num[i];
            } else {
                if(candidate==num[i]){
                    count++;
                }else{
                    count--;
                }
            }
        }
        return candidate;
    }
};