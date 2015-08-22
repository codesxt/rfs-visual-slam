#ifndef TRAJECTORY_HPP
#define TRAJECTORY_HPP

#include <vector>
#include "pose.hpp"

using namespace std;

class Trajectory{
public:
  vector <Pose> poses;

  Trajectory();
private:
};

#endif //TRAJECTORY_HPP
