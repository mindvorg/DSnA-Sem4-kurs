#pragma once
#include"edge.h"
#include"list.h"
#include"parsing.h"
#include<iostream>
using namespace std;
const int MAX_E = (int)1e6;
const int MAX_V = (int)1e3;
const int INF = (int)1e9;

int numOfVertex, numOfEdge, sourceVertex, destinationVertex, edgeCount;
int capacity[MAX_E], onEnd[MAX_E], nextEdge[MAX_E];
int firstEdge[MAX_V], visited[MAX_V];

void addEdge(int u, int v, int cap/*, int* onEnd, int* nextEdge, int* firstEdge, int* capacity*/) {
    //    edge forward
    onEnd[edgeCount] = v;                   
    nextEdge[edgeCount] = firstEdge[u];    
    firstEdge[u] = edgeCount;             
    capacity[edgeCount++] = cap;            
    // edge back
    onEnd[edgeCount] = u;                   
    nextEdge[edgeCount] = firstEdge[v];     
    firstEdge[v] = edgeCount;               
    capacity[edgeCount++] = 0; 
}

int findFlow(int u, int flow/*, int* nextEdge, int* visited, int* firstEdge, int* capacity, int* onEnd*/) {
    if (u == destinationVertex) return flow; // return min flow 
    visited[u] = true;
    for (int edge = firstEdge[u]; edge != -1; edge = nextEdge[edge]) {
        int to = onEnd[edge];
        if (!visited[to] && capacity[edge] > 0) {
            int minResult = findFlow(to, min(flow, capacity[edge])/*, nextEdge, visited, firstEdge, capacity, onEnd*/); 
            if (minResult > 0) {                  
                capacity[edge] -= minResult;   // minus forward edge
                capacity[edge ^ 1] += minResult;   // plus back edge
                return minResult;
            }
        }
    }
    return 0; 
}
int fordFalkerson(List<Edge>* listEdg, List<string>* listStr)
{
   int size = listEdg->getSize();
    fill(firstEdge, firstEdge + MAX_V, -1);    
    sourceVertex = listEdg->head->data.indexFrom;//in list2.head
    destinationVertex = listEdg->tail->data.indexTo;// out list2.tail
    for (int i = 0; i <size; i++)
        addEdge((*listEdg)[i].indexFrom, (*listEdg)[i].indexTo, (*listEdg)[i].costTo);
    int maxFlow = 0;
    int iterationResult = 0;
    while ((iterationResult = findFlow(sourceVertex, INF)) > 0) {
        fill(visited, visited + MAX_V, false);
        maxFlow += iterationResult;

    }
    return maxFlow;
}