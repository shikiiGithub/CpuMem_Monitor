#include "shared_export.h"

#pragma once
#include <iostream>
#ifdef WIN32
#ifdef LIBX_EXPORTS
#define LIBX_EXPORT __declspec(dllexport)
#else
#ifndef LIBX_STATIC
#ifdef LIBX_EXPORTS
#define LIBX_EXPORT __declspec(dllexport)
#else
#define LIBX_EXPORT __declspec(dllimport)
#endif
#else
#define LIBX_EXPORT
#endif
#endif
#else
#define LIBX_EXPORT
#endif

extern "C" {
#include <assert.h>

LIBX_EXPORT double GetCPUUsage();
LIBX_EXPORT double GetMemUsage();
LIBX_EXPORT void *InitCpuAnalysisWorker();
LIBX_EXPORT int luaopen_cpumem_monitor(void *L);
}
