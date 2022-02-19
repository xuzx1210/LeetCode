class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        if (nums.size() < 4)
            return vector<vector<int>>();
        sort(nums.begin(), nums.end());
        set<vector<int>> answer;
        answer.clear();
        for (int i = 0; i < nums.size() - 3; ++i)
        {
            int a = nums[i];
            for (int j = i + 1; j < nums.size() - 2; ++j)
            {
                int b = nums[j];
                int curTarget = target - a - b;
                int k = j + 1, l = nums.size() - 1;
                while (k < l)
                {
                    int c = nums[k], d = nums[l];
                    int sum = c + d;
                    if (sum < curTarget)
                        ++k;
                    else if (sum > curTarget)
                        --l;
                    else
                    {
                        answer.insert({a, b, c, d});
                        ++k;
                        --l;
                    }
                }
            }
        }
        vector<vector<int>> result;
        result.clear();
        for (auto n : answer)
            result.push_back(n);
        return result;
    }
};
