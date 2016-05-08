#ifndef VISUALIZATION_IEDGE_H
#define VISUALIZATION_IEDGE_H

#include "ivertex.h"

class IEdge
{
    IVertex *from;
    IVertex *to;

public:
    IEdge(IVertex *from, IVertex *to);
    ~IEdge();
    const IVertex *getFrom() const;
    const IVertex *getTo() const;
};

#endif // VISUALIZATION_IEDGE_H
