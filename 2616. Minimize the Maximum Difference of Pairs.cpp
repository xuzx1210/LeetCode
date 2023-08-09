class Solution
{
public:
    int minimizeMax(vector<int> &nums, int p)
    {
        const int size = nums.size();
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.back() - nums.front();
        while (left < right)
        {
            const int middle = (left + right) >> 1;
            int pairs = 0;
            for (int i = 1; i < size && pairs < p; ++i)
                if (nums[i] - nums[i - 1] <= middle)
                {
                    ++i;
                    ++pairs;
                }
            if (pairs == p)
                right = middle;
            else
                left = middle + 1;
        }
        return left;
    }
};
