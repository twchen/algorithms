/*
Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:

If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
Example 1:

Input: tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]
Example 2:

Input: tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"]. But it is larger in lexical order.
*/

// lexical order: ["ABC", "DEF", "GHI"] < ["BCD"]

class Solution { 
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        for(auto ticket : tickets){
            adjacency_list[ticket.first].insert(ticket.second);
        }
        visit("JFK");
        reverse(route.begin(), route.end());
        return route;
    }

private:
    void visit(const string &airport){
        auto &neighbours = adjacency_list[airport];
        while(neighbours.size()){
            string t = *neighbours.begin();
            neighbours.erase(neighbours.begin());
            visit(t);
        }
        route.push_back(airport);
    }

    vector<string> route;
    unordered_map<string, multiset<string>> adjacency_list;
};
