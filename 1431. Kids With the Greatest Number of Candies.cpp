class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        const int n = candies.size();
        int maximum = 0;
        for (int candy : candies)
            maximum = max(maximum, candy);
        vector<bool> result(n);
        for (int i = 0; i < n; ++i)
            result[i] = maximum <= candies[i] + extraCandies;
        return result;
    }
};
