/*
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/
*/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
// BFS
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return nullptr;
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> hash; // original to copy
        queue<UndirectedGraphNode *> q; // nodes whose copies have uninitialized neighbors
        UndirectedGraphNode *origin, *copy, *neighbor, *neighbor_copy;

        copy = new UndirectedGraphNode(node->label);
        hash[node] = copy;
        q.push(node);

        while(q.size()){
            origin = q.front();
            q.pop();
            copy = hash[origin];
            copy->neighbors.resize(origin->neighbors.size());
            for(int i = 0; i < origin->neighbors.size(); ++i){
                neighbor = origin->neighbors[i];
                auto it = hash.find(neighbor);
                if(it != hash.end()){
                    neighbor_copy = it->second;
                }else{
                    neighbor_copy = new UndirectedGraphNode(neighbor->label);
                    hash[neighbor] = neighbor_copy;
                    q.push(neighbor);
                }
                copy->neighbors[i] = neighbor_copy;
            }
        }
        return hash[node];
    }
};

// DFS
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return nullptr;
        unordered_map<Node *, Node *> hash;
        return clone(node, hash);
    }

private:
    typedef UndirectedGraphNode Node;
    Node *clone(Node *node, unordered_map<Node *, Node *> &hash){
        if(hash.find(node) == hash.end()){
            auto copy = new Node(node->label);
            hash[node] = copy;
            // copy->neighbors.reserve(node->neighbors.size()); // could speed up slightly
            for(auto neighbor : node->neighbors){
                auto neighbor_copy = clone(neighbor, hash);
                copy->neighbors.push_back(neighbor_copy);
            }
        }
        return hash[node];
    }
};
