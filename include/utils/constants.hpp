// Constants.h
#pragma once

#include <string>

namespace AppConfig {
    //Application Information not used yet
    const std::string APP_NAME = "Data Manager";
    const std::string APP_VERSION = "1.0.0";
    const std::string APP_AUTHOR = "";
    const std::string APP_EMAIL = "";

    //Paths to the images
    const char* const _THUB_PATH = "misc/Thub.jpg";
    const char* const _ICON_APPERANCE = "misc/menu_icons/Icon_Apperance.png";
    const char* const _ICON_DATABASE_BACKUP = "misc/menu_icons/Icon_Backup.png";
    const char* const _ICON_BUG = "misc/menu_icons/Icon_Bug.jpg";
    const char* const _ICON_CREATE_DATABASE = "misc/menu_icons/Icon_Create_Database.png";
    const char* const _ICON_DATABASE_LOGS = "misc/menu_icons/Icon_Database_Logs.png";
    const char* const _ICON_DATABASE = "misc/menu_icons/Icon_Database.png";
    const char* const _ICON_DELETE_DATABASE = "misc/menu_icons/Icon_Delete_Database.png";
    const char* const _ICON_DOCS = "misc/menu_icons/Icon_Docs.png";
    const char* const _ICON_DATABASE_IMPORT = "misc/menu_icons/Icon_Import.png";
    const char* const _ICON_DATABASE_EXPORT = "misc/menu_icons/Icon_Export.png";
    const char* const _ICON_HELP = "misc/menu_icons/Icon_Help.png";
    const char* const _ICON_LIST_DATABASE = "misc/menu_icons/Icon_List_Database.jpg";
    const char* const _ICON_MANAGE_CONNECTION = "misc/menu_icons/Icon_Manage_Connection.png";
    const char* const _ICON_NEW_CONNECTION = "misc/menu_icons/Icon_New_Connection.png";
    const char* const _ICON_PREFERENCES = "misc/menu_icons/Icon_Preferences.png";
    const char* const _ICON_RESTORE = "misc/menu_icons/Icon_Restore.png";
    const char* const _ICON_SETTINGS = "misc/menu_icons/Icon_Settings.png";
    const char* const _ICON_TOOLS = "misc/menu_icons/Icon_Tools.png";
    const char* const _ICON_UPDATE = "misc/menu_icons/Icon_Update.png";
    const char* const _ICON_VISUALIZE_DATABASE = "misc/menu_icons/Icon_Visualize_Database.png";

    //MenuBar Items
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
};