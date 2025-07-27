#include "editor_ui.hpp"

#include "editor/app_settings.hpp"

#include "imgui.h"

void editor_init(SEditorState * editor_state, SAppSettings * app_settings)
{
    if (app_settings != nullptr)
    {
        // TODO: load up last project
        if (app_settings->last_project.hasValue())
        {
            editor_state->project_path = app_settings->last_project.value();
        }
    }
}

void editor_cleanup(SEditorState * editor_state, SAppSettings * app_settings)
{
    if (app_settings != nullptr)
    {
        // TODO: load up last project
        if (app_settings->last_project.hasValue())
        {
            editor_state->project_path = app_settings->last_project.value();
        }
    }
}


void do_editor_ui(SEditorState * editor_state, SAppSettings * app_settings)
{
    ImGui::BeginMainMenuBar();

    if (ImGui::BeginMenu("File"))
    {
        if (ImGui::MenuItem("New..."))
        {
            // TODO:
        }
        
        if (ImGui::MenuItem("Save"))
        {
            // TODO:
        }
        
        if (ImGui::MenuItem("Save Project"))
        {
            // TODO:
            if (app_settings != nullptr)
            {
                
            }
        }

        ImGui::Separator();

        if (ImGui::MenuItem("Exit"))
        {
            editor_state->should_close = true;
        }

        ImGui::EndMenu();
    }

    if (ImGui::BeginMenu("Help"))
    {
        if (ImGui::MenuItem("About"))
        {
            editor_state->display_about = true;
        }

        ImGui::Separator();

        if (ImGui::MenuItem("Display ImGui demo ", "", &editor_state->display_imgui_demo))
        {
//            m_display_imgui_demo = !m_display_imgui_demo;
        }
        ImGui::EndMenu();
    }
    ImGui::EndMainMenuBar();
    
    if (editor_state->display_about == true)
    {
        editor_state->display_about = false;
        ImGui::OpenPopup("About - Doulos PnC Editor");
    }

    bool unused_close = true;
    if (ImGui::BeginPopupModal("About - Doulos PnC Editor", &unused_close, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize))
    {
        ImGui::Text("Doulos PnC engine editor\n" \
                    "Version 0.1a\n" \
                    "(c) 2023 Tom Haygarth");

        ImGui::EndPopup();
    }
    
    if (editor_state->display_imgui_demo == true)
    {
        ImGui::ShowDemoWindow();
    }
}
