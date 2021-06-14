#ifndef FULL_MODEL
#define FULL_MODEL



#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/State.h>
#include <mavros_msgs/ParamGet.h>
#include <mavros_msgs/ParamSet.h>

class fullmodel
{
private:

    
public:

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


#endif