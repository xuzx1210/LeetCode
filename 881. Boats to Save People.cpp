class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        sort(people.begin(), people.end());
        int left = 0, right = people.size() - 1, result = 0;
        while (left <= right)
        {
            ++result;
            if (people[left] + people[right] <= limit)
                ++left;
            --right;
        }
        return result;
    }
};
