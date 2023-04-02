#pragma once

#include <cinttypes>

//------------------------------------------------------------------------------
// Forward declarations
struct SAppSettings;

//------------------------------------------------------------------------------

struct SEditorState
{
    /* data */
    bool should_close = false;

    bool display_about = false;
    bool display_imgui_demo = false;
};

void do_editor_ui(SEditorState * editor_state, SAppSettings * app_settings);
