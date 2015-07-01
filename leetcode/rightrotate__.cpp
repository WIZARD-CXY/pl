class Solution {
public:

    int gcd(int a, int b){
        return b==0?a:gcd(b,a%b);
    }
    
    void rotate(int nums[], int n, int k) {
        k=k%n;
        
        if(k==0){
            return;
        }
        
        int g = gcd(n,k);
        
        for(int i=0; i<g; i++){
            int j=i;
            int cur=nums[j];
            
            do{
                int temp=nums[(j+k)%n];
                nums[(j+k)%n]=cur;
                cur=temp;
                j=(j+k)%n;
            }while(j!=i);
        }
    }
        
        
};