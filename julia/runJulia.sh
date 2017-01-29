#!/bin/bash

juliaExe=$(which julia)
if [ $? -eq 0 ]; then
 $juliaExe -p 4 helloParallel.jl
else
  echo "No executable found for running julia code"
fi
