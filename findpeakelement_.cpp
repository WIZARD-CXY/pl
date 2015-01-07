class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int l=0;
        int r=num.size()-1;
        
        while(l<r){
            int mid=(l+r)/2;
        
            if(num[mid]<num[mid+1]){
                //find in the right
                l=mid+1;
            }else{
                //find in the left
                r=mid;
            }
        }
        
        return l;
    }

};