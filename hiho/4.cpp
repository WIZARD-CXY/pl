#include <iostream>
using namespace std;
#include <vector>

 void rotate(vector<vector<int> >& matrix,int x,int y,int n) {
    
    for(int i=x; i<x+n/2; i++){
        for(int j=y; j<y+n; j++){
            swap(matrix[i][j],matrix[n-1-i][j]);
        }
    }
    
    for(int i=x; i<x+n; i++){
        for(int j=i; j<y+n; j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }      
}

bool isSame(vector<vector<int> > &A, vector<vector<int> > &B){
	int n=A.size();

	if(n&1){
		//n is odd
		if(A[n/2][n/2]!=B[n/2][n/2]){
			return false;
		}

		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(A[i][j]!=B[i][j]){
					return false;
				}
			}
		}
	}else{
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(A[i][j]!=B[i][j]){
					return false;
				}
			}
		}
	}
	return true;
}

bool process(vector<vector<int> > &A){
	int n=A.size();
	bool flag=false;
	if(n&1){
		for(int k=0;k<4; k++){
			rotate(A);

			if(isSame(A,B)){
				flag=true;
				break;
	        }

		}
	}else{
		flag=process(A,0,0,n/2) && process(A,0,n/2,n/2) && process(A,n/2,n/2) && process(n/2,n/2,n/2);
        
	}


	return flag;

}
int main(){
	int t;
	cin>>t;

	for(int cas=0; cas<t; cas++){
		int n;
		cin>>n;

		vector<vector<int> > A(n,vector<int>(n));
		vector<vector<int> > B(n,vector<int>(n));

		for(int i=0; i<n;i++){
			for(int j=0; j<n; j++){
				cin>>A[i][j];
			}
		}

		for(int i=0; i<n;i++){
			for(int j=0; j<n; j++){
				cin>>B[i][j];
			}
		}

		bool flag=false;


		if(n&1){
			for(int k=0;k<4; k++){
				rotate(A);

				if(isSame(A,B)){
					flag=true;
					break;
		        }

			}
		}
		
		if(flag){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}

	}
	
}