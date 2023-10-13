#include "log.hh"
#include <ATen/Context.h>
#include <torch/torch.h>

int main(int argc, char *argv[]) {

  torch::hasHIP();
  torch::Device device(torch::kHIP);
  ALOG(MSG) << device.is_hip();
  torch::data::datasets::MNIST data{"./mnist"};

  return 0;
}