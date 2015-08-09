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
        int max_airplane=0;
        int plane=0;
        
        vector<int> start;
        vector<int> end;
        
        for(auto interval : airplanes){
            start.push_back(interval.start);
            end.push_back(interval.end);
        }
        
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        
        
        int s=0,e=0;
        
        while(s<airplanes.size()){
            if(start[s]<end[e]){
                plane++;
                max_airplane=max(max_airplane,plane);
                s++;
            }else{
                plane--;
                e++;
            }
        }
        
        return max_airplane;
    }
};
