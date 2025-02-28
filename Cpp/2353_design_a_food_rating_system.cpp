// https://leetcode.cn/problems/design-a-food-rating-system/

#include <vector>
#include <string>
#include <unordered_map>
#include <set>

using namespace std;

class FoodRatings {
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); ++i) {
            string food = foods[i], cuisine = cuisines[i];
            int rating = ratings[i];
            foods_[food] = make_pair(cuisine, rating);
            cuisines_[cuisine].insert(make_pair(-rating, food));
        }
    }
    
    void changeRating(string food, int newRating) {
        auto cr = foods_[food];
        foods_[food].second = newRating;
        cuisines_[cr.first].erase(make_pair(-cr.second, food));
        cuisines_[cr.first].insert(make_pair(-newRating, food));
    }
    
    string highestRated(string cuisine) {
        return (*cuisines_[cuisine].begin()).second;
    }

    unordered_map<string, pair<string, int>> foods_;
    unordered_map<string, set<pair<int, string>>> cuisines_;
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */