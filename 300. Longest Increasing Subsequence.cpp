class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> result = {};
        for (int num : nums)
            if (result.empty())
                result.push_back(num);
            else if (result.back() < num)
                result.push_back(num);
            else
                *lower_bound(result.begin(), result.end(), num) = num;
        return result.size();
    }
};
