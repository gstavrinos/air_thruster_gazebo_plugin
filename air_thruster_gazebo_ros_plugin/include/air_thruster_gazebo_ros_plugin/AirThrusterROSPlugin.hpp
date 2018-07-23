#pragma once

#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <gazebo/common/Plugin.hh>
#include <air_thruster_gazebo_plugin/AirThrusterPlugin.hpp>

namespace air_thruster
{
  class AirThrusterROSPlugin : public gazebo::AirThrusterPlugin{
    public:
      AirThrusterROSPlugin();
      ~AirThrusterROSPlugin();
      void Load(gazebo::physics::ModelPtr _parent, sdf::ElementPtr _sdf);

    private:
      ros::Subscriber sub;
      std::unique_ptr<ros::NodeHandle> nh;
      void helper(const std_msgs::Float64::ConstPtr& msg);
  };
}
