#include "../multi_utils/mesh.h"
#include "flocking_constants.h"
#include <Eigen/Dense>
//matrix tools interfaces with opengl

Eigen::MatrixXd VelocityMatrix(std::vector<std::shared_ptr<Mesh>> input_objects){
    Eigen::MatrixXd result_matrix(3, input_objects.size());

    for (int col = 0; col <input_objects.size(); col++){
        result_matrix(0,col) = input_objects[col]->transform.m_vel.x;
        result_matrix(1,col) = input_objects[col]->transform.m_vel.y;
        result_matrix(2,col) = input_objects[col]->transform.m_vel.z;
    }

    return result_matrix;
}

Eigen::MatrixXd PositionMatrix(std::vector<std::shared_ptr<Mesh>> input_objects){
    Eigen::MatrixXd result_matrix(3, input_objects.size());

    for (int col = 0; col <input_objects.size(); col++){
        result_matrix(0,col) = input_objects[col]->transform.m_pos.x;
        result_matrix(1,col) = input_objects[col]->transform.m_pos.y;
        result_matrix(2,col) = input_objects[col]->transform.m_pos.z;
    }
    return result_matrix;
}

void update_velocities(Eigen::MatrixXd velocity_matrix, std::vector<std::shared_ptr<Mesh>> input_objects){

    for (int i = 0; i <velocity_matrix.cols(); i++){
        input_objects[i]->transform.setVel(velocity_matrix(0,i), velocity_matrix(1,i), velocity_matrix(2,i));
    }

}

double velocity_mag(double target_distance, double max_vel, double dt) {
    double min_vel = 3;  // introduce a minimum velocity
    if (target_distance > max_vel * dt) {
        return max_vel;
    } else {
        double result = target_distance / dt;
        return (result > min_vel) ? result : min_vel;  // ensure velocity doesn’t go below min_vel
    }
}


//tend to get velocity to ge the same
Eigen::MatrixXd alignment_vel(Eigen::MatrixXd object_velocities){

    
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



Eigen::MatrixXd cohesion_vel(Eigen::MatrixXd object_positions, 
                            Vector3f control_point,
                            double max_vel)
{
    
    Eigen::MatrixXd result_matrix(3, object_positions.cols());

    //convert to eigen
    Eigen::Vector3d control_pos;
    control_pos.x() = control_point.x;
    control_pos.y() = control_point.y;
    control_pos.z() = control_point.z;

    //get average positions
    Eigen::Vector3d obj_pos_sum;
    for (int i = 0; i < object_positions.cols(); i++){
        obj_pos_sum += object_positions.col(i);
    }

    //get target position
    Eigen::Vector3d target_position = (control_pos + obj_pos_sum/(object_positions.cols()))/2;

    for (int c = 0; c< object_positions.cols(); c++){
        Eigen::Vector3d obj_pos = object_positions.col(c);
        Eigen::Vector3d target_vector = target_position - obj_pos;

        Eigen::Vector3d coh_vel_c = velocity_mag(target_vector.norm(), max_vel, 1.0)*target_vector/target_vector.norm();
        result_matrix.col(c) = coh_vel_c;
    }

    return result_matrix;
}


Eigen::MatrixXd seperation_vel(Eigen::MatrixXd object_positions){
    Eigen::MatrixXd result_matrix(3, object_positions.cols());

    for (int c = 0; c<object_positions.cols(); c++){
        Eigen::Vector3d sep_vel_c = Eigen::Vector3d::Zero();
        Eigen::Vector3d obj_pos_c = object_positions.col(c);
    

        for (int n = 0; n<object_positions.cols(); n++){
            if(n!=c){
                Eigen::Vector3d obj_pos_n = object_positions.col(n);
                Eigen::Vector3d d_pos_cn = obj_pos_n - obj_pos_c;
                double d_pos_mag = d_pos_cn.norm();
                if (d_pos_mag > 0.001) { 
                    sep_vel_c -= d_pos_cn/(pow(d_pos_mag,2));
                }
            }
        }
        result_matrix.col(c) = sep_vel_c;
    }

    return result_matrix;
}

void flocking_control(std::vector<std::shared_ptr<Mesh>> input_objects, Vector3f control_point){
    Eigen::MatrixXd vel_mat = VelocityMatrix(input_objects);
    Eigen::MatrixXd pos_mat = PositionMatrix(input_objects);

    Eigen::MatrixXd ali_vels = alignment_vel(vel_mat);
    Eigen::MatrixXd coh_vels = cohesion_vel(pos_mat, control_point, V_MAX);
    Eigen::MatrixXd sep_vels = seperation_vel(pos_mat);

    Eigen::MatrixXd v_net = 0.25*(K_ALI*ali_vels + K_COH*coh_vels + K_SEP*sep_vels);

    update_velocities(v_net, input_objects);

}