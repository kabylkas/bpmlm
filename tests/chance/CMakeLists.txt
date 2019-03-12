cmake_minimum_required(VERSION 2.8)

project(chance_test)

set (SRC_DIR ../../src)

set (SIM_HDR 
  ${SRC_DIR}/Chance.h
)

set (SIM_SRC 
  ${SRC_DIR}/Chance.cpp
)
add_executable(chance_test chance_test.cpp ${SIM_HDR} ${SIM_SRC})
