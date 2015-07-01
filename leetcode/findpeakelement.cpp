class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        for(int i=0; i<num.size()-1; i++){
            if(num[i]>num[i+1]){
                return i;
            }
        }
        return num.size()-1;
    }

};