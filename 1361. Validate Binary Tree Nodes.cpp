class Solution
{
public:
    bool validateBinaryTreeNodes(int n, vector<int> &leftChild, vector<int> &rightChild)
    {
        vector<int> parent(n, -1);
        for (int i = 0; i < n; ++i)
        {
            if (leftChild[i] != -1)
                if (parent[leftChild[i]] == -1)
                    parent[leftChild[i]] = i;
                else
                    return false;
            if (rightChild[i] != -1)
                if (parent[rightChild[i]] == -1)
                    parent[rightChild[i]] = i;
                else
                    return false;
        }
        if (count(parent.begin(), parent.end(), -1) != 1)
            return false;
        const int root = find(parent.begin(), parent.end(), -1) - parent.begin();
        vector<bool> visited(n, false);
        queue<int> bfs({root});
        int size = 0;
        while (!bfs.empty())
        {
            const int node = bfs.front();
            bfs.pop();
            if (node == -1 || visited[node])
                continue;
            visited[node] = true;
            ++size;
            bfs.emplace(leftChild[node]);
            bfs.emplace(rightChild[node]);
        }
        return size == n;
    }
};
