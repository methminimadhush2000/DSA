#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// Structure to represent a weighted edge
struct Edge {
    int destination;
    int weight;
};

// Function to perform Dijkstra's algorithm for SSSP
void Dijkstra(vector<vector<Edge>>& graph, int source, vector<int>& distances) {
    int numVertices = graph.size();
    distances.resize(numVertices, numeric_limits<int>::max()); // Initialize distances to infinity
    distances[source] = 0; // Distance from source to itself is 0

    // Priority queue to store vertices and their distances
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, source));

    while (!pq.empty()) {
        int u = pq.top().second; // Get the vertex with the minimum distance
        pq.pop();

        for (const Edge& edge : graph[u]) {
            int v = edge.destination;
            int weight = edge.weight;

            // If a shorter path is found, update the distance and enqueue the vertex
            if (distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                pq.push(make_pair(distances[v], v));
            }
        }
    }
}

// Utility function to add an edge to the graph
void addEdge(vector<vector<Edge>>& graph, int source, int destination, int weight) {
    Edge edge;
    edge.destination = destination;
    edge.weight = weight;
    graph[source].push_back(edge);
}

int main() {
    int numVertices = 6;
    vector<vector<Edge>> graph(numVertices);

    // Add edges to the graph (example)
    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 4, 15);
    addEdge(graph, 0, 5, 5);
    addEdge(graph, 1, 0, 10);
    addEdge(graph, 1, 2, 10);
    addEdge(graph, 1, 3, 30);
    addEdge(graph, 2, 1, 10);
    addEdge(graph, 2, 3, 12);
    addEdge(graph, 2, 4, 5);
    addEdge(graph, 3, 1, 30);
    addEdge(graph, 3, 2, 12);
    addEdge(graph, 3, 5, 20);
    addEdge(graph, 4, 0, 15);
    addEdge(graph, 4, 2, 5);
    addEdge(graph, 5, 0, 5);
    addEdge(graph, 5, 3, 20);
    int source =0;
    vector<int> distances;

    Dijkstra(graph, source, distances);

    // Print the shortest distances from the source to all vertices
    for (int i = 0; i < numVertices; ++i) {
        cout << "shortest time taken from city ";
        cout <<source;
        cout << " to vertex " << i << ": " << distances[i] << endl;
    }

    return 0;
}

