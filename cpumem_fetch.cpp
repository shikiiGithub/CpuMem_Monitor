#include "cpumem_fetch.h"
#include "cpumem_monitor.h"
#include <cmath>

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
  cpuusage = mon.getCPUUsage();
  if (std::isnan(cpuusage.TotalUse))
    return 0;
  else
    return cpuusage.TotalUse;
}
