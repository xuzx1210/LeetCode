class Solution
{
private:
    class Node
    {
    public:
        int index, length;
        bool color; // false: red, true: blue
        Node(int i, int l, bool c) : index(i), length(l), color(c) {}
    };

public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
    {
        const bool red = false, blue = true;
        vector<vector<int>> redGraph(n, vector<int>{}), blueGraph(n, vector<int>{});
        for (vector<int> &edge : redEdges)
            redGraph[edge[0]].emplace_back(edge[1]);
        for (vector<int> &edge : blueEdges)
            blueGraph[edge[0]].emplace_back(edge[1]);
        queue<Node> bfs{};
        bfs.emplace(0, 0, red);
        bfs.emplace(0, 1, blue);
        vector<bool> redVisited(n, false), blueVisited(n, false);
        redVisited[0] = true;
        blueVisited[0] = true;
        vector<int> answer(n, INT_MAX);
        answer[0] = 0;
        while (!bfs.empty())
        {
            const int index = bfs.front().index;
            const int length = bfs.front().length;
            const bool color = bfs.front().color;
            bfs.pop();
            answer[index] = min(answer[index], length);
            if (color == red)
                for (const int &next : blueGraph[index])
                {
                    if (blueVisited[next])
                        continue;
                    bfs.emplace(next, length + 1, blue);
                    blueVisited[next] = true;
                }
            else
                for (const int &next : redGraph[index])
                {
                    if (redVisited[next])
                        continue;
                    bfs.emplace(next, length + 1, red);
                    redVisited[next] = true;
                }
        }
        for (int &length : answer)
            if (length == INT_MAX)
                length = -1;
        return answer;
    }
};
