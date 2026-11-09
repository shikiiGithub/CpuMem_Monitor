#include "cpumem_fetch.h"
#include <iostream>
#include <thread>

std::thread *ShowCpuMemRatio() {
  std::thread *th = new std::thread([&]() {
    while (true) {
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
      double lf_memRatio = GetMemUsage();
      double lf_cpuRation = GetCPUUsage();
      std::cout << "cpu ratio:" << lf_cpuRation << " mem ratio:" << lf_memRatio
                << std::endl;
    }
  });
  return th;
}
int main() {
  auto pTh1 = (std::thread *)InitCpuAnalysisWorker();
  auto pTh2 = ShowCpuMemRatio();
  pTh1->join();
  pTh2->join();
}
