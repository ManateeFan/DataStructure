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
class Solution
{
public:
    int numJewelsInStones(string J, string S)
    {
        int sum = 0;
        multiset<char> s;
        for(auto& ch: S) s.insert(ch);
        for(auto& ch: J)
            sum += s.count(ch);
        return sum;
    }
};