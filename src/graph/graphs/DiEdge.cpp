//
// Created by PatrickDesle on 26.04.2016.
//

#include "DiEdge.h"


Vertex* DiEdge::getFrom() { return getEither(); }
Vertex* DiEdge::getTo() { return getOther(getEither()); }