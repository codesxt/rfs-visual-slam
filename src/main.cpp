#include <string>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/features2d.hpp>
#include "pose.hpp"
#include <boost/program_options.hpp>
#include <boost/filesystem.hpp>

using namespace std;
namespace po = boost::program_options;

int main( int argc, char** argv )	{
  string dataset_path = "";
  string ground_truth_path = "";

  po::options_description desc("Random Finite Set");
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

  return 0;
}
