#!/usr/bin/env python
import rospy
from std_msgs.msg import Float64
from air_thruster_gazebo_plugin_msgs.msg import NamedFloatArray

publishers = {}

def callback(msg):
    global publishers
    if len(msg.values) == len(msg.names):
        for i in xrange(len(msg.names)):
            publishers[msg.names[i]].publish(msg.values[i])
    else:
        print 'Received malformed message! Doing nothing.'

def init():
    global publishers
    rospy.init_node('named_float_array_to_individual_messages')
    model_name = rospy.get_param('~model_name','tie_fighter')
    input_topic = rospy.get_param('~input_topic', model_name + '/named_float_array_to_individual_messages/input')
    thruster_names = rospy.get_param('~thruster_names', ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '10', '11', '12', '13', '14', '15'])
    rospy.Subscriber(input_topic, NamedFloatArray, callback)
    for i in thruster_names:
        publishers[i] = (rospy.Publisher(model_name+'/air_thrusters/'+i+'/input', Float64, queue_size=10));
    rospy.spin()



if __name__ == '__main__':
    init()