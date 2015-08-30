class Solution {
public:
    int mySqrt(int x) {
        int l=0;
        int r=x/2+2;
        
        while(l<r){
            int mid=l+((r-l)>>1);
            // when multiply two big number, first convert to long long then do the multiplication
            long long tmp=(long long)mid*mid;
            
            if(x==tmp){
                return mid;
            }else if (x<tmp){
               r=mid;
            }else{
               l=mid+1;
            }
        }
        
        return l-1;
    }
};