class Solution
{
public:
    int arraySign(vector<int> &nums)
    {
        int positive = true;
        for (int num : nums)
            if (num == 0)
                return 0;
            else if (num < 0)
                positive = !positive;
        return positive ? 1 : -1;
    }
};
