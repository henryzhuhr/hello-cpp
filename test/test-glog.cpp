#include <iostream>
#include <string>
#include <glog/logging.h>

int main(int argc, char* argv[])
{
    auto log_file=argv[1];
    std::cout << " --- --- Test glog --- --- " << std::endl;
    // Initialize Google’s logging library.
    std::cout<< "Log file in "<<log_file <<std::endl;

    FLAGS_logbufsecs = 0;
    google::InitGoogleLogging(log_file);
    FLAGS_log_dir=std::string("./logs");


    // ...
    int num_cookies = 10;
    LOG(INFO) << "Found " << num_cookies << " cookies";
}