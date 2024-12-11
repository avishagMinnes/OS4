#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <stack>
#include <set>

class DirectedGraph {
private:
    std::unordered_map<int, std::list<int>> adjacencyList;
    std::unordered_map<int, int> inDegree;
    std::unordered_map<int, int> outDegree;

    void dfs(int v, std::unordered_map<int, bool>& visited) {
        visited[v] = true;
        for (int u : adjacencyList[v]) {
            if (!visited[u]) {
                dfs(u, visited);
            }
        }
    }

    bool isStronglyConnected() {
        std::unordered_map<int, bool> visited;
        for (const auto& pair : adjacencyList) {
            visited[pair.first] = false;
        }
        
        int start = adjacencyList.begin()->first;
        dfs(start, visited);
        
        for (const auto& pair : adjacencyList) {
            if (!visited[pair.first] && outDegree[pair.first] > 0) {
                return false;
            }
        }

        std::unordered_map<int, std::list<int>> reversedGraph;
        for (const auto& pair : adjacencyList) {
            for (int u : pair.second) {
                reversedGraph[u].push_back(pair.first);
            }
        }
        
        visited.clear();
        for (const auto& pair : reversedGraph) {
            visited[pair.first] = false;
        }

        dfs(start, visited);
        
        for (const auto& pair : reversedGraph) {
            if (!visited[pair.first] && inDegree[pair.first] > 0) {
                return false;
            }
        }

        return true;
    }

public:
    // Add an edge from source to destination
    void addEdge(int source, int destination) {
        adjacencyList[source].push_back(destination);
        outDegree[source]++;
        inDegree[destination]++;
    }

    // Find Eulerian circuit
    void findEulerianCircuit() {
        if (!isStronglyConnected()) {
            std::cout << "Graph is not strongly connected. No Eulerian circuit exists." << std::endl;
            return;
        }
        
        for (const auto& pair : inDegree) {
            if (inDegree[pair.first] != outDegree[pair.first]) {
                std::cout << "In-degree and out-degree of vertex " << pair.first << " are not equal. No Eulerian circuit exists." << std::endl;
                return;
            }
        }

        std::stack<int> currPath;
        std::vector<int> circuit;
        std::unordered_map<int, std::list<int>> tempAdjList = adjacencyList;
        
        int currV = adjacencyList.begin()->first;
        currPath.push(currV);
        
        while (!currPath.empty()) {
            if (!tempAdjList[currV].empty()) {
                currPath.push(currV);
                int nextV = tempAdjList[currV].front();
                tempAdjList[currV].pop_front();
                currV = nextV;
            } else {
                circuit.push_back(currV);
                currV = currPath.top();
                currPath.pop();
            }
        }
        
        for (auto it = circuit.rbegin(); it != circuit.rend(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
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

