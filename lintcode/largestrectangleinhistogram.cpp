class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int res=0;
        
        int i=0;
        
        stack<int> ss;
        height.push_back(0);
        while(i<height.size()){
            if(ss.empty() || height[i]>=height[ss.top()]){
                ss.push(i++);
            }else{
                //met a smaller element
                int h=ss.top();
                ss.pop();
                //i-1 is right barrier, s.top is left barrier
                int area=height[h]*(ss.empty()?i:i-1-ss.top());
                res=max(res,area);
            }
        }
        
        return res;
    }
};