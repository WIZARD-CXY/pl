class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsets(vector<int> &nums) {
    	// write your code here
    	int n=nums.size();
    	vector<vector<int> > res;
    	
    	// use bitmap to generate subset
    	for(int i=0; i<(1<<n); i++){
            vector<int> tmp;
    	    for(int j=0; j<n; j++){
    	        if(i & (1<<j)){
    	            tmp.push_back(nums[j]);
    	        }
    	    }
    	    
    	    res.push_back(tmp);
    	}
    	
    	return res;
    }
};
