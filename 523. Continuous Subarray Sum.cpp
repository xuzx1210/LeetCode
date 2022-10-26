class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, bool> mod;
        int cur = 0, pre = 0;
        for (int &num : nums)
        {
            cur = (cur + num) % k;
            if (mod[cur])
                return true;
            mod[pre] = true;
            pre = cur;
        }
        return false;
    }
};
