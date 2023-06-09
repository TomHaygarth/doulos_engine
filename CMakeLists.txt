cmake_minimum_required(VERSION 3.16)

message("Setting Module path to include : ${CMAKE_MODULE_PATH}")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

# list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

foreach(module_path ${CMAKE_MODULE_PATH})
    message("Setting Module path to include : ${module_path}")
endforeach()


# Force Zero Check on xcode projects
set (CMAKE_XCODE_GENERATE_TOP_LEVEL_PROJECT_ONLY ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Platform properties
# --------------------------------------------------------------------------------
set (BUILD_FOR_DESKTOP OFF CACHE INTERNAL "" FORCE)
set (BUILD_FOR_MAC OFF CACHE INTERNAL "" FORCE)
set (BUILD_FOR_WINDOWS OFF CACHE INTERNAL "" FORCE)
set (BUILD_FOR_LINUX OFF CACHE INTERNAL "" FORCE)
set (BUILD_FOR_UWP OFF CACHE INTERNAL "" FORCE)

if (APPLE)
    set (DEFAULT_PLATFORM "macos")
elseif (WIN32)
    set (DEFAULT_PLATFORM "windows")
else()
    set (DEFAULT_PLATFORM "linux")
endif()

set (Platform ${DEFAULT_PLATFORM} CACHE STRING "Platform to build for")

if (${Platform} STREQUAL "macos")

    set (BUILD_FOR_DESKTOP ON CACHE INTERNAL "" FORCE)
    set (BUILD_FOR_MAC ON CACHE INTERNAL "" FORCE)
    set (CMAKE_OSX_DEPLOYMENT_TARGET "10.13" CACHE STRING "Minimum OS X deployment version"  FORCE)
    set (CMAKE_XCODE_GENERATE_SCHEME TRUE)

elseif (${Platform} STREQUAL "windows")

    set (BUILD_FOR_DESKTOP ON CACHE INTERNAL "" FORCE)
    set (BUILD_FOR_WINDOWS ON CACHE INTERNAL "" FORCE)

elseif (${Platform} STREQUAL "linux")

    set (BUILD_FOR_DESKTOP ON CACHE INTERNAL "" FORCE)
    set (BUILD_FOR_LINUX ON CACHE INTERNAL "" FORCE)

elseif  (${Platform} STREQUAL "uwp")

set (BUILD_FOR_UWP ON CACHE INTERNAL "" FORCE)

endif()


# Render properties
# --------------------------------------------------------------------------------
set (BUILD_RENDERER_VULKAN OFF CACHE INTERNAL "" FORCE)
set (BUILD_RENDERER_OPENGL OFF CACHE INTERNAL "" FORCE)
set (BUILD_RENDERER_DX12 OFF CACHE INTERNAL "" FORCE)

if (BUILD_FOR_DESKTOP)

    set (Renderer "vulkan" CACHE STRING "Which renderer to use [vulkan, opengl, dx12]")

    if (${Renderer} STREQUAL "vulkan")
        set (BUILD_RENDERER_VULKAN ON CACHE INTERNAL "" FORCE)

    elseif (${Renderer} STREQUAL "opengl")
        set (BUILD_RENDERER_OPENGL ON CACHE INTERNAL "" FORCE)

    elseif (${Renderer} STREQUAL "dx12")
        set (BUILD_RENDERER_DX12 ON CACHE INTERNAL "" FORCE)

    endif()

elseif(BUILD_FOR_UWP)
    set(CMAKE_SYSTEM_NAME WindowsStore)
    set(CMAKE_SYSTEM_VERSION 10.0)
    set (BUILD_RENDERER_DX12 ON CACHE INTERNAL "" FORCE)
endif()

# Options
# --------------------------------------------------------------------------------

option(BUILD_EDITOR "Build the editor for the project" ON)

project(DoulosPnC LANGUAGES CXX)

include(externals)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")

# Engine and Editor
# --------------------------------------------------------------------------------

add_subdirectory(../doulos_framework ${CMAKE_BINARY_DIR}/framework)


add_subdirectory(src/pnc_engine)

if (BUILD_EDITOR AND BUILD_FOR_DESKTOP)
	add_subdirectory(src/editor)
endif()