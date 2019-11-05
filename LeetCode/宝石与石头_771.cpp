class Solution
{
public:
    int numJewelsInStones(string J, string S)
    {
        int sum = 0;
        for (auto &chj : J)
        {
            for (auto &chs : S)
            {
                if (chj == chs)
                    sum++;
            }
        }
        return sum;
    }
};