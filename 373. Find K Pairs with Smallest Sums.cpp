class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        const size_t size1 = nums1.size(), size2 = nums2.size();
        vector<vector<int>> result{};
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap{};
        for (int i = 0; i < size1; ++i)
            minHeap.emplace(nums1[i] + nums2[0], pair<int, int>{i, 0});
        while (!minHeap.empty() && k--)
        {
            const auto [x, y] = minHeap.top().second;
            minHeap.pop();
            result.emplace_back(vector<int>{nums1[x], nums2[y]});
            if (y + 1 < size2)
                minHeap.emplace(nums1[x] + nums2[y + 1], pair<int, int>{x, y + 1});
        }
        return result;
    }
};
