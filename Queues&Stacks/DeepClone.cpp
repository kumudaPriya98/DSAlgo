#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

/**********
// Uses extra space for Map
Node* cloneGraph(Node* node) {
    if (!node) return node;

    unordered_map<Node*, Node*> visited;
    return dfs(node, visited);
}

Node* dfs(Node* node, unordered_map<Node*, Node*>& visited) {
    if (visited.find(node) != visited.end()) return visited[node];
    Node* newNode = new Node(node->val);
    visited[node] = newNode;

    for (auto adjNode : node->neighbors) {
        newNode->neighbors.push_back(dfs(adjNode, visited));
    }
    return newNode;
}
************/

// Optimized solution without Visited Map
// But the constraint for this solution to work, all the node val are unique
Node *cloneGraph(Node *node)
{
    if (!node)
        return node;

    Node *newNode = dfs(node);
    removeCopy(node);
    return newNode;
}

Node *dfs(Node *node)
{
    if (node->neighbors.empty() || node->neighbors.back()->val != node->val)
    {
        Node *newNode = new Node(node->val);
        node->neighbors.push_back(newNode);
        for (int i = 0; i < node->neighbors.size() - 1; i++)
        {
            newNode->neighbors.push_back(dfs(node->neighbors[i]));
        }
    }
    return node->neighbors.back();
}

void removeCopy(Node *node)
{
    if (!node->neighbors.empty() && node->neighbors.back()->val == node->val)
    {
        node->neighbors.pop_back();
        for (auto neighbor : node->neighbors)
        {
            removeCopy(neighbor);
        }
    }
}