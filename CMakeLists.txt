cmake_minimum_required(VERSION 3.8)
project(LearnC)

set(CMAKE_C_STANDARD 99)

#set(SOURCE_FILES main.c L1_Simple.h L1_Simple2.h L2_Point.c)
#add_executable(LearnC ${SOURCE_FILES})
add_executable(01LearnC main.c L1_Simple.h L1_Simple2.h)
add_executable(02Point L2_Point.c)
add_executable(02Method L02Method.c L02mysprintf.h)
add_executable(02PreDeal L02PreDeal.c L2_Simple.h)
add_executable(03Struct L03_Struct.c)
add_executable(03Cpp L03_Cpp.cpp L03_A.c L03_A.h)
add_executable(04Object1 L04_Object/Student.cpp L04_Object/Student.h L04_Object/main.cpp)