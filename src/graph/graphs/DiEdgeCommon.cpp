//
// Created by PatrickDesle on 16.05.2016.
//

#include "DiEdgeCommon.h"

Vertex* DiEdgeCommon::from() const {
    return _a;
}

Vertex* DiEdgeCommon::to() const {
    return _b;
}

string DiEdgeCommon::edgeStyle() const {
    return "->";
}

Vertex *DiEdgeCommon::either() const {
    return from();
}

Vertex *DiEdgeCommon::other(Vertex *v) const {
    UNUSED(v);
    return to();
}




