#pragma once
#include "vector3f.h"
#include "vector2f.h"

class Vertex {
    public:
        Vertex() noexcept;
        Vertex(Vector3f position, Vector2f texture_coords) noexcept;
        Vertex(Vector3f position, Vector3f normal, Vector2f texture_coords) noexcept;

        Vector3f get_position() noexcept;
        Vector3f get_normal() noexcept;
        Vector2f get_texuture_coords() noexcept;
    private:
        Vector3f position{}, normal{};
        Vector2f texture_coords{};
};