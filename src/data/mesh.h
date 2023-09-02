#include "vertex.h"
#include <vector>

#ifndef MESH_H
#define MESH_H

class Mesh {
    std::vector<Vertex> vertices;

  public:
    Mesh() noexcept;
    Mesh(std::vector<Vertex>) noexcept;

    std::vector<Vertex> get_verts() noexcept;
};

#endif