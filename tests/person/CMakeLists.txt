cmake_minimum_required(VERSION 2.8)

project(person_test)

set (SRC_DIR ../../src)

set (SIM_HDR 
  ${SRC_DIR}/Chance.h
  ${SRC_DIR}/Person.h
)

set (SIM_SRC 
  ${SRC_DIR}/Chance.cpp
  ${SRC_DIR}/Person.cpp
)
add_executable(person_test person_test.cpp ${SIM_HDR} ${SIM_SRC})
