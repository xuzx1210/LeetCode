class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
            return true;
        int start = 0, end = nums[start], M = end;
        if (end >= n - 1)
            return true;
        while (true)
        {
            bool change = false;
            for (int i = start; i <= end; ++i)
            {
                int destination = i + nums[i];
                if (destination > M)
                {
                    M = destination;
                    if (M >= n - 1)
                        return true;
                    change = true;
                }
            }
            if (!change)
                break;
            start = end + 1;
            end = M;
        }
        return false;
    }
};
