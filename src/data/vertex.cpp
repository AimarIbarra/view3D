#include "vertex.h"

Vertex::Vertex() noexcept {}

Vertex::Vertex(Vector3f position, Vector2f texture_coords) noexcept
{
    this->position = position;
    this->texture_coords = texture_coords;
}

Vertex::Vertex(Vector3f position, Vector3f normal, Vector2f texture_coords) noexcept
{
    this->position = position;
    this->normal = normal;
    this->texture_coords = texture_coords;
}

Vector3f Vertex::get_position() noexcept
{
    return this->position;
}

Vector3f Vertex::get_normal() noexcept
{
    return this->normal;
}

Vector2f Vertex::get_texuture_coords() noexcept
{
    return this->texture_coords;
}
