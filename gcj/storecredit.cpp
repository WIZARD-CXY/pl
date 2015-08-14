#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){
	freopen("A-large-practice.in","r",stdin);

	int n;
	scanf("%d",&n);

	for(int i=1; i<=n; i++){
		int c;
		int l;
		scanf("%d%d",&c,&l);

		vector<int> items(l);
		for(int j=0; j<l; j++){
			scanf("%d",&items[j]);
		}

		unordered_map<int,int> mm;

		for(int j=0; j<l; j++){
			auto it=mm.find(c-items[j]);

			if(it!=mm.end()){
				printf("Case #%d: %d %d\n",i,it->second,j+1);
				break;
			}
			mm[items[j]]=j+1;
		}
	}

}