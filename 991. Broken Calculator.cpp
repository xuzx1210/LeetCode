class Solution
{
public:
    int brokenCalc(int startValue, int target)
    {
        int result = 0;
        for (; target > startValue; ++result)
            target = (target & 1) ? (target + 1) : (target >> 1);
        return result + startValue - target;
    }
};
