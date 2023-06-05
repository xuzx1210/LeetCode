class Solution
{
public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        const int x = coordinates[0][0], y = coordinates[0][1];
        const int dx = coordinates[1][0] - x, dy = coordinates[1][1] - y;
        for (const vector<int> &coordinate : coordinates)
            if (dx * (coordinate[1] - y) != dy * (coordinate[0] - x))
                return false;
        return true;
    }
};
