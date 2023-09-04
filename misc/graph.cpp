#include <iostream>
#include <vector>
#include <utility> // for std::pair

// Weighted graph using adjacency list representation
class WeightedGraph {
private:
    int numVertices;
    std::vector<std::vector<std::pair<int, int>>> adjList; // (vertex, weight) pairs

public:
    WeightedGraph(int vertices) : numVertices(vertices), adjList(vertices) {}

    void addEdge(int src, int dest, int weight) {
        adjList[src].push_back(std::make_pair(dest, weight));
        adjList[dest].push_back(std::make_pair(src, weight)); // for undirected graph
    }

    void printGraph() {
        for (int i = 0; i < numVertices; ++i) {
            std::cout << "Adjacent vertices of node " << i << ": ";
            for (auto pair : adjList[i]) {
                std::cout << "(" << pair.first << ", " << pair.second << ") ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    WeightedGraph graph(9); // Create a graph with 4 vertices

    // Add weighted edges
    graph.addEdge(0, 1, 5);
    graph.addEdge(0, 2, 3);
    graph.addEdge(1, 3, 2);
    graph.addEdge(2, 3, 7);

    // Print the graph
    graph.printGraph();

    return 0;
}
