class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        const int size = nums.size();
        int k = 0;
        for (int i = 0; i < size; ++i)
            if (k < 2)
                nums[k++] = nums[i];
            else if (nums[k - 2] != nums[i])
                nums[k++] = nums[i];
        return k;
    }
};
