class Solution
{
private:
    int result;
    vector<int> degrees;
    void dfs(const int index, const int achieved, vector<vector<int>> &requests)
    {
        if (index == requests.size())
        {
            for (const int degree : degrees)
                if (degree) // the degree of a building is not correct
                    return;
            result = max(result, achieved);
            return;
        }
        if (achieved + requests.size() - index <= result) // pruning
            return;
        const vector<int> &request = requests[index];
        const int from = request[0], to = request[1];
        --degrees[from];
        ++degrees[to];
        dfs(index + 1, achieved + 1, requests); // achieve
        ++degrees[from];
        --degrees[to];
        dfs(index + 1, achieved, requests); // no achieve
    }

public:
    int maximumRequests(int n, vector<vector<int>> &requests)
    {
        result = 0;
        degrees.resize(n, 0);
        dfs(0, 0, requests);
        return result;
    }
};
