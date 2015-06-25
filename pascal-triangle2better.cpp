class Solution {
public:
    vector<int> getRow(int rowIndex) 
    {
        vector<int> array;
        for (int i = 0; i <= rowIndex; i++) 
        {
            for (int j = i-1; j > 0; j--)// from tail to head to prevent corruption
            {
                array[j] = array[j-1] + array[j];
            }
            array.push_back(1);
        }
        return array;
    }
};
