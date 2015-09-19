class Solution{
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */    
    void sortColors2(vector<int> &colors, int k) {
        // write your code here
        // to avoid using extra space, you need to utilize the colors;
        
        //3 2 2 1 4

        //2 2 -1 1 4

        //2 -1 -1 1 4

        //0 -2 -1 1 4

        //-1 -2 -1 0 4

        //-1 -2 -1 -1 0
        for(int i=0; i<colors.size(); i++){
            
            while(colors[i]>0){
                int num=colors[i];
                
                //use colors[num-1] to store the count of num
                if(colors[num-1]>0){
                    //exist color move it to colors[i];
                    colors[i]=colors[num-1];
                    colors[num-1]=-1;// -1 as num occur once
                }else{
                    // the count is empty or using as index
                    colors[num-1]--;
                    colors[i]=0; //jump out the while loop to proceed
                }
                
            }
        }
        
        int idx=colors.size()-1;
        for(int i=k-1; i>=0;i--){
            int cnt=-colors[i];
             
            while(cnt--){
                colors[idx--]=i+1;
            }
        }
    }
};
