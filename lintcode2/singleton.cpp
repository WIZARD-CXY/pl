class Solution {
public:
    /**
     * @return: The same instance of this class every time
     */
    static Solution* getInstance() {
        // write your code here
        // new c++11 local-static-initialization
        static Solution *instance = new Solution();
        
        return instance;
    }
    
    Solution(const Solution &s) = delete;
    Solution& operator=(const Solution &s) = delete;
private:
    Solution(){}
    ~Solution(){}
};
