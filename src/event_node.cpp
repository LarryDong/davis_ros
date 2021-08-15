
#include <iostream>

#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>

#include <dvs_msgs/EventArray.h>

#include <opencv2/opencv.hpp>


using namespace std;
using namespace cv;

#define WIDTH 365
#define HEIGHT 280


void eventCallback(const dvs_msgs::EventArray::ConstPtr& msg){
    ROS_INFO("Event callback");
    Mat img = Mat::zeros(Size(WIDTH, HEIGHT), CV_8UC1);
    for (const dvs_msgs::Event &e : msg->events){
        img.at<uchar>(e.y, e.x) = 255;
    }
    imshow("src", img);
    waitKey(1);
}


// #include <signal.h>


int main(int argc, char **argv){

	// google::ParseCommandLineFlags(&argc, &argv, true);	// gflags
	ros::init(argc, argv, "event_node");
	ros::NodeHandle nh;

    ros::Subscriber subEvent = nh.subscribe("events", 10, eventCallback);

    while(ros::ok()){
        ros::spinOnce();
    }
    
    return 0;
}



