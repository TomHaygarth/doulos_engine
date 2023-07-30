#pragma once

#include <cinttypes>
#include <string>

//------------------------------------------------------------------------------
// Forward declarations
struct SAppSettings;

//------------------------------------------------------------------------------

struct SEditorState
{
    /* data */
    std::string project_path = "";

    bool should_close = false;

    bool display_about = false;
    bool display_imgui_demo = false;
};


//------------------------------------------------------------------------------
// editor functions
void editor_init(SEditorState * editor_state, SAppSettings * app_settings);
void editor_cleanup(SEditorState * editor_state, SAppSettings * app_settings);
void do_editor_ui(SEditorState * editor_state, SAppSettings * app_settings);
