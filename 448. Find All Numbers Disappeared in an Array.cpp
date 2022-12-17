class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        for (int &num : nums)
        {
            const int index = (num > 0 ? num : -num) - 1;
            if (nums[index] > 0)
                nums[index] = -nums[index];
        }
        vector<int> result{};
        const size_t size = nums.size();
        for (size_t i = 0; i < size; ++i)
            if (nums[i] > 0)
                result.emplace_back(i + 1);
        return result;
    }
};
