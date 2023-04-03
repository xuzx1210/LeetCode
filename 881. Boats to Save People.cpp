class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        sort(people.begin(), people.end());
        int result = 0;
        for (int left = 0, right = people.size() - 1; left <= right; --right, ++result)
            if (people[left] + people[right] <= limit)
                ++left;
        return result;
    }
};
