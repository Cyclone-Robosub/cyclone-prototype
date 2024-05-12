#include "cyclone_hw/T200.hpp"

#include <cstdio>
#include <algorithm>

int linear_map(double  in, double in_low, double in_high, int out_low, int out_high) {
    in = std::clamp(in, in_low, in_high);

    in = (in - in_low) * ((out_high - out_low)/(in_high - in_low)) + out_low;

    // Should be good to just round and return - insignificant impact

    return (int) in;
}

T200::T200(/* args */)
{
    printf("Constructor");
}

T200::~T200()
{
    printf("Destructor");
}

int T200::update_thrust(double thrust_kgf) {
    int pwm;
    if(thrust_kgf < 0) {
        pwm = linear_map(thrust_kgf, -2.59, 0, 1180, 1500);
    } else {
        pwm = linear_map(thrust_kgf, 0, 3.32, 1500, 1820);
    }

    return pwm;
}