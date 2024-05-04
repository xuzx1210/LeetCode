class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        int result = 0;
        sort(people.begin(), people.end());
        for (int light = 0, heavy = people.size() - 1; light <= heavy; --heavy, ++result)
            if (people[light] + people[heavy] <= limit)
                ++light;
        return result;
    }
};
