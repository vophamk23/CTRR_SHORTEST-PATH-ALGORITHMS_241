#ifndef BELLMAN_H
#define BELLMAN_H

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;


void BF(int graph[30][30], int nVertices, char start, int Label[], int Prev[]);
string BF_Path(int graph[30][30], int nVertices, char start, char goal);

#endif
