# DAVIS ros

Code for my own davis365 development.

## Usage

### rpg_dvs_ros
The davis driver is `rpg_dvs_ros`.  
Clone and build `rpg_dvs_ros` from github first.

Then add a new launch file, to add a namespace for davis device.
```bash
cp davis_ros/launch/my_davis.launch <path-to-rpg_dvs_ros>/davis_ros_driver/launch
source ~/dvs_ros_ws/devel/setup.bash
roslaunch davis_ros_driver my_davis.launch
```

### dvs_msgs
Copy `dvs_msgs` from `rpg_dvs_ros` to current worksapce, and compile.


### event_node
To run event_node receive events from `davis` namespace:
```bash
source ~/davis_ws/devel/setup.bash
roslaunch davis_ros test.launch
```

## Run two event camera together
The celex and davis can run together. Attention that two node namespace are set in each launch file.