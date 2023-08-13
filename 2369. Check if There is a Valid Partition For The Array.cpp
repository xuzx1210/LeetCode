class Solution
{
public:
    bool validPartition(vector<int> &nums)
    {
        const int size = nums.size();
        bool a = true, b = false, c = nums[0] == nums[1];
        for (int i = 2; i < size; ++i)
        {
            bool curr = false;
            curr |= b && nums[i - 1] == nums[i];
            curr |= a && nums[i - 2] == nums[i - 1] && nums[i - 1] == nums[i];
            curr |= a && nums[i - 2] + 1 == nums[i - 1] && nums[i - 1] + 1 == nums[i];
            a = b;
            b = c;
            c = curr;
        }
        return c;
    }
};
