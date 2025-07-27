#pragma once

#include <cinttypes>
#include <string>
#include <vector>

#include "utility/optional.hpp"

struct SAppSettings
{
    int window_width = 1024;
    int window_height = 576;

    Utility::optional<std::string> last_project;
};


SAppSettings load_settings(std::string const & file_path);

bool save_settings(std::string const & file_path, SAppSettings const & settings);
