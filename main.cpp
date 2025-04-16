#include "tsm.h"
#include <iostream>
#include <vector>
#include "bellman.h"
using namespace std;

#define MAX_VERTICES 30

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES] = {
    {0, 12, 29, 22, 13, 27, 18, 25, 40, 36, 50, 28},
    {12, 0, 15, 35, 19, 23, 29, 41, 17, 24, 38, 20},
    {29, 15, 0, 30, 31, 10, 21, 26, 45, 33, 25, 39},
    {22, 35, 30, 0, 18, 12, 31, 50, 20, 17, 44, 32},
    {13, 19, 31, 18, 0, 29, 16, 34, 25, 27, 14, 24},
    {27, 23, 10, 12, 29, 0, 40, 22, 35, 20, 28, 30},
    {18, 29, 21, 31, 16, 40, 0, 28, 39, 15, 24, 19},
    {25, 41, 26, 50, 34, 22, 28, 0, 31, 26, 45, 35},
    {40, 17, 45, 20, 25, 35, 39, 31, 0, 12, 18, 22},
    {36, 24, 33, 17, 27, 20, 15, 26, 12, 0, 19, 21},
    {50, 38, 25, 44, 14, 28, 24, 45, 18, 19, 0, 37},
    {28, 20, 39, 32, 24, 30, 19, 35, 22, 21, 37, 0}
};
    int numVertices = 12;
    char start = 'A';
    char goal= 'I';
    string path = BF_Path(graph, numVertices, start, goal);
    // string path = Traveling(graph, numVertices, start);
   
    cout << "BF path: " << path << endl;
    
    return 0;
}
