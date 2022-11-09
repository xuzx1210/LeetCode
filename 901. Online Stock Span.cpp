class StockSpanner
{
private:
    stack<pair<int, int>> stock;

public:
    StockSpanner()
    {
        stock = {};
    }
    int next(int price)
    {
        int result = 1;
        while (!stock.empty())
            if (stock.top().first <= price)
            {
                result += stock.top().second;
                stock.pop();
            }
            else
                break;
        stock.emplace(price, result);
        return result;
    }
};
