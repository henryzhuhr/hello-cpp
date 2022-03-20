#include <iostream>
#include <gflags/gflags.h>
 
DEFINE_bool(isvip, false, "If Is VIP");
DEFINE_string(ip, "127.0.0.1", "connect ip");
DECLARE_int32(port);
DEFINE_int32(port, 80, "listen port");
 
int main(int argc, char** argv)
{
  std::cout<< " --- --- Test gflags --- --- " <<std::endl;
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  std::cout<<"ip:"<<FLAGS_ip<<std::endl;
  std::cout<<"port:"<<FLAGS_port<<std::endl;
  if (FLAGS_isvip)
  {
      std::cout<<"isvip:"<<FLAGS_isvip<<std::endl;
  }
  google::ShutDownCommandLineFlags();
  return 0;
}

