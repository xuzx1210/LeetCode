class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        const size_t size = points.size();
        int result = 1;
        for (vector<int> &center : points)
        {
            unordered_map<double, int> counter{};
            for (vector<int> &other : points)
                if (center != other)
                    ++counter[atan2(other[1] - center[1], other[0] - center[0])];
            for (auto &[key, value] : counter)
                result = max(result, value + 1);
        }
        return result;
    }
};
