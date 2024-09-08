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

