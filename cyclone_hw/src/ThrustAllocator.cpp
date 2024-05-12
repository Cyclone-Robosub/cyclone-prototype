#include "cyclone_hw/ThrustAllocator.hpp"

#include <cstdio>
#include <cmath>

ThrustAllocation ThrustAllocator::allocate_thrust_basic(Wrench &w) {
    auto t = ThrustAllocation();

    // Set vertical thrusters to 0, we are only doing lateral movement for now
    t.tfr = 0;
    t.tbr = 0;
    t.tbl = 0;
    t.tfl = 0;

    const double root2_inv = 1/std::sqrt(2);

    // Allocate thrust by multiplying the desired force in x and y by the inverse
    // of the allocation matrix
    double thrust_2_4 = (w.fx * root2_inv) + (w.fy * root2_inv);

    double thrust_1_3 = (w.fx * (-root2_inv)) + (w.fy * root2_inv);

    const double max_val = std::abs(std::max(thrust_1_3, thrust_2_4));


    // Constrain thrust to our limits
    // This is a very not nice way of doing it
    if(max_val > 1) {
        thrust_2_4 /= max_val;
        thrust_1_3 /= max_val;
    }

    t.bfr = thrust_1_3; // Thruster 1
    t.bbl = thrust_1_3; // Thruster 3

    t.bfl = thrust_2_4; // Thruster 2
    t.bbr = thrust_2_4; // Thruster 4
}

