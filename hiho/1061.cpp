#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

struct node{
	char c;
	int cnt;
};

int main(){
	int t;
	cin>>t;

	for(int i=0; i<t; i++){
		int num;
		cin>>num;
		if(num==0){
			cout<<"NO"<<endl;
			continue;
		}
        
        string s;
		cin>>s;

		vector<node> vnode;
        int cnt=1;
        char pre=s[0];
		for(int i=1; i<num; i++){
			if(s[i]==pre){
				cnt++;
			}else{
				node newnode;
				newnode.c=pre;
				newnode.cnt=cnt;

				vnode.push_back(newnode);
				pre=s[i];
				cnt=1;
			}
		}

		node newnode;
		newnode.c=pre;
		newnode.cnt=cnt;

		vnode.push_back(newnode);

        bool flag=false;
		for(int i=0; i<vnode.size()-2; i++){
			if(vnode[i].c+1==vnode[i+1].c &&
				vnode[i+1].c+1==vnode[i+2].c &&
				vnode[i].cnt>=vnode[i+1].cnt &&
				vnode[i+2].cnt>=vnode[i+1].cnt){
				flag=true;
			    break;
			}
		}
        if(flag){
        	cout<<"YES"<<endl;
        }else{
        	cout<<"NO"<<endl;
        }

	}

}