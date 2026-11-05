cmake_minimum_required(VERSION 3.8)
project(cpumem_monitor)
set (forWezterm "ForWeztermCpuMem")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) 
option(BUILD_SHARED_LIBS "Build shared library" OFF) 

if(MSVC)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
else()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic")
endif()

add_library(${PROJECT_NAME} SHARED cpumem_monitor.h cpumem_monitor.cpp cpumem_fetch.cpp luaCPUMem.cpp )
# add_executable(${forWezterm} cpumem_monitor.h cpumem_monitor.cpp cpumem_fetch.cpp main.cpp luaCPUMem.cpp)
# 根据平台定义宏
if (WIN32)
    target_compile_definitions(${PROJECT_NAME} PRIVATE LIBX_EXPORTS)
else()
    # 添加 -fPIC 编译选项
   # set(CMAKE_POSITION_INDEPENDENT_CODE ON)
    set_property(TARGET ${PROJECT_NAME} PROPERTY  POSITION_INDEPENDENT_CODE ON) #相当于指定-fPIC编译选项    
    
    # target_link_libraries( ${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/liblua.a )
endif()

install (TARGETS ${PROJECT_NAME}  
	RUNTIME DESTINATION bin
	ARCHIVE DESTINATION lib
	LIBRARY DESTINATION lib
)

install (FILES 
	cpumem_monitor.h 
	DESTINATION include
)
add_subdirectory(test)

