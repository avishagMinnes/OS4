#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>

class DirectedGraph {
private:
    std::unordered_map<int, std::list<int>> adjacencyList;

public:
    // Add an edge from source to destination
    void addEdge(int source, int destination) {
        adjacencyList[source].push_back(destination);
    }

    // Print the graph representation
    void printGraph() {
        for (const auto& pair : adjacencyList) {
            std::cout << pair.first << " -> ";
            for (const auto& dest : pair.second) {
                std::cout << dest << " ";
            }
            std::cout << std::endl;
        }
    }
};


// #include <iostream>
// #include <vector>
// #include <list>
// #include <unordered_map>

// using namespace std;

// class DirectedGraph {
// private:
//     unordered_map<int, list<int>> outDegree; 
//     unordered_map<int, list<int>> inDegree;

// public:
//     int getInDegree(int vertex) {
//         return inDegree[vertex].size();
//     }

//     int getOutDegree(int vertex) {
//         return outDegree[vertex].size();
//     }

//     // Add an edge from source to destination
//     void addEdge(int source, int destination) {
//         outDegree[source].push_back(destination);
//         inDegree[destination].push_back(source);
//     }

//     // Print the graph representation
//     void printGraph() {
//         for (const auto& pair : outDegree) {
//             std::cout << pair.first << " -> ";
//             for (const auto& dest : pair.second) {
//                 std::cout << dest << " ";
//             }
//             std::cout << std::endl;
//         }
//     }
// };


