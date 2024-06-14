class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        vector<int> colors(3, 0);
        for (const int num : nums)
            ++colors[num];
        nums.clear();
        for (int i = 0; i < 3; ++i)
            nums.insert(nums.end(), colors[i], i);
    }
};
