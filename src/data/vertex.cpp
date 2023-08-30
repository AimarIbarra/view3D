#include <vertex.h>

Vertex::Vertex(const Vector<3> &pos, const Vector<2> &coor) noexcept
    : position(pos), coords(coor) {}

Vertex::Vertex(const Vector<3> &pos, const Vector<3> &norm,
               const Vector<2> &coor) noexcept
    : position(pos), normal(norm), coords(coor) {}

const Vector<3> &Vertex::get_position() const noexcept { return position; }

const Vector<3> &Vertex::get_normal() const noexcept { return normal; }

const Vector<2> &Vertex::get_coords() const noexcept { return coords; }
