#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "imgui.h"
#include <unordered_map>

#define _THUB_PATH "misc/Thub.jpg"
#define _ICON_APPERANCE "misc/menu_icons/Icon_Apperance.png"
#define _ICON_DATABASE_BACKUP "misc/menu_icons/Icon_Backup.png"
#define _ICON_BUG "misc/menu_icons/Icon_Bug.jpg"
#define _ICON_CREATE_DATABASE "misc/menu_icons/Icon_Create_Database.png"
#define _ICON_DATABASE_LOGS "misc/menu_icons/Icon_Database_Logs.png"
#define _ICON_DATABASE "misc/menu_icons/Icon_Database.png"
#define _ICON_DELETE_DATABASE "misc/menu_icons/Icon_Delete_Database.png"
#define _ICON_DOCS "misc/menu_icons/Icon_Docs.png"
#define _ICON_DATABASE_IMPORT "misc/menu_icons/Icon_Import.png"
#define _ICON_DATABASE_EXPORT "misc/menu_icons/Icon_Export.png"
#define _ICON_HELP "misc/menu_icons/Icon_Help.png"
#define _ICON_LIST_DATABASE "misc/menu_icons/Icon_List_Database.jpg"
#define _ICON_MANAGE_CONNECTION "misc/menu_icons/Icon_Manage_Connection.png"
#define _ICON_NEW_CONNECTION "misc/menu_icons/Icon_New_Connection.png"
#define _ICON_PREFERENCES "misc/menu_icons/Icon_Preferences.png"
#define _ICON_RESTORE "misc/menu_icons/Icon_Restore.png"
#define _ICON_SETTINGS "misc/menu_icons/Icon_Settings.png"
#define _ICON_TOOLS "misc/menu_icons/Icon_Tools.png"
#define _ICON_UPDATE "misc/menu_icons/Icon_Update.png"
#define _ICON_VISUALIZE_DATABASE "misc/menu_icons/Icon_Visualize_Database.png"

class T_data
{
private:
    GLuint      _backgroundTextureID; //Background image
    std::unordered_map<std::string, GLuint> _iconTextureIDs; 
    GLFWwindow* _window;        //App window
    ImGuiIO*    _io;            //TODO: add description!

public:
    //status
    bool        _status;

    //Constructor Destructor
    T_data();
    ~T_data();

    // Setter methods in tData.cpp
    void addIconTextureID(const std::string& name, GLuint textureID);


    // Setter methods
    void setBackgroundTextureID(const GLuint backgroundTextureID) { _backgroundTextureID = backgroundTextureID; }
    void setWindow(GLFWwindow* window) { _window = window; }
    void setIo(ImGuiIO* io) { _io = io; }

    // Getter methods in tData.cpp
    GLuint getIconTextureID(const std::string& name) const;

    // Getter methods
    GLuint getBackgroundTextureID() const { return _backgroundTextureID; }
    GLFWwindow* getWindow() { return _window; }
    ImGuiIO* getIo() { return _io; }


    int initImgui();
    void loadIcons();
    GLuint loadImage(const char* imagePath);
};

