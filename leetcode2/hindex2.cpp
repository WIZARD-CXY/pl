class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        int l=0;
        int r=n;
        
        while(l<r){
            int m=l+((r-l)>>1);
            
            if(citations[m]==n-m){
                return citations[m];
            }else if(citations[m]<n-m){
                l=m+1;
            }else{
                r=m;
            }
        }
        
        return n-l;
    }
};