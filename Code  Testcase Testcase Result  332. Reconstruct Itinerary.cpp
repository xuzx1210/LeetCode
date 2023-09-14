class Solution
{
private:
    vector<string> result;
    unordered_map<string, multiset<string>> airports;
    void visit(string from)
    {
        multiset<string> &airport = airports[from];
        while (!airport.empty())
        {
            const string to = *airport.begin();
            airport.erase(airport.begin());
            visit(to);
        }
        result.emplace_back(from);
    }

public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        result.clear();
        airports.clear();
        for (const vector<string> ticket : tickets)
            airports[ticket[0]].emplace(ticket[1]);
        visit("JFK");
        reverse(result.begin(), result.end());
        return result;
    }
};
