//
// Created by sebri on 15.05.2016.
//

#ifndef GRAPH_GRAPHALGORITHM_H
#define GRAPH_GRAPHALGORITHM_H


#include "../graphs/IGraph.h"
#include "../graphs/Graph.h"
#include "../graphs/DiGraph.h"
#include "../graphs/FlowGraph.h"

class GraphAlgorithm
{
public:
    static IGraph* bfs(IGraph *g, Vertex *from, vector<int>& distances);
    static IGraph* dfs(IGraph *g, Vertex *from, vector<int>& dfsnum);
    static vector<int>& connectedComponent(IGraph *g);
    static IGraph* kruskal(IGraph *g);
    static IGraph* prim(IGraph *g, Vertex *from);
};


#endif //GRAPH_GRAPHALGORITHM_H
