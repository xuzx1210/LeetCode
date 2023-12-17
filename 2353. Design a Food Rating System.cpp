class FoodRatings
{
private:
    unordered_map<string, map<int, set<string>>> cuisine2rating2food;
    unordered_map<string, string> food2cuisine;
    unordered_map<string, int> food2rating;

public:
    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings)
    {
        cuisine2rating2food.clear();
        food2cuisine.clear();
        food2rating.clear();
        const int n = foods.size();
        for (int i = 0; i < n; ++i)
        {
            const string &food = foods[i], &cuisine = cuisines[i];
            const int rating = ratings[i];
            cuisine2rating2food[cuisine][rating].emplace(food);
            food2cuisine[food] = cuisine;
            food2rating[food] = rating;
        }
    }
    void changeRating(string food, int newRating)
    {
        const string &cuisine = food2cuisine[food];
        const int oldRating = food2rating[food];
        cuisine2rating2food[cuisine][oldRating].erase(food);
        if (cuisine2rating2food[cuisine][oldRating].empty())
            cuisine2rating2food[cuisine].erase(oldRating);
        food2rating[food] = newRating;
        cuisine2rating2food[cuisine][newRating].emplace(food);
    }
    string highestRated(string cuisine)
    {
        return *cuisine2rating2food[cuisine].rbegin()->second.begin();
    }
};
