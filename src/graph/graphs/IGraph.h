//
// Created by sebri on 18.04.2016.
//

#ifndef GRAPH_IGRAPH_H
#define GRAPH_IGRAPH_H

#include <list>
#include "Edge.h"

class Visitor;

class IGraph {
public:

    typedef list<Edge*> edges;
    typedef list<Vertex*> vertices;

    virtual ~IGraph(){}
    virtual bool isEmpty() const = 0;
    virtual bool isSimple() const = 0;
    virtual bool isConnected() const = 0;
    virtual bool isStronglyConnected() const = 0;
    virtual bool isDirected() const = 0;
    virtual bool isNegativeWeighted() const = 0;
    virtual bool isPlanar() const = 0;
    virtual vertices getVertices() const = 0;
    virtual edges getEdges() const = 0;
    virtual int V() const = 0; // retourne le nombre de sommet
    virtual void ponderate(std::list<Edge> edges, double weight) = 0;
    virtual void ponderateEdges(double weight) = 0;
    virtual void ponderate(std::list<Vertex> vertices, double weight) = 0;
    virtual void addEdge(Edge e) = 0;
    virtual void addEdge(Vertex v1, Vertex v2) = 0;
    virtual void addVertex(Vertex v) = 0;
    virtual void removeEdge(Edge e) = 0;
    virtual void removeVertex(Vertex v) = 0;

    template <typename Func>
    void forEachAdjacentVertex(const Vertex& v, Func f);
    //virtual void accept(Visitor* v);
};

#endif //GRAPH_IGRAPH_H
