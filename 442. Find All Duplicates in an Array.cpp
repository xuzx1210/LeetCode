class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        const int size = nums.size();
        vector<int> result{};
        for (int i = 0; i < size; ++i)
        {
            const int index = (nums[i] < 0 ? -nums[i] : nums[i]) - 1;
            if (nums[index] < 0)
                result.emplace_back(index + 1);
            else
                nums[index] = -nums[index];
        }
        return result;
    }
};
