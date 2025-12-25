#include <bits/stdc++.h>
using namespace std;

/*

knapsack means bag, fractional means, we need to compare the fractions, being value / weight.
this fraction or real_value will be compared one another

*/

struct Item {
    int value;
    int weight;
};

bool compare(Item a, Item b) {
    double real_value_a = (double)a.value / a.weight;
    double real_value_b = (double)b.value / b.weight;
    return real_value_a > real_value_b; // sort descending
}

double fractionalKnapsack(int max_weight, vector<Item> &items) {
    // sort with custom compare
    sort(items.begin(), items.end(), compare);
    int curr_weight = 0;
    int curr_total_value = 0;

    // greedy: devour until almost full; bonus: if almost full get fraction of value
    for (auto &item : items) {
        if (curr_weight + item.weight < max_weight) {
            curr_weight += item.weight;
            curr_total_value += item.value;
        } else { // greed fulfilled, cannot add anymore whole items. eat it's fraction
            auto weight_budget = max_weight - item.weight;
            double item_value_reduced = (double)item.value * ((double)weight_budget / item.weight);
            curr_total_value += item_value_reduced;
        }
    }

    return curr_total_value;
}

auto main() -> int {
    int max_weight = 50;
    std::vector<Item> items = {{60, 10}, {100, 20}, {120, 30}};

    std::cout << "Max Value: " << fractionalKnapsack(max_weight, items) << std::endl;
    return 0;
}