#include <iostream>

#define LANTERN_BUILD

#include "lantern/lantern.h"

#include <torch/torch.h>

#include "utils.hpp"

void *_lantern_Device(const char *type, int64_t index, bool useIndex)
{
  LANTERN_FUNCTION_START
  std::string deviceName(type);
  torch::DeviceType deviceType = torch::DeviceType::CPU;
  torch::DeviceIndex deviceIndex = index;

  if (deviceName == "cuda")
  {
    deviceType = torch::DeviceType::CUDA;
  }
  else if (deviceName == "mkldnn")
  {
    deviceType = torch::DeviceType::MKLDNN;
  }
  else if (deviceName == "opengl")
  {
    deviceType = torch::DeviceType::OPENGL;
  }
  else if (deviceName == "opencl")
  {
    deviceType = torch::DeviceType::OPENCL;
  }
  else if (deviceName == "ideep")
  {
    deviceType = torch::DeviceType::IDEEP;
  }
  else if (deviceName == "hip")
  {
    deviceType = torch::DeviceType::HIP;
  }
  else if (deviceName == "fpga")
  {
    deviceType = torch::DeviceType::FPGA;
  }
  else if (deviceName == "msnpu")
  {
    deviceType = torch::DeviceType::MSNPU;
  }
  else if (deviceName == "xla")
  {
    deviceType = torch::DeviceType::XLA;
  }
  else if (deviceName == "test")
  {
    deviceType = torch::DeviceType::ONLY_FOR_TEST;
  }

  torch::Device device = torch::Device(deviceType);

  if (useIndex)
  {
    device = torch::Device(deviceType, deviceIndex);
  }

  return (void *)new LanternPtr<torch::Device>(device);
  LANTERN_FUNCTION_END
}

const char *_lantern_Device_type(void *device)
{
  LANTERN_FUNCTION_START
  torch::Device type = ((LanternPtr<torch::Device> *)device)->get().type();

  if (type == torch::DeviceType::CPU)
  {
    return "cpu";
  }
  else if (type == torch::DeviceType::CUDA)
  {
    return "cuda";
  }
  else if (type == torch::DeviceType::MKLDNN)
  {
    return "mkldnn";
  }
  else if (type == torch::DeviceType::OPENGL)
  {
    return "opengl";
  }
  else if (type == torch::DeviceType::OPENCL)
  {
    return "opencl";
  }
  else if (type == torch::DeviceType::IDEEP)
  {
    return "ideep";
  }
  else if (type == torch::DeviceType::HIP)
  {
    return "hip";
  }
  else if (type == torch::DeviceType::FPGA)
  {
    return "fpga";
  }
  else if (type == torch::DeviceType::MSNPU)
  {
    return "msnpu";
  }
  else if (type == torch::DeviceType::XLA)
  {
    return "xla";
  }
  else if (type == torch::DeviceType::ONLY_FOR_TEST)
  {
    return "test";
  }
  else
  {
    return "unknown";
  }
  LANTERN_FUNCTION_END
}

int64_t _lantern_Device_index(void *device)
{
  LANTERN_FUNCTION_START
  return ((LanternPtr<torch::Device> *)device)->get().index();
  LANTERN_FUNCTION_END_RET(0)
}