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
    static bool cmp(Interval &a, Interval &b){
        if(a.start<b.start){
            return true;
        }else if(a.start==b.start){
            return a.end<b.end;
        }else{
            return false;
        }
    }
    vector<Interval> merge(vector<Interval>& intervals) {
      vector<Interval> res;
      if(intervals.size()==0){
          return res;
      }
      sort(intervals.begin(),intervals.end(),cmp);
      
      res.push_back(intervals[0]);
      
      for(int i=1; i<intervals.size(); i++){
          if(res.back().end<intervals[i].start){
              //[1 2] [3 4]
              res.push_back(intervals[i]);
          }else if(res.back().end<intervals[i].end){
              //[1 3] [2 4]
              // need merge
              res.back().end=intervals[i].end;
          }else{
              //[1 4] [2 3] don't do anything
          }
      }
      return res;
    }
};