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
    static bool cmp(const Interval &a ,const Interval &b){
        if(a.start==b.start){
            return a.end<b.end;
        }
        return a.start<b.start;
    }
    vector<Interval> merge(vector<Interval> &intervals) {
        // write your code here
        int n=intervals.size();
        
        vector<Interval> res;
        
        if(n==0){
            return res;
        }
        
        sort(intervals.begin(),intervals.end(),cmp);
        
        res.push_back(intervals[0]);
        
        for(int i=1; i<n; i++){
            Interval back=res.back();
            if(back.end<intervals[i].start){
                //[1 2] [3 4]
                res.push_back(intervals[i]);
            }else if(back.end < intervals[i].end){
                //[1 3] [2 4]
                back.end=intervals[i].end;
                res.pop_back();
                res.push_back(back);
            }else{
                // big swallow small (back swallow intervals[i])
            }
        }
        return res;
    }
};
