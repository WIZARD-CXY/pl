#include <iostream>

using namespace std;

int updatebits(int m, int n, int i, int j){
	//update bit j to i to 0

	// make a i to j all 0, other bit all 1 mask

	int allone=~0;

	int leftmask=allone<<(j+1);
	int rightmask=(1<<i)-1;

	int mask=leftmask|rightmask;

	return (m&mask) |(n<<i);
}

int main(){
	int m=1024,n=19;
	int i=2,j=6;

	cout<<hex<<updatebits(m,n,i,j)<<endl;
}