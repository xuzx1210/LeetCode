class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        unordered_map<int, int> frequency({});
        int result = 0;
        for (int num : nums)
        {
            int remain = k - num;
            if (frequency[remain])
            {
                --frequency[remain];
                ++result;
            }
            else
                ++frequency[num];
        }
        return result;
    }
};
