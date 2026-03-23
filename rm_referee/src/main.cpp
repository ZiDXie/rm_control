//
// Created by ljq on 2022/5/17.
//

#include "rm_referee/referee.h"

int main(int argc, char** argv)
{
  std::string robot;
  ros::init(argc, argv, "rm_referee");  // rm_referee
  ros::NodeHandle nh("~");
  rm_referee::Referee referee(nh);
  double read_loop_hz = 200.0;
  nh.param("read_loop_hz", read_loop_hz, 200.0);
  ros::Rate loop_rate(read_loop_hz);
  while (ros::ok())
  {
    ros::spinOnce();
    referee.read();
    loop_rate.sleep();
  }

  return 0;
}
