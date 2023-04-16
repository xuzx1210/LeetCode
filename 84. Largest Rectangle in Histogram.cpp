class Solution
{
private:
    void findBound(const int heightIndex, const vector<int> &heights, stack<int> &monotonic, vector<int> &bound)
    {
        while (heights[monotonic.top()] >= heights[heightIndex])
            monotonic.pop();
        bound[heightIndex - 1] = monotonic.top();
        monotonic.emplace(heightIndex);
    }

public:
    int largestRectangleArea(vector<int> &heights)
    {
        const int size = heights.size();
        heights.insert(heights.begin(), -1); // -1, {heights}
        heights.emplace_back(-1);            // -1, {heights}, -1
        vector<int> leftBound(size), rightBound(size);
        stack<int> monotonic({0}); // heights index
        for (int i = 1; i <= size; ++i)
            findBound(i, heights, monotonic, leftBound);
        monotonic = stack<int>({size + 1});
        for (int i = size; i >= 1; --i)
            findBound(i, heights, monotonic, rightBound);
        int result = 0;
        for (int i = 0; i < size; ++i)
            result = max(result, heights[i + 1] * (rightBound[i] - leftBound[i] - 1));
        return result;
    }
};
