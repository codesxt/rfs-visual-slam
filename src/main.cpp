#include <string>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/features2d.hpp>
#include <boost/program_options.hpp>
#include <boost/filesystem.hpp>

#include "pose.hpp"
#include "trajectory.hpp"

using namespace std;
using namespace cv;
namespace po = boost::program_options;
namespace fs = boost::filesystem;

int main( int argc, char** argv )	{
  string dataset_path = "";
  string ground_truth_path = "";

  po::options_description desc("RFS Based Visual Slam");
  desc.add_options()
    ("help", "Prints this description")
    ("dataset", po::value<string>(), "Dataset path")
    ("ground-truth", po::value<string>(), "Ground-truth path");

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if(vm.count("help")){
      cout << desc << endl;
      return 0;
    }else if(vm.count("dataset") && vm.count("ground-truth")){
      dataset_path = vm["dataset"].as<string>();
      ground_truth_path = vm["ground-truth"].as<string>();
      cout << "Initializing program with options:" << endl;
      cout << "Dataset Path: " << dataset_path << endl;
      cout << "Ground Truth Path: " << ground_truth_path << endl;
    }else{
      cout << "Wrong program initialization. Run " << argv[0] << " --help for use instructions." << endl;
      return (1);
    }

    /* ---------------------------------------------
     * Main program begins here
     * --------------------------------------------- */
    fs::path p(dataset_path);
    fs::directory_iterator end_itr;

    // Read files from dataset directory
    vector<string>filenames;
    for (fs::directory_iterator itr(p); itr != end_itr; ++itr)
    {
      string current_file = itr->path().string();
      filenames.push_back(current_file);
    }
    sort(filenames.begin(), filenames.end());

    // Images are processed
    Ptr<Feature2D> detector = ORB::create();
    vector <KeyPoint> kp;
    Mat frame;
    namedWindow("Image", 1);
    for(int i=0; i< (int) filenames.size(); i++){
      frame = imread(filenames.at(i));
      detector->detect(frame, kp);
      putText(frame, "Frame: "+to_string(i), Point(50,50), FONT_HERSHEY_SIMPLEX, 1, Scalar(0,200,200), 4);
      drawKeypoints(frame, kp, frame);
      imshow("Image", frame);
      waitKey(33);
    }

  return 0;
}
