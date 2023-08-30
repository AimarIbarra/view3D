#ifndef VERTEX_H
#define VERTEX_H

#include <vector.h>

class Vertex {
    Vector<3> position;
    Vector<3> normal;
    Vector<2> coords;

public:
    Vertex(const Vector<3> &pos, const Vector<2> &coor) noexcept;
    Vertex(const Vector<3> &pos, const Vector<3> &norm,
           const Vector<2> &coor) noexcept;

    const Vector<3> &get_position() const noexcept;
    const Vector<3> &get_normal() const noexcept;
    const Vector<2> &get_coords() const noexcept;
};

#endif
