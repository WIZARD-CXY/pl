class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        //ss just store
        stack<int> ss;
        
        //insert a dummy element to the height
        height.push_back(0);
        int i=0;
        int res=0;
        
        while(i<height.size()){
            if(ss.empty() || height[i]>=height[ss.top()]){
                ss.push(i++);
            }else{
                //meet a lower rectangle
                int idx=ss.top();
                ss.pop();
                // [ss.top()+1,i-1] range 
                int area=height[idx]*(ss.empty()?i:i-1-ss.top());
                res=max(res,area);
            }
        }
        
        return res;
    }
};