class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        if (nums.size() < 3)
            return vector<vector<int>>();
        sort(nums.begin(), nums.end());
        set<vector<int>> threeSum;
        threeSum.clear();
        for (int i = 0; i < nums.size() - 2; ++i)
        {
            int j = i + 1, k = nums.size() - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0)
                    ++j;
                else if (sum > 0)
                    --k;
                else
                {
                    threeSum.insert({nums[i], nums[j], nums[k]});
                    int left = nums[j], right = nums[k];
                    while (j < k && left == nums[j])
                        ++j;
                    while (j < k && right == nums[k])
                        --k;
                }
            }
        }
        vector<vector<int>> result;
        result.clear();
        for (auto three : threeSum)
            result.push_back(three);
        return result;
    }
};
