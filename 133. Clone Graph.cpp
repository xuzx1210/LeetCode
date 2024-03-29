class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return nullptr;
        vector<Node *> index2node{};
        unordered_map<Node *, int> node2index{};
        unordered_map<Node *, bool> visited{};
        queue<Node *> bfs({node});
        while (!bfs.empty())
        {
            Node *cur = bfs.front();
            bfs.pop();
            if (visited[cur])
                continue;
            visited[cur] = true;
            node2index[cur] = index2node.size();
            index2node.emplace_back(cur);
            for (Node *neighbor : cur->neighbors)
                bfs.emplace(neighbor);
        }
        const int size = index2node.size();
        vector<Node *> graph(size, nullptr);
        for (int i = 0; i < size; ++i)
            graph[i] = new Node(index2node[i]->val);
        for (int i = 0; i < size; ++i)
            for (Node *neighbor : index2node[i]->neighbors)
                graph[i]->neighbors.emplace_back(graph[node2index[neighbor]]);
        return graph[node2index[node]];
    }
};
class Solution
{
private:
    unordered_map<Node *, Node *> old2new;
    Node *dfs(Node *cur)
    {
        Node *clone = new Node(cur->val);
        old2new[cur] = clone;
        for (Node *neighbor : cur->neighbors)
            clone->neighbors.emplace_back(old2new.find(neighbor) == old2new.end() ? dfs(neighbor) : old2new[neighbor]);
        return clone;
    }

public:
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return nullptr;
        old2new.clear();
        return dfs(node);
    }
};
