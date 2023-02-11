class Solution
{
private:
    class Node
    {
    public:
        int label, length;
        bool color; // come from path of which color
        Node(int la, int le, bool c) : label(la), length(le), color(c) {}
    };

public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
    {
        // define color
        const bool red = false, blue = true;
        // define graph
        vector<vector<int>> redGraph(n, vector<int>{}), blueGraph(n, vector<int>{});
        for (vector<int> &edge : redEdges)
            redGraph[edge[0]].emplace_back(edge[1]);
        for (vector<int> &edge : blueEdges)
            blueGraph[edge[0]].emplace_back(edge[1]);
        // queue for bfs
        queue<Node> bfs{};
        bfs.emplace(0, 0, red);
        bfs.emplace(0, 0, blue);
        // visited by path of which color
        vector<bool> redVisited(n, false), blueVisited(n, false);
        redVisited[0] = true;
        blueVisited[0] = true;
        // the answer of this function
        vector<int> answer(n, INT_MAX);
        answer[0] = 0;
        while (!bfs.empty())
        {
            const int label = bfs.front().label;
            const int length = bfs.front().length;
            const bool color = bfs.front().color;
            bfs.pop();
            answer[label] = min(answer[label], length); // update to minimum length
            if (color == red)
                for (const int &next : blueGraph[label])
                {
                    if (blueVisited[next])
                        continue;
                    bfs.emplace(next, length + 1, blue);
                    blueVisited[next] = true;
                }
            else
                for (const int &next : redGraph[label])
                {
                    if (redVisited[next])
                        continue;
                    bfs.emplace(next, length + 1, red);
                    redVisited[next] = true;
                }
        }
        for (int &length : answer)
            if (length == INT_MAX) // if not visited
                length = -1;
        return answer;
    }
};
