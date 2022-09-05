class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        const int size = nums.size();
        int index = 0;
        for (int i = 0; i < size; ++i)
            if (nums[i])
                nums[index++] = nums[i];
        for (int i = index; i < size; ++i)
            nums[i] = 0;
    }
};
