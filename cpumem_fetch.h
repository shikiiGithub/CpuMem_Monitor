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

#include <assert.h>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
extern "C" {

LIBX_EXPORT double GetCPUUsage();
LIBX_EXPORT double GetMemUsage();
}
