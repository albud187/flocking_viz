#ifndef MATRIX_UTILS_H
#define MATRIX_UTILS_H

#include <Eigen/Dense>
#include <cmath>
#include "../multi_utils/mesh.h"


Eigen::MatrixXd VelocityMatrix(std::vector<std::shared_ptr<Mesh>> game_objects);
Eigen::MatrixXd PositionMatrix(std::vector<std::shared_ptr<Mesh>> game_objects);
void update_velocities(Eigen::MatrixXd velocity_matrix);
#endif