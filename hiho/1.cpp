#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int main(){
	double x,y,r;
	cin>>x>>y>>r;

	//only check the right up part
	int leftx=ceil(x);
	int lefty=floor(y+r);

	int rightx=floor(x+r);
	int righty=ceil(y);
    
    double res=0;
    int resx;
    int resy;
    for(int j=lefty; j>=righty; j--){
	    for(int i=rightx; i>=leftx; i--){
			double dist2=(double)(x-i)*(x-i)+(double)(y-j)*(y-j);
			if(dist2>res && dist2<=r*r){
				res=dist2;
				resx=i;
				resy=j;
			}else if(abs(dist2-res)<1e-15 && dist2<=r*r){
				if(i>resx){
					resx=i;
					resy=j;
				}else if (i==resx && j>resy){
					resx=i;
					resy=j;
				}
			}
		}
	}

	cout<<resx<<" "<<resy<<endl;
}