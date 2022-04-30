class Solution
{
private:
    static bool compare(string &a, string &b)
    {
        string c = a + b, d = b + a;
        return c > d;
    }

public:
    string largestNumber(vector<int> &nums)
    {
        int size = nums.size();
        vector<string> numString(size);
        for (int i = 0; i < size; ++i)
            numString[i] = to_string(nums[i]);
        sort(numString.begin(), numString.end(), compare);
        if (numString[0] == "0")
            return "0";
        string result("");
        for (auto ns : numString)
            result += ns;
        return result;
    }
};
