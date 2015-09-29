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
        int idx=0;
        //flag is true means last read byte <4 means can't read next time
        // break
        bool flag=false;
        
        while(idx<n){
            if(tmpidx==tmplen){
                //last read is finished buffer is empty
                //start a new read4
                tmpidx=0;
                tmplen=read4(buffer);
                
                if(tmplen<4){
                    flag=true;
                }
            }
            
            for(;tmpidx<tmplen && idx<n; tmpidx++){
                    buf[idx++]=buffer[tmpidx];
            }
            
            if(flag){
                break;
            }
        }
        
        return idx;
    }
    char buffer[4];
    int tmpidx=0; // indicate the buffer idx buf[idx] to buf[tmplen] is unreaded last time.
    int tmplen=0; // tmplen is mostly 4, except we dont't get a 4 byte read last time and leave some chars in buffer
                  // if will be consumed by next read
};