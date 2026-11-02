#include "cpumem_fetch.h"
#include "cpumem_monitor.h"
#include <cmath>
#include <iostream>
#include <thread>

SL::NET::CPUMemMonitor mon;

double GetMemUsage() {
  auto memusage = mon.getMemoryUsage();

  if (std::isnan(memusage.PhysicalTotalUsed / memusage.PhysicalTotalAvailable))
    return 0;
  else
    return ((double)memusage.PhysicalTotalUsed /
            memusage.PhysicalTotalAvailable);
}
double GetCPUUsage() {

  auto cpuusage = mon.getCPUUsage();

  std::this_thread::sleep_for(std::chrono::microseconds(200));

  cpuusage = mon.getCPUUsage();
  std::cout << " cpu :" << cpuusage.TotalUse << std::endl;
  if (std::isnan(cpuusage.TotalUse))
    return 0;
  else
    return cpuusage.TotalUse;
}
