class Solution
{
private:
    bool turnLeft(vector<int> &A, vector<int> &B, vector<int> &C)
    {
        return (B[0] - A[0]) * (C[1] - B[1]) > (B[1] - A[1]) * (C[0] - B[0]);
    }
    void convexHull(int i, vector<vector<int>> &result, vector<vector<int>> &trees)
    {
        for (int size = result.size(); size > 1; size = result.size())
            if (turnLeft(result[size - 2], result.back(), trees[i]))
                result.pop_back();
            else
                break;
        result.emplace_back(trees[i]);
    }

public:
    vector<vector<int>> outerTrees(vector<vector<int>> &trees)
    {
        const int size = trees.size();
        if (size < 4)
            return trees;
        auto compare = [](vector<int> &a, vector<int> &b)
        {
            if (a[0] < b[0])
                return true;
            if (a[0] > b[0])
                return false;
            return a[1] < b[1];
        };
        sort(trees.begin(), trees.end(), compare);
        vector<vector<int>> result;
        for (int i = 0; i < size; ++i)
            convexHull(i, result, trees);
        if (result.size() == size)
            return result;
        for (int i = size - 2; i >= 0; --i)
            convexHull(i, result, trees);
        result.pop_back();
        return result;
    }
};
