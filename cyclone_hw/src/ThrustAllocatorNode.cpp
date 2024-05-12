#include "cyclone_hw/ThrustAllocatorNode.hpp"

#include "rclcpp/rclcpp.hpp"

#include <cstdio>
#include <functional>

using std::placeholders::_1;

ThrustAllocatorNode::ThrustAllocatorNode()
  : Node("thrust_allocator_node") {
    wrench_sub = this->create_subscription<geometry_msgs::msg::Wrench>(
      "rov/wrench_cmd",
      10,
      std::bind(&ThrustAllocatorNode::wrench_received_callback, this, _1)
    );

    vfr_thrust_pub = this->create_publisher<std_msgs::msg::Float64>(
      "thruster1/cmd_thrust", 
      10
    );

    vbr_thrust_pub = this->create_publisher<std_msgs::msg::Float64>(
      "thruster2/cmd_thrust", 
      10
    );

    vbl_thrust_pub = this->create_publisher<std_msgs::msg::Float64>(
      "thruster3/cmd_thrust", 
      10
    );

    vfl_thrust_pub = this->create_publisher<std_msgs::msg::Float64>(
      "thruster4/cmd_thrust", 
      10
    );

    lfr_thrust_pub = this->create_publisher<std_msgs::msg::Float64>(
      "thruster5/cmd_thrust", 
      10
    );

    vfr_thrust_pub = this->create_publisher<std_msgs::msg::Float64>(
      "thruster6/cmd_thrust", 
      10
    );

    vfr_thrust_pub = this->create_publisher<std_msgs::msg::Float64>(
      "thruster7/cmd_thrust", 
      10
    );

    vfr_thrust_pub = this->create_publisher<std_msgs::msg::Float64>(
      "thruster7/cmd_thrust", 
      10
    );
}

void ThrustAllocatorNode::wrench_received_callback(const geometry_msgs::msg::Wrench& msg) {
  this->lbl_thrust_pub.
}

int main() {
  printf("Hello There");
}