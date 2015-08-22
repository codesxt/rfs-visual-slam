#include <iostream>

#include "../include/trajectory.hpp"

Trajectory::Trajectory(){
  cout << "New trajectory created." << endl;
  poses.push_back(Pose(0.0, 0.0, 0.0));
}
