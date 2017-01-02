//https: //discuss.leetcode.com/topic/67482/solution-with-detailed-explanation/7
class Solution
{
  public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest)
    {

        int r = minutesToTest / minutesToDie + 1;

        return ceil(log(buckets) / log(r));
    }
};