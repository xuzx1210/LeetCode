class Solution
{
public:
    long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
    {
        const int n = nums1.size();
        vector<pair<int, int>> nums(n);
        for (int i = 0; i < n; ++i)
            nums[i] = {nums2[i], nums1[i]};
        sort(nums.rbegin(), nums.rend());
        priority_queue<int, vector<int>, greater<int>> pq{};
        long long sum = 0;
        for (int i = 0; i < k; ++i)
        {
            sum += nums[i].second;
            pq.emplace(nums[i].second);
        }
        long long result = sum * nums[k - 1].first;
        for (int i = k; i < n; ++i)
        {
            sum = sum + nums[i].second - pq.top();
            pq.pop();
            pq.emplace(nums[i].second);
            result = max(result, sum * nums[i].first);
        }
        return result;
    }
};
