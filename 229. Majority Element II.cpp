class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        vector<int> result{};
        const int size = nums.size();
        int candidate0, candidate1;
        int count0 = 0, count1 = 0;
        for (int i = 0; i < size; ++i)
            if (nums[i] == candidate0)
                ++count0;
            else if (nums[i] == candidate1)
                ++count1;
            else if (count0 == 0)
            {
                candidate0 = nums[i];
                count0 = 1;
            }
            else if (count1 == 0)
            {
                candidate1 = nums[i];
                count1 = 1;
            }
            else
            {
                --count0;
                --count1;
            }
        count0 = count1 = 0;
        for (int i = 0; i < size; ++i)
            if (nums[i] == candidate0)
                ++count0;
            else if (nums[i] == candidate1)
                ++count1;
        const int threshold = size / 3;
        if (count0 > threshold)
            result.emplace_back(candidate0);
        if (count1 > threshold)
            result.emplace_back(candidate1);
        return result;
    }
};
