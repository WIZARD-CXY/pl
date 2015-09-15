class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int> > res,heights;
        
        //height is point set
        for(auto b : buildings){
            heights.push_back(make_pair(b[0],-b[2]));
            heights.push_back(make_pair(b[1],b[2]));
        }
        sort(heights.begin(),heights.end());
        
        multiset<int> hset;
        //insert a dummy element
        hset.insert(0);
        //travesal point set height
        int pre=0;
        int cur=0;
        for(auto h :heights){
            if(h.second<0){
                //left point
                hset.insert(-h.second);
            }else{
                //need remove from hset
                hset.erase(hset.find(h.second));
            }
            
            cur=*hset.rbegin(); // the highest point ever had
            if(pre!=cur){
                res.push_back(make_pair(h.first,cur));
                pre=cur;
            }
        }
        
        return res;
    }
};