#include<iostream>
#include<vector>
using namespace std;

int majorityElement(vector<int> &num) {
        int candidate=0;
        int count=0;
        
        for(int i=0; i<num.size(); i++){
            
            if(count == 0){
                count==1;
                candidate=num[i];
            } else {
                if(candidate==num[i]){
                    count++;
                }else{
                    count--;
                }
            }
        }
        return candidate;
    }

int main(){
	vector<int> ivec;
	ivec.push_back(3);
	ivec.push_back(3);
	ivec.push_back(4);
	cout<<majorityElement(ivec)<<endl;
}
