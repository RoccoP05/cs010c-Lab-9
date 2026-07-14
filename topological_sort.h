#ifndef TOPOLOGICAL_SORT_H
#define TOPOLOGICAL_SORT_H
#include <queue>
#include "graph.h"

//(Q1.1)
// 1. Using set theoretic notation, formally describe the graph G = (V, E). - V = {0, 1, 2, 3, 4, 5, 6} 
//and E = {(0,1), (1,2), (1,3), (1,5), (2,3), (3,4), (3,6)}
// 2. What are the degrees of vertices 3 and 5? - 3:4,  5:1
// 3. Is G a multigraph? - Yes
// 4. Describe a path from vertex 5 to 6. - 5 -> 1 -> 3 -> 6
// 5. Does G have a cycle? If so, what vertices constitute to the cycle? - Yes: 1 -> 2 -> 3
// 6. Is G a connected graph? If G is connected, what is one edge you could
// remove such that it still remains connected? - Yes it is connected one the {1,3} edge could be removed and it would remain so
// 7. Is G a complete graph? - No

class TopologicalSort {
    public:
        // Perform topological sort on @G
        TopologicalSort(Graph G);
        // Return true if at least one linear ordering exists
        bool HasOrdering();
        // Return possible linear ordering of all vertices
        std::vector<int> GetOrdering();
    private:
        // TODO (Q2.1): Add private data members
        std::vector<int> visited_;
        std::vector<int> inDegree_;
        std::vector<int> order_;
        bool isValid_;
        // Hint: You need to track visited vertices, in-degrees, and the final ordering
        // TODO (Q2.1): Implement helper functions
        void SetVisited(int v);
        bool IsVisited(int v);
        void FillInDegree(Graph G);
        // TODO (Q2.2): Implement the main algorithm
        std::vector<int> LinearOrdering(Graph G);
};


// TODO (Q2.3): Implement the constructor
// It should:
// 1. Initialize visited vector (all false)
// 2. Initialize indegree vector (all 0)
// 3. Call FillInDegree to compute in-degrees
// 4. Call LinearOrdering to perform topological sort
TopologicalSort::TopologicalSort(Graph G)
    :visited_(G.V(),0), inDegree_(G.V(),0)
    {
        FillInDegree(G);
        order_ = LinearOrdering(G);
    }

// TODO (Q2.3): Implement HasOrdering()
// Return true if order is not empty
bool TopologicalSort::HasOrdering(){
    return !order_.empty();
}

std::vector<int> TopologicalSort::GetOrdering(){
    if(!HasOrdering()){
        throw std::runtime_error("Order vector is empty");
    }
    return order_;
}

// TODO (Q2.3): Implement GetOrdering()
// Throw an exception if there's no ordering (graph has a cycle)
// Otherwise return the order vector

// TODO (Q2.1): Implement SetVisited(int v)
// Mark vertex v as visited
void TopologicalSort::SetVisited(int v){
    visited_[v] = true;
}

// TODO (Q2.1): Implement IsVisited(int v)
// Return whether vertex v has been visited
bool TopologicalSort::IsVisited(int v){
    return visited_[v];
}

// TODO (Q2.1): Implement FillInDegree(Graph G)
// For each vertex v in G:
// For each adjacent vertex w of v:
// Increment indegree[w]
void TopologicalSort::FillInDegree(Graph G){
    for(int v = 0; v < G.V(); v++){
        for(int w : G.Adj(v)){
            inDegree_[w]++;
        }
    }
}

// TODO (Q2.2): Implement LinearOrdering(Graph G)
// 1. Create a queue and a sequence vector
// 2. Find all vertices with in-degree 0 and add them to queue
// 3. While queue is not empty:
// a. Dequeue a vertex and add it to sequence
// b. For each adjacent vertex:
// - Decrement its in-degree
// - If in-degree becomes 0, add to queue
// 4. If sequence size != number of vertices, return empty vector (cycle detected)
// 5. Otherwise return sequence
std::vector<int> TopologicalSort::LinearOrdering(Graph G){
    std::queue<int> q;
    for(int v = 0; v < G.V(); v++){
        if(inDegree_[v] == 0){
            q.push(v);
        }
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        order_.push_back(u);
        for(int v : G.Adj(u)){
            if(--inDegree_[v] == 0){
                q.push(v);
            }
        }
        
    }
    if(order_.size() != static_cast<size_t>(G.V())){
        return std::vector<int> (0);
    }
    return order_;
}

// TODO (Q2.4): What is the time complexity of this algorithm?
// Answer: O(V + E) each vertex is enqueued/dequeued once and each edge is processed once
#endif // TOPOLOGICAL_SORT_H_