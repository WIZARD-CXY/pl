class Solution {
public:
    /**
     * @param A an integer array
     * @param start an integer
     * @param end an integer
     * @return the number of possible answer
     */
    int subarraySumII(vector<int>& A, int start, int end) {
        // sum_from_start[i] denotes sum for 0 ~ i - 1.
        int n=A.size();
        vector<int> sum(n+ 1);
        for(int i=1; i<=n; i++){
            sum[i]=sum[i-1]+A[i-1];
        }

        int result = 0;
        for (int j = 1; j <= A.size(); ++j) {
            const auto left = lower_bound(sum.cbegin(),
                                          sum.cbegin() + j,
                                          sum[j] - end);
            const auto right = upper_bound(sum.cbegin(),
                                           sum.cbegin() + j,
                                           sum[j] - start);
            result += (right - left);
        }

        return result;
    }
};