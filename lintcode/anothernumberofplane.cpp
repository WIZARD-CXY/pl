/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution {
public:
    /**
     * @param intervals: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        // write your code here
        int res=0;
        vector<pair<int,bool>> v;
        
        for(auto item: airplanes){
            v.push_back(make_pair(item.start,true));
            v.push_back(make_pair(item.end,false));
        }
        
        sort(v.begin(),v.end());
        
        int cur=0;
        for(auto item : v){
            if(item.second){
                // take off
                cur++;
                res=max(cur,res);
            }else{
                // land
                cur--;
            }
            
        }
        
        return res;
    }
};