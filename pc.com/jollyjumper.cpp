#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int n;

    while(cin>>n){
        vector<bool> diff(n-1,0);
        int pre;
        //cout<<"xixi"<<n<<endl;
        if(n==1){
            cout<<"Jolly"<<endl;
            //redundant input send to null
            int null;
            cin>>null;
            continue;
        }

        int i;
        for (i=0; i<n; i++){
            int num;
            cin>>num;
            if(i!=0){
                int absdiff=abs(pre-num);
                if(absdiff<1 || absdiff> n-1){
                    cout<<"Not jolly"<<endl;
                    break;
                }

                if(diff[absdiff-1]==0){
                    diff[absdiff-1]=1;
                }else{
                    cout<<"Not jolly"<<endl;
                    break;
                }
            }
            pre=num;
        }
        if(i==n){
            cout<<"Jolly"<<endl;   
        }else{
            // redundant number send to null
            int cnt=n-i;
            while(--cnt){
                int null;
                cin>>null;
            }
        }
    }
}