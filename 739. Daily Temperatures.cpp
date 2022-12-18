class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        stack<pair<int, int>> monotonic{}; // first: temperature, second: index, top: lowest temperature
        const int size = temperatures.size();
        vector<int> result(size);
        for (int i = size - 1; i >= 0; --i)
        {
            while (!monotonic.empty() && monotonic.top().first <= temperatures[i])
                monotonic.pop();
            result[i] = monotonic.empty() ? 0 : monotonic.top().second - i;
            monotonic.emplace(temperatures[i], i);
        }
        return result;
    }
};
