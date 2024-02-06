#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
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

enum class SelectedMenuItem 
{
    StartPage,
    ListDatabases,
    NewConnection,
    ManageConnections,
    ImportConnection,
    ExportConnection,
    CreateDatabase,
    DeleteDatabase,
    BackupDatabase,
    RestoreDatabase,
    VisualizeDatabase,
    DatabaseLogs,
    Preferences,
    Appearance,
    Docs,
    CheckForUpdates
};

class T_data
{
public:
    //Constructor Destructor
    T_data();
    ~T_data();

    // High-Level Functional Methods
    int                 initImgui();
    bool                setupImGui();
    void                loadIcons();
    GLuint              loadImage(const char* imagePath);

    // UI Render Methods
    void                renderSelected(ImVec2 windowSize);
    void                renderSearchOptions(ImVec2 windowSize);
    void                renderBackground(ImVec2 windowSize);
    void                renderMenuBar();

    // Setter methods
    void                setBackgroundTextureID(const GLuint backgroundTextureID);
    void                setWindow(GLFWwindow* window);
    void                setIo(ImGuiIO* io);
    void                setCurrentMenuItem(SelectedMenuItem menuItem);

    // Getter methods
    GLuint              getBackgroundTextureID() const;
    GLFWwindow*         getWindow();
    ImGuiIO*            getIo();
    SelectedMenuItem    getCurrentMenuItem() const;


    void cleanup();
    bool mainLoop();
    int initGui();

private:
    GLuint                                  _backgroundTextureID;
    std::unordered_map<std::string, GLuint> _iconTextureIDs; 
    GLFWwindow*                             _window;        
    ImGuiIO*                                _io;            
    SelectedMenuItem                        _currentMenuItem;
    
    void                addIconTextureID(const std::string& name, GLuint textureID);
    GLuint              getIconTextureID(const std::string& name) const;

};