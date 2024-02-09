#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "constants.hpp"
#include <unordered_map>
#include <vector>
#include <algorithm>

class Data
{
public:
    //Constructor Destructor
    Data();
    ~Data();

    // High-Level Functional Methods
    int                 initImgui();
    bool                setupImGui();
    void                loadIcons();
    GLuint              loadImage(const char* imagePath);

    // UI Render Methods
    void                renderSelected(const ImVec2& windowSize);
    void                renderListDataBases(const ImVec2& windowSize);
    void                renderBackground(const ImVec2& windowSize);
    void                renderMenuBar();
    void                renderDatabaseSearch();

    // Setter methods
    void                setBackgroundTextureID(const GLuint& backgroundTextureID);
    void                setWindow(GLFWwindow* window);
    void                setIo(ImGuiIO* io);
    void                setCurrentMenuItem(AppConfig::SelectedMenuItem menuItem);

    // Getter methods
    GLuint                          getBackgroundTextureID() const;
    GLFWwindow*                     getWindow() const;
    ImGuiIO*                        getIo() const;
    AppConfig::SelectedMenuItem     getCurrentMenuItem() const;


    void cleanup();
    bool mainLoop();
    int initGui();

private:
    GLuint                                  _backgroundTextureID;
    std::unordered_map<std::string, GLuint> _iconTextureIDs; 
    GLFWwindow*                             _window;      
    ImGuiIO*                                _io;            
    AppConfig::SelectedMenuItem             _currentMenuItem;
    
    //private methods
    void                addIconTextureID(const std::string& name, const GLuint& textureID);
    GLuint              getIconTextureID(const std::string& name) const;
};