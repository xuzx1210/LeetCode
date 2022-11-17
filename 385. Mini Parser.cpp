class Solution
{
private:
    NestedInteger dfs(stringstream &ss)
    {
        // if the first element is an integer
        int number;
        if (ss >> number)
            return NestedInteger(number);
        // if the first element is a NestedInteger
        ss.clear(); // set error state flags to goodbit after get number failed
        ss.get();   // remove '['
        NestedInteger ni;
        while (ss.peek() != ']') // add all element into ni
        {
            ni.add(dfs(ss));
            if (ss.peek() == ',') // remove comma
                ss.get();
        }
        ss.get(); // remove ']'
        return ni;
    }

public:
    NestedInteger deserialize(string s)
    {
        stringstream ss(s);
        return dfs(ss);
    }
};
