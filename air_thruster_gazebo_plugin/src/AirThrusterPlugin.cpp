#include <air_thruster_gazebo_plugin/AirThrusterPlugin.hpp>

GZ_REGISTER_MODEL_PLUGIN(gazebo::AirThrusterPlugin)

namespace gazebo {

    void AirThrusterPlugin::Load(physics::ModelPtr _model, sdf::ElementPtr _sdf){
        GZ_ASSERT(_model != NULL, "Invalid model pointer");

        this->node = transport::NodePtr(new transport::Node());
        #if GAZEBO_MAJOR_VERSION >= 8
            this->node->Init(_model->GetWorld()->Name());
        #else
            this->node->Init(_model->GetWorld()->GetName());
        #endif

        GZ_ASSERT(_sdf->HasElement("linkName"), "Could not find linkName.");
        std::string linkName = _sdf->Get<std::string>("linkName");
        this->thrusterName = _sdf->Get<std::string>("thrusterName");
        this->thrusterLink = _model->GetLink(linkName);
        GZ_ASSERT(this->thrusterLink, "thruster link is invalid");

        std::stringstream strs;
        strs << "/" << _model->GetName() << "/air_thrusters/" << this->thrusterName << "/";
        this->topicPrefix = strs.str();

        this->sub_ = this->node->Subscribe(this->topicPrefix + "input", &AirThrusterPlugin::Thruuuuust, this);
    }

    void AirThrusterPlugin::Thruuuuust(ConstVector3dPtr &msg){
        ignition::math::Vector3d t(0, 0, -std::max(0.0, msg->z()));
        this->thrusterLink->AddRelativeForce(t);
    }
}
