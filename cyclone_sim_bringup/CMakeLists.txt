cmake_minimum_required(VERSION 3.8)
project(cyclone_sim_bringup)

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(cyclone_description REQUIRED)


# Install launch and config files to share
install(
  DIRECTORY
    launch/
  DESTINATION share/${PROJECT_NAME}/launch
)

install(
  DIRECTORY
    config/
  DESTINATION share/${PROJECT_NAME}/config
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
