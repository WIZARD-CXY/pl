/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution { 
public:
    /**
     *@param A, queries: Given an integer array and an query list
     *@return: The result list
     */
    vector<long long> intervalSum(vector<int> &A, vector<Interval> &queries) {
        // write your code here
        //use presum 
        vector<long long > sum(A.size()+1);
        
        //sum[i] records the [0..i) sum
        
        for(int i=1;i<=A.size(); i++){
            sum[i]=A[i-1]+sum[i-1];
        }
        
        vector<long long> res;
        
        for(auto query : queries){
            res.push_back(sum[query.end+1]-sum[query.start]);
        }
        
        return res;
    }
};
