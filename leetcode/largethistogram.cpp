class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int res=0;
        stack<int> ss;
        
        int i=0;
        height.push_back(0);// one dummy element int the end
        
        while(i<height.size()){
            if(ss.empty()||height[i]>=height[ss.top()]){
                //push current idx into stack and move forward
                ss.push(i++);
            }else{
                //pop the stack and compute all the candidates
                int t=ss.top();
                ss.pop();
                res=max(res,height[t]*(ss.empty()?i:i-ss.top()-1));
            }
        }
        return res;
        
    }
};