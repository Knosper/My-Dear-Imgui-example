/*#include "tData.hpp"
#include "imgui.h"
#include "AppGui.hpp"

void showDatabaseConfigWindow(T_data& params)
{
    static char dbHost[255] = "";
    static char dbName[255] = "";
    static char dbUser[255] = "";
    static char dbPass[255] = "";
    static int dbPort = 0;
    // Get the main window's position and size
    int main_window_x, main_window_y;
    int main_window_width, main_window_height;
    glfwGetWindowPos(params.getWindow(), &main_window_x, &main_window_y);
    glfwGetWindowSize(params.getWindow(), &main_window_width, &main_window_height);

    // Set the position of the database config window within the boundaries
    ImGui::SetNextWindowPos(ImVec2(main_window_x, main_window_y), ImGuiCond_FirstUseEver, ImVec2(0, 0));
    ImGui::SetNextWindowSizeConstraints(ImVec2(300, 200), ImVec2(main_window_width, main_window_height));

    // Begin the window
    ImGui::Begin("Init Database", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_AlwaysAutoResize);

    // Input fields with labels
    ImGui::InputText("Host", dbHost, IM_ARRAYSIZE(dbHost));
    ImGui::InputText("Database Name", dbName, IM_ARRAYSIZE(dbName));
    ImGui::InputText("User", dbUser, IM_ARRAYSIZE(dbUser));
    ImGui::InputText("Password", dbPass, IM_ARRAYSIZE(dbPass), ImGuiInputTextFlags_Password);
    ImGui::InputInt("Port", &dbPort);

    // Space between input fields and buttons
    ImGui::Spacing();

    if (ImGui::Button("Connect", ImVec2(ImGui::GetContentRegionAvail().x, 0))) {
        // Attempt to connect to the database and provide feedback

    }
    ImGui::End();
}*/