#include "mesh.h"
#include "vector.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

template <std::size_t siz>
std::ifstream &operator>>(std::ifstream &is, Vector<siz> &vec) {
    for (auto &p : vec) {
        is >> p;
    }

    return is;
}

Mesh obj_parser(std::string obj_file) {
    std::ifstream file(obj_file);

    std::string mtlfile;
    std::vector<Vector<3>> points;
    std::vector<Vector<3>> normals;
    std::vector<Vector<2>> textures;

    std::string mode;
    Vector<2> tempvec2;
    Vector<3> tempvec3;

    std::vector<Vertex> vts{};

    file >> mode;

    if (mode.empty()) {
        throw std::invalid_argument("File: `" + obj_file + "` not found");
    }

    while (!file.eof()) {
        if (mode == "v") {
            file >> tempvec3;
            points.push_back(tempvec3);
        } else if (mode == "vn") {
            file >> tempvec3;
            normals.push_back(tempvec3);
        } else if (mode == "vt") {
            file >> tempvec2;
            textures.push_back(tempvec2);
        } else if (mode == "f") {
            char temp;
            int v, vt, vn;

            for (int i = 0; i < 3; i++) {
                file >> v;
                file >> temp;
                file >> vt;
                file >> temp;
                file >> vn;

                vts.push_back(
                    Vertex(points[v - 1], normals[vn - 1], textures[vt - 1]));
            }

        } else if (mode == "mtllib") {
            file >> mtlfile;
        } else {
            std::string temp;
            std::getline(file, temp);
        }
        file >> mode;
    }

    if (mtlfile.empty()) {
        std::cerr << "[    LOG   ] No Material File Found" << std::endl;
    } else {
        std::cerr << "[    LOG   ] Material File Found: " << mtlfile
                  << std::endl;
    }

    file.close();

    // DEBUGGING. Very Verbose.
    // for (auto i : Mesh(vts).get_verts()) {
    //     std::cerr << "Position:" << i.get_position()
    //               << "\t| Normals:" << i.get_normal()
    //               << "\t| TexCords:" << i.get_coords() << std::endl;
    // }
    return Mesh(vts);
}