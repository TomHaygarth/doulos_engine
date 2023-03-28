
#define SOKOL_IMPL
#define SOKOL_GLCORE33
#include "sokol_gfx.h"
#include "sokol_app.h"
#include "sokol_log.h"
#include "sokol_glue.h"

#include "io/file_helper.hpp"
#include "utility/logging.hpp"

#include "imgui.h"
#include "util/sokol_imgui.h"

#include "editor/app_settings.hpp"

sg_pass_action pass_action = {};
SAppSettings app_settings;
bool app_settings_dirty = false;
char app_data_folder[] = "/doulos_editor";
char settings_path[] = "/doulos_editor/pnc_editor.ini";

void try_save_settings(void)
{
    std::string app_data_full_path = IO::get_app_data_folder() + app_data_folder;
    std::string full_settings_path = IO::get_app_data_folder() + settings_path;

    if (app_settings_dirty == true)
    {
        if (IO::folder_exists(app_data_full_path) == false)
        {
            if (IO::make_directory(app_data_full_path) == false)
            {
                ERROR_LOG("Failed to make app data folder");
            }
            
        }
        DEBUG_LOG("Saving Settings...");
        if (save_settings(full_settings_path, app_settings) == false)
        {
            ERROR_LOG("Failed to save settings");
        }
        else
        {
            DEBUG_LOG("Saving complete!");
            app_settings_dirty = false;
        }
    }
}

void init(void)
{
    sg_desc gfx_desc = {};
    gfx_desc.context = sapp_sgcontext();
    gfx_desc.logger.func = slog_func;
    
    sg_setup(&gfx_desc);
    
    sg_color_attachment_action clear_colour_action ={};
    clear_colour_action.action=SG_ACTION_CLEAR;
    clear_colour_action.value={0.0f, 0.0f, 0.0f, 1.0f};
    
    pass_action.colors[0] = clear_colour_action;

    simgui_desc_t imgui_desc;
    simgui_setup(&imgui_desc);
}

void frame(void)
{
    simgui_frame_desc_t frame_desc;
    frame_desc.width = sapp_width();
    frame_desc.height = sapp_height();
    frame_desc.delta_time = sapp_frame_duration();
    frame_desc.dpi_scale = sapp_dpi_scale();
    
    simgui_new_frame(&frame_desc);

//    float g = pass_action.colors[0].value.g + 0.01f;
//    pass_action.colors[0].value.g = (g > 1.0f) ? 0.0f : g;
    sg_begin_default_pass(&pass_action, sapp_width(), sapp_height());
    simgui_render();
    sg_end_pass();
    sg_commit();
}

void cleanup(void)
{
    try_save_settings();

    simgui_shutdown();
    sg_shutdown();
}

void event_cb(const sapp_event * event)
{
    bool imgui_keybaord_capture = simgui_handle_event(event);
    
    if (imgui_keybaord_capture == true)
    {
        
    }
    else
    {
        switch (event->type)
        {
            case SAPP_EVENTTYPE_RESIZED:
            {
                app_settings_dirty = true;
                app_settings.window_width = event->window_width;
                app_settings.window_height = event->window_height;
                break;
            }

            case SAPP_EVENTTYPE_QUIT_REQUESTED:
            {
                DEBUG_LOG("Quit requested");
                try_save_settings();
                break;
            }

            default:
            {
                break;
            }
        }
    }
}

sapp_desc sokol_main(int argc, char* argv[])
{
    if (argc > 0)
    {
        for(int i = 0; i < argc; ++i)
        {
            std::string arg_print(argv[i]);
            DEBUG_LOG(arg_print);
        }
    }

    std::string full_settings_path = IO::get_app_data_folder() + settings_path;
    DEBUG_LOG(full_settings_path);
    
    app_settings = load_settings(full_settings_path);

    sapp_desc app_desc;
    
    app_desc.init_cb = init;
    app_desc.frame_cb = frame;
    app_desc.cleanup_cb = cleanup;
    app_desc.event_cb = event_cb;
    app_desc.width = app_settings.window_width;
    app_desc.height = app_settings.window_height;
    app_desc.window_title = "Doulos PnC Editor";
    app_desc.logger.func = slog_func;
    
    return app_desc;
}
