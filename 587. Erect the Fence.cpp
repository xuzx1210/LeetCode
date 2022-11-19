class Solution
{
private:
    bool turnLeft(vector<int> &A, vector<int> &B, vector<int> &C)
    { // cross product
        return (B[0] - A[0]) * (C[1] - B[1]) > (B[1] - A[1]) * (C[0] - B[0]);
    }
    void convexHull(int i, vector<vector<int>> &stack, vector<vector<int>> &points)
    { // turn right
        for (int size = stack.size(); size > 1; size = stack.size())
            if (turnLeft(stack[size - 2], stack.back(), points[i]))
                stack.pop_back();
            else
                break;
        stack.emplace_back(points[i]);
    }

public:
    vector<vector<int>> outerTrees(vector<vector<int>> &trees)
    { // Andrew's monotone chain
        const int size = trees.size();
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
        for (int i = 0; i < size; ++i) // upper
            convexHull(i, result, trees);
        if (result.size() == size) // if all points form a line
            return result;
        for (int i = size - 2; i >= 0; --i) // lower
            convexHull(i, result, trees);
        result.pop_back();
        return result;
    }
};
