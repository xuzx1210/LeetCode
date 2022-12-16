class Solution
{
public:
    int numberOfBoomerangs(vector<vector<int>> &points)
    {
        int result = 0;
        const size_t size = points.size();
        for (size_t i = 0; i < size; ++i)
        {
            unordered_map<int, vector<size_t>> distance2i{};
            for (size_t j = 0; j < size; ++j)
            {
                if (j == i)
                    continue;
                const int xij = points[i][0] - points[j][0], yij = points[i][1] - points[j][1];
                distance2i[xij * xij + yij * yij].emplace_back(j);
            }
            for (auto &[key, value] : distance2i)
            {
                const size_t counter = value.size();
                result += counter * (counter - 1);
            }
        }
        return result;
    }
};
