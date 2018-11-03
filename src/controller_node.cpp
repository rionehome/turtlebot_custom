#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/Joy.h>

  class ControrerOpetation {

      public: ControrerOpetation();

      private: void calcController(const sensor_msgs::Joy::ConstPtr& joy);

      int stick_vertical_L;
      int stick_horizontal_L;
      int stick_vertical_R;
      int stick_horizontal_R;
      int cross_vertical;
      int cross_horizontal;
      int button_L2;
      int button_R2;
      int button_L;
      int button_R;
      int button_Circle;
      int button_Cross;


      double verticalAccel;
      double horizontalAccel;
      double angularAccel;

      ros::NodeHandle nh;
      ros::Publisher publisher;
      ros::Subscriber subscriber;
      geometry_msgs::Twist velocity;
  };

  ControrerOpetation::ControrerOpetation():
      stick_vertical_R(5),
      stick_horizontal_R(2),
      stick_vertical_L(1),
      stick_horizontal_L(0),
      cross_vertical(10),
      cross_horizontal(9),
      button_L2(3),
      button_R2(4),
      button_L(1),
      button_R(2),

      button_Cross(1),
      button_Circle(2),

      verticalAccel(0.3),
      horizontalAccel(1.0),
      angularAccel(1.0)
  {
    publisher=nh.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/teleop", 1);
    subscriber=nh.subscribe<sensor_msgs::Joy>("joy", 1, &ControrerOpetation::calcController, this);
  }


  void ControrerOpetation::calcController(const sensor_msgs::Joy::ConstPtr& joy){
    double accel=(double)(joy->buttons[button_Circle])/2+1;
    
    double inputX=accel*verticalAccel*joy->axes[stick_vertical_L]
                  +accel*verticalAccel*joy->axes[stick_vertical_R]
                  +accel*verticalAccel*joy->axes[cross_vertical];

    double inputZ=accel*angularAccel*((joy->axes[button_R2]-1)/2)
                  -accel*angularAccel*((joy->axes[button_L2]-1)/2);

    if(inputX!=0||inputZ!=0){
      velocity.linear.x=inputX;
      velocity.angular.z=inputZ;
      ROS_INFO("%f : %f",inputX,inputZ);
      publisher.publish(velocity);
    }
  }

  int main(int argc, char **argv) {
    ROS_INFO("Start Controller_node !!");
    ros::init(argc, argv, "controller_node");
    ControrerOpetation controrerOpetation;
    ros::spin();
  }
