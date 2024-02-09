#include "Data.hpp"

void Data::renderSelected(const ImVec2& windowSize)
{
    switch (this->getCurrentMenuItem())
    {
        case AppConfig::SelectedMenuItem::StartPage:
        {
            this->renderBackground(windowSize);
            break;
        }
        case AppConfig::SelectedMenuItem::ListDatabases:
        {
            //renderListDataBases(windowSize);
            break;
        }
        case AppConfig::SelectedMenuItem::NewConnection:
            break;
        case AppConfig::SelectedMenuItem::ManageConnections:
            break;
        case AppConfig::SelectedMenuItem::ImportConnection:
            break;
        case AppConfig::SelectedMenuItem::ExportConnection:
            break;
        case AppConfig::SelectedMenuItem::CreateDatabase:
            break;
        case AppConfig::SelectedMenuItem::DeleteDatabase:
            break;
        case AppConfig::SelectedMenuItem::BackupDatabase:
            break;
        case AppConfig::SelectedMenuItem::RestoreDatabase:
            break;
        case AppConfig::SelectedMenuItem::VisualizeDatabase:
            break;
        case AppConfig::SelectedMenuItem::DatabaseLogs:
            break;
        case AppConfig::SelectedMenuItem::Preferences:
            break;
        case AppConfig::SelectedMenuItem::Appearance:
            break;
        case AppConfig::SelectedMenuItem::Docs:
            break;
        case AppConfig::SelectedMenuItem::CheckForUpdates:
            break;
        default:
        {
            renderBackground(windowSize);
            break;
        }
    }
}

void Data::renderMenuBar()
{
    if (ImGui::BeginMainMenuBar())
    {
        ImGui::Image(reinterpret_cast<void*>(static_cast<intptr_t>(getIconTextureID(AppConfig::_ICON_DATABASE))), ImVec2(18, 18));
        ImGui::SameLine();
        if (ImGui::BeginMenu("Database"))
        {
            ImGui::Image(reinterpret_cast<void*>(static_cast<intptr_t>(getIconTextureID(AppConfig::_ICON_LIST_DATABASE))), ImVec2(18, 18));
            ImGui::SameLine();
            if (ImGui::MenuItem("List Databases"))
            {
                //setCurrentMenuItem(AppConfig::SelectedMenuItem::ListDatabases);
                std::cout << "List all detected databases" << std::endl;
            }
            ImGui::Image(reinterpret_cast<void*>(static_cast<intptr_t>(getIconTextureID(AppConfig::_ICON_NEW_CONNECTION))), ImVec2(18, 18));
            ImGui::SameLine();
            if (ImGui::MenuItem("New Connection"))
            {
                //setCurrentMenuItem(AppConfig::SelectedMenuItem::NewConnection);
                std::cout << "Open the 'New Connection' Input window" << std::endl;
            }
            ImGui::Image(reinterpret_cast<void*>(static_cast<intptr_t>(getIconTextureID(AppConfig::_ICON_MANAGE_CONNECTION))), ImVec2(18, 18));
            ImGui::SameLine();
            if (ImGui::MenuItem("Manage Connections"))
            {
                //setCurrentMenuItem(AppConfig::SelectedMenuItem::ManageConnections);
                std::cout << "Open the 'Manage Connections' window" << std::endl;
            }
            ImGui::Image(reinterpret_cast<void*>(static_cast<intptr_t>(getIconTextureID(AppConfig::_ICON_DATABASE_IMPORT))), ImVec2(18, 18));
            ImGui::SameLine();
            if (ImGui::MenuItem("Import Connection"))
            {
                //setCurrentMenuItem(AppConfig::SelectedMenuItem::ImportConnection);
                std::cout << "Open the 'Import Connection' window" << std::endl;
            }
            ImGui::Image(reinterpret_cast<void*>(static_cast<intptr_t>(getIconTextureID(AppConfig::_ICON_DATABASE_EXPORT))), ImVec2(18, 18));
            ImGui::SameLine();
            if (ImGui::MenuItem("Export Connection"))
            {
                //setCurrentMenuItem(AppConfig::SelectedMenuItem::ExportConnection);
                std::cout << "Open the 'Export Connection' window" << std::endl;
            }
            ImGui::Image(reinterpret_cast<void*>(static_cast<intptr_t>(getIconTextureID(AppConfig::_ICON_CREATE_DATABASE))), ImVec2(18, 18));
            ImGui::SameLine();
            if (ImGui::MenuItem("Create Database"))
            {
                //setCurrentMenuItem(AppConfig::SelectedMenuItem::CreateDatabase);
                std::cout << "Open the 'Create Database' window" << std::endl;
            }
            ImGui::Image(reinterpret_cast<void*>(static_cast<intptr_t>(getIconTextureID(AppConfig::_ICON_DELETE_DATABASE))), ImVec2(18, 18));
            ImGui::SameLine();
            if (ImGui::MenuItem("Delete Database"))
            {
                //setCurrentMenuItem(AppConfig::SelectedMenuItem::DeleteDatabase);
                std::cout << "Open the 'Delete Database' window" << std::endl;
            }
            ImGui::Image(reinterpret_cast<void*>(static_cast<intptr_t>(getIconTextureID(AppConfig::_ICON_DATABASE_BACKUP))), ImVec2(18, 18));
            ImGui::SameLine();
            if (ImGui::MenuItem("Backup Database"))
            {
                //setCurrentMenuItem(AppConfig::SelectedMenuItem::BackupDatabase);
                std::cout << "Open the 'Backup Database' window" << std::endl;
            }
            ImGui::Image(reinterpret_cast<void*>(static_cast<intptr_t>(getIconTextureID(AppConfig::_ICON_RESTORE))), ImVec2(18, 18));
            ImGui::SameLine();
            if (ImGui::MenuItem("Restore Database"))
            {
                //setCurrentMenuItem(AppConfig::SelectedMenuItem::RestoreDatabase);
                std::cout << "Open the 'Restore Database' window" << std::endl;
            }
            ImGui::EndMenu();
        }
        ImGui::Image(reinterpret_cast<void*>(static_cast<intptr_t>(getIconTextureID(AppConfig::_ICON_TOOLS))), ImVec2(18, 18));
        ImGui::SameLine();
        if (ImGui::BeginMenu("Tools"))
        {
            //ImGui::Image(reinterpret_cast<void*>(static_cast<intptr_t>(getIconTextureID(AppConfig::_ICON_VISUALIZE_DATABASE))), ImVec2(18, 18));
            ImGui::SameLine();
            if (ImGui::MenuItem("Visualize Database"))
            {
                setCurrentMenuItem(AppConfig::SelectedMenuItem::VisualizeDatabase);
                std::cout << "Open the 'Visualize Database' window" << std::endl;
            }
            //ImGui::Image(reinterpret_cast<void*>(static_cast<intptr_t>(getIconTextureID(AppConfig::_ICON_DATABASE_LOGS))), ImVec2(18, 18));
            ImGui::SameLine();
            if (ImGui::MenuItem("Database Logs"))
            {
                setCurrentMenuItem(AppConfig::SelectedMenuItem::DatabaseLogs);
                std::cout << "Open the 'Database Logs' window" << std::endl;
            }
            ImGui::EndMenu();
        }
        ImGui::Image(reinterpret_cast<void*>(static_cast<intptr_t>(getIconTextureID(AppConfig::_ICON_SETTINGS))), ImVec2(18, 18));
        ImGui::SameLine();
        if (ImGui::BeginMenu("Settings"))
        {
            ImGui::Image(reinterpret_cast<void*>(static_cast<intptr_t>(getIconTextureID(AppConfig::_ICON_PREFERENCES))), ImVec2(18, 18));
            ImGui::SameLine();
            if (ImGui::MenuItem("Preferences"))
            {
                //setCurrentMenuItem(AppConfig::SelectedMenuItem::Preferences);
                std::cout << "Open the 'Preferences' window" << std::endl;
            }
            ImGui::Image(reinterpret_cast<void*>(static_cast<intptr_t>(getIconTextureID(AppConfig::_ICON_APPERANCE))), ImVec2(18, 18));
            ImGui::SameLine();
            if (ImGui::MenuItem("Appearance"))
            {
                //setCurrentMenuItem(AppConfig::SelectedMenuItem::Appearance);
                std::cout << "Open the 'Appearance' window" << std::endl;
            }
            ImGui::EndMenu();
        }
        ImGui::Image(reinterpret_cast<void*>(static_cast<intptr_t>(getIconTextureID(AppConfig::_ICON_HELP))), ImVec2(18, 18));
        ImGui::SameLine();
        if (ImGui::BeginMenu("Help"))
        {
            ImGui::Image(reinterpret_cast<void*>(static_cast<intptr_t>(getIconTextureID(AppConfig::_ICON_DOCS))), ImVec2(18, 18));
            ImGui::SameLine();
            if (ImGui::MenuItem("Docs"))
            {
                //setCurrentMenuItem(AppConfig::SelectedMenuItem::Docs);
                std::cout << "Open the 'Docs' window" << std::endl;
            }
            ImGui::Image(reinterpret_cast<void*>(static_cast<intptr_t>(getIconTextureID(AppConfig::_ICON_UPDATE))), ImVec2(18, 18));
            ImGui::SameLine();
            if (ImGui::MenuItem("Check for Updates"))
            {
                //setCurrentMenuItem(AppConfig::SelectedMenuItem::CheckForUpdates);
                std::cout << "Open the 'Check for Updates' window" << std::endl;
            }
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }
}

//complete window background
void Data::renderBackground(const ImVec2& windowSize)
{
    //render background image
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
    ImGui::Begin("##Background", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoInputs);
    ImGui::SetWindowPos(ImVec2(0, 0), ImGuiCond_Always);
    ImGui::SetWindowSize(windowSize, ImGuiCond_Always);
    ImGui::Image(reinterpret_cast<void*>(static_cast<intptr_t>(this->_backgroundTextureID)), windowSize);
    ImGui::PopStyleVar(); 
}