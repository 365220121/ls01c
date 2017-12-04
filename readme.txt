镭神公司激光雷达驱动及hector_mapping的demo



系统：ubuntu 14.04
ros版本:indigo
启动命令： roslaunch ls01c_hector_mapping.launch
此demo版本号：1.0
学校：HIT

注意事项：
如果启动时，激光雷达没有正常旋转，是因为端口没有权限，需要执行以下命令：
cd /dev
sudo chmod 777 ttyUSB0			(ttyUSB0是端口号，可能会有所变化，自己对应修改)
