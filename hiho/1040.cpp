#include <iostream>
#include <set>
using namespace std;

struct Point{
	int x;
	int y;

	bool operator==(const Point &p) const{
		return x==p.x && y==p.y;
	}
	bool operator<(const Point &p) const{
		if (x<p.x || (x==p.x && y<p.y)){
			return true;
		}else{
			return false;
		}
	}
};

struct Line{
	Point p1;
	Point p2;
};

bool checkRect(Line l[]){
	//check if 2 line vertical to l[0] and 1 line vertical to l[0]
    int vcnt=0;
    int pcnt=0;
    int dx0=l[0].p1.x-l[0].p2.x;
    int dy0=l[0].p1.y-l[0].p2.y;
	for(int i=1; i<4; i++){
		int dxi=l[i].p1.x-l[i].p2.x;
		int dyi=l[i].p1.y-l[i].p2.y;

		if(dx0*dxi+dy0*dyi==0){
			vcnt++;
			continue;
		}

		if(dx0*dyi-dxi*dy0==0){
			pcnt++;
			continue;
		}

	}

	return vcnt==2 && pcnt==1;
}

int main(){
	
	int t;
	cin>>t;
    
	for(int i=0; i<t; i++){
		set<Point> pset;
		Line l[4];
		for(int j=0; j<4; j++){
			int x1,y1,x2,y2;
			cin>>x1>>y1>>x2>>y2;
			Point a,b;
			a.x=x1;
			a.y=y1;
			b.x=x2;
			b.y=y2;
			l[j].p1=a;
			l[j].p2=b;
			pset.insert(a);
			pset.insert(b);
		}
        
		//judge if exactly 4 points
		if(pset.size()!=4){
			cout<<"not 4 "<<pset.size()<<endl;
			cout<<"NO"<<endl;
			continue;
		}

		if(!checkRect(l)){
			cout<<"NO"<<endl;
		}else{
			cout<<"YES"<<endl;
		}
	}

}