#!/bin/sh

DIR=$(cd $(dirname $0); pwd)

echo $DIR

cp -f /opt/ros/kinetic/share/turtlebot_description/urdf/turtlebot_common_library.urdf.xacro $DIR/turtlebot_common_library.urdf.xacro
