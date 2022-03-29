class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        vector<bool> exist(nums.size() - 1, false);
        for (auto num : nums)
        {
            if (exist[num])
                return num;
            exist[num] = true;
        }
        return 0;
    }
};
