class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        nums.emplace_back(1000001);
        const int size = nums.size();
        vector<pair<int, int>> numberOfLIS(size, {1, 1});
        for (int i = 1; i < size; ++i)
        {
            int maxLength = 0;
            for (int j = 0; j < i; ++j)
                if (nums[j] < nums[i])
                    maxLength = max(maxLength, numberOfLIS[j].first);
            if (maxLength == 0)
                continue;
            int count = 0;
            for (int j = 0; j < i; ++j)
                if (nums[j] < nums[i] && numberOfLIS[j].first == maxLength)
                    count += numberOfLIS[j].second;
            numberOfLIS[i] = {maxLength + 1, count};
        }
        return numberOfLIS.back().second;
    }
};
