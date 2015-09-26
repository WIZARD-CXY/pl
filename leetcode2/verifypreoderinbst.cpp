class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> ss;
        int low=INT_MIN;
        
        for(auto num : preorder){
            if(num<low){
                return false;
            }
            while(!ss.empty() && ss.top()<num){
                low=ss.top();
                ss.pop();
            }
            
            ss.push(num);
        }
        
        return true;
    }
};