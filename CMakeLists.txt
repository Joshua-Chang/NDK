cmake_minimum_required(VERSION 3.8)
project(LearnC)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
#set(SOURCE_FILES main.c L1_Simple.h L1_Simple2.h L2_Point.c)
#add_executable(LearnC ${SOURCE_FILES})
add_executable(01LearnC main.c L1_Simple.h L1_Simple2.h)
add_executable(02Point L2_Point.c)
add_executable(02Method L02Method.c L02mysprintf.h)
add_executable(02PreDeal L02PreDeal.c L2_Simple.h)
add_executable(03Struct L03_Struct.c)
add_executable(03Cpp L03_Cpp.cpp L03_A.c L03_A.h)
add_executable(04Object1 L04_Object/Student.cpp L04_Object/Student.h L04_Object/main.cpp L04_Object/Instance.cpp L04_Object/Instance.h L04_Object/Operator.h L04_Object/Extends.h)
add_executable(05Container L05_Container/main.cpp)
add_executable(06Posix L06_Posix/main.cpp L06_Posix/threadsync.cpp)
add_executable(06TheadSync  L06_Posix/threadsync.cpp L06_Posix/safe_queue.h L06_Posix/Ptr.h)

#------------------构建库---------------

#构建库多个源文件

# 定义源文件列表
#AUX_SOURCE_DIRECTORY(. SRC_LIST)
## 指定最终生成的可执行文件的路径
#SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
## 指定生成目标 目标名字随便写；${SRC_LIST}代表前面定义的源文件列表变量
#ADD_LIBRARY(math MODULE ${SRC_LIST})
##mac os x,如果用SHARED则生成的是.dyld动态库，换成MODULE才生成的是.so动态库


#构建库单个源文件
#SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
add_library(my-shrlib SHARED L08_clang/add2.c)
#add_library(my-lib L08_clang/add2.c)

#------------------依赖库---------------

# 指定头文件搜索路径
include_directories(L08_clang)
# 指定引用的外部库的搜索路径
link_directories(L08_clang)
# 指定可执行文件存放目录
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
# 构建可执行程序
add_executable(08Clnag L08_clang/test.c)
#指定要连接的静态库
target_link_libraries(08Clnag my-shrlib)






#加入头文件 查找目录
include_directories("/Library/Java/JavaVirtualMachines/jdk1.8.0_92.jdk/Contents/Home/include")
include_directories("/Library/Java/JavaVirtualMachines/jdk1.8.0_92.jdk/Contents/Home/include/darwin")
add_library(07jni SHARED L07_Jni/main.cpp)