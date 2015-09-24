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
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        
        //rooms end time may be duplicate so use multiset
        multiset<int> roomsendtime;
        
        for(int i=0; i<intervals.size(); i++){
            // find the min end time room
           
           if(!roomsendtime.empty() && *roomsendtime.begin()<=intervals[i].start){
               //update the room end time
               roomsendtime.erase(roomsendtime.begin());
           }
           roomsendtime.insert(intervals[i].end);
        }
        
        return roomsendtime.size();
    }
    
    static bool cmp(const Interval &a, const Interval &b){
        if(a.start<b.start){
            return true;
        }else if (a.start==b.start){
            return a.end<b.end;
        }else{
            return false;
        }
    }
};