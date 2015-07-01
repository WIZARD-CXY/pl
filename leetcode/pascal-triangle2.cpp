vector<int> getRow(int rowIndex) 
{
        vector<int> pre;
        if (rowIndex < 0) return pre;
        vector<int> rs(1,1);
 
        for (int i = 0; i < rowIndex; i++)
        {
            
            swap(rs,pre);
            rs.clear();
 
            rs.push_back(1);
            for (int j = 0; j < i; j++)
            {
                rs.push_back(pre[j]+pre[j+1]);
            }
            rs.push_back(1);
        }
        return rs;
}
