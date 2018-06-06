//
//  main.cpp
//  autoxQ2
//
//  Created by Yang Taozheng on 6/5/18.
//  Copyright © 2018 Yang Taozheng. All rights reserved.
//

#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

constexpr double kPi = 3.1415926;
constexpr double kVelocity = 1;
constexpr double kWheelbase = 2.0;
vector<double> rmserror;

struct CarPose {
    double x;
    double y;
    double theta;
};
/**
 * Returns the new pose of the car.
 *
 * Integrate the current pose forwards by timestep seconds when applying a given
 * steering angle to the car at a given velocity using the first order forward
 * Euler method.
 *
 * Kinematics model:
 * dot(x) = v0*cos(theta)
 * dot(y) = v0*sin(theta)
 * dot(theta) = v0*tan(u)/L
 *
 * where
 * x: car's x position
 * y: car's y position
 * theta: heading angle theta == 0,  car in x direction
 *                      theta == PI/2, car in y direction
 * L: wheelbase ==  2m,
 * v0: velocity == 1m/s.
 *
 * @param current_pose[in] The current car's pose
 * @param steering_angle[in] The applied steering angle to the car in radians
 * @param velocity[in] The car's velocity
 * @param timestep[in] The timestep to integrate by
 * @return Car's pose at timestep seconds
 */
CarPose Step(const CarPose& current_pose, double steering_angle,
             double velocity, double timestep) {
    CarPose res;
    double dotx = velocity*cos(steering_angle);
    double doty = velocity*sin(steering_angle);
    double dottheta = velocity*tan(steering_angle)/kWheelbase;
    res.x = current_pose.x + timestep*dotx;
    res.y = current_pose.y + timestep*doty;
    res.theta = current_pose.theta + timestep*dottheta;
    return res;
}
/**
 * Simulates the car tracking the reference path by setting the car's
 * steering_angles.
 *
 * Steering angles are limited to [-0.5, 0.5].
 *
 * @param reference[in] The reference path to track
 * @param initial_pose[in] The initial pose of the car
 * @param path[out] The path that the car drives
 * @param steering_angle[out] The steering angles applied to the car
 * @return Root mean squared error of trajectory
 */
double Simulate(const std::vector<CarPose>& reference,
                const CarPose& initial_pose, std::vector<CarPose>* path,
                std::vector<double>* steering_angles) {
    //PID controller design
    //apply constant speed, but changing steering angle
    
    double rms = 0; //root mean square error
    double currSteer = 0;
    CarPose currPos = initial_pose; // initialize the current position as the initial position
    
    // p errors
    double currXErr;
    double currYErr;
    double currThetaErr; // current heading angle difference between reference and state
    // i erros
    double iXErr = 0;
    double iYErr = 0;
    double iThetaErr = 0; // integral error of the heading angle differences
    // d errors
    double dXErr = 0;
    double dYErr = 0;
    double dThetaErr = 0; // derivative error of the heading angle differneces
    // previous time step errors
    double prevXErr = 0;
    double prevYErr = 0;
    double prevThetaErr = 0; // initialize the previous heading angle difference as o
    
    // control gains
    double kp = 0.006;
    double ki = 0.006;
    double kd = 1;
    
    for(int i=0; i<reference.size(); i++){
        
        currXErr = reference[i].x - currPos.x;
        currYErr = reference[i].y - currPos.y;
        currThetaErr = reference[i].theta - currPos.theta;
        
        iXErr += currXErr;
        iYErr += currYErr;
        iThetaErr += currThetaErr;
        
        dXErr = (currXErr - prevXErr)/0.02;
        dYErr = (currYErr - prevYErr)/0.02;
        dThetaErr = (currThetaErr - prevThetaErr)/0.02;
        
        // update the previous differences as the current heading angle difference
        prevXErr = currXErr;
        prevYErr = currYErr;
        prevThetaErr = currThetaErr;

        currSteer = kp*(currXErr + currYErr + 0*currThetaErr) + ki*(iXErr + iYErr + 0*iThetaErr) +kd*(dXErr + dYErr + 0*dThetaErr);
        if(currSteer>0.5){
            currSteer = 0.5;
        }
        if(currSteer<-0.5){
            currSteer = -0.5;
        }
        // find the current root mean square
        double tempRMS = sqrt((currPos.x-reference[i].x)*(currPos.x-reference[i].x) + (currPos.y-reference[i].y)*(currPos.y-reference[i].y) + (currPos.theta-reference[i].theta)*(currPos.theta-reference[i].theta));
        
        rmserror.push_back(tempRMS);
        rms+= tempRMS;
        
        // update the actual path and steering angle
        path->push_back(currPos);
        steering_angles->push_back(currSteer);
        
        currPos = Step(currPos, currSteer, kVelocity, 0.02);
    }
    
    return rms;
}

int main() {
    constexpr int kTimesteps = 200;
    constexpr double kDt = 0.02;
    constexpr double kSteeringAngle = 0.2;
    CarPose initial_pose = {0, 0, kPi / 2.0};
    std::vector<CarPose> reference_path(kTimesteps);
    reference_path[0] = CarPose{0.2, 0.2, kPi / 2.0};
    for (int i = 1; i < kTimesteps; ++i) {
        const CarPose new_pose =
        Step(reference_path[i-1], kSteeringAngle, kVelocity, kDt);
        reference_path[i] = new_pose;
    }
    std::vector<double> u;
    std::vector<CarPose> path;
    std::cout << "RMSE: " << Simulate(reference_path, initial_pose, &path, &u)
    << std::endl;
    
    for(int i=0; i<path.size(); i++){
        std::cout<<"x:"<<"  ";
        std::cout<<path[i].x<<"  ";
        std::cout<<reference_path[i].x<<" ";

        std::cout<<"y:"<<"  ";
        std::cout<<path[i].y<<"  ";
        std::cout<<reference_path[i].y<<" ";

        std::cout<<"theta:"<<"  ";
        std::cout<<path[i].theta<<"  ";
        std::cout<<reference_path[i].theta<<" ";
        std::cout<<std::endl;
    }
    
    for(int i=0; i<u.size(); i++){
        std::cout<<u[i]<<std::endl;
    }
    return 0;
}

