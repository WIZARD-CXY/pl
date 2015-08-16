class Solution {
public:
    /**
     * @param buildings: A list of lists of integers
     * @return: Find the outline of those buildings
     */
     
    struct endpoint{
        int height;
        bool isStart;
    };
    vector<vector<int> > buildingOutline(vector<vector<int> > &buildings) {
        // write your code here
        vector<vector<int> > res;
        
        map<int,vector<endpoint>> point2height;
        
        for(const auto& building : buildings){
            point2height[building[0]].push_back(endpoint{building[2],true});
            point2height[building[1]].push_back(endpoint{building[2],false});
        }
        
        map<int,int> height2count;
        
        int cur_start=-1;
        int cur_max=0;
        
        //enumerate each point in increasing order of x-axis
        for(auto & kvp : point2height){
            const auto point =kvp.first;
            const auto heights = kvp.second;
            
            for(auto& h:heights){
                if(h.isStart){
                    ++height2count[h.height];
                }else{
                    --height2count[h.height];
                    if(height2count[h.height]==0){
                        height2count.erase(h.height);
                    }
                }
            }
            
            if(height2count.empty() || cur_max !=height2count.crbegin()->first){
                if(cur_max>0){
                    res.push_back({cur_start,point,cur_max});
                }
                cur_start=point;
                cur_max=height2count.empty()?0:height2count.crbegin()->first;
            }
        }
        
        return res;
        
        
    }
};
