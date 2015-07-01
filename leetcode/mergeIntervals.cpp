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
    static bool cmp(const Interval& a,const Interval& b){
        if(a.start==b.start){
            return a.end<b.end;
        }
        return a.start < b.start;
    }
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> res;
        int n = intervals.size();
        if(n <= 1){
            return intervals;
        }
        // sort with start increasing order
        sort(intervals.begin(),intervals.end(),cmp);

        res.push_back(intervals[0]);
        
        for(int i = 1;i<n;i++){
            Interval preIn = res.back();
            Interval curIn = intervals[i];
            
            if(curIn.start>preIn.end){
                // [1,2] [3,4]
                res.push_back(curIn);
            } else if (curIn.end>preIn.end){
                 // [1,3] [2,6]
                preIn.end=curIn.end;
                res.pop_back();
                res.push_back(preIn);
            }
            // [1,7] [2,3] do nothing skip [2,3]
        }
        return res;
    }
};