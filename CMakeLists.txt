cmake_minimum_required(VERSION 2.8)
project(bpmlm)

set (FLAGS "-std=c++11")
set (CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} ${FLAGS})

set (SRC_DIR ./src)

include_directories(${SRC_DIR})

option(TRACE "Enable traces..." OFF)
if (TRACE)
  message("-- Turning traces on...")
  add_definitions("-DTRACE")
endif(TRACE)

option(DEBUG "Enable debug prints..." OFF)
if (DEBUG)
  message("-- Turning debug prints on...")
  add_definitions("-DDEBUG")
endif(DEBUG)

set (SIM_HDR 
  ${SRC_DIR}/Person.h
  ${SRC_DIR}/Chance.h
  ${SRC_DIR}/Simulation.h
  ${SRC_DIR}/ProductLine.h
)

set (SIM_SRC 
  ${SRC_DIR}/main.cpp
  ${SRC_DIR}/Person.cpp
  ${SRC_DIR}/Chance.cpp
  ${SRC_DIR}/Simulation.cpp
  ${SRC_DIR}/ProductLine.cpp
)

add_subdirectory(tests)

add_executable(bpmlm ${SIM_HDR} ${SIM_SRC})
