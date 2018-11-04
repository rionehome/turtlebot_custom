#!/bin/sh

DIR=$(cd $(dirname $0); pwd)
DEST=$(rospack find turtlebot_description)/urdf

sudo cp -f $DIR/turtlebot_common_library.urdf.xacro ${DEST}/turtlebot_common_library.urdf.xacro

echo -e "\n complete copy turtlebot.urdf.xacro \n"
