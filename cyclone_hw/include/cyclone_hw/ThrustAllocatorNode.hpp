#ifndef THRUST_ALLOCATOR_NODE_H
#define THRUST_ALLOCATOR_NODE_H
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float64.hpp"
#include "geometry_msgs/msg/wrench.hpp"

typedef rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr PubFloat64;

class ThrustAllocatorNode : public rclcpp::Node {
public:
  ThrustAllocatorNode();

private:
  // Vertical Thruster command publishers
  PubFloat64 vfr_thrust_pub;
  PubFloat64 vbr_thrust_pub;
  PubFloat64 vbl_thrust_pub;
  PubFloat64 vfl_thrust_pub;

  // Lateral Thruster command publishers
  PubFloat64 lfr_thrust_pub;
  PubFloat64 lbr_thrust_pub;
  PubFloat64 lbl_thrust_pub;
  PubFloat64 lfl_thrust_pub;

  // Control wrench subscriber
  rclcpp::Subscription<geometry_msgs::msg::Wrench>::SharedPtr wrench_sub;

  void wrench_received_callback(const geometry_msgs::msg::Wrench& msg);
};

#endif