#include "catch2/catch_test_macros.hpp"

#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

int const kTimesteps = 30;

struct Valve {
    std::string name;
    std::vector<std::string> neighbours;
    int rate;
};

struct State {
    std::string current;
    std::vector<std::string> open;
    int time_remaining;
    int flow_per_minute = 0;
    int total_flow = 0;
};

using CostToOpen = std::map<std::string, int>;
class World {
public:
    World(std::vector<std::string>  valves) : valves_{valves} {}
    CostToOpen get_costs_to_open(State state) {
        std::string start = state.current;
        if (!cost_cache_.contains(start)) {
            // Find the shortest paths to every non-zero node.

        }
        auto costs = cost_cache_[start];
        for (const auto open_valve : state.open) {
            costs.erase(open_valve);
        }
        return costs;
    }
private:
    std::vector<std::string> valves_;
    std::map<std::string, CostToOpen> cost_cache_;
}

TEST_CASE("Can calculate cost to open") {

};