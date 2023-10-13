cmake_minimum_required(VERSION 3.22)


set(CMAKE_CXX_STANDARD 23)# turn on the dynamic depends for ninja
set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP 1)
# turn on the experimental API
set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API  "2182bf5c-ef0d-489a-91da-49dbc3090d2a")
#set(CMAKE_EXPERIMENTAL_CXX_MODULE_MAP_FORMAT "gcc")
#set(CMAKE_EXPERIMENTAL_CXX_MODULE_MAP_FLAG  "${compiler_flags_for_module_map} -fmodule-mapper=<MODULE_MAP_FILE>")
project(ppct)

set(ENV{PYTORCH_ROCM_ARCH} gfx1103)
set(HIP_ROOT_DIR /opt/rocm/)
add_executable(pcp main.cc loader.cc model.cc)
target_include_directories(pcp PRIVATE include)

find_package(Torch) 
if(Torch_FOUND)
    target_include_directories(pcp PRIVATE ${TORCH_INCLUDE_DIRS})
    target_link_libraries(pcp ${TORCH_LIBRARIES})

else(Torch_FOUND)
    message(FATAL_ERROR ”Torch library not found”)
endif(Torch_FOUND)


