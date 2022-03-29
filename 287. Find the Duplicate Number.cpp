class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int n = nums.size() - 1;
        vector<bool> exist(n, false);
        for (auto num : nums)
        {
            if (exist[num])
                return num;
            exist[num] = true;
        }
        return 0;
    }
};
