// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int cnt;
        int idx=0;
        char tmp[4];
        
        while(idx<n){
            int cnt=read4(tmp);
            //move tmp to buf, need a pointer which is idx
            for(int i=0; i<cnt && idx<n; i++){
                buf[idx++]=tmp[i];
            }
            if(cnt<4){
                break;
            }
        }
        
       return idx;
    }
};