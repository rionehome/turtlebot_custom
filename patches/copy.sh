#!/bin/sh

DIR=$(cd $(dirname $0); pwd)
DEST=$(rospack find turtlebot_description)/urdf

cp -f ${DEST}/turtlebot_common_library.urdf.xacro $DIR/turtlebot_common_library.urdf.xacro

echo -e "\n complete copy turtlebot.urdf.xacro \n"
