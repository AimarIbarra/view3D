#include "vertex.h"

Vertex::Vertex() noexcept : position{}, normal{}, coords{} {}

Vertex::Vertex(const Vectorf<3> &pos, const Vectorf<2> &coor) noexcept
    : position(pos), normal{}, coords(coor) {}

Vertex::Vertex(const Vectorf<3> &pos, const Vectorf<3> &norm,
               const Vectorf<2> &coor) noexcept
    : position(pos), normal(norm), coords(coor) {}

const Vectorf<3> &Vertex::get_position() const noexcept { return position; }

const Vectorf<3> &Vertex::get_normal() const noexcept { return normal; }

const Vectorf<2> &Vertex::get_coords() const noexcept { return coords; }
