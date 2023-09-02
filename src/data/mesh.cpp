#include <mesh.h>

Mesh::Mesh() noexcept {}

Mesh::Mesh(std::vector<Vertex> verts) noexcept {
    vertices = verts;
}

std::vector<Vertex> Mesh::get_verts() noexcept {
    return vertices;
}