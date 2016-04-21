#include <QDebug>

#include "graphview.h"

GraphView::GraphView(IGraph *graph)
    : QGraphicsView()
{
    // Initialisation de la scene
    scene = new QGraphicsScene();
    this->setScene(scene);
    this->setRenderHints(QPainter::Antialiasing);

    const int GRID_WIDTH = 4;
    int x = 0;
    int y = 0;

    // Création et ajout des sommets à la scéne
    for (IVertex *vertex : graph->getVertex()) {

        // Création du nouvel élément graphique
        VertexItem *vertexItem = new VertexItem(vertex);

        // Sommets positionnés sur une grille
        if (x >= GRID_WIDTH) {
            x = 0;
            y++;
        }
        vertexItem->setPos(x * 100, y * 100);
        x++;

        // Ajout de l'élément graphique à la liste
        vertexItems.append(vertexItem);
        scene->addItem(vertexItem);
        vertexItem->setVisible(true);
    }

    // Création et ajout des arcs et arêtes à la scéne
    for (IEdge *edge : graph->getEdges()) {

        // Création du nouvel élément graphique
        // lié aux bons sommets (graphiques)
        EdgeItem *edgeItem = new EdgeItem(
            edge,
            vertexItems.at(edge->getFrom()->getId()),
            vertexItems.at(edge->getTo()->getId())
        );

        // Ajout de l'élément graphique à la liste
        edgeItems.append(edgeItem);
        scene->addItem(edgeItem);
        edgeItem->setVisible(true);
    }
}

GraphView::~GraphView() {
    for (VertexItem *v : vertexItems) {
        delete v;
    }
    for (EdgeItem *e : edgeItems) {
        delete e;
    }
    delete scene;
}
