class Solution {
public:
    void swap(int &a,int &b){
        int temp=a;
        a=b;
        b=temp;
    }
    
    void reverse(int num[],int n){
        for(int i=0; i<n/2; i++){
            swap(num[i],num[n-1-i]);
        }
    }
    void rotate(int nums[], int n, int k) {
        k=k%n;
        
        reverse(nums,n);
        reverse(nums,k);
        reverse(nums+k,n-k);
    }
        
        
};