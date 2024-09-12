#ifndef FLOCKING_H
#define FLOCKING_H
#include <Eigen/Dense>
#include <cmath>
#include "../multi_utils/mesh.h"


Eigen::MatrixXd VelocityMatrix(std::vector<std::shared_ptr<Mesh>> input_objects);

Eigen::MatrixXd PositionMatrix(std::vector<std::shared_ptr<Mesh>> input_objects);

void update_velocities(Eigen::MatrixXd velocity_matrix, std::vector<std::shared_ptr<Mesh>> input_objects);

Eigen::MatrixXd alignment_vel(Eigen::MatrixXd object_velocities);

Eigen::MatrixXd cohesion_vel(Eigen::MatrixXd object_positions, 
                             Vector3f control_point,
                             double max_vel);

Eigen::MatrixXd seperation_vel(Eigen::MatrixXd object_positions);

void flocking_control(std::vector<std::shared_ptr<Mesh>> input_objects, Vector3f control_point);
// Eigen::MatrixXd velocity_net(Eigen::MatrixXd ali_vel, Eigen::MatrixXd coh_vel, Eigen::MatrixXd sep_vel,
//                              float K_ali, float K_coh, float K_sep);




#endif