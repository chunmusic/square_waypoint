#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/State.h>
#include <mavros_msgs/ParamGet.h>
#include <mavros_msgs/ParamSet.h>

#include <iostream>

using namespace std;

mavros_msgs::State uav0_current_state;
mavros_msgs::State uav2_current_state;
mavros_msgs::State uav3_current_state;
mavros_msgs::State uav4_current_state;
mavros_msgs::State uav5_current_state;

void uav0_state_callback(const mavros_msgs::State::ConstPtr& msg){

    uav0_current_state = *msg;
}

void uav2_state_callback(const mavros_msgs::State::ConstPtr& msg){

    uav2_current_state = *msg;
}

void uav3_state_callback(const mavros_msgs::State::ConstPtr& msg){

    uav3_current_state = *msg;
}

void uav4_state_callback(const mavros_msgs::State::ConstPtr& msg){

    uav4_current_state = *msg;
}

void uav5_state_callback(const mavros_msgs::State::ConstPtr& msg){

    uav5_current_state = *msg;
}

int main (int argc, char **argv) 
{

    ros::init(argc, argv, "one_unit");
    ros::NodeHandle nh; 

    ros::Subscriber uav0_state_sub = nh.subscribe<mavros_msgs::State>("uav0/mavros/state", 10, uav0_state_callback); // 10 is buffer size
    ros::Publisher uav0_local_pos_pub = nh.advertise<geometry_msgs::PoseStamped>("uav0/mavros/setpoint_position/local", 10);
    ros::Subscriber uav2_state_sub = nh.subscribe<mavros_msgs::State>("uav2/mavros/state", 10, uav2_state_callback); // 10 is buffer size
    ros::Publisher uav2_local_pos_pub = nh.advertise<geometry_msgs::PoseStamped>("uav2/mavros/setpoint_position/local", 10);
    ros::Subscriber uav3_state_sub = nh.subscribe<mavros_msgs::State>("uav3/mavros/state", 10, uav3_state_callback); // 10 is buffer size
    ros::Publisher uav3_local_pos_pub = nh.advertise<geometry_msgs::PoseStamped>("uav3/mavros/setpoint_position/local", 10);
    ros::Subscriber uav4_state_sub = nh.subscribe<mavros_msgs::State>("uav4/mavros/state", 10, uav4_state_callback); // 10 is buffer size
    ros::Publisher uav4_local_pos_pub = nh.advertise<geometry_msgs::PoseStamped>("uav4/mavros/setpoint_position/local", 10);
    ros::Subscriber uav5_state_sub = nh.subscribe<mavros_msgs::State>("uav5/mavros/state", 10, uav5_state_callback); // 10 is buffer size
    ros::Publisher uav5_local_pos_pub = nh.advertise<geometry_msgs::PoseStamped>("uav5/mavros/setpoint_position/local", 10);

    ros::ServiceClient uav0_arming_client = nh.serviceClient<mavros_msgs::CommandBool>("uav0/mavros/cmd/arming");
    ros::ServiceClient uav0_set_mode_client = nh.serviceClient<mavros_msgs::SetMode>("uav0/mavros/set_mode");
    ros::ServiceClient uav2_arming_client = nh.serviceClient<mavros_msgs::CommandBool>("uav2/mavros/cmd/arming");
    ros::ServiceClient uav2_set_mode_client = nh.serviceClient<mavros_msgs::SetMode>("uav2/mavros/set_mode");
    ros::ServiceClient uav3_arming_client = nh.serviceClient<mavros_msgs::CommandBool>("uav3/mavros/cmd/arming");
    ros::ServiceClient uav3_set_mode_client = nh.serviceClient<mavros_msgs::SetMode>("uav3/mavros/set_mode");
    ros::ServiceClient uav4_arming_client = nh.serviceClient<mavros_msgs::CommandBool>("uav4/mavros/cmd/arming");
    ros::ServiceClient uav4_set_mode_client = nh.serviceClient<mavros_msgs::SetMode>("uav4/mavros/set_mode");
    ros::ServiceClient uav5_arming_client = nh.serviceClient<mavros_msgs::CommandBool>("uav5/mavros/cmd/arming");
    ros::ServiceClient uav5_set_mode_client = nh.serviceClient<mavros_msgs::SetMode>("uav5/mavros/set_mode");


    ros::Rate rate(20.0);

    while (ros::ok() && !uav0_current_state.connected && !uav2_current_state.connected && !uav3_current_state.connected
                && !uav4_current_state.connected && !uav5_current_state.connected){

        ros::spinOnce();
        rate.sleep();
    }

    geometry_msgs::PoseStamped uav0_pose;
    geometry_msgs::PoseStamped uav2_pose;
    geometry_msgs::PoseStamped uav3_pose;
    geometry_msgs::PoseStamped uav4_pose;
    geometry_msgs::PoseStamped uav5_pose;

    uav0_pose.pose.position.x = 0;
    uav0_pose.pose.position.y = 0;
    uav0_pose.pose.position.z = 2;

    uav2_pose.pose.position.x = 0;
    uav2_pose.pose.position.y = 0;
    uav2_pose.pose.position.z = 2;

    uav3_pose.pose.position.x = 0;
    uav3_pose.pose.position.y = 0;
    uav3_pose.pose.position.z = 2;

    uav4_pose.pose.position.x = 0;
    uav4_pose.pose.position.y = 0;
    uav4_pose.pose.position.z = 2;

    uav5_pose.pose.position.x = 0;
    uav5_pose.pose.position.y = 0;
    uav5_pose.pose.position.z = 2;

    for (int i = 20; ros::ok() && i > 0; --i){

        uav0_local_pos_pub.publish(uav0_pose);
        uav2_local_pos_pub.publish(uav2_pose);
        uav3_local_pos_pub.publish(uav3_pose);
        uav4_local_pos_pub.publish(uav4_pose);
        uav5_local_pos_pub.publish(uav5_pose);

        ros::spinOnce();
        rate.sleep();
        ROS_INFO("Iteration: %d",i);
    }

    mavros_msgs::SetMode uav0_offb_set_mode;
    mavros_msgs::SetMode uav2_offb_set_mode;
    mavros_msgs::SetMode uav3_offb_set_mode;
    mavros_msgs::SetMode uav4_offb_set_mode;
    mavros_msgs::SetMode uav5_offb_set_mode;

    uav0_offb_set_mode.request.custom_mode = "OFFBOARD";
    uav2_offb_set_mode.request.custom_mode = "OFFBOARD";
    uav3_offb_set_mode.request.custom_mode = "OFFBOARD";
    uav4_offb_set_mode.request.custom_mode = "OFFBOARD";
    uav5_offb_set_mode.request.custom_mode = "OFFBOARD";

    mavros_msgs::CommandBool uav0_arm_cmd;
    mavros_msgs::CommandBool uav2_arm_cmd;
    mavros_msgs::CommandBool uav3_arm_cmd;
    mavros_msgs::CommandBool uav4_arm_cmd;
    mavros_msgs::CommandBool uav5_arm_cmd;

    uav0_arm_cmd.request.value = true;
    uav2_arm_cmd.request.value = true;
    uav3_arm_cmd.request.value = true;
    uav4_arm_cmd.request.value = true;
    uav5_arm_cmd.request.value = true;

    ros::Time last_request = ros::Time::now();


    while (ros::ok()){

        if(uav0_current_state.mode != "OFFBOARD" && uav2_current_state.mode != "OFFBOARD" && uav3_current_state.mode != "OFFBOARD" 
            && uav4_current_state.mode != "OFFBOARD" && uav5_current_state.mode != "OFFBOARD" && (ros::Time::now() - last_request > ros::Duration(5.0))){

            if (uav0_set_mode_client.call(uav0_offb_set_mode) && uav0_offb_set_mode.response.mode_sent){
                ROS_INFO("UAV0_Offboard enabled");
            }
            if (uav2_set_mode_client.call(uav2_offb_set_mode) && uav2_offb_set_mode.response.mode_sent){
                ROS_INFO("UAV2_Offboard enabled");
            }
            if (uav3_set_mode_client.call(uav3_offb_set_mode) && uav3_offb_set_mode.response.mode_sent){
                ROS_INFO("UAV3_Offboard enabled");
            }
            if (uav4_set_mode_client.call(uav4_offb_set_mode) && uav4_offb_set_mode.response.mode_sent){
                ROS_INFO("UAV4_Offboard enabled");
            }
            if (uav5_set_mode_client.call(uav5_offb_set_mode) && uav5_offb_set_mode.response.mode_sent){
                ROS_INFO("UAV5_Offboard enabled");
            }

            last_request = ros::Time::now();

        }

        else{
            if(!uav0_current_state.armed && !uav2_current_state.armed &&  !uav3_current_state.armed && !uav4_current_state.armed && 
                !uav5_current_state.armed && (ros::Time::now() - last_request > ros::Duration(5.0))){

                if(uav0_arming_client.call(uav0_arm_cmd) && uav0_arm_cmd.response.success){
                    ROS_INFO("UAV0_Vehicle armed");
                }

                if(uav2_arming_client.call(uav2_arm_cmd) && uav2_arm_cmd.response.success){
                    ROS_INFO("UAV2_Vehicle armed");
                }

                if(uav3_arming_client.call(uav3_arm_cmd) && uav3_arm_cmd.response.success){
                    ROS_INFO("UAV3_Vehicle armed");
                }

                if(uav4_arming_client.call(uav4_arm_cmd) && uav4_arm_cmd.response.success){
                    ROS_INFO("UAV4_Vehicle armed");
                }

                if(uav5_arming_client.call(uav5_arm_cmd) && uav5_arm_cmd.response.success){
                    ROS_INFO("UAV5_Vehicle armed");
                    break;
                }

                last_request = ros::Time::now();
            }
        }

        ros::spinOnce();
        rate.sleep();
        uav0_local_pos_pub.publish(uav0_pose);
        uav2_local_pos_pub.publish(uav2_pose);
        uav3_local_pos_pub.publish(uav3_pose);
        uav4_local_pos_pub.publish(uav4_pose);
        uav5_local_pos_pub.publish(uav5_pose);

    } 


    
    for (int i = 200; ros::ok() && i > 0; --i){

        uav0_local_pos_pub.publish(uav0_pose);
        uav2_local_pos_pub.publish(uav2_pose);
        uav3_local_pos_pub.publish(uav3_pose);
        uav4_local_pos_pub.publish(uav4_pose);
        uav5_local_pos_pub.publish(uav5_pose);

        ros::spinOnce();
        rate.sleep();
        ROS_INFO("Iterartion: %d",i);

    }

    uav0_pose.pose.position.x = 15;
    uav0_pose.pose.position.y = 0;
    uav0_pose.pose.position.z = 2;

    uav2_pose.pose.position.x = 15;
    uav2_pose.pose.position.y = 0;
    uav2_pose.pose.position.z = 2;

    uav3_pose.pose.position.x = 15;
    uav3_pose.pose.position.y = 0;
    uav3_pose.pose.position.z = 2;

    uav4_pose.pose.position.x = 15;
    uav4_pose.pose.position.y = 0;
    uav4_pose.pose.position.z = 2;

    uav5_pose.pose.position.x = 15;
    uav5_pose.pose.position.y = 0;
    uav5_pose.pose.position.z = 2;

    for (int i = 200; ros::ok() && i > 0; --i){

        uav0_local_pos_pub.publish(uav0_pose);
        uav2_local_pos_pub.publish(uav2_pose);
        uav3_local_pos_pub.publish(uav3_pose);
        uav4_local_pos_pub.publish(uav4_pose);
        uav5_local_pos_pub.publish(uav5_pose);

        ros::spinOnce();
        rate.sleep();
        ROS_INFO("Iterartion: %d",i);

    }

    uav0_pose.pose.orientation.x =  0;
    uav0_pose.pose.orientation.y =  0;
    uav0_pose.pose.orientation.z =  0.707;
    uav0_pose.pose.orientation.w =  0.707;

    uav2_pose.pose.orientation.x =  0;
    uav2_pose.pose.orientation.y =  0;
    uav2_pose.pose.orientation.z =  0.707;
    uav2_pose.pose.orientation.w =  0.707;

    uav3_pose.pose.orientation.x =  0;
    uav3_pose.pose.orientation.y =  0;
    uav3_pose.pose.orientation.z =  0.707;
    uav3_pose.pose.orientation.w =  0.707;

    uav4_pose.pose.orientation.x =  0;
    uav4_pose.pose.orientation.y =  0;
    uav4_pose.pose.orientation.z =  0.707;
    uav4_pose.pose.orientation.w =  0.707;

    uav5_pose.pose.orientation.x =  0;
    uav5_pose.pose.orientation.y =  0;
    uav5_pose.pose.orientation.z =  0.707;
    uav5_pose.pose.orientation.w =  0.707;


    for (int i = 200; ros::ok() && i > 0; --i){

        uav0_local_pos_pub.publish(uav0_pose);
        uav2_local_pos_pub.publish(uav2_pose);
        uav3_local_pos_pub.publish(uav3_pose);
        uav4_local_pos_pub.publish(uav4_pose);
        uav5_local_pos_pub.publish(uav5_pose);
        
        ros::spinOnce();
        rate.sleep();
        ROS_INFO("Iterartion: %d",i);
    }

    uav0_pose.pose.position.x = 15;
    uav0_pose.pose.position.y = 15;
    uav0_pose.pose.position.z = 2;

    uav2_pose.pose.position.x = 15;
    uav2_pose.pose.position.y = 15;
    uav2_pose.pose.position.z = 2;

    uav3_pose.pose.position.x = 15;
    uav3_pose.pose.position.y = 15;
    uav3_pose.pose.position.z = 2;

    uav4_pose.pose.position.x = 15;
    uav4_pose.pose.position.y = 15;
    uav4_pose.pose.position.z = 2;

    uav5_pose.pose.position.x = 15;
    uav5_pose.pose.position.y = 15;
    uav5_pose.pose.position.z = 2;

    for (int i = 200; ros::ok() && i > 0; --i){

        uav0_local_pos_pub.publish(uav0_pose);
        uav2_local_pos_pub.publish(uav2_pose);
        uav3_local_pos_pub.publish(uav3_pose);
        uav4_local_pos_pub.publish(uav4_pose);
        uav5_local_pos_pub.publish(uav5_pose);

        ros::spinOnce();
        rate.sleep();
        ROS_INFO("Iterartion: %d",i);
    }

    uav0_pose.pose.orientation.x =  0;
    uav0_pose.pose.orientation.y =  0;
    uav0_pose.pose.orientation.z =  1;
    uav0_pose.pose.orientation.w =  0;

    uav2_pose.pose.orientation.x =  0;
    uav2_pose.pose.orientation.y =  0;
    uav2_pose.pose.orientation.z =  1;
    uav2_pose.pose.orientation.w =  0;

    uav3_pose.pose.orientation.x =  0;
    uav3_pose.pose.orientation.y =  0;
    uav3_pose.pose.orientation.z =  1;
    uav3_pose.pose.orientation.w =  0;

    uav4_pose.pose.orientation.x =  0;
    uav4_pose.pose.orientation.y =  0;
    uav4_pose.pose.orientation.z =  1;
    uav4_pose.pose.orientation.w =  0;

    uav5_pose.pose.orientation.x =  0;
    uav5_pose.pose.orientation.y =  0;
    uav5_pose.pose.orientation.z =  1;
    uav5_pose.pose.orientation.w =  0;


    for (int i = 200; ros::ok() && i > 0; --i){

        uav0_local_pos_pub.publish(uav0_pose);
        uav2_local_pos_pub.publish(uav2_pose);
        uav3_local_pos_pub.publish(uav3_pose);
        uav4_local_pos_pub.publish(uav4_pose);
        uav5_local_pos_pub.publish(uav5_pose);
        
        ros::spinOnce();
        rate.sleep();
        ROS_INFO("Iterartion: %d",i);
    }

    uav0_pose.pose.position.x = 0;
    uav0_pose.pose.position.y = 15;
    uav0_pose.pose.position.z = 2;

    uav2_pose.pose.position.x = 0;
    uav2_pose.pose.position.y = 15;
    uav2_pose.pose.position.z = 2;

    uav3_pose.pose.position.x = 0;
    uav3_pose.pose.position.y = 15;
    uav3_pose.pose.position.z = 2;

    uav4_pose.pose.position.x = 0;
    uav4_pose.pose.position.y = 15;
    uav4_pose.pose.position.z = 2;

    uav5_pose.pose.position.x = 0;
    uav5_pose.pose.position.y = 15;
    uav5_pose.pose.position.z = 2;


    for (int i = 200; ros::ok() && i > 0; --i){

        uav0_local_pos_pub.publish(uav0_pose);
        uav2_local_pos_pub.publish(uav2_pose);
        uav3_local_pos_pub.publish(uav3_pose);
        uav4_local_pos_pub.publish(uav4_pose);
        uav5_local_pos_pub.publish(uav5_pose);
        
        ros::spinOnce();
        rate.sleep();
        ROS_INFO("Iterartion: %d",i);
    }

    uav0_pose.pose.orientation.x =  0;
    uav0_pose.pose.orientation.y =  0;
    uav0_pose.pose.orientation.z =  -0.707;
    uav0_pose.pose.orientation.w =  0.707;

    uav2_pose.pose.orientation.x =  0;
    uav2_pose.pose.orientation.y =  0;
    uav2_pose.pose.orientation.z =  -0.707;
    uav2_pose.pose.orientation.w =  0.707;

    uav3_pose.pose.orientation.x =  0;
    uav3_pose.pose.orientation.y =  0;
    uav3_pose.pose.orientation.z =  -0.707;
    uav3_pose.pose.orientation.w =  0.707;

    uav4_pose.pose.orientation.x =  0;
    uav4_pose.pose.orientation.y =  0;
    uav4_pose.pose.orientation.z =  -0.707;
    uav4_pose.pose.orientation.w =  0.707;

    uav5_pose.pose.orientation.x =  0;
    uav5_pose.pose.orientation.y =  0;
    uav5_pose.pose.orientation.z =  -0.707;
    uav5_pose.pose.orientation.w =  0.707;

    for (int i = 200; ros::ok() && i > 0; --i){

        uav0_local_pos_pub.publish(uav0_pose);
        uav2_local_pos_pub.publish(uav2_pose);
        uav3_local_pos_pub.publish(uav3_pose);
        uav4_local_pos_pub.publish(uav4_pose);
        uav5_local_pos_pub.publish(uav5_pose);
        
        ros::spinOnce();
        rate.sleep();
        ROS_INFO("Iterartion: %d",i);
    }

    uav0_pose.pose.position.x = 0;
    uav0_pose.pose.position.y = 0;
    uav0_pose.pose.position.z = 2;

    uav2_pose.pose.position.x = 0;
    uav2_pose.pose.position.y = 0;
    uav2_pose.pose.position.z = 2;

    uav3_pose.pose.position.x = 0;
    uav3_pose.pose.position.y = 0;
    uav3_pose.pose.position.z = 2;

    uav4_pose.pose.position.x = 0;
    uav4_pose.pose.position.y = 0;
    uav4_pose.pose.position.z = 2;

    uav5_pose.pose.position.x = 0;
    uav5_pose.pose.position.y = 0;
    uav5_pose.pose.position.z = 2;


    for (int i = 200; ros::ok() && i > 0; --i){

        uav0_local_pos_pub.publish(uav0_pose);
        uav2_local_pos_pub.publish(uav2_pose);
        uav3_local_pos_pub.publish(uav3_pose);
        uav4_local_pos_pub.publish(uav4_pose);
        uav5_local_pos_pub.publish(uav5_pose);
        
        ros::spinOnce();
        rate.sleep();
        ROS_INFO("Iterartion: %d",i);
    }

    uav0_pose.pose.orientation.x =  0;
    uav0_pose.pose.orientation.y =  0;
    uav0_pose.pose.orientation.z =  0;
    uav0_pose.pose.orientation.w =  0;

    uav2_pose.pose.orientation.x =  0;
    uav2_pose.pose.orientation.y =  0;
    uav2_pose.pose.orientation.z =  0;
    uav2_pose.pose.orientation.w =  0;

    uav3_pose.pose.orientation.x =  0;
    uav3_pose.pose.orientation.y =  0;
    uav3_pose.pose.orientation.z =  0;
    uav3_pose.pose.orientation.w =  0;

    uav4_pose.pose.orientation.x =  0;
    uav4_pose.pose.orientation.y =  0;
    uav4_pose.pose.orientation.z =  0;
    uav4_pose.pose.orientation.w =  0;

    uav5_pose.pose.orientation.x =  0;
    uav5_pose.pose.orientation.y =  0;
    uav5_pose.pose.orientation.z =  0;
    uav5_pose.pose.orientation.w =  0;


    for (int i = 200; ros::ok() && i > 0; --i){

        uav0_local_pos_pub.publish(uav0_pose);
        uav2_local_pos_pub.publish(uav2_pose);
        uav3_local_pos_pub.publish(uav3_pose);
        uav4_local_pos_pub.publish(uav4_pose);
        uav5_local_pos_pub.publish(uav5_pose);
        
        ros::spinOnce();
        rate.sleep();
        ROS_INFO("Iterartion: %d",i);
    }

    // landing
    uav0_pose.pose.position.x = 0;
    uav0_pose.pose.position.y = 0;
    uav0_pose.pose.position.z = -0.2;

    for (int i = 200; ros::ok() && i > 0; --i){

        uav0_local_pos_pub.publish(uav0_pose);
        uav2_local_pos_pub.publish(uav2_pose);
        uav3_local_pos_pub.publish(uav3_pose);
        uav4_local_pos_pub.publish(uav4_pose);
        uav5_local_pos_pub.publish(uav5_pose);
        
        ros::spinOnce();
        rate.sleep();
        ROS_INFO("Iterartion: %d",i);
    }

    return 0;

}