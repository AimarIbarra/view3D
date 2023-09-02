#include "obj_parser.cpp"
#include <gtest/gtest.h>
#include <mesh.h>

// Throw Exception if obj file not found
TEST(ObjParser, ObjFileNotFound) {
    try {
        obj_parser("random.obj");
    } catch (const std::invalid_argument &e) {
        EXPECT_STREQ(e.what(), "File: `random.obj` not found");
    } catch (...) {
        FAIL() << "Unxpected Error";
    }
}

// Load mesh from obj file without Mat. Log in -V
TEST(ObjParser, ObjFileFoundNoMat) {
    // TODO: Catch Log
    Mesh mesh = obj_parser("../../resources/cube_no_mat.obj");
}

// Load mesh from obj file with Mat Ceremonial Only. Log in -V
TEST(ObjParser, ObjFileFoundWithMat) {
    // TODO: Catch Log
    Mesh mesh = obj_parser("../../resources/cube.obj");
}