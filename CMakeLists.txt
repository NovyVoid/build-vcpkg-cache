cmake_minimum_required(VERSION 3.21)
project(CacheTriggerProject)

# Set C++ standard (Qt6 requires at least C++17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- Section 1: OpenCV ---
find_package(OpenCV REQUIRED)

# --- Section 2: Qt6 ---
# We need Core, Gui, and Widgets to trigger a proper build
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

# --- Section 3: The Target ---
# This tells CMake to actually create a program from your dummy file
add_executable(dummy_app dummy.cpp)

# --- Section 4: Linking ---
# This is the most important part! 
# It forces vcpkg to actually provide the binaries.
target_link_libraries(dummy_app PRIVATE 
    Qt6::Widgets 
    ${OpenCV_LIBS}
)

# --- Section 5: Windows DLL Copying ---
# This ensures the DLLs are collected in the build folder
if(WIN32)
    add_custom_command(TARGET dummy_app POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_RUNTIME_DLLS:dummy_app>
            $<TARGET_FILE_DIR:dummy_app>
        COMMAND_EXPAND_LISTS
    )
endif()