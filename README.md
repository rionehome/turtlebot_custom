# turtlebot_custom
## Overview
Turtlebot用のLaunchのまとめパッケージ

## Setup

デフォルトのTurtlebotにはlaser_frameというLinkが存在していない。

これがないとLidarをGmappingやamclなどのmove_baseが認識しないので、追加する
 
1. patchesの中にあるturtlebot_common_library.urdf.xacroをturtlebot_descriptionパッケージのurdf 内にある同名ファイルと入れ替える

## Usage

( Lidarの起動 )
```
roslaunch turtlebot_custom lidar.launch
```

( Gmappingの起動 )
```
roslaunch turtlebot_custom gmapping_lidar.launch
```

( Rviz )
```
roslaunch turtlebot_custom rviz.launch
```

( laser_filter )

デフォルトで Lidarのレーザーデータのトピックは```/scan_original```としてある
これをlaser_filterを通してデータを制限したうえで、```/scan```としてPublishする
```
roslaunch turtlebot_custom laser_filter.launch
```

