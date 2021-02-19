#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/State.h>
#include <mavros_msgs/ParamGet.h>
#include <mavros_msgs/ParamSet.h>

#include <iostream>

using namespace std;

mavros_msgs::State current_state;

void state_callback(const mavros_msgs::State::ConstPtr& msg){

    current_state = *msg;
}

int main (int argc, char **argv) 
{

    ros::init(argc, argv, "square_waypoint");
    ros::NodeHandle nh; 

    ros::Subscriber state_sub = nh.subscribe<mavros_msgs::State>("uav0/mavros/state", 10, state_callback); // 10 is buffer size
    ros::Publisher local_pos_pub = nh.advertise<geometry_msgs::PoseStamped>("uav0/mavros/setpoint_position/local", 10);

    ros::ServiceClient arming_client = nh.serviceClient<mavros_msgs::CommandBool>("uav0/mavros/cmd/arming");
    ros::ServiceClient set_mode_client = nh.serviceClient<mavros_msgs::SetMode>("uav0/mavros/set_mode");

    // ros::ServiceClient param_get = nh.serviceClient<mavros_msgs::ParamGet>("uav0/mavros/param/get");
    // ros::ServiceClient param_set = nh.serviceClient<mavros_msgs::ParamSet>("uav0/mavros/param/set");

    // // READ disable Failsafe
    // mavros_msgs::ParamGet nav_dll_act;
    // nav_dll_act.request.param_id = "NAV_DLL_ACT";
    // param_get.call(nav_dll_act);

    // mavros_msgs::ParamGet nav_rcl_act;
    // nav_rcl_act.request.param_id = "NAV_RCL_ACT";
    // param_get.call(nav_rcl_act);

    // ROS_INFO("response_dll_int: %d", nav_dll_act.response.value);

    // // ROS_INFO("response_dll_int: %d",(int)nav_dll_act.response.value.integer);
    // // ROS_INFO("response_dll_real: %f",(double)nav_dll_act.response.value.real);

    // // ROS_INFO("response_rcl_int: %d",(int)nav_rcl_act.response.value.integer);
    // // ROS_INFO("response_rcl_real: %f",(double)nav_rcl_act.response.value.real);


    // // Write disable Failsafe
    // mavros_msgs::ParamSet new_nav_dll_act;
    // new_nav_dll_act.request.param_id = "NAV_DLL_ACT";
    // new_nav_dll_act.request.value.integer = 0;
    // new_nav_dll_act.request.value.real = 0.0;
    // param_set.call(new_nav_dll_act);

    // mavros_msgs::ParamSet new_nav_rcl_act;
    // new_nav_rcl_act.request.param_id = "NAV_RCL_ACT";
    // new_nav_rcl_act.request.value.integer = 0;
    // new_nav_rcl_act.request.value.real = 0.0;
    // param_set.call(new_nav_rcl_act);


    // ROS_INFO("new_response_dll_int: %d", new_nav_dll_act.response.value);
    // // ROS_INFO("new_response_dll_real: %f", new_nav_dll_act.response.value.real);

    // ROS_INFO("new_response_rcl_int: %d", new_nav_rcl_act.response.value);
    // // ROS_INFO("new_response_rcl_real: %f", new_nav_rcl_act.response.value.real);


    ros::Rate rate(20.0);

    while (ros::ok() && !current_state.connected){
        ros::spinOnce();
        rate.sleep();
    }

    geometry_msgs::PoseStamped pose;

    pose.pose.position.x = 0;
    pose.pose.position.y = 0;
    pose.pose.position.z = 2;

    for (int i = 20; ros::ok() && i > 0; --i){

        local_pos_pub.publish(pose);
        ros::spinOnce();
        rate.sleep();
        ROS_INFO("Iterartion: %d",i);
    }

    mavros_msgs::SetMode offb_set_mode;
    offb_set_mode.request.custom_mode = "OFFBOARD";

    mavros_msgs::CommandBool arm_cmd;
    arm_cmd.request.value = true;

    ros::Time last_request = ros::Time::now();

    int iteration = 0;

    while (ros::ok()){

        if(current_state.mode != "OFFBOARD" && (ros::Time::now() - last_request > ros::Duration(5.0))){
            if (set_mode_client.call(offb_set_mode) && offb_set_mode.response.mode_sent){
                ROS_INFO("Offboard enabled");
            }
            last_request = ros::Time::now();
        }
        else{
            if(!current_state.armed && (ros::Time::now() - last_request > ros::Duration(5.0))){
                if(arming_client.call(arm_cmd) && arm_cmd.response.success){
                    ROS_INFO("Vehicle armed");
                    break;
                }
                last_request = ros::Time::now();
            }
        }

        ros::spinOnce();
        rate.sleep();
        local_pos_pub.publish(pose);

    } 
    
    for (int i = 200; ros::ok() && i > 0; --i){

        local_pos_pub.publish(pose);
        ros::spinOnce();
        rate.sleep();
        ROS_INFO("Iterartion: %d",i);

    }


    pose.pose.position.x = 5;
    pose.pose.position.y = 0;
    pose.pose.position.z = 2;

    for (int i = 200; ros::ok() && i > 0; --i){

        local_pos_pub.publish(pose);
        ros::spinOnce();
        rate.sleep();
        ROS_INFO("Iterartion: %d",i);

    }

    pose.pose.position.x = 5;
    pose.pose.position.y = 0;
    pose.pose.position.z = 2;

    pose.pose.orientation.x =  0;
    pose.pose.orientation.y =  0;
    pose.pose.orientation.z =  0.707;
    pose.pose.orientation.w =  0.707;

    for (int i = 200; ros::ok() && i > 0; --i){

        local_pos_pub.publish(pose);
        ros::spinOnce();
        rate.sleep();
        ROS_INFO("Iterartion: %d",i);
    }

    pose.pose.position.x = 5;
    pose.pose.position.y = 5;
    pose.pose.position.z = 2;

    pose.pose.orientation.x =  0;
    pose.pose.orientation.y =  0;
    pose.pose.orientation.z =  0.707;
    pose.pose.orientation.w =  0.707;


    for (int i = 200; ros::ok() && i > 0; --i){

        local_pos_pub.publish(pose);
        ros::spinOnce();
        rate.sleep();
        ROS_INFO("Iterartion: %d",i);
    }


    pose.pose.position.x = 5;
    pose.pose.position.y = 5;
    pose.pose.position.z = 2;

    pose.pose.orientation.x =  0;
    pose.pose.orientation.y =  0;
    pose.pose.orientation.z =  1;
    pose.pose.orientation.w =  0;


    for (int i = 200; ros::ok() && i > 0; --i){

        local_pos_pub.publish(pose);
        ros::spinOnce();
        rate.sleep();
        ROS_INFO("Iterartion: %d",i);
    }


    pose.pose.position.x = 0;
    pose.pose.position.y = 5;
    pose.pose.position.z = 2;

    pose.pose.orientation.x =  0;
    pose.pose.orientation.y =  0;
    pose.pose.orientation.z =  1;
    pose.pose.orientation.w =  0;


    for (int i = 200; ros::ok() && i > 0; --i){

        local_pos_pub.publish(pose);
        ros::spinOnce();
        rate.sleep();
        ROS_INFO("Iterartion: %d",i);
    }


    pose.pose.position.x = 0;
    pose.pose.position.y = 5;
    pose.pose.position.z = 2;

    pose.pose.orientation.x =  0;
    pose.pose.orientation.y =  0;
    pose.pose.orientation.z =  -0.707;
    pose.pose.orientation.w =  0.707;


    for (int i = 200; ros::ok() && i > 0; --i){

        local_pos_pub.publish(pose);
        ros::spinOnce();
        rate.sleep();
        ROS_INFO("Iterartion: %d",i);
    }


    pose.pose.position.x = 0;
    pose.pose.position.y = 0;
    pose.pose.position.z = 2;

    pose.pose.orientation.x =  0;
    pose.pose.orientation.y =  0;
    pose.pose.orientation.z =  -0.707;
    pose.pose.orientation.w =  0.707;


    for (int i = 200; ros::ok() && i > 0; --i){

        local_pos_pub.publish(pose);
        ros::spinOnce();
        rate.sleep();
        ROS_INFO("Iterartion: %d",i);
    }

    pose.pose.position.x = 0;
    pose.pose.position.y = 0;
    pose.pose.position.z = 2;

    pose.pose.orientation.x =  0;
    pose.pose.orientation.y =  0;
    pose.pose.orientation.z =  0;
    pose.pose.orientation.w =  0;


    for (int i = 200; ros::ok() && i > 0; --i){

        local_pos_pub.publish(pose);
        ros::spinOnce();
        rate.sleep();
        ROS_INFO("Iterartion: %d",i);
    }

    // landing
    pose.pose.position.x = 0;
    pose.pose.position.y = 0;
    pose.pose.position.z = -0.1;

    pose.pose.orientation.x =  0;
    pose.pose.orientation.y =  0;
    pose.pose.orientation.z =  0;
    pose.pose.orientation.w =  0;


    for (int i = 200; ros::ok() && i > 0; --i){

        local_pos_pub.publish(pose);
        ros::spinOnce();
        rate.sleep();
        ROS_INFO("Iterartion: %d",i);
    }

    return 0;

}