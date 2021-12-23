#!/bin/bash
source /opt/intel/inteloneapi/setvars.sh > /dev/null 2>&1
/bin/echo "##" $(whoami) is compiling
mpiicpc -cxx=icpx -w -c tasks.cc
mpiicpc -cxx=icpx -w -c main.cc
mpiicpc -cxx=icpx -o encryp tasks.o main.o  
   
