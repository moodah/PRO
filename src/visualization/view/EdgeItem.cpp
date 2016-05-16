#include <QPainter>
#include <QDebug>
#include <QtMath>

#include "Constants.h"
#include "EdgeItem.h"

EdgeItem::EdgeItem(const IEdge *edge, VertexItem *source, VertexItem *dest)
    : edge(edge), sourceItem(source), destItem(dest)
{
    setAcceptedMouseButtons(0);
    setZValue(-1);

    sourceItem->addEdge(this);
    destItem->addEdge(this);

    adjust();
}

EdgeItem::~EdgeItem()
{}

QRectF EdgeItem::boundingRect() const
{
    QRectF rect(sourcePoint, destPoint);
    return rect.normalized().adjusted(-EDGE_ARROW_SIZE,
                                      -EDGE_ARROW_SIZE,
                                      EDGE_ARROW_SIZE,
                                      EDGE_ARROW_SIZE);
}

void EdgeItem::paint(QPainter *painter,
                       const QStyleOptionGraphicsItem *option,
                       QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    // Dessin de la ligne
    QPen pen = painter->pen();
    pen.setColor(EDGE_COLOR);
    pen.setWidth(EDGE_WIDTH);
    painter->setPen(pen);

    QLineF line(sourcePoint, destPoint);
    painter->drawLine(line);

    // Calcul des points de la flèche en direction du sommet de destination
    double angle = qAcos(line.dx() / line.length());
    if (line.dy() >= 0) {
        angle = 2 * M_PI - angle;
    }
    QPointF arrowP1 = destPoint + QPointF(
                qSin(angle - M_PI / 3) * EDGE_ARROW_SIZE,
                qCos(angle - M_PI / 3) * EDGE_ARROW_SIZE
    );
    QPointF arrowP2 = destPoint + QPointF(
                qSin(angle - 2 * M_PI / 3) * EDGE_ARROW_SIZE,
                qCos(angle - 2 * M_PI / 3) * EDGE_ARROW_SIZE
    );
    QPolygonF arrow;
    arrow.push_back(line.p2());
    arrow.push_back(arrowP1);
    arrow.push_back(arrowP2);

    // Dessin de la flèche
    pen = painter->pen();
    pen.setColor(EDGE_COLOR);
    painter->setPen(pen);
    QBrush brush = painter->brush();
    brush.setColor(EDGE_COLOR);
    brush.setStyle(Qt::SolidPattern);
    painter->setBrush(brush);
    painter->drawPolygon(arrow);
}

// Ajuste les extrémités de la ligne pour que celle-ci ne soit
// pas dessinée jusqu'au centre des sommets, mais en bordure
// de ceux-ci (rayon du sommet + bordure du sommet / 2 + marge).
// Effectue un décalage au début et à la fin de la ligne par thalès.
void EdgeItem::adjust()
{
    QPointF sourceCenter = sourceItem->getCenter();
    QPointF destCenter = destItem->getCenter();
    QLineF line(sourceCenter, destCenter);

    qreal diff = (VERTEX_RADIUS +
                  VERTEX_BORDER_WIDTH / 2 +
                  EDGE_VERTEX_MARGIN) / line.length();
    qreal dx = line.dx() * diff;
    qreal dy = line.dy() * diff;

    prepareGeometryChange();

    sourcePoint.setX(sourceCenter.x() + dx);
    sourcePoint.setY(sourceCenter.y() + dy);
    destPoint.setX(destCenter.x() - dx);
    destPoint.setY(destCenter.y() - dy);

    update();
}