class Solution {
public:
    /**
     * @param A: An integer matrix
     * @return: The index of the peak
     */
    vector<int> findPeakII(vector<vector<int> > A) {
        // write your code here
        vector<int> res;
        int left = 0, right = A.size() - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            int col = findPeakIdx(A[mid]);
            if (A[mid][col] < A[mid+1][col]) {
                //find in the lower half
                left = mid + 1;
            } else if (A[mid][col] < A[mid-1][col]) {
                //find in the upper half
                right = mid - 1;
            } else {
                //find it
                return {mid, col};
            }
        }
        return res;
    }
    int findPeakIdx(vector<int> &v) {
        int maxIdx = 0;
        for (int i = 1; i < v.size(); ++i) {
            if (v[i] > v[maxIdx]) maxIdx = i;
        }
        return maxIdx;
    }
};