class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int k = 1, size = nums.size();
        for (int i = 1; i < size; ++i)
            if (nums[i] != nums[i - 1])
                nums[k++] = nums[i];
        return k;
    }
};
