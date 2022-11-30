class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        auto compare = [](vector<int> &a, vector<int> &b)
        {
            if (a[0] > b[0])
                return true;
            if (a[0] < b[0])
                return false;
            return a[1] < b[1];
        };
        sort(people.begin(), people.end(), compare);
        vector<vector<int>> result;
        for (vector<int> &person : people)
            result.emplace(result.begin() + person[1], person);
        return result;
    }
};
