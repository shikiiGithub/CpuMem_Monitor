// luacpumem.cpp
#include "./cpumem_fetch.h" // 包含你原有的导出函数声明
extern "C" {
#include "/home/shikii/下载/lua-5.4.1/lauxlib.h"
}
// 1. 为每个要暴露给 Lua 的函数编写一个包装函数
// 这些包装函数负责从 Lua 栈中获取参数，并压入返回值

// GetCPUUsage 没有参数，返回一个 number
static int l_get_cpu_usage(lua_State *L) {
  double usage = GetCPUUsage(); // 调用你的实际函数
  lua_pushnumber(L, usage);     // 将结果压入 Lua 栈
  return 1;                     // 告诉 Lua 返回了 1 个值
}

// GetMemUsage 同理
static int l_get_mem_usage(lua_State *L) {
  double usage = GetMemUsage();
  lua_pushnumber(L, usage);
  return 1;
}

// InitCpuAnalysisWorker 没有参数，也没有返回值
static int l_init_worker(lua_State *L) {
  InitCpuAnalysisWorker();
  return 0; // 返回 0 个值
}

// 2. 定义一个注册表，将 Lua 中使用的名称映射到你的包装函数
static const luaL_Reg cpumem_lib[] = {
    {"get_cpu_usage", l_get_cpu_usage},
    {"get_mem_usage", l_get_mem_usage},
    {"init_worker", l_init_worker},
    {NULL, NULL} // 数组必须以 NULL 结尾
};

// 3. 定义模块入口函数
// 函数名必须是 luaopen_ + 你的模块名。假设你的模块名为 "cpumem"
extern "C" int luaopen_cpumem_monitor(lua_State *L) {
  luaL_newlib(L, cpumem_lib); // Lua 5.2+ 创建新表并注册函数
  return 1;                   // 返回这个表
}
