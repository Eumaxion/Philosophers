#!/bin/bash

echo "Test 1: basic simulation"
./philo 5 800 200 200

echo "------------------------"

echo "Test 2: philosopher should die"
./philo 4 310 200 100

echo "------------------------"

echo "Test 3: many philosophers"
./philo 200 800 200 200

echo "------------------------"

echo "Test 4: required meals"
./philo 5 800 200 200 7

echo "------------------------"

echo "Test 5: quick death"
./philo 2 200 100 100

echo "------------------------"

echo "Test finished"
