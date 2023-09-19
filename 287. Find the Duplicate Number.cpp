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
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int slow = 0, fast = 0;
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        slow = 0;
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
