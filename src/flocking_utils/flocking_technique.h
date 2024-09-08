#ifndef FLOCKING_H
#define FLOCKING_H
#include <Eigen/Dense>
#include <cmath>
#include "../multi_utils/mesh.h"


Eigen::MatrixXd VelocityMatrix(std::vector<std::shared_ptr<Mesh>> input_objects);
Eigen::MatrixXd PositionMatrix(std::vector<std::shared_ptr<Mesh>> input_objects);
void update_velocities(Eigen::MatrixXd velocity_matrix, std::vector<std::shared_ptr<Mesh>> input_objects);



void test_func();
#endif