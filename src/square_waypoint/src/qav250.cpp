#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/State.h>
#include <mavros_msgs/ParamGet.h>
#include <mavros_msgs/ParamSet.h>

#include <iostream>
#include <future>

using namespace std;

mavros_msgs::State uav0_current_state;

void uav0_state_callback(const mavros_msgs::State::ConstPtr& msg){

    uav0_current_state = *msg;
}

void check_connection(){

    ros::Rate rate(20.0);

    while (ros::ok() && !uav0_current_state.connected){

        ros::spinOnce();
        rate.sleep();
    }

}

bool send_position(int iter, ros::Publisher uav_loc, float pos_x, float pos_y, float pos_z, float rot_x, float rot_y, float rot_z, float rot_w){
    
    ros::Rate rate(20.0);

    geometry_msgs::PoseStamped uav0_pose;

    uav0_pose.pose.position.x = pos_x;
    uav0_pose.pose.position.y = pos_y;
    uav0_pose.pose.position.z = pos_z;
    uav0_pose.pose.orientation.x = rot_x;
    uav0_pose.pose.orientation.y = rot_y;
    uav0_pose.pose.orientation.z = rot_z;
    uav0_pose.pose.orientation.w = rot_w;

    for (int i = iter; ros::ok() && i > 0; --i){

        uav_loc.publish(uav0_pose);

        ros::spinOnce();
        rate.sleep();
        ROS_INFO("Iteration: %d",i);
    }

}

void set_offboard(ros::ServiceClient uav0_set_mode_client, ros::ServiceClient uav0_arming_client, ros::Publisher uav0_local_pos_pub
                    ){

    mavros_msgs::SetMode uav0_offb_set_mode;
    uav0_offb_set_mode.request.custom_mode = "OFFBOARD";
    mavros_msgs::CommandBool uav0_arm_cmd;
    uav0_arm_cmd.request.value = true;

    ros::Rate rate(20.0);
    ros::Time last_request = ros::Time::now();

    while (ros::ok()){

        if(uav0_current_state.mode != "OFFBOARD" && (ros::Time::now() - last_request > ros::Duration(5.0))){

            if (uav0_set_mode_client.call(uav0_offb_set_mode) && uav0_offb_set_mode.response.mode_sent){
                ROS_INFO("UAV0_Offboard enabled");
            }

            last_request = ros::Time::now();

        }

        else{
            if(!uav0_current_state.armed && (ros::Time::now() - last_request > ros::Duration(5.0))){

                if(uav0_arming_client.call(uav0_arm_cmd) && uav0_arm_cmd.response.success){
                    ROS_INFO("UAV0_Vehicle armed");
                }
                
                last_request = ros::Time::now();
                break;
            }
        }

        ros::spinOnce();
        rate.sleep();

        geometry_msgs::PoseStamped uav0_pose;

        uav0_pose.pose.position.x = 0;
        uav0_pose.pose.position.y = 0;
        uav0_pose.pose.position.z = 0.3;
        uav0_pose.pose.orientation.x = 0;
        uav0_pose.pose.orientation.y = 0;
        uav0_pose.pose.orientation.z = 0;
        uav0_pose.pose.orientation.w = 1;
        uav0_local_pos_pub.publish(uav0_pose);

    } 

}

int main (int argc, char **argv) 
{

    ros::init(argc, argv, "one_unit");
    ros::NodeHandle nh; 

    ros::Subscriber uav0_state_sub = nh.subscribe<mavros_msgs::State>("mavros/state", 10, uav0_state_callback); // 10 is buffer size
    ros::Publisher uav0_local_pos_pub = nh.advertise<geometry_msgs::PoseStamped>("mavros/setpoint_position/local", 10);

    ros::ServiceClient uav0_arming_client = nh.serviceClient<mavros_msgs::CommandBool>("mavros/cmd/arming");
    ros::ServiceClient uav0_set_mode_client = nh.serviceClient<mavros_msgs::SetMode>("mavros/set_mode");

    check_connection();

    send_position(200, uav0_local_pos_pub , 0, 0, 0.3, 0, 0 , 0, 1);

    set_offboard(uav0_set_mode_client, uav0_arming_client, uav0_local_pos_pub);
    
    send_position(200   , uav0_local_pos_pub , 0, 0, 0.3, 0, 0, 0, 1);
    send_position(200, uav0_local_pos_pub , 1, 0, 0.3, 0, 0 , 0, 1);
    send_position(200, uav0_local_pos_pub , 1, 0, 0.3, 0, 0 , 0.707, 0.707);
    send_position(200, uav0_local_pos_pub , 1, 1, 0.3, 0, 0 , 0.707, 0.707);
    send_position(200, uav0_local_pos_pub , 1, 1, 0.3, 0, 0 , 1, 0);
    send_position(200, uav0_local_pos_pub , 0, 1, 0.3, 0, 0 , 1, 0);
    send_position(200, uav0_local_pos_pub , 0, 1, 0.3, 0, 0 , 0.707, -0.707);
    send_position(200, uav0_local_pos_pub , 0, 0, 0.3, 0, 0 , 0.707, -0.707);
    send_position(200, uav0_local_pos_pub , 0, 0, 0.3, 0, 0 , 0, 1);
    send_position(200, uav0_local_pos_pub , 0, 0, -0.5, 0, 0 , 0, 1);

    return 0;

}