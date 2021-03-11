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


}

#endif