class Solution {
public:
    /**
     * @param pages: a vector of integers
     * @param k: an integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int k) {
        // write your code here
        int sum=0;
        
        if(k>pages.size()){
            return *max_element(pages.begin(),pages.end());
        }
        
        for(auto page : pages){
            sum+=page;
        }
        
        //lower bound is average 
        //upper bound is total pages
        int average=sum/k;
        
        //using bs to find lower_bound 
        return bs(pages,k,average,sum);
    }
    
    int bs(vector<int> &pages,int k, int l,int r){
        
        while(l<=r){
            int mid=l+((r-l)>>1);
            
            if(valid(pages,mid,k)){
                //try smaller mid
                r=mid-1;
            }else{
                //try larger mid
                l=mid+1;
            }
        }
        
        return l;
    }
    
    bool valid(vector<int> &pages,int x,int k){
        // check whether we can finish copy the book with everybody copy x pages
        // using k people
        
        int cnt=0;
        int havecopied=0;
        int i=0;
        while(i<pages.size()){
            if(pages[i] > x) {
                return false;
            }
            if(havecopied+pages[i] > x) {
                // use another man to copy
                cnt++;
                havecopied = 0;
            }
            havecopied+=pages[i];
            i++;
        }
        //left some pages to copy
        if(havecopied>0){
            cnt++;
        }
        return cnt<=k;
    }
};
