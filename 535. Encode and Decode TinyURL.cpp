class Solution
{
public:
    vector<string> table;
    string head;
    Solution()
    {
        table.clear();
        head = "http://tinyurl.com/";
    }
    string encode(string longUrl)
    {
        auto it = find(table.begin(), table.end(), longUrl);
        if (it == table.end())
        {
            table.push_back(longUrl);
            return head + to_string(table.size() - 1);
        }
        return head + to_string(it - table.begin());
    }
    string decode(string shortUrl)
    {
        shortUrl.erase(0, 19);
        return table[stoi(shortUrl)];
    }
};
