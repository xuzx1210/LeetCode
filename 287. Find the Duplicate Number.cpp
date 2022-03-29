class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        vector<bool> exist(nums.size() - 1, false);
        for (auto num : nums)
        {
            if (exist[num - 1])
                return num;
            exist[num - 1] = true;
        }
        return 0;
    }
};
