class SmallestInfiniteSet
{
private:
    int smallest;
    set<int> added;

public:
    SmallestInfiniteSet()
    {
        smallest = 1;
        added.clear();
    }
    int popSmallest()
    {
        if (added.empty())
            return smallest++;
        const int result = *added.begin();
        added.erase(result);
        return result;
    }
    void addBack(int num)
    {
        if (num < smallest)
            added.emplace(num);
    }
};
