#include <ros/ros.h>
#include <sensor_msgs/Image.h>

void depthImageCallback(const sensor_msgs::Image::ConstPtr& msg)
{
  ROS_INFO("Received depth image with height: %d, width: %d", msg->height, msg->width);
  // 여기에 depth 이미지 처리 로직을 추가할 수 있습니다.
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "depth_camera_processor");
  ros::NodeHandle nh;

  ros::Subscriber sub = nh.subscribe("/depth_camera/depth/image_raw", 1, depthImageCallback);

  ros::spin();

  return 0;
}