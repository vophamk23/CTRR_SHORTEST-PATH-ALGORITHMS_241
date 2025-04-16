#include "bellman.h"
#include <algorithm>

void BF(int graph[30][30], int nVertices, char start, int Label[], int Prev[]) {
    int startIdx = start - 'A';
    int newArrLabel[30];
    if (Label[startIdx] == -1) Label[startIdx] = 0;


    copy(Label, Label + nVertices, newArrLabel);
    // Single step of Bellman-Ford relaxation
    int u = 0;
    while(u < nVertices)
    {
            int v = 0;
            while (v < nVertices)
            {
               
                if (graph[u][v] != 0 && Label[u] != -1) 
                {
                    if(Label[u] + graph[u][v] < newArrLabel[v] || newArrLabel[v] == -1){
                        newArrLabel[v] = Label[u] + graph[u][v];
                        Prev[v] = u;
                    }
                
                }
                v++;
            }
            u++;
    }   
    copy(newArrLabel, newArrLabel + nVertices, Label);
}


const int INF = 999999999;
std::string BF_Path(int graph[30][30], int numVertices, char start, char goal) {
    std::vector<int> distances(numVertices, INF);
    std::vector<int> predecessor(numVertices, -1);
    int startIndex = start - 'A';
    int goalIndex = goal - 'A';
    distances[startIndex] = 0;

    // Bellman-Ford relaxation
    for (int i = 0; i < numVertices - 1; ++i) {
        for (int u = 0; u < numVertices; ++u) {
            for (int v = 0; v < numVertices; ++v) {
                if (graph[u][v] != 0 && 
                    distances[u] != INF && 
                    distances[u] + graph[u][v] < distances[v]) {
                    distances[v] = distances[u] + graph[u][v];
                    predecessor[v] = u;
                }
            }
        }
    }

    // Reconstruct path
    std::string path;
    int current = goalIndex;
    while (current != -1) {
        path = static_cast<char>(current + 'A') + path;
        current = predecessor[current];
    }

    string output;
    for (size_t i = 0; i < path.size(); i++) {
        output += path[i];
        if (i != path.size() - 1) {
            output += ' ';
        }
    }

    return output;

}