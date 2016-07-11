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
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    static bool cmp(const Interval &a, const Interval &b){
        if(a.start<b.start){
            return true;
        }else if(a.start==b.start){
            return a.end < b.end;
        }else{
            return false;
        }
    }
    vector<Interval> merge(vector<Interval> &intervals) {
        // write your code here
        
        int n=intervals.size();
        vector<Interval> res;
        
        if(n==0){
            return res;
        }
        
        //sort the interval first 
        sort(intervals.begin(),intervals.end(),cmp);
        
        //push_back the first small one
        res.push_back(intervals[0]);
        
        for(int i=1; i<intervals.size(); i++){
            auto back = res.rbegin();
            if(back->end<intervals[i].start){
                //like [1 2] and [3 4]
                res.push_back(intervals[i]);
            }else if(back->end<intervals[i].end){
                //like [1 3] and [2 4]
                back->end=intervals[i].end;
            }else{
                //like [1 4] and [2 3] do nothing 
            }
        }
        
        
        return res;
    }
};