/*!
 * \brief IGraph widget visualizer class
 *
 * \file GraphWidget.cpp
 * \author Damien Rochat
 * \date 23.05.2016
 */

#include <QVBoxLayout>

#include "../graph/graphs/IGraph.h"

#include "GraphWidget.h"
#include "view/GraphSceneManager.h"

GraphWidget::GraphWidget(const IGraph *graph, QWidget *parent)
    : QWidget(parent)
{
    view = new GraphView();
    scene = GraphSceneManager::getInstance()->scene(graph);
    view->setScene(scene);
    view->setRenderHints(QPainter::Antialiasing);
    layout = new QVBoxLayout();
    layout->addWidget(view);
    setLayout(layout);
}

GraphWidget::~GraphWidget() {
    delete layout;
    delete view;
}
