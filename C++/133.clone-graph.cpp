/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    // version 1: bfs
    /*
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) {
            return NULL;
        }
        queue<UndirectedGraphNode*> q;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> m;
        UndirectedGraphNode *head = new UndirectedGraphNode(node->label);
        m[node] = head;
        q.push(node);
        while (!q.empty()) {
            UndirectedGraphNode* n = q.front();
            q.pop();
            for (auto neighbor : n->neighbors) {
                if (m.count(neighbor) == 0) {
                    q.push(neighbor);
                    auto newneighbor = new UndirectedGraphNode(neighbor->label);
                    m[neighbor] = newneighbor;
                }
                m[n]->neighbors.push_back(m[neighbor]);
            }
            
        }
        return head;
    }
    */
    // version 2: dfs non-recursive
    /*
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) {
            return NULL;
        }
        stack<UndirectedGraphNode*> s;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> m;
        UndirectedGraphNode *head = new UndirectedGraphNode(node->label);
        s.push(node);
        m[node] = head;
        while (!s.empty()) {
            auto curn = s.top();
            s.pop();
            for (auto neighbor : curn->neighbors) {
                if (m.count(neighbor) == 0) {
                    auto newneighbor = new UndirectedGraphNode(neighbor->label);
                    m[neighbor] = newneighbor;
                    s.push(neighbor);
                }
                m[curn]->neighbors.push_back(m[neighbor]);
            }
        }
        return head;
    }
    */
    // version 3: dfs recursive
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<int, UndirectedGraphNode*> umap;
        return clone(node, umap);
    }
    UndirectedGraphNode *clone(UndirectedGraphNode *node, unordered_map<int, UndirectedGraphNode*> &umap) {
        if (!node) return node;
        if (umap.count(node->label)) return umap[node->label];
        UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
        umap[node->label] = newNode;
        for (int i = 0; i < node->neighbors.size(); ++i) {
            (newNode->neighbors).push_back(clone(node->neighbors[i], umap));
        }
        return newNode;
    } 

    

};