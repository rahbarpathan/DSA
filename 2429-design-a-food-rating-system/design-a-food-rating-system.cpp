#include <bits/stdc++.h>
using namespace std;

class FoodRatings {
private:
    // food -> {cuisine, rating}
    unordered_map<string, pair<string, int>> foodInfo;
    
    // cuisine -> set of (-rating, food)
    unordered_map<string, set<pair<int, string>>> cuisineFoods;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            foodInfo[foods[i]] = {cuisines[i], ratings[i]};
            cuisineFoods[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        auto& [cuisine, oldRating] = foodInfo[food];
        
        // remove old rating entry
        cuisineFoods[cuisine].erase({-oldRating, food});
        
        // insert new rating entry
        cuisineFoods[cuisine].insert({-newRating, food});
        
        // update in foodInfo
        oldRating = newRating;
    }
    
    string highestRated(string cuisine) {
        // first element in set = highest rating, lexicographically smallest
        return cuisineFoods[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
