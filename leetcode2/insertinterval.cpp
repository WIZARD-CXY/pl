/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        
        for(int i=0; i<intervals.size(); i++){
            //new is [1 2] interval[i] is [3 4]
            if(newInterval.end<intervals[i].start){
                res.push_back(newInterval);
                res.insert(res.end(),intervals.begin()+i,intervals.end());
                return res;
            }else if(newInterval.start>intervals[i].end){
                // new is [3 4] interval[i] is [1 2]
                res.push_back(intervals[i]);
            }else{
                // overlap with 4 condition
                // enlarge newInterval, enter the next iteration
                // new is [1 3] intervals[i] is [2 4]
                // new is [2 3] intervals[i] is [1 4]
                // new is [1 4] intervals[i] is [2 3]
                // new is [2 4] intervals[i] is [1 3]
                newInterval.end=max(newInterval.end,intervals[i].end);
                newInterval.start=min(newInterval.start,intervals[i].start);
            }
        }
        
        res.push_back(newInterval);
        
        return res;
    }
};