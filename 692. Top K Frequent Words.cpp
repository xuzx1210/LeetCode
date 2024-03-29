class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> counter;
        for (string &word : words)
            ++counter[word];
        vector<pair<string, int>> wordCount(counter.size());
        int index = 0;
        for (auto &[key, value] : counter)
        {
            wordCount[index].first = key;
            wordCount[index++].second = value;
        }
        auto compare = [](pair<string, int> &a, pair<string, int> &b) -> bool
        {
            if (a.second > b.second)
                return true;
            if (a.second < b.second)
                return false;
            return a.first.compare(b.first) < 0;
        };
        sort(wordCount.begin(), wordCount.end(), compare);
        vector<string> result(k);
        for (int i = 0; i < k; ++i)
            result[i] = wordCount[i].first;
        return result;
    }
};
