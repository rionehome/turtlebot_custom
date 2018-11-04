#!/bin/sh

DIR=$(cd $(dirname $0); pwd)
DEST=$(rospack find turtlebot_description)/urdf

sudo cp -f $DIR/turtlebot_common_library.urdf.xacro ${DEST}/turtlebot_common_library.urdf.xacro
sudo cp -f $DIR/turtlebot_gazebo.urdf.xacro ${DEST}/turtlebot_gazebo.urdf.xacro
echo -e "\n complete copy turtlebot_common_library.urdf.xacro \n"
echo -e "\n complete copy turtlebot_gazebo.urdf.xacro \n"
