class Solution {
public:
    void rotate(int nums[], int n, int k) {
        k=k%n;
        
        int b[n];
        
        for(int i=0; i<n; i++){
            b[(i+k)%n]=nums[i];
        }
        
        
        for(int i=0; i<n; i++){
            nums[i]=b[i];
        }
        
    }
};