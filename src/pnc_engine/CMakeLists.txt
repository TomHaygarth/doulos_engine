cmake_minimum_required(VERSION 3.16)

# Source files
# --------------------------------------------------------------------------------

set (pnc_engine_sources
"project.hpp"

"pnc_runner.cpp"
"pnc_runner.hpp"
)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${pnc_engine_sources})

# Add Library
# --------------------------------------------------------------------------------

add_library(pnc_engine_target STATIC
    ${pnc_engine_sources}
)

target_include_directories(pnc_engine_target PUBLIC
    "./"
)

message ("INCLUDING ${CMAKE_CURRENT_SOURCE_DIR}")

# Precompile Headers
# --------------------------------------------------------------------------------
target_precompile_headers(pnc_engine_target PRIVATE
                          <cinttypes>
                          <string>
                          <vector>
                          )

target_compile_features(pnc_engine_target PUBLIC cxx_std_14)
