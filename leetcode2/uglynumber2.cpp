class Solution {
public:
    int nthUglyNumber(int n) {
        
        vector<int> ugly(n);
        int i2=0;
        int i3=0;
        int i5=0;
        ugly[0]=1;
        
        for(int i=1; i<n; i++){
             //i2 means the smallest index that makes ugly[i2]*2 > ugly[i]
             //i3 means the smallest index that makes ugly[i3]*3 > ugly[i]
             //i5 means the smallest index that makes ugly[i5]*5 > ugly[i]
            int minres=min(ugly[i2]*2,min(ugly[i3]*3,ugly[i5]*5));
            ugly[i]=minres;
            if (minres==ugly[i2]*2){
                i2++;
            }
            if (minres==ugly[i3]*3){
                i3++;
            }
            if (minres==ugly[i5]*5){
                i5++;
            }
        }
        
        return ugly[n-1];
        
    }
};