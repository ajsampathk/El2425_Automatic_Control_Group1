#!/usr/bin/env python
import rospy
from tf.transformations import euler_from_quaternion
from numpy import *
import matplotlib as mp
from sensor_msgs.msg import LaserScan
from path_points import path_points
from low_level_interface.msg import lli_ctrl_request
from nav_msgs.msg import Odometry
import pdb

class PurePursuit(object):
    def __init__(self):
        self.path = path_points('linear')
        self.Estop = 0
        self.parking = 0
        self.parking_lot_dist = 0
        self.car_heading = 0
        # Subscribe to the topics
        self.car_pose_sub = rospy.Subscriber("SVEA1/odom", Odometry, self.car_pose_cb)
        self.Lidar_sub = rospy.Subscriber("/scan", LaserScan, self.lidar_cb)
        self.has_parking_spot = False

        rospy.loginfo(self.car_pose_sub)
        # init Publisher
        self.car_control_pub = rospy.Publisher("lli/ctrl_request", lli_ctrl_request, queue_size=10)
        rate = rospy.Rate(10)
        # goal = self.path[0]
        lli_msg = lli_ctrl_request()
        lli_msg.velocity = speed
        self.ld = 0.5
        self.xs = []
        self.ys = []
        while len(self.path) > 0:
            if hasattr(self, 'car_pose'):
                while not (rospy.is_shutdown() or len(self.path) == 0):
                    if not self.has_parking_spot:
                        goal = self.choose_point()
                        lli_msg.velocity,lli_msg.steering = self.controller(goal)
                        self.car_control_pub.publish(lli_msg)
                    else:
                        lli_msg.velocity, lli_msg.steering = self.parallell_parking_start()
                        self.car_control_pub.publish(lli_msg)
                        break
                    rate.sleep()
                # goal = self.path[0]
        lli_msg.velocity = 0
        self.car_control_pub.publish(lli_msg)
        pose_arr = array([self.xs, self.ys])
        savetxt("/home/nvidia/catkin_ws/real_path.csv", pose_arr, delimiter=",")

    def controller(self,goal):
        xr, yr = self.car_pose.pose.pose.position.x, self.car_pose.pose.pose.position.y
        #self.car_heading = self.car_pose.twist.twist.angular.z
        self.xs.append(xr)
        self.ys.append(yr)
        xo, yo = self.car_pose.pose.pose.orientation.x, self.car_pose.pose.pose.orientation.y
        zo, w = self.car_pose.pose.pose.orientation.z, self.car_pose.pose.pose.orientation.w
        self.current_heading = euler_from_quaternion([xo, yo, zo, w])[2]
        xg, yg = goal[0],goal[1]  # self.path
        L = 0.32
        ld = sqrt((xg - xr)**2 + (yg - yr)**2)
        des_heading = arctan2((yg - yr), (xg - xr))
        print('des_head',des_heading)
        headErr = des_heading - self.current_heading
        # print("headErrOriginal", headErr)
        if headErr > pi:
            headErr = -2 * pi + headErr
        if headErr < -1 * pi:
            headErr = 2 * pi + headErr
        print('phi',headErr)
        # print('difference_phi',phi*180/pi)
        curv = 2 * sin(headErr) / ld
        des_phi = arctan(L * curv)
        print('des_phi',des_phi)

        if headErr > pi/2 or des_phi > pi/4:  # or 100
            phi = pi/4
        elif headErr < -pi/2 or des_phi < -pi/4:  # or -100
            phi = -pi/4
        else:
            phi = des_phi
        #v = self.speed_control(phi)
        v = 10
        # print('real phi',(phi*180/pi))
        return v, -int(100/(pi/4)*phi)

    def speed_control(self, phi):
        if self.Estop == 0:
            if abs(phi) < pi/12:
                speed = 20
            else:
                speed = 15
        else:
            speed = -10
        #speed = E_stop(speed)
        return speed

    def reach_goal(self, goal):
        xr, yr = self.car_pose.pose.pose.position.x, self.car_pose.pose.pose.position.y
        tol = 0.2
        if dist((xr,yr), goal) <= tol:
            return True
        else:
            return False


    def car_pose_cb(self, car_pose_msg):
        self.car_pose = car_pose_msg

    def choose_point(self):
        xr, yr = self.car_pose.pose.pose.position.x, self.car_pose.pose.pose.position.y
        while(len(self.path) > 1):
            examined_point = self.path[0]
            distance = dist((xr,yr), examined_point)
            if distance > self.ld:
                return examined_point
            self.path.remove(examined_point)
        goal_point = self.path[0]
        self.path.remove(goal_point)
        return goal_point

    def parallell_parking_start(self):
        return 0, 0

    def e_stop(self,data):
        angles = arange(data.angle_min, data.angle_max + data.angle_increment, data.angle_increment)
        ranges = data.ranges
        e_stop_threshold_dist = 1
        Estop = 0
        parking = 0
        for i in range(len(angles)):
            if abs(angles[i]) > pi-pi/6:
                if ranges[i] < e_stop_threshold_dist:
                    Estop = 1
        self.Estop = Estop

    def parking_stop(self,data):
        angles = arange(data.angle_min, data.angle_max + data.angle_increment, data.angle_increment)
        ranges = data.ranges
        parking_threshold = 0.5
        pp_len_threshold = 0.7          #Length of gap, subject to change
        for i in range(len(angles)):
            if angles[i] < pi / 2 + pi / 50 and angles[i] > pi / 2 - pi / 50:
                if self.parking == 0:
                    if ranges[i] < parking_threshold:
                        return
                    elif angles[i+1] > pi / 2 + pi / 50 or angles[i+1] < pi / 2 - pi / 50:    ##All relevant angles passed test
                        self.parking_lot_start = [self.car_pose.pose.pose.position.x, self.car_pose.pose.pose.position.y]
                        self.parking = 1
                        print("START:"+str(self.parking_lot_start))
                elif ranges[i] < parking_threshold and self.parking == 1:
                    parking_lot_end = [self.car_pose.pose.pose.position.x, self.car_pose.pose.pose.position.y]
                    self.parking_lot_dist = sqrt((parking_lot_end[0] - self.parking_lot_start[0]) ** 2 + (parking_lot_end[1] - self.parking_lot_start[1]) ** 2)
                    print("Dist"+str(self.parking_lot_dist))
                    if self.parking_lot_dist > pp_len_threshold:
                        self.has_parking_spot = True
                    else:
                        self.parking = 0



    def lidar_cb(self,data):
        self.e_stop(data)
        self.parking_stop(data)





        #parking_lot_start = [self.car_pose.pose.pose.position.x, self.car_pose.pose.pose.position.y] 




 
 
 


def dist(p1, p2):
    return sqrt((p1[0] - p2[0])**2 + (p1[1] - p2[1])**2)


if __name__ == "__main__":

    rospy.init_node('path_follow')
    speed = 10
    try:
        PurePursuit()
    except rospy.ROSInterruptException:
        pass

