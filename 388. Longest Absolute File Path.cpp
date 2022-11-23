class Solution
{
public:
    int lengthLongestPath(string input)
    {
        stringstream ss(input);
        stack<int> length;
        string line;
        int result = 0;
        while (getline(ss, line))
        {
            int tabs = 0;
            while (line[tabs] == '\t')
                ++tabs;
            for (int i = length.size() - 1; i >= tabs; --i)
                length.pop();
            length.emplace((length.empty() ? 0 : length.top() + 1) + line.length() - tabs);
            if (line.find('.') != string::npos) // check if line is a file (with . and extension)
                result = max(result, length.top());
        }
        return result;
    }
};
