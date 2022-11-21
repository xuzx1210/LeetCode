class Solution
{
public:
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
    {
        int m = maze.size(), n = maze.front().size();
        queue<pair<pair<int, int>, int>> bfs({{{entrance[0], entrance[1]}, 0}}); // {{x, y}, depth}
        while (!bfs.empty())
        {
            int x = bfs.front().first.first, y = bfs.front().first.second, depth = bfs.front().second;
            bfs.pop();
            if (x < 0 || m <= x || y < 0 || n <= y) // check border
                continue;
            if (maze[x][y] == '+') // check empty or wall
                continue;
            if ((x == 0 || x == m - 1 || y == 0 || y == n - 1) && depth) // check exit
                return depth;
            maze[x][y] = '+'; // mark as wall
            ++depth;
            bfs.push({{x - 1, y}, depth});
            bfs.push({{x, y - 1}, depth});
            bfs.push({{x, y + 1}, depth});
            bfs.push({{x + 1, y}, depth});
        }
        return -1;
    }
};
