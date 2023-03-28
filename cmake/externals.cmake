cmake_minimum_required(VERSION 3.16)

set (EXTERNAL_SRC_DIR "${PROJECT_SOURCE_DIR}/externals")

# Desktop includes
# --------------------------------------------------------------------------------
if (BUILD_FOR_DESKTOP)

    # Sokol
    # --------------------------------------------------------------------------------
    include_directories(SYSTEM "${EXTERNAL_SRC_DIR}/sokol")

    # ImGui
    # --------------------------------------------------------------------------------
    include_directories(SYSTEM "${EXTERNAL_SRC_DIR}/imgui")

    set (imgui_sources
    "${EXTERNAL_SRC_DIR}/imgui/imgui.cpp"
    "${EXTERNAL_SRC_DIR}/imgui/imgui.h"
    "${EXTERNAL_SRC_DIR}/imgui/imgui_internal.h"
    "${EXTERNAL_SRC_DIR}/imgui/imgui_demo.cpp"
    "${EXTERNAL_SRC_DIR}/imgui/imgui_draw.cpp"
    "${EXTERNAL_SRC_DIR}/imgui/imgui_tables.cpp"
    "${EXTERNAL_SRC_DIR}/imgui/imgui_widgets.cpp"
    "${EXTERNAL_SRC_DIR}/imgui/misc/cpp/imgui_stdlib.cpp"
    "${EXTERNAL_SRC_DIR}/imgui/misc/cpp/imgui_stdlib.h"
    )


    # ImGui node editor
    # --------------------------------------------------------------------------------
    include_directories(SYSTEM "${EXTERNAL_SRC_DIR}/imgui-node-editor")
    set( imgui_node_editor_sources
    "${EXTERNAL_SRC_DIR}/imgui-node-editor/crude_json.cpp"
    "${EXTERNAL_SRC_DIR}/imgui-node-editor/crude_json.h"
    "${EXTERNAL_SRC_DIR}/imgui-node-editor/imgui_bezier_math.h"
    "${EXTERNAL_SRC_DIR}/imgui-node-editor/imgui_bezier_math.inl"
    "${EXTERNAL_SRC_DIR}/imgui-node-editor/imgui_canvas.cpp"
    "${EXTERNAL_SRC_DIR}/imgui-node-editor/imgui_canvas.cpp"
    "${EXTERNAL_SRC_DIR}/imgui-node-editor/imgui_canvas.h"
    "${EXTERNAL_SRC_DIR}/imgui-node-editor/imgui_canvas.h"
    "${EXTERNAL_SRC_DIR}/imgui-node-editor/imgui_extra_math.h"
    "${EXTERNAL_SRC_DIR}/imgui-node-editor/imgui_extra_math.inl"
    "${EXTERNAL_SRC_DIR}/imgui-node-editor/imgui_node_editor_api.cpp"
    "${EXTERNAL_SRC_DIR}/imgui-node-editor/imgui_node_editor_internal.h"
    "${EXTERNAL_SRC_DIR}/imgui-node-editor/imgui_node_editor_internal.inl"
    "${EXTERNAL_SRC_DIR}/imgui-node-editor/imgui_node_editor.cpp"
    "${EXTERNAL_SRC_DIR}/imgui-node-editor/imgui_node_editor.h"
    "${EXTERNAL_SRC_DIR}/imgui-node-editor/misc/imgui_node_editor.natvis"
    )

endif()