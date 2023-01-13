class Solution
{
private:
    vector<vector<int>> children;
    int result;
    int dfs(const size_t cur, const string &s)
    {
        int firstLongest = 0, secondLongest = 0;
        for (const int &child : children[cur])
        {
            const int childLongest = dfs(child, s);
            if (s[cur] == s[child])
                continue;
            if (childLongest > firstLongest)
            {
                secondLongest = firstLongest;
                firstLongest = childLongest;
            }
            else if (childLongest > secondLongest)
                secondLongest = childLongest;
        }
        result = max(result, firstLongest + secondLongest + 1);
        return firstLongest + 1;
    }

public:
    int longestPath(vector<int> &parent, string s)
    {
        const size_t n = parent.size();
        children.resize(n, vector<int>{});
        for (size_t i = 1; i < n; ++i)
            children[parent[i]].emplace_back(i);
        result = 1;
        dfs(0, s);
        return result;
    }
};
