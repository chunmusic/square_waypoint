#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <iostream>
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/State.h>
#include <mavros_msgs/ParamGet.h>
#include <mavros_msgs/ParamSet.h>

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

    ros::Subscriber uav2_state_sub = nh.subscribe<mavros_msgs::State>("uav2/mavros/state", 10, uav2_state_callback); // 10 is buffer size
    ros::Subscriber uav3_state_sub = nh.subscribe<mavros_msgs::State>("uav3/mavros/state", 10, uav3_state_callback); // 10 is buffer size
    ros::Subscriber uav4_state_sub = nh.subscribe<mavros_msgs::State>("uav4/mavros/state", 10, uav4_state_callback); // 10 is buffer size
    ros::Subscriber uav5_state_sub = nh.subscribe<mavros_msgs::State>("uav5/mavros/state", 10, uav5_state_callback); // 10 is buffer size
    

    std::array<ros::Publisher, 6> uav_local_pos_pub;

    std::array<ros::ServiceClient, 6> uav_arming_client;
    std::array<ros::ServiceClient, 6> uav_set_mode_client;

    std::array<mavros_msgs::SetMode, 6> uav_offb_set_mode;
    std::array<mavros_msgs::CommandBool, 6> uav_arm_cmd;


    for (int i=0; i < uav_local_pos_pub.size(); ++i)
    {
        uav_local_pos_pub[i] = nh.advertise<geometry_msgs::PoseStamped>("uav" + to_string(i) + "/mavros/setpoint_position/local", 10);
        uav_arming_client[i] = nh.serviceClient<mavros_msgs::CommandBool>("uav"+ to_string(i) +"/mavros/cmd/arming");
        uav_set_mode_client[i] = nh.serviceClient<mavros_msgs::SetMode>("uav"+ to_string(i) +"/mavros/set_mode");
        uav_offb_set_mode[i];
        uav_arm_cmd[i];
    }
    
    cout << "CHECKPOINT";

    ros::Rate rate(20.0);

    while (ros::ok() && !uav0_current_state.connected
                && !uav2_current_state.connected && !uav3_current_state.connected && !uav4_current_state.connected && !uav5_current_state.connected)

    {

        ros::spinOnce();
        rate.sleep();
    }
    
    std::array<geometry_msgs::PoseStamped, 6> uav_pose;

    for (int i=0; i <uav_pose.size(); ++i){

        uav_pose[i].pose.position.x = 0;
        uav_pose[i].pose.position.y = 0;
        uav_pose[i].pose.position.z = 2;
    }

    for (int i = 20; ros::ok() && i > 0; --i){
        
        for (int j = 0; j<6; ++j){
            uav_local_pos_pub[j].publish(uav_pose[j]);
        }

        ros::spinOnce();
        rate.sleep();
        ROS_INFO("Iteration: %d",i);
    }

    for (int i = 0; i<uav_offb_set_mode.size(); ++i){

        uav_offb_set_mode[i].request.custom_mode = "OFFBOARD";

    }

    for (int i = 0; i<uav_offb_set_mode.size(); ++i){

        uav_arm_cmd[i].request.value = true;

    }

    ros::Time last_request = ros::Time::now();


    while (ros::ok()){

        if(uav0_current_state.mode != "OFFBOARD"
            && uav2_current_state.mode != "OFFBOARD" && uav3_current_state.mode != "OFFBOARD" && uav4_current_state.mode != "OFFBOARD" && uav5_current_state.mode != "OFFBOARD"
            && (ros::Time::now() - last_request > ros::Duration(5.0))){

            for (int i = 0; i < 6; ++i)
            {
                if (uav_set_mode_client[i].call(uav_offb_set_mode[i]) && uav_offb_set_mode[i].response.mode_sent){
                    ROS_INFO_STREAM("UAV" + to_string(i) + "_Offboard enabled");
                }
            }
            

            last_request = ros::Time::now();

        }

        else{
            if(!uav0_current_state.armed
                && !uav2_current_state.armed &&  !uav3_current_state.armed && !uav4_current_state.armed && !uav5_current_state.armed 

                && (ros::Time::now() - last_request > ros::Duration(5.0))){

                for (int i = 0; i < 6; ++i)
                {
                    if(uav_arming_client[i].call(uav_arm_cmd[i]) && uav_arm_cmd[i].response.success){
                        ROS_INFO_STREAM("UAV" + to_string(i) + "_Vehicle armed");
                    }

                }

                last_request = ros::Time::now();
                break;
            }
        }

        ros::spinOnce();
        rate.sleep();

        for (int i = 0; i < 6; ++i)
        {
            uav_local_pos_pub[i].publish(uav_pose[i]);
        }

        ros::spinOnce();
        rate.sleep();

    } 
    
    for (int i = 40; ros::ok() && i > 0; --i){

        for (int i = 0; i < 6; ++i)
        {
            uav_local_pos_pub[i].publish(uav_pose[i]);
        }

        ros::spinOnce();
        rate.sleep();
        ROS_INFO("Iterartion: %d",i);

    }

    for (int i=0; i <uav_pose.size(); ++i){

        uav_pose[i].pose.position.x = 2;
        uav_pose[i].pose.position.y = 0;
        uav_pose[i].pose.position.z = 2;
    }


    for (int i = 40; ros::ok() && i > 0; --i){

        for (int i = 0; i < 6; ++i)
        {
            uav_local_pos_pub[i].publish(uav_pose[i]);
        }

        ros::spinOnce();
        rate.sleep();
        ROS_INFO("Iterartion: %d",i);

    }

    for (int i=0; i <uav_pose.size(); ++i){

        uav_pose[i].pose.orientation.x =  0;
        uav_pose[i].pose.orientation.y =  0;
        uav_pose[i].pose.orientation.z =  0.707;
        uav_pose[i].pose.orientation.w =  0.707;
    }

    for (int i = 40; ros::ok() && i > 0; --i){

        for (int i = 0; i < 6; ++i)
        {
            uav_local_pos_pub[i].publish(uav_pose[i]);
        }

        ros::spinOnce();
        rate.sleep();
        ROS_INFO("Iterartion: %d",i);

    }

    for (int i=0; i <uav_pose.size(); ++i){

        uav_pose[i].pose.position.x = 2;
        uav_pose[i].pose.position.y = 2;
        uav_pose[i].pose.position.z = 2;
    }


    for (int i = 40; ros::ok() && i > 0; --i){

        for (int i = 0; i < 6; ++i)
        {
            uav_local_pos_pub[i].publish(uav_pose[i]);
        }

        ros::spinOnce();
        rate.sleep();
        ROS_INFO("Iterartion: %d",i);

    }


    for (int i=0; i <uav_pose.size(); ++i){

        uav_pose[i].pose.orientation.x =  0;
        uav_pose[i].pose.orientation.y =  0;
        uav_pose[i].pose.orientation.z =  1;
        uav_pose[i].pose.orientation.w =  0;
    }

    for (int i = 40; ros::ok() && i > 0; --i){

        for (int i = 0; i < 6; ++i)
        {
            uav_local_pos_pub[i].publish(uav_pose[i]);
        }

        ros::spinOnce();
        rate.sleep();
        ROS_INFO("Iterartion: %d",i);

    }

    for (int i=0; i <uav_pose.size(); ++i){

        uav_pose[i].pose.position.x = 0;
        uav_pose[i].pose.position.y = 2;
        uav_pose[i].pose.position.z = 2;
    }


    for (int i = 40; ros::ok() && i > 0; --i){

        for (int i = 0; i < 6; ++i)
        {
            uav_local_pos_pub[i].publish(uav_pose[i]);
        }

        ros::spinOnce();
        rate.sleep();
        ROS_INFO("Iterartion: %d",i);

    }

    for (int i=0; i <uav_pose.size(); ++i){

        uav_pose[i].pose.orientation.x =  0;
        uav_pose[i].pose.orientation.y =  0;
        uav_pose[i].pose.orientation.z =  -0.707;
        uav_pose[i].pose.orientation.w =  0.707;
    }

    for (int i = 40; ros::ok() && i > 0; --i){

        for (int i = 0; i < 6; ++i)
        {
            uav_local_pos_pub[i].publish(uav_pose[i]);
        }

        ros::spinOnce();
        rate.sleep();
        ROS_INFO("Iterartion: %d",i);

    }

    for (int i=0; i <uav_pose.size(); ++i){

        uav_pose[i].pose.position.x = 0;
        uav_pose[i].pose.position.y = 0;
        uav_pose[i].pose.position.z = 2;
    }


    for (int i = 40; ros::ok() && i > 0; --i){

        for (int i = 0; i < 6; ++i)
        {
            uav_local_pos_pub[i].publish(uav_pose[i]);
        }

        ros::spinOnce();
        rate.sleep();
        ROS_INFO("Iterartion: %d",i);

    }

    for (int i=0; i <uav_pose.size(); ++i){

        uav_pose[i].pose.orientation.x =  0;
        uav_pose[i].pose.orientation.y =  0;
        uav_pose[i].pose.orientation.z =  0;
        uav_pose[i].pose.orientation.w =  0;
    }

    for (int i = 40; ros::ok() && i > 0; --i){

        for (int i = 0; i < 6; ++i)
        {
            uav_local_pos_pub[i].publish(uav_pose[i]);
        }

        ros::spinOnce();
        rate.sleep();
        ROS_INFO("Iterartion: %d",i);

    }

    for (int i=0; i <uav_pose.size(); ++i){

        uav_pose[i].pose.position.x = 0;
        uav_pose[i].pose.position.y = 0;
        uav_pose[i].pose.position.z = -0.4;
    }

    for (int i = 40; ros::ok() && i > 0; --i){

        for (int i = 0; i < 6; ++i)
        {
            uav_local_pos_pub[i].publish(uav_pose[i]);
        }

        ros::spinOnce();
        rate.sleep();
        ROS_INFO("Iterartion: %d",i);

    }
    
    return 0;

}