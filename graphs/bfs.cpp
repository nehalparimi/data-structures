#include <iostream>
#include <vector>
#include <string>
#include <queue>

struct Vertex {
    int value;
    std::string color;
    Vertex parent;
    int distance;
};

void BFS(Vertex s) {
    std::vector<Vertex> adj(100);       // Mimic graph
    
    for(Vertex u : adj) {
        // Reset
        if(u.value != s.value) {
            u.color = "white";
            u.parent = "";
            u.distance = 0;
        }

        std::queue<Vertex> Q;
        Q.push(s);

        while(!Q.empty()) {
            Vertex curr = Q.pop();
            std::cout << curr.value << std::endl;

            // Adjacency list with an array
            for(std::vector<Vertex> v: (adj[curr]).connections) {
                if(v.color == white) {
                    v.color == "black";
                    v.distance = u.distance + 1;
                    v.parent = u;

                    Q.push(v);
                }
            }
        }
    }
    
}