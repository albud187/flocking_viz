
#include "../ogl_utils/ogldev_math_3d.h"
#include "world_transform.h"
#ifndef CONSTANTS_H
#define CONSTANTS_H

std::vector<unsigned char> CAM_KEYS ={'a', 'A', 's', 'S', 'd', 'D', 'w', 'W', 'q', 'Q', 'z','Z','-','='};
std::vector<unsigned char> ADD_CUBE_KEYS ={'e', 'E'};
std::vector<unsigned char> DEL_CUBE_KEYS ={'r', 'R'};

std::vector<unsigned char> MESH_MOVE_KEYS={'i', 'I', 'k', 'K', 'j','J','l','L', 'n', 'N', 'm','M'};
float WINDOW_WIDTH = 1000;
float WINDOW_HEIGHT = 1000;

float TARGET_FPS = 60;
int TARGET_FPS_DELAY_MS = 1000*(1/TARGET_FPS);

Vector3f CAMERA_POS(0.0f, 12.0f, -2.0f);
Vector3f CAMERA_TARGET(-0.2001f, -2.0f, 1.0001f);
Vector3f CAMERA_UP(0.0f, 0.1f, 0.0f);

float FOV = 90.0f;
float Z_NEAR= 0.25f;
float Z_FAR = 1000.0f;

const char* VS_FILE_NAME= "/workdir/src/shaders/shader.vs";
const char* FS_FILE_NAME = "/workdir/src/shaders/shader.fs";

const char* VS2_FILE_NAME= "/workdir/src/shaders/shader2.vs";
const char* FS2_FILE_NAME = "/workdir/src/shaders/shader2.fs";

VT CUBE_VERTICES[] = {
    VT(0.10f, 0.10f, 0.10f, 0.35, 0.35, 0.95),
    VT(-0.10f, 0.10f, -0.10f, 0.95, 0.55, 0.95),
    VT(-0.10f, 0.10f, 0.10f, 0.95, 0.65, 0.35),
    VT(0.10f, -0.10f, -0.10f, 0.25, 0.75, 0.35),
    VT(-0.10f, -0.10f, -0.10f, 0.95, 0.85, 0.35),
    VT(0.10f, 0.10f, -0.10f, 0.45, 0.75, 0.35),
    VT(0.10f, -0.10f, 0.10f, 0.95, 0.15, 0.35),
    VT(-0.10f, -0.10f, 0.10f, 0.55, 0.55, 0.35)
    };
    
unsigned int CUBE_INDICES[] = {
                              0, 1, 2,
                              1, 3, 4,
                              5, 6, 3,
                              7, 3, 6,
                              2, 4, 7,
                              0, 7, 6,
                              0, 5, 1,
                              1, 5, 3,
                              5, 0, 6,
                              7, 4, 3,
                              2, 1, 4,
                              0, 2, 7};

// Define the vertices for a triangular-based pyramid
VT PYRAMID3_VERTICES[] = {
    VT(0.0f, 0.18f, -0.15f, 0.95, 0.35, 0.35),    // Tip of the pyramid
    VT(-0.2f, -0.2f, 0.22f, 0.35, 0.35, 0.95),  // Base vertex 1
    VT(0.18f, -0.18f, 0.18f, 0.45, 0.75, 0.35),   // Base vertex 2
    VT(0.0f, -0.18f, -0.3f, 0.55, 0.55, 0.35)   // Base vertex 3
};

// Define the indices for the faces of the pyramid
unsigned int PYRAMID3_INDICES[] = {
    0, 1, 2,  // Side 1
    0, 2, 3,  // Side 2
    0, 3, 1,  // Side 3
    1, 3, 2   // Base
};

// 0,1,2
// 3,4,5
// 6,7,8
// 9,10,11

VT SQUARE_VERTICES[] ={
    
    VT(0.0, 0.0, 0.0, 0.75, 0.75, 0.75),  // Vertex 0: Bottom Left
    VT(0.0, 0.0, 1.0, 0.75, 0.75, 0.75),   // Vertex 1: Bottom Right
    VT(1.0, 0.0, 1.0, 0.75, 0.75, 0.75),   // Vertex 2: Top Right
    VT(1.0, 0.0, 0.0, 0.75, 0.75, 0.75), // Vertex 3: Top Left
   
};

unsigned int SQUARE_INDICES[] = {
    0, 1,
    1, 2,
    2, 3,
    3, 0

};

unsigned int NV_SQ = sizeof(SQUARE_VERTICES) / sizeof(SQUARE_VERTICES[0]);
unsigned int NI_SQ = sizeof(SQUARE_INDICES) / sizeof(SQUARE_INDICES[0]);


unsigned int NV_PYRAMID3 = sizeof(PYRAMID3_VERTICES) / sizeof(PYRAMID3_VERTICES[0]);
unsigned int NI_PYRAMID3 = sizeof(PYRAMID3_INDICES) / sizeof(PYRAMID3_INDICES[0]);
unsigned int NV_CUBE= sizeof(CUBE_VERTICES) / sizeof(CUBE_VERTICES[0]);
unsigned int NI_CUBE = sizeof(CUBE_INDICES) / sizeof(CUBE_INDICES[0]);


const int GRID_SIZE = 20; // The total size of the grid
const int GRID_LINES_SPACING = 1; // Spacing between lines
const Vector3f GRID_COLOR = Vector3f(0.9f, 0.9f, 0.9f); // Grey color

int GRID_L = 10;
int GRID_W = 10;


#endif