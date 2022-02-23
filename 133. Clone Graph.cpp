class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (node == nullptr)
            return nullptr;
        int M = 0, start = node->val;
        queue<Node *> bfs;
        while (!bfs.empty())
            bfs.pop();
        bfs.push(node);
        set<Node *> visited;
        visited.clear();
        visited.insert(node);
        vector<pair<int, vector<int>>> graph({});
        while (!bfs.empty())
        {
            Node *cur = bfs.front();
            bfs.pop();
            int curVal = cur->val;
            M = max(M, cur->val);
            vector<int> curNeighbor({});
            for (auto neighbor : cur->neighbors)
            {
                curNeighbor.push_back(neighbor->val);
                if (visited.find(neighbor) == visited.end())
                {
                    bfs.push(neighbor);
                    visited.insert(neighbor);
                }
            }
            graph.push_back({curVal, curNeighbor});
        }
        vector<vector<bool>> connection(M, vector<bool>(M, false));
        for (auto vertex : graph)
            for (auto neighbor : vertex.second)
                connection[vertex.first - 1][neighbor - 1] = true;
        vector<Node *> result({});
        for (int i = 0; i < M; ++i)
        {
            Node *tmp = new Node(i + 1);
            tmp->neighbors.clear();
            result.push_back(tmp);
        }
        for (int i = 0; i < M; ++i)
        {
            Node *cur = result[i];
            for (int j = 0; j < M; ++j)
                if (connection[i][j])
                    cur->neighbors.push_back(result[j]);
        }
        return result[start - 1];
    }
};
