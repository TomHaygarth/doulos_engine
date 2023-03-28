#pragma once

#include <cinttypes>
#include <string>
#include <vector>

struct SAppSettings
{
    int window_width = 1024;
    int window_height = 576;
};


SAppSettings load_settings(std::string const & file_path);

bool save_settings(std::string const & file_path, SAppSettings const & settings);
