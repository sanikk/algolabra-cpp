# Set the component's name
set(TARGET_NAME scenario_service)

# Add the target as a library
add_library(${TARGET_NAME}
    scenario_service.cpp
    filereader.cpp
)

# Include directories for this target
target_include_directories(${TARGET_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR} # Includes scenario_service.h, filereader.h, and scenario.h
)

# Specify the target's properties (e.g., C++ standard)
target_compile_features(${TARGET_NAME} PRIVATE cxx_std_17)
