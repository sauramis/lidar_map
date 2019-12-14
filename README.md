## Create a 3D point cloud using a 2D-lidar:
This repository is primarily using spin_hokuyo to run a hokuyo lidar with a dynamixel and generating a 3D pointcloud pubblished to /assembled_cloud topic.
To build the repository clone the repository into a catkin workspace, replace the src folder and run
    ./build_workspace
To add the udev rules to run rplidar/hokuyo and dynamixel run
    ./create_udev_rules
## To run a hokuyo use:
    roslaunch spin_lidar tilt_hokuyo_continous
This launches the dynamixel, parameters for motor are in spin_hokuyo/launch/dynamixel_servos_tilting.yaml. Before running the spin_hokuyo node make sure motor_id is known. This value is currently hardcoded in the dynamixel_servos_tilting.yaml file. Hokuyo device has been mapped to /dev/ttyUSB0, so the user should have access to this device or create a udev rule and assign the device the symlink you create.
## To run a rplidar use:
    roslaunch spin_lidar tilt_rplidar_continuous
This launches the dynamixel and the rplidar node.
To visualize the point cloud open a new terminal, run rviz and select the topic as /assembled_points.
