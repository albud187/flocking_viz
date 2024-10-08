#ifndef MESH_H
#define MESH_H

#include <GL/glew.h>
#include <GL/freeglut.h>
#include "../ogl_utils/ogldev_math_3d.h" 
#include "world_transform.h"
#include <memory>

class Mesh {
public:
    WorldTrans transform; // Transformation data for the mesh
    GLuint shaderProgramID;
    Vector3f uniqueColor;
    int obj_id;
    const VT* mesh_vertices;
    const unsigned int* mesh_indices;
    unsigned int numIndices;
    Mesh(const VT* vertices, unsigned int numVertices, const unsigned int* indices, unsigned int numIndices);
    ~Mesh();
    
    void Draw(const Matrix4f& projection, const Matrix4f& view, GLuint gWVPLocation);
    void DrawLine(const Matrix4f& projection, const Matrix4f& view, GLuint gWVPLocation);
    void SetShaderProgram(GLuint programID);
    void setID(int id_num);
private:
    GLuint vbo; // Vertex Buffer Object
    GLuint ibo; // Index Buffer Object
     // Number of indices
   
    void createVertexBuffer(const VT* vertices, unsigned int numVertices);
    void createIndexBuffer(const unsigned int* indices, unsigned int numIndices);
    
};

void draw_triangles(const std::vector<std::shared_ptr<Mesh>>& game_objects, Matrix4f Projection, Matrix4f View, GLuint gWVPLocation);
void draw_lines(const std::vector<std::shared_ptr<Mesh>>& game_objects, Matrix4f Projection, Matrix4f View, GLuint gWVPLocation);

VT* generateSquareVertices(float sideLength);

unsigned int* generateSquareIndices();

void move_mesh(std::shared_ptr<Mesh> mesh_ptr, unsigned char key);

void printTrianglePoint(Vector3f p);

struct meshTriangle {
    Vector3f a;
    Vector3f b;
    Vector3f c;
    meshTriangle(Vector3f p1, Vector3f p2, Vector3f p3);

};

std::vector<meshTriangle> get3DTriangle(VT* verticies, WorldTrans transform, int size);
std::vector<meshTriangle> get3DTriangles(const VT* verticies, const unsigned int* indices, int n_indices, WorldTrans transform);

float triangleIntersectTest
(const Vector3f& camray, const Vector3f& rayOrigin, const meshTriangle& triangle);

float objectIntersectTest
(const Vector3f& camray, const Vector3f& rayOrigin, const std::shared_ptr<Mesh>& obj);

std::vector<std::pair<std::shared_ptr<Mesh>, float>> ObjectDistances
(const std::vector<std::shared_ptr<Mesh>>& game_objects, const Vector3f& camray, const Vector3f& rayOrigin);

std::shared_ptr<Mesh> pick_object(const std::vector<std::pair<std::shared_ptr<Mesh>, float>>& objects);
#endif
