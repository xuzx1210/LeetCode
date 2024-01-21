class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int prevYes = 0, prevNo = 0;
        for (const int num : nums)
        {
            const int currYes = prevNo + num, currNo = max(prevYes, prevNo);
            prevYes = currYes;
            prevNo = currNo;
        }
        return max(prevYes, prevNo);
    }
};
