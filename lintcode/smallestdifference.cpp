class Solution {
public:
    /**
     * @param A, B: Two integer arrays.
     * @return: Their smallest difference.
     */
    int smallestDifference(vector<int> &A, vector<int> &B) {
        // write your code here
        sort(B.begin(),B.end());;
        
        int res=INT_MAX;
        for(auto a : A){
            auto it=lower_bound(B.begin(),B.end(),a);
            
            if(it==B.end()){
                //do not find 
                res=min(res,abs(a-*(it-1)));
            }else if(it==B.begin()){
                // first one or too small 
                res=min(res,abs(a-*it));
            }else{
                //one step behind or find it exactly
                // 4 6 10 find lower_bound(7)
                // 4 6 7  find lower_bound(7)
                // 4 6 10 find lower_bound(9)
                res=min(res,abs(a-*(it-1)));
                res=min(res,abs(a-*(it)));
            }
        }
        
        return res;
    }
};