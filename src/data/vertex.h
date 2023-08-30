#ifndef VERTEX_H
#define VERTEX_H

#include <vector.h>

class Vertex {
    Vectorf<3> position;
    Vectorf<3> normal;
    Vectorf<2> coords;

public:
    Vertex() noexcept;
    Vertex(const Vectorf<3> &pos, const Vectorf<2> &coor) noexcept;
    Vertex(const Vectorf<3> &pos, const Vectorf<3> &norm,
           const Vectorf<2> &coor) noexcept;

    const Vectorf<3> &get_position() const noexcept;
    const Vectorf<3> &get_normal() const noexcept;
    const Vectorf<2> &get_coords() const noexcept;
};

#endif
