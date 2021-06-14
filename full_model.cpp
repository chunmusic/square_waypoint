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
mavros_msgs::State uav1_current_state;
mavros_msgs::State uav6_current_state;
mavros_msgs::State uav11_current_state;
mavros_msgs::State uav16_current_state;

mavros_msgs::State uav2_current_state;
mavros_msgs::State uav3_current_state;
mavros_msgs::State uav4_current_state;
mavros_msgs::State uav5_current_state;

mavros_msgs::State uav7_current_state;
mavros_msgs::State uav8_current_state;
mavros_msgs::State uav9_current_state;
mavros_msgs::State uav10_current_state;

mavros_msgs::State uav12_current_state;
mavros_msgs::State uav13_current_state;
mavros_msgs::State uav14_current_state;
mavros_msgs::State uav15_current_state;

mavros_msgs::State uav17_current_state;
mavros_msgs::State uav18_current_state;
mavros_msgs::State uav19_current_state;
mavros_msgs::State uav20_current_state;

void uav0_state_callback(const mavros_msgs::State::ConstPtr& msg){

    uav0_current_state = *msg;
}
void uav1_state_callback(const mavros_msgs::State::ConstPtr& msg){

    uav1_current_state = *msg;
}
void uav6_state_callback(const mavros_msgs::State::ConstPtr& msg){

    uav6_current_state = *msg;
}
void uav11_state_callback(const mavros_msgs::State::ConstPtr& msg){

    uav11_current_state = *msg;
}
void uav16_state_callback(const mavros_msgs::State::ConstPtr& msg){

    uav16_current_state = *msg;
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


void uav7_state_callback(const mavros_msgs::State::ConstPtr& msg){

    uav7_current_state = *msg;
}

void uav8_state_callback(const mavros_msgs::State::ConstPtr& msg){

    uav8_current_state = *msg;
}

void uav9_state_callback(const mavros_msgs::State::ConstPtr& msg){

    uav9_current_state = *msg;
}

void uav10_state_callback(const mavros_msgs::State::ConstPtr& msg){

    uav10_current_state = *msg;
}

void uav12_state_callback(const mavros_msgs::State::ConstPtr& msg){

    uav12_current_state = *msg;
}

void uav13_state_callback(const mavros_msgs::State::ConstPtr& msg){

    uav13_current_state = *msg;
}

void uav14_state_callback(const mavros_msgs::State::ConstPtr& msg){

    uav14_current_state = *msg;
}

void uav15_state_callback(const mavros_msgs::State::ConstPtr& msg){

    uav15_current_state = *msg;
}

void uav17_state_callback(const mavros_msgs::State::ConstPtr& msg){

    uav17_current_state = *msg;
}

void uav18_state_callback(const mavros_msgs::State::ConstPtr& msg){

    uav18_current_state = *msg;
}

void uav19_state_callback(const mavros_msgs::State::ConstPtr& msg){

    uav19_current_state = *msg;
}

void uav20_state_callback(const mavros_msgs::State::ConstPtr& msg){

    uav20_current_state = *msg;
}


int main (int argc, char **argv) 
{

    ros::init(argc, argv, "one_unit");
    ros::NodeHandle nh; 

    ros::Subscriber uav0_state_sub = nh.subscribe<mavros_msgs::State>("uav0/mavros/state", 10, uav0_state_callback); // 10 is buffer size
    ros::Subscriber uav1_state_sub = nh.subscribe<mavros_msgs::State>("uav1/mavros/state", 10, uav1_state_callback); // 10 is buffer size
    ros::Subscriber uav6_state_sub = nh.subscribe<mavros_msgs::State>("uav6/mavros/state", 10, uav6_state_callback); // 10 is buffer size
    ros::Subscriber uav11_state_sub = nh.subscribe<mavros_msgs::State>("uav11/mavros/state", 10, uav11_state_callback); // 10 is buffer size
    ros::Subscriber uav16_state_sub = nh.subscribe<mavros_msgs::State>("uav16/mavros/state", 10, uav16_state_callback); // 10 is buffer size
    
    ros::Subscriber uav2_state_sub = nh.subscribe<mavros_msgs::State>("uav2/mavros/state", 10, uav2_state_callback); // 10 is buffer size
    ros::Subscriber uav3_state_sub = nh.subscribe<mavros_msgs::State>("uav3/mavros/state", 10, uav3_state_callback); // 10 is buffer size
    ros::Subscriber uav4_state_sub = nh.subscribe<mavros_msgs::State>("uav4/mavros/state", 10, uav4_state_callback); // 10 is buffer size
    ros::Subscriber uav5_state_sub = nh.subscribe<mavros_msgs::State>("uav5/mavros/state", 10, uav5_state_callback); // 10 is buffer size
    
    ros::Subscriber uav7_state_sub = nh.subscribe<mavros_msgs::State>("uav7/mavros/state", 10, uav7_state_callback); // 10 is buffer size
    ros::Subscriber uav8_state_sub = nh.subscribe<mavros_msgs::State>("uav8/mavros/state", 10, uav8_state_callback); // 10 is buffer size
    ros::Subscriber uav9_state_sub = nh.subscribe<mavros_msgs::State>("uav9/mavros/state", 10, uav9_state_callback); // 10 is buffer size
    ros::Subscriber uav10_state_sub = nh.subscribe<mavros_msgs::State>("uav10/mavros/state", 10, uav10_state_callback); // 10 is buffer size

    ros::Subscriber uav12_state_sub = nh.subscribe<mavros_msgs::State>("uav12/mavros/state", 10, uav12_state_callback); // 10 is buffer size
    ros::Subscriber uav13_state_sub = nh.subscribe<mavros_msgs::State>("uav13/mavros/state", 10, uav13_state_callback); // 10 is buffer size
    ros::Subscriber uav14_state_sub = nh.subscribe<mavros_msgs::State>("uav14/mavros/state", 10, uav14_state_callback); // 10 is buffer size
    ros::Subscriber uav15_state_sub = nh.subscribe<mavros_msgs::State>("uav15/mavros/state", 10, uav15_state_callback); // 10 is buffer size

    ros::Subscriber uav17_state_sub = nh.subscribe<mavros_msgs::State>("uav17/mavros/state", 10, uav17_state_callback); // 10 is buffer size
    ros::Subscriber uav18_state_sub = nh.subscribe<mavros_msgs::State>("uav18/mavros/state", 10, uav18_state_callback); // 10 is buffer size
    ros::Subscriber uav19_state_sub = nh.subscribe<mavros_msgs::State>("uav19/mavros/state", 10, uav19_state_callback); // 10 is buffer size
    ros::Subscriber uav20_state_sub = nh.subscribe<mavros_msgs::State>("uav20/mavros/state", 10, uav20_state_callback); // 10 is buffer size


    std::array<ros::Publisher, 21> uav_local_pos_pub;

    std::array<ros::ServiceClient, 21> uav_arming_client;
    std::array<ros::ServiceClient, 21> uav_set_mode_client;

    std::array<mavros_msgs::SetMode, 21> uav_offb_set_mode;
    std::array<mavros_msgs::CommandBool, 21> uav_arm_cmd;


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

    while (ros::ok() && !uav0_current_state.connected && !uav1_current_state.connected && !uav6_current_state.connected
                && !uav11_current_state.connected && !uav16_current_state.connected 
                && !uav2_current_state.connected && !uav3_current_state.connected && !uav4_current_state.connected && !uav5_current_state.connected
                && !uav7_current_state.connected && !uav8_current_state.connected && !uav9_current_state.connected && !uav10_current_state.connected
                && !uav12_current_state.connected && !uav13_current_state.connected && !uav14_current_state.connected && !uav15_current_state.connected
                && !uav17_current_state.connected && !uav18_current_state.connected && !uav19_current_state.connected && !uav20_current_state.connected)

    {

        ros::spinOnce();
        rate.sleep();
    }
    
    std::array<geometry_msgs::PoseStamped, 21> uav_pose;

    for (int i=0; i <uav_pose.size(); ++i){

        uav_pose[i].pose.position.x = 0;
        uav_pose[i].pose.position.y = 0;
        uav_pose[i].pose.position.z = 4;
    }

    for (int i = 20; ros::ok() && i > 0; --i){
        
        for (int j = 0; j<21; ++j){
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

        if(uav0_current_state.mode != "OFFBOARD" && uav1_current_state.mode != "OFFBOARD" && uav6_current_state.mode != "OFFBOARD" 
            && uav11_current_state.mode != "OFFBOARD" && uav16_current_state.mode != "OFFBOARD" 
            && uav2_current_state.mode != "OFFBOARD" && uav3_current_state.mode != "OFFBOARD" && uav4_current_state.mode != "OFFBOARD" && uav5_current_state.mode != "OFFBOARD"
            && uav7_current_state.mode != "OFFBOARD" && uav8_current_state.mode != "OFFBOARD" && uav9_current_state.mode != "OFFBOARD" && uav10_current_state.mode != "OFFBOARD"
            && uav12_current_state.mode != "OFFBOARD" && uav13_current_state.mode != "OFFBOARD" && uav14_current_state.mode != "OFFBOARD" && uav15_current_state.mode != "OFFBOARD"
            && uav17_current_state.mode != "OFFBOARD" && uav18_current_state.mode != "OFFBOARD" && uav19_current_state.mode != "OFFBOARD" && uav20_current_state.mode != "OFFBOARD"
            && (ros::Time::now() - last_request > ros::Duration(5.0))){

            for (int i = 0; i < 21; ++i)
            {
                if (uav_set_mode_client[i].call(uav_offb_set_mode[i]) && uav_offb_set_mode[i].response.mode_sent){
                    ROS_INFO_STREAM("UAV" + to_string(i) + "_Offboard enabled");
                }
            }
            

            last_request = ros::Time::now();

        }

        else{
            if(!uav0_current_state.armed && !uav1_current_state.armed &&  !uav6_current_state.armed && !uav11_current_state.armed && !uav16_current_state.armed 
                && !uav2_current_state.armed &&  !uav3_current_state.armed && !uav4_current_state.armed && !uav5_current_state.armed 
                && !uav7_current_state.armed &&  !uav8_current_state.armed && !uav9_current_state.armed && !uav10_current_state.armed 
                && !uav12_current_state.armed &&  !uav13_current_state.armed && !uav14_current_state.armed && !uav15_current_state.armed 
                && !uav17_current_state.armed &&  !uav18_current_state.armed && !uav19_current_state.armed && !uav20_current_state.armed 
                && (ros::Time::now() - last_request > ros::Duration(5.0))){

                for (int i = 0; i < 21; ++i)
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

        for (int i = 0; i < 21; ++i)
        {
            uav_local_pos_pub[i].publish(uav_pose[i]);
        }

        ros::spinOnce();
        rate.sleep();

    } 
    
    for (int i = 600; ros::ok() && i > 0; --i){

        for (int i = 0; i < 21; ++i)
        {
            uav_local_pos_pub[i].publish(uav_pose[i]);
        }

        ros::spinOnce();
        rate.sleep();
        ROS_INFO("Iterartion: %d",i);

    }

    for (int i=0; i <uav_pose.size(); ++i){

        uav_pose[i].pose.position.x = 5;
        uav_pose[i].pose.position.y = 0;
        uav_pose[i].pose.position.z = 4;
    }


    for (int i = 600; ros::ok() && i > 0; --i){

        for (int i = 0; i < 21; ++i)
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

    for (int i = 600; ros::ok() && i > 0; --i){

        for (int i = 0; i < 21; ++i)
        {
            uav_local_pos_pub[i].publish(uav_pose[i]);
        }

        ros::spinOnce();
        rate.sleep();
        ROS_INFO("Iterartion: %d",i);

    }

    for (int i=0; i <uav_pose.size(); ++i){

        uav_pose[i].pose.position.x = 5;
        uav_pose[i].pose.position.y = 5;
        uav_pose[i].pose.position.z = 4;
    }


    for (int i = 600; ros::ok() && i > 0; --i){

        for (int i = 0; i < 21; ++i)
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

    for (int i = 600; ros::ok() && i > 0; --i){

        for (int i = 0; i < 21; ++i)
        {
            uav_local_pos_pub[i].publish(uav_pose[i]);
        }

        ros::spinOnce();
        rate.sleep();
        ROS_INFO("Iterartion: %d",i);

    }

    for (int i=0; i <uav_pose.size(); ++i){

        uav_pose[i].pose.position.x = 0;
        uav_pose[i].pose.position.y = 5;
        uav_pose[i].pose.position.z = 4;
    }


    for (int i = 600; ros::ok() && i > 0; --i){

        for (int i = 0; i < 21; ++i)
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

    for (int i = 600; ros::ok() && i > 0; --i){

        for (int i = 0; i < 21; ++i)
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
        uav_pose[i].pose.position.z = 4;
    }


    for (int i = 600; ros::ok() && i > 0; --i){

        for (int i = 0; i < 21; ++i)
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

    for (int i = 600; ros::ok() && i > 0; --i){

        for (int i = 0; i < 21; ++i)
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

    for (int i = 600; ros::ok() && i > 0; --i){

        for (int i = 0; i < 21; ++i)
        {
            uav_local_pos_pub[i].publish(uav_pose[i]);
        }

        ros::spinOnce();
        rate.sleep();
        ROS_INFO("Iterartion: %d",i);

    }
    
    return 0;

}