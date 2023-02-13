class Solution
{
public:
    int countOdds(int low, int high)
    {
        int result = (high - low) >> 1;
        if ((low & 1) || (high & 1))
            ++result;
        return result;
    }
};
