class Solution {  
 public:  
  vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {  
    // Note: The Solution object is instantiated only once and is reused by each test case.
    vector<Interval> res;
    
    vector<Interval>::iterator it = intervals.begin();  
    for(;it!=intervals.end(); it++){
        if(it->end < newInterval.start){
            res.push_back(*it);
        }else if(it->start > newInterval.end){
            res.push_back(newInterval);
            res.insert(res.end(),it,intervals.end());
            return res;
        }else{
            //overlap
            newInterval.start=min(it->start,newInterval.start);
            newInterval.end=max(it->end,newInterval.end);
        }
    }
    res.push_back(newInterval);

    return res;  
  }  
};  