cmake_minimum_required(VERSION 3.10)
project(grasp_utils)
add_definitions(-std=c++17)

find_package(catkin_simple REQUIRED)
find_package(Boost REQUIRED)
find_package(Eigen3 REQUIRED)
catkin_simple(ALL_DEPS_REQUIRED)
include_directories(
        include
        ${catkin_INCLUDE_DIRS}
        ${EIGEN3_INCLUDE_DIR}
        ${Boost_INCLUDE_DIRS}
)

catkin_package()

cs_add_library(grasp_utils_lib src/grasp_exec.cpp)

cs_add_executable(grasp_exec_node src/grasp_exec_node.cpp)
cs_add_executable(grasp_det_node src/grasp_det_node.cpp)

target_link_libraries(grasp_exec_node grasp_utils_lib)

cs_install()


cs_export()

# ## Use C++14
# set(CMAKE_CXX_STANDARD 14)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ## By adding -Wall and -Werror, the compiler does not ignore warnings anymore,
# ## enforcing cleaner code.
# add_definitions(-Wall -Werror)

# ## Find catkin macros and libraries
# find_package(catkin REQUIRED
#   COMPONENTS
#     roscpp
#     sensor_msgs
#     roslint
#     roscpp std_msgs
#     message_generation
#     moveit_msgs
# )

# ## Find system libraries
# find_package(Eigen3 REQUIRED)
# find_package(Boost REQUIRED)

# add_message_files(FILES
#   GraspArray.msg
# )
# generate_messages(
#   DEPENDENCIES
#   std_msgs
#   moveit_msgs
# )
# ###################################
# ## catkin specific configuration ##
# ###################################
# ## The catkin_package macro generates cmake config files for your package
# ## Declare things to be passed to dependent projects
# ## INCLUDE_DIRS: uncomment this if your package contains header files
# ## LIBRARIES: libraries you create in this project that dependent projects also need
# ## CATKIN_DEPENDS: catkin_packages dependent projects also need
# ## DEPENDS: system dependencies of this project that dependent projects also need
# catkin_package(
#   INCLUDE_DIRS
#     include
#     # This is only necessary because Eigen3 sets a non-standard EIGEN3_INCLUDE_DIR variable
#     ${EIGEN3_INCLUDE_DIR}
#   LIBRARIES
#     ${PROJECT_NAME}_core
#   CATKIN_DEPENDS message_runtime
#     roscpp
#     sensor_msgs
#     moveit_msgs
#   DEPENDS
#   ## find_package(Eigen3) provides a non standard EIGEN3_INCLUDE_DIR instead of Eigen3_INCLUDE_DIRS.
#   ## Therefore, the DEPEND does not work as expected and we need to add the directory to the INCLUDE_DIRS
#   Eigen3

#   ## Boost is not part of the DEPENDS since it is only used in source files,
#   ## Dependees do not depend on Boost when they depend on this package.
# )

# ###########
# ## Build ##
# ###########


# ## Specify additional locations of header files
# ## Your package locations should be listed before other locations
# include_directories(
#   include
#   ${catkin_INCLUDE_DIRS}
#   # Set manually because Eigen sets a non standard INCLUDE DIR
#   ${EIGEN3_INCLUDE_DIR}
#   # Set because Boost is an internal dependency, not transitive.
#   ${Boost_INCLUDE_DIRS}
# )

# ## Declare a cpp library
# add_library(${PROJECT_NAME}_core
#    src/grasp_exec.cpp
# )
# target_compile_features(${PROJECT_NAME}_core INTERFACE cxx_std_11)

# ## Declare cpp executables
# add_executable(${PROJECT_NAME}_grasp_node
# #  src/${PROJECT_NAME}_node.cpp
# #  src/RosPackageTemplate.cpp
# #  src/grasp_exec.cpp
#   src/grasp_exec_node.cpp
# #  src/grasp_det_node.cpp
# #  src/grasp_det.cpp
# )

# add_executable(${PROJECT_NAME}_det_node
# src/grasp_det_node.cpp
# )


# target_compile_features(${PROJECT_NAME}_det_node INTERFACE cxx_std_11)

# ## Add dependencies to exported targets, like ROS msgs or srvs
# add_dependencies(${PROJECT_NAME}_core
#   ${catkin_EXPORTED_TARGETS}
# )

# add_dependencies(${PROJECT_NAME}_det_node
#   ${catkin_EXPORTED_TARGETS}
# )
# add_dependencies(${PROJECT_NAME}_grasp_node
#   ${catkin_EXPORTED_TARGETS}
# )
# ## Specify libraries to link executable targets against
# target_link_libraries(${PROJECT_NAME}_core
#   ${catkin_LIBRARIES}
# )

# target_link_libraries(${PROJECT_NAME}_det_node
#   ${PROJECT_NAME}_core
#   ${catkin_LIBRARIES}
# )
# target_link_libraries(${PROJECT_NAME}_grasp_node
#   ${PROJECT_NAME}_core
#   ${catkin_LIBRARIES}
# )
# #############
# ## Install ##
# #############

# # Mark executables and/or libraries for installation
# install(
#   TARGETS ${PROJECT_NAME}_grasp_node ${PROJECT_NAME}_det_node
#   ${PROJECT_NAME}_core
#   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

# # Mark cpp header files for installation
# install(
#   DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
# )
# message(DIRECTORY="include/${PROJECT_NAME}/")
# message(DESTINATION="${CATKIN_PACKAGE_INCLUDE_DESTINATION}")

# # Mark other files for installation
# install(
#   DIRECTORY doc
#   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
# )

# #############
# ## Testing ##
# #############

# # if(${CATKIN_ENABLE_TESTING})
# # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
# # ## Add gtest based cpp test target and link libraries
# # catkin_add_gtest(${PROJECT_NAME}-test
# #   #test/test_ros_package_template.cpp
# # )
# # target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME}_core)
# # endif()

# ##########################
# ## Static code analysis ##
# ##########################

# roslint_cpp()
