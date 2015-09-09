// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l=1;
        //in case n+1 is overflow the INT_MAX
        long long r=(long long)n+1;
        
        while(l<r){
            int mid=l+((r-l)>>1);
            
            if(isBadVersion(mid)){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        
        return l;
    }
};