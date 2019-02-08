#!/bin/sh

#echo $DIR
$(rospack find ydlidar &>/dev/null)
if [ $? -ne 0 ]; then
  cd $(dirname $(cd $(dirname $0); pwd))
  git clone https://github.com/EAIBOT/ydlidar
  cd $(rospack find ydlidar)/startup
  sudo chmod 777 ./*
  sudo bash initenv.sh
  echo -e "\n complete setup ydlidar \n"
fi

#bash patches/copy.sh
