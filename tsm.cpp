#include "tsm.h"
using namespace std;

const int INT_MAX = 2147483647;

int calculateFirstEdgeCost(int G[30][30], int i, int numVertices) {
    int min = INT_MAX;
    for (int k = 0; k < numVertices; k++){
        if (k != i && G[i][k] != 0 && G[i][k] < min)
        {
                min = G[i][k];
        }
    }       

    if(min == INT_MAX) return 0;
    return min;
}

int computeSecondEdgeCost(int G[30][30], int i, int numVertices) 
{
    int one = INT_MAX;
    int two = INT_MAX;
    for (int j = 0; j < numVertices; j++) {
        if (i == j || G[i][j] == 0)
        {
             continue;
        }
           
        if (G[i][j] <= one) 
        {
            two = one;
            one = G[i][j];
        } 
        else if (G[i][j] <= two && G[i][j] != one)
        {
            two = G[i][j];
        }
            
    }
    return two == INT_MAX ? 0 : two;
}

void processTSPBranch(int G[30][30], int currentBound, int currWeight, int level, 
             int routePath[], bool nodeVisited[], int &minimumCost, int optimalPath[], int numVertices) {
    if (level == numVertices) 
    {
        if (G[routePath[level - 1]][routePath[0]] != 0) 
        {
            int currRes = currWeight + G[routePath[level - 1]][routePath[0]];
            if (currRes < minimumCost) 
            {
                for (int i = 0; i < numVertices; i++)
                {
                    optimalPath[i] = routePath[i];
                }
                
                optimalPath[numVertices] = routePath[0];
                minimumCost = currRes;
            }
        }
        return;
    }
    

    for (int i = 0; i < numVertices; i++) 
    {
        if (G[routePath[level - 1]][i] != 0 && !nodeVisited[i]) 
        {
            int temp = currentBound;
            currWeight += G[routePath[level - 1]][i];
            
            if (level == 1)
                currentBound -= ((calculateFirstEdgeCost(G, routePath[level - 1], numVertices) + 
                               calculateFirstEdgeCost(G, i, numVertices)) / 2);
            else
                currentBound -= ((computeSecondEdgeCost(G, routePath[level - 1], numVertices) + 
                               calculateFirstEdgeCost(G, i, numVertices)) / 2);
            
            if (currentBound + currWeight < minimumCost) {
                routePath[level] = i;
                nodeVisited[i] = true;
                
                processTSPBranch(G, currentBound, currWeight, level + 1, 
                        routePath, nodeVisited, minimumCost, optimalPath, numVertices);
                

                nodeVisited[i] = false;
            }
            

            currWeight -= G[routePath[level - 1]][i];
            currentBound = temp;
        }
    }
}


string Traveling(int G[30][30], int numVertices, char start) {
    int routePath[31];
    int optimalPath[31];
    bool nodeVisited[30] = {false};
    string routeResult;
    

    for (int i = 0; i < numVertices; i++) 
    {
        for (int j = 0; j < numVertices; j++) 
        {

            if (G[i][j] == 0 && i != j) 
            {
                G[i][j] = INT_MAX;
            }
        }
    }
    
    int currentBound = 0;

    for (int i = 0; i < numVertices; i++)
        currentBound += (calculateFirstEdgeCost(G, i, numVertices) + 
                      computeSecondEdgeCost(G, i, numVertices));
    
    currentBound = (currentBound & 1) ? currentBound / 2 + 1 : currentBound / 2;
    
    nodeVisited[start - 'A'] = true;
    routePath[0] = start - 'A';
    
    int minimumCost = INT_MAX;

    processTSPBranch(G, currentBound, 0, 1, routePath, nodeVisited, minimumCost, optimalPath, numVertices);
    
    
    for (int i = 0; i <= numVertices; i++) 
    {
        routeResult += (char)(optimalPath[i] + 'A');
        if (i < numVertices) routeResult += " ";
    }
    
    return routeResult;
}
