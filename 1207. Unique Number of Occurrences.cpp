class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> countNumber;
        unordered_map<int, bool> countOccurrence;
        for (int &number : arr)
            ++countNumber[number];
        for (auto &[key, value] : countNumber)
            if (countOccurrence[value])
                return false;
            else
                countOccurrence[value] = true;
        return true;
    }
};
