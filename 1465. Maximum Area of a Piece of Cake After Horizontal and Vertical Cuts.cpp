class Solution
{
public:
    int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts)
    {
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        sort(verticalCuts.begin(), verticalCuts.end());
        int horizontalMax = 0, verticalMax = 0;
        int horizontalSize = horizontalCuts.size(), verticalSize = verticalCuts.size();
        for (int i = 1; i < horizontalSize; ++i)
            horizontalMax = max(horizontalMax, horizontalCuts[i] - horizontalCuts[i - 1]);
        for (int i = 1; i < verticalSize; ++i)
            verticalMax = max(verticalMax, verticalCuts[i] - verticalCuts[i - 1]);
        return ((long long)horizontalMax * (long long)verticalMax) % 1000000007;
    }
};
