#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
#include<limits.h>
#include<stack>
using namespace std;

int gcd(int a, int b){
        return b==0?a:gcd(b,a%b);
}
    
void rotate(int nums[], int n, int k) {
    k=k%n;
        
    if(k==0){
        return;
    }
    
    while(k--){
        int temp = nums[n-1];
        
        for(int i=0; i<n-1; i++){
            nums[n-1-i]=nums[n-2-i];
        }
        nums[0]=temp;
    }
}


int main(){
    int nums[]={1,2,3,4,5,6,7};
    rotate(nums,7,7);
    for(int i=0; i<7; i++){
        cout<<nums[i]<<" ";
    }

}