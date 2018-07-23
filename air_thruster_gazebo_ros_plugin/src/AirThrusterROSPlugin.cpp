#include <air_thruster_gazebo_ros_plugin/AirThrusterROSPlugin.hpp>

namespace air_thruster{
    GZ_REGISTER_MODEL_PLUGIN(AirThrusterROSPlugin)

    AirThrusterROSPlugin::AirThrusterROSPlugin(){}

    AirThrusterROSPlugin::~AirThrusterROSPlugin(){
        this->nh->shutdown();
    }

    void AirThrusterROSPlugin::Load(gazebo::physics::ModelPtr _parent, sdf::ElementPtr _sdf){
        try {
            AirThrusterPlugin::Load(_parent, _sdf);
        }
        catch(gazebo::common::Exception &_e){
            gzerr << "Error loading plugin."
            << "Please ensure that your model is correct."
            << '\n';
            return;
        }

        if (!ros::isInitialized()){
            gzerr << "Not loading plugin since ROS has not been "
            << "properly initialized.  Try starting gazebo with ros plugin:\n"
            << "  gazebo -s libgazebo_ros_api_plugin.so\n";
            return;
        }

        this->nh.reset(new ros::NodeHandle(""));

        this->sub = this->nh->subscribe<std_msgs::Float64>(this->sub_->GetTopic(), 10, boost::bind(&AirThrusterROSPlugin::helper, this, _1));

        gzmsg << "Thruster Name: " << this->thrusterName << " initialized" << std::endl
        << "\t- Link: " << this->thrusterLink->GetName() << std::endl
        << "\t- Robot model: " << _parent->GetName() << std::endl
        << "\t- Input command topic: " <<
        this->sub_->GetTopic() << std::endl;
    }

    void AirThrusterROSPlugin::helper(const std_msgs::Float64::ConstPtr& msg){
      ignition::math::Vector3<double> xyz = ignition::math::Vector3<double>(0.0, 0.0, msg->data);
      gazebo::msgs::Vector3d v_ = gazebo::msgs::Convert(xyz);
      ConstVector3dPtr v(new gazebo::msgs::Vector3d(v_));
      Thruuuuust(v);
    }

}
