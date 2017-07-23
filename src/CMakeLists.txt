cmake_minimum_required(VERSION 3.1)
project(COULOMBSOLVER)
set(COULOMBSOLVER_MAJOR_VERSION 0)
set(COULOMBSOLVER_MINOR_VERSION 1)
set(COULOMBSOLVER_PATCH_VERSION 0)
set(COULOMBSOLVER_VERSION
   ${COULOMBSOLVER_MAJOR_VERSION}.${COULOMBSOLVER_MINOR_VERSION}.${COULOMBSOLVER_PATCH_VERSION})

set( CMAKE_CXX_STANDARD 11)
if(CMAKE_COMPILER_IS_GNUCXX)
   set(CMAKE_CXX_FLAGS "-O3")
endif()

option(CALCULATE_POTENTIAL "Calculate the coulomb Potential." OFF)
if(CALCULATE_POTENTIAL)
   add_definitions(-DCALCULATE_POTENTIAL)
endif()

option(DOUBLE_PRECISION "Set the precision to double." OFF)
if(DOUBLE_PRECISION)
   add_definitions(-DPRECISION=double)
else()
   add_definitions(-DPRECISION=float)
endif()

include_directories(../include)
set(COULOMBSOLVER_SOURCES ../include/mathHelpers.hpp ../include/float_t.hpp ../include/csv.hpp ../include/coulombSolver.hpp
   mathHelpers.cpp csv.cpp coulombSolver.cpp)
add_library(_coulombSolver STATIC ${COULOMBSOLVER_SOURCES})
set(SOURCES main.cpp)
set(EXECUTABLE_OUTPUT_PATH "../bin")
add_executable(coulombSolver ${SOURCES})
target_link_libraries(coulombSolver _coulombSolver)
