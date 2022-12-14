#include <ros/ros.h>
#include <serial/serial.h>
#include <std_msgs/String.h>
#include <std_msgs/Empty.h>
#include <string>
#include <memory.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <sstream>
#include "LF/MsgDetect.h"
//#include "LF/MsgDetect2.h"

serial::Serial ser;

void write_callback(const std_msgs::String::ConstPtr& msg){
    ROS_INFO_STREAM("Writing to serial port" << msg->data);
    ser.write(msg->data);
}

int main (int argc, char** argv){
    ros::init(argc, argv, "serial_example_node");
    ros::NodeHandle nh;

    //ros::Subscriber write_sub = nh.subscribe("write", 1000, write_callback);
    ros::Publisher uart_pub = nh.advertise<LF::MsgDetect>("data_detect", 100);
    //ros::Publisher uart_pub2 = nh.advertise<LF::MsgDetect>("data_detect2", 100);
    LF::MsgDetect msg;

    try
    {
        ser.setPort("/dev/ttyUSB0");
        ser.setBaudrate(9600);
        serial::Timeout to = serial::Timeout::simpleTimeout(1000);
        ser.setTimeout(to);
        ser.open();
    }
    catch (serial::IOException& e)
    {
        ROS_ERROR_STREAM("Unable to open port ");
        return -1;
    }

    if(ser.isOpen()){
        ROS_INFO_STREAM("Serial Port initialized");
    }else{
        return -1;
    }

    ros::Rate loop_rate(10);
    while(ros::ok()){
        std::string result;
        ros::spinOnce();

	msg.detect = 0;
        if(ser.available()){
            ROS_INFO_STREAM("Reading from serial port");
            result = ser.read(ser.available());
            result = result.front();
            //ROS_INFO_STREAM("Read: " << result);
            std::stringstream sslnt(result);
            sslnt >> msg.detect;
            //ROS_INFO_STREAM("Read: " << msg.detect);
            
        }
	
	ROS_INFO("Read : %d", msg.detect);
	uart_pub.publish(msg);
	//uart_pub2.publish(msg);
        loop_rate.sleep();

    }
}

