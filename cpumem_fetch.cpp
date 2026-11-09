#include "cpumem_fetch.h"
#include "cpumem_monitor.h"
#include <assert.h>
#include <chrono>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <mutex>
#include <queue>
#include <string>
#include <thread>
#include <vector>
SL::NET::CPUMemMonitor mon;
std::queue<double> q;
std::mutex mtx;
double GetMemUsage() {
  auto memusage = mon.getMemoryUsage();
  if (std::isnan(memusage.PhysicalTotalUsed / memusage.PhysicalTotalAvailable))
    return 0;
  else
    return ((double)memusage.PhysicalTotalUsed /
            memusage.PhysicalTotalAvailable);
}
double InternalGetCPUUsage() {
  auto cpuusage = mon.getCPUUsage();
  if (std::isnan(cpuusage.TotalUse))
    return 0;
  else
    return cpuusage.TotalUse;
}
double GetCPUUsage() {
  double v = 0;
  {
    std::lock_guard<std::mutex> lock(mtx);
    if (!q.empty()) {
      v = q.front();
      q.pop();
    }
  }
  return v;
}
void *InitCpuAnalysisWorker() {
  auto pTh = new std::thread([&]() {
    while (true) {
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
      {
        std::lock_guard<std::mutex> lock(mtx);
        double cpu_usage = InternalGetCPUUsage();
        q.push(cpu_usage);
      }
    }
  });
  return pTh;
}
