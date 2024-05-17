class Solution
{
public:
    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
    {
        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<pair<double, pair<int, int>>>> pq{};
        for (int i = arr.size() - 1; i; --i)
            pq.push({(double)arr[0] / arr[i], {0, i}});
        while (--k)
        {
            auto [i, j] = pq.top().second;
            pq.pop();
            ++i;
            if (i < j)
                pq.push({(double)arr[i] / arr[j], {i, j}});
        }
        const auto [numeratorIndex, denominatorIndex] = pq.top().second;
        return {arr[numeratorIndex], arr[denominatorIndex]};
    }
};
