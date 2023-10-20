class NestedIterator
{
private:
    int index;
    vector<int> flattenedList;
    void flatten(const vector<NestedInteger> &nestedList)
    {
        for (const NestedInteger &nestedInteger : nestedList)
            if (nestedInteger.isInteger())
                flattenedList.emplace_back(nestedInteger.getInteger());
            else
                flatten(nestedInteger.getList());
    }

public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        index = 0;
        flatten(nestedList);
    }
    int next()
    {
        return flattenedList[index++];
    }
    bool hasNext()
    {
        return index < flattenedList.size();
    }
};

class NestedIterator
{
private:
    stack<pair<vector<NestedInteger>::iterator, vector<NestedInteger>::iterator>> layers;

public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        while (!layers.empty())
            layers.pop();
        layers.emplace(nestedList.begin(), nestedList.end());
    }
    int next()
    {
        hasNext();
        return (layers.top().first++)->getInteger();
    }
    bool hasNext()
    {
        while (!layers.empty())
            if (layers.top().first == layers.top().second)
                layers.pop();
            else
            {
                vector<NestedInteger>::iterator curr = layers.top().first;
                if (curr->isInteger())
                    return true;
                ++layers.top().first;
                layers.emplace(curr->getList().begin(), curr->getList().end());
            }
        return false;
    }
};
