#include <cstdio>
#include "cyclone_hw/T200.hpp"

int main(int argc, char **argv) {
    (void)argc;
    (void)argv;

    auto t1 = T200();
    printf("New thrust = %d", t1.update_thrust(10));
    return 0;
}
