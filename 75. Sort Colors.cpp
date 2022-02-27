class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int count[3];
        for (auto num : nums)
            ++count[num];
        nums.clear();
        for (int i = 0; i < 3; ++i)
            nums.insert(nums.end(), count[i], i);
    }
};
