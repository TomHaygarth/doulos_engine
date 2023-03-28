#include "app_settings.hpp"

#include "data/json.hpp"
#include "io/file_helper.hpp"
#include "utility/logging.hpp"

SAppSettings load_settings(std::string const & file_path)
{
    SAppSettings settings;

    std::vector<char> settings_file = IO::read_file(file_path);

    if (settings_file.empty() == false)
    {
        std::string file_data(settings_file.data(), settings_file.size());
        Data::SJsonDoc json_doc = Data::json_create_doc();
        bool success = Data::json_parse(file_data, json_doc);

        if (success == true)
        {
            Data::SJsonObj json_obj;
            if (success && Data::json_get_root_obj(json_doc, json_obj) == false)
            {
                success = false;
            }

            int64_t window_width = settings.window_width;
            if (success && Data::json_obj_get_int64(json_obj, "window_width", window_width) == false)
            {
                success = false;
            }
            settings.window_width = window_width;

            int64_t window_height = settings.window_height;
            if (success && Data::json_obj_get_int64(json_obj, "window_height", window_height) == false)
            {
                success = false;
            }
            settings.window_height = window_height;

            Data::SJsonObj test_obj;
            if (success && Data::json_create_obj(test_obj) == false)
            {
                success = false;
            }

            if (success && Data::json_obj_get_obj(json_obj, "testy", test_obj) == false)
            {
                success = false;
            }

            std::string test_string = "";
            if (success && Data::json_obj_get_string(test_obj, "test_string", test_string) == false)
            {
                success = false;
            }
            else
            {
                DEBUG_LOG(test_string);
            }

            bool test_bool = true;
            if (success && Data::json_obj_get_bool(test_obj, "test_bool", test_bool) == false)
            {
                success = false;
            }
            else
            {
                DEBUG_LOG(test_bool ?  "test_bool is true" : "test_bool is false");
            }

            Data::json_destroy_obj(test_obj);
        }

        Data::json_destroy_doc(json_doc);
    }

    return settings;
}

bool save_settings(std::string const & file_path, SAppSettings const & settings)
{
    Data::SJsonDoc json_doc = Data::json_create_doc();
    Data::SJsonObj json_obj;
    bool result = Data::json_get_root_obj(json_doc, json_obj);

    int64_t window_width = settings.window_width;
    if (result && Data::json_obj_set_int64(json_doc, json_obj, "window_width", window_width) == false)
    {
        result = false;
    }

    int64_t window_height = settings.window_height;
    if (result && Data::json_obj_set_int64(json_doc, json_obj, "window_height", window_height) == false)
    {
        result = false;
    }

    Data::SJsonObj test_obj;
    if (result && Data::json_create_obj(test_obj) == false)
    {
        result = false;
    }

    std::string test_string = "Testing string";
    if (result && Data::json_obj_set_string(json_doc, test_obj, "test_string", test_string) == false)
    {
        result = false;
    }

    bool test_bool = false;
    if (result && Data::json_obj_set_bool(json_doc, test_obj, "test_bool", test_bool) == false)
    {
        result = false;
    }

    if (result && Data::json_obj_set_obj(json_doc, json_obj, "testy", test_obj) == false)
    {
        result = false;
    }
    
    if (result == true)
    {
        std::string json_str = Data::json_stringify(json_doc, true);
        
        std::vector<char> file_data(json_str.begin(), json_str.end());
        result = IO::write_file(file_path, file_data);
    }

    Data::json_destroy_obj(test_obj);
    Data::json_destroy_doc(json_doc);
    
    return result;
}
