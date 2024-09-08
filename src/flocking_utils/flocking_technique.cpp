#include "matrix_tools.h"
#include "../multi_utils/mesh.h"
#include <Eigen/Dense>
//matrix tools interfaces with opengl

Eigen::MatrixXd VelocityMatrix(std::vector<std::shared_ptr<Mesh>> input_objects){
    Eigen::MatrixXd result_matrix(3, input_objects.size());

    int col = 0;

    for (const auto& mesh_ptr : input_objects){
        result_matrix(0, col) = mesh_ptr->transform.m_pos.x;
        result_matrix(0, col) = mesh_ptr->transform.m_pos.y;
        result_matrix(0, col) = mesh_ptr->transform.m_pos.z;
        
    }

    return result_matrix;
}

Eigen::MatrixXd PositionMatrix(std::vector<std::shared_ptr<Mesh>> input_objects){
    Eigen::MatrixXd result_matrix(3, input_objects.size());

    int col = 0;

    for (const auto& mesh_ptr : input_objects){
        result_matrix(0, col) = mesh_ptr->transform.m_pos.x;
        result_matrix(0, col) = mesh_ptr->transform.m_pos.y;
        result_matrix(0, col) = mesh_ptr->transform.m_pos.z;
        
    }

    return result_matrix;
}

void update_velocities(Eigen::MatrixXd velocity_matrix, std::vector<std::shared_ptr<Mesh>> input_objects){

    for (int i = 0; i <velocity_matrix.cols(); i++){
        input_objects[i]->transform.setVel(velocity_matrix(0,i), velocity_matrix(1,i), velocity_matrix(2,i));
    }

}

Eigen::MatrixXd alignment_vel(Eigen::MatrixXd object_velocities, Eigen::MatrixXd object_positions){

    
    Eigen::MatrixXd result_matrix(3, object_velocities.cols());

    Eigen::Vector3d vectorsum = Eigen::Vector3d::Zero();
    for (int i = 0; i < object_velocities.cols(); i++){
        vectorsum = vectorsum + object_velocities.col(i);
    }
    Eigen::Vector3d avg_vect = vectorsum / object_velocities.cols();

    for (int i = 0; i < object_velocities.cols(); i++){
        result_matrix.col(i) = avg_vect;
    }

    return result_matrix;

}
