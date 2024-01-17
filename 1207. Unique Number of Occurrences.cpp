class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> occurrences{};
        for (const int num : arr)
            ++occurrences[num];
        unordered_set<int> countOccurrence{};
        for (const auto &[num, occurrence] : occurrences)
            if (countOccurrence.find(occurrence) == countOccurrence.end())
                countOccurrence.emplace(occurrence);
            else
                return false;
        return true;
    }
};
