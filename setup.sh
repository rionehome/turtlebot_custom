#!/bin/sh

DIR=$(cd $(dirname $0); pwd)
DEST=$(rospack find turtlebot_description)/urdf

cp -f ${DEST}/turtlebot_common_library.urdf.xacro $DIR/patches/turtlebot_common_library.urdf.xacro

cd $(rospack find ydlidar)/startup
sudo chmod 777 ./*
sudo sh initenv.sh
