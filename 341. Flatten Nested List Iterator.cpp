class NestedIterator
{
private:
    vector<int> list;
    size_t index, size;
    void flatten(NestedInteger &x)
    {
        if (x.isInteger())
            list.push_back(x.getInteger());
        else
            for (auto y : x.getList())
                flatten(y);
    }

public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        list.clear();
        index = 0;
        for (auto x : nestedList)
            flatten(x);
        size = list.size();
    }
    int next()
    {
        return list[index++];
    }
    bool hasNext()
    {
        return index < size;
    }
};
