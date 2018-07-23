#pragma once

#include <math.h>
#include <gazebo/gazebo.hh>
#include <boost/scoped_ptr.hpp>
#include <gazebo/physics/physics.hh>
#include <gazebo/transport/TransportTypes.hh>

namespace gazebo{

    class AirThrusterPlugin : public gazebo::ModelPlugin{
        public:
          AirThrusterPlugin(){}
          virtual ~AirThrusterPlugin(){}
          virtual void Load(gazebo::physics::ModelPtr _model, sdf::ElementPtr _sdf);
        protected:
          void Thruuuuust(ConstVector3dPtr &msg);
          transport::SubscriberPtr sub_;
          std::string thrusterName;
          gazebo::physics::LinkPtr thrusterLink;

        private:
          std::string topicPrefix;
          transport::NodePtr node;
    };

}
