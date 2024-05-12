#ifndef THRUST_ALLOCATOR_H
#define THRUST_ALLOCATOR_H

struct Wrench
{
    double fx, fy, fz;
    double tr, tp, ty;
};

/**
 * @brief Represents the relative force allocated to each thruster.
 * Each field should be a double in the range [-1, 1].
 * 1 represents maximum forward thrust, -1 is maximum reverse thrust
 */
struct ThrustAllocation
{   
    // Vertical movement thrusts
    double
        tfr,
        tbr,
        tbl,
        tfl;

    // Lateral movement thrusts
    double 
        bfr,
        bbr,
        bbl,
        bfl;
};

class ThrustAllocator
{
    public:
    /**
     * @brief Allocates xy movement lateral thrusters
     * Ignores rotations and z movement 
     */
    ThrustAllocation allocate_thrust_basic(Wrench &wrench);
    ThrustAllocation allocate_thrust_advanced(Wrench &wrench);
};




#endif // THRUST_ALLOCATOR_H
