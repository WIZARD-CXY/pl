#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
#include<limits.h>
#include<stack>
#include<queue>
#include<set>
#include<cstring>
using namespace std;

class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @param k: an integer
     * @return: the kth smallest number in the matrix
     */
    //a node for matrix node
    struct HeapNode{
        int val;
        int r;
        int c;
        HeapNode(int v, int row, int col):val(v),r(row),c(col){}
        HeapNode():val(0),r(0),c(0){}
    };
    void swap(HeapNode &a, HeapNode &b){
        HeapNode c=a;
        a=b;
        b=c;
    }
    // min heapify on a HeapNode array
    void minheapify(HeapNode a[], int i, int heapsize){
        int l=2*i+1;
        int r=2*i+2;
        
        int smallest=i;
        if(l<heapsize && a[l].val<a[smallest].val){
            smallest=l;
        }
        
        if(r<heapsize && a[r].val<a[smallest].val){
            smallest=r;
        }
        
        if(smallest!=i){
            swap(a[i],a[smallest]);
            minheapify(a,smallest,heapsize);
        }
    }
    
    void buildminheap(HeapNode a[],int heapsize){
        for(int i=(heapsize-1)/2; i>=0; i--){
            minheapify(a,i,heapsize);
        }
    }
    int kthSmallest(vector<vector<int> > &matrix, int k) {
        // write your code here
        int n=matrix[0].size();
        int m=matrix.size();
        
        if(k<0 || k>m*n){
            return INT_MAX;
        }
        
        //initial the first row as HeapNode row
        HeapNode a[n];
        for(int j=0; j<n; j++){
            a[j]=HeapNode(matrix[0][j],0,j);
        }
        
        //buildminheap(a,n);
        
        HeapNode hr;
        // iterate k times 
        while(k--){
            hr=a[0];
            // push the same col next row val in the heap
            int nextval=(hr.r+1<m)?matrix[hr.r+1][hr.c]:INT_MAX;
            a[0]=HeapNode(nextval,hr.r+1,hr.c);
            minheapify(a,0,n);
        }
        
        return hr.val;
    }
};


int main(){
    Solution sln;
    vector<int> vec={1};
    vector<int> avec={2};
    vector<int> bvec={3};
    vector<int> cvec={100};
    vector<int> dvec={101};
    vector<int> evec={1000};
    vector<int> fvec={9999};
    
    
    vector<vector<int> > v;
    v.push_back(vec);
    v.push_back(avec);
    v.push_back(bvec);
    v.push_back(cvec);
    v.push_back(dvec);
    v.push_back(evec);
    v.push_back(fvec);
   
    
    cout<<sln.kthSmallest(v,5);
}

