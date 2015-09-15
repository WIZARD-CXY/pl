class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> res, height;
        
        // height is point set
        for(auto &b : buildings){
            height.push_back({b[0],-b[2]});//left side height is meant to be left
            height.push_back({b[1],b[2]});
        }
        
        multiset<int> maxheap; //record the left height
        maxheap.insert(0);//left dummy height
        
        int pre=0;// pre contour height
        int cur=0;
        sort(height.begin(),height.end());

        for(auto &h : height){
            if(h.second<0){
                //left point
                maxheap.insert(-h.second);
            }else{
                //right point delete from maxheap
                maxheap.erase(maxheap.find(h.second));
            }
            
            cur=*maxheap.rbegin();//get the max height
            if(pre!=cur){
                //met a cross point
                res.push_back({h.first,cur});
                pre=cur;
            }
        }
        return res;
        
    }
};