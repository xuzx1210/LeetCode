class Solution
{
public:
    bool isPathCrossing(string path)
    {
        set<pair<int, int>> positions{{0, 0}};
        pair<int, int> cur{0, 0};
        for (const char direction : path)
        {
            if (direction == 'N')
                ++cur.second;
            else if (direction == 'S')
                --cur.second;
            else if (direction == 'E')
                ++cur.first;
            else
                --cur.first;
            if (positions.find(cur) != positions.end())
                return true;
            positions.emplace(cur);
        }
        return false;
    }
};
