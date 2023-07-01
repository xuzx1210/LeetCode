class Solution
{
private:
    int result;
    vector<int> children;
    void dfs(const int index, const int maximum, const vector<int> &cookies)
    {
        if (index == cookies.size())
        {
            result = maximum;
            return;
        }
        for (int &child : children)
        {
            if (result <= child + cookies[index])
                continue;
            child += cookies[index];
            dfs(index + 1, max(maximum, child), cookies);
            child -= cookies[index];
        }
    }

public:
    int distributeCookies(vector<int> &cookies, int k)
    {
        result = INT_MAX;
        children.resize(k, 0);
        dfs(0, 0, cookies);
        return result;
    }
};
