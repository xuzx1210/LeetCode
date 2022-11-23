class Solution
{
public:
    int lengthLongestPath(string input)
    {
        stringstream ss(input);
        vector<int> length{0}; // avoid calling back() when empty
        string line;
        int result = 0;
        while (getline(ss, line))
        {
            int tabs = line.find_last_of('\t') + 1;
            length.erase(length.begin() + tabs + 1, length.end());
            length.emplace_back(length.back() + 1 + line.length() - tabs);
            if (line.find('.') != string::npos) // check if line is a file (with . and extension)
                result = max(result, length.back() - 1);
        }
        return result;
    }
};
