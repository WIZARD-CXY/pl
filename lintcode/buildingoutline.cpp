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

// solution 2: a clean and neat one
/*
We adopt multiset as a min-heap, hence we could 
keep track of the current height. whenever it changes, 
we update the result.
*/

vector<vector<int> > buildingOutline(vector<vector<int> > &buildings) {
        // write your code here
        vector<vector<int>> ans;
        if(buildings.size() == 0) {
            return ans;
        }
        // borrow the idea from skyline problem and
        // deal with the output format if neccessary
        
        vector<pair<int, int>> heights;
        for(auto b: buildings) {
            heights.push_back(make_pair(b[0], -b[2]));
            heights.push_back(make_pair(b[1], b[2]));
        }
        
        sort(heights.begin(), heights.end());
        
        vector<pair<int,int>> res;
        
        multiset<int> set;
        set.insert(0);
        int prev = 0;
        
        int start = -1;

        for(auto h:heights) {
            // start point
            if(h.second < 0) {
                set.insert(-h.second);
            }
            else {
                // end point
                set.erase(set.find(h.second));
            }
            
            int cur = *set.rbegin();
            if(prev != cur) {
            	if(prev > 0) {
            		ans.push_back(vector<int>{start, h.first, prev});
            	}
            	start = h.first;
            	prev = cur;
            }
            
        }
       
       	
        return ans;
    }
