#pragma once
//#define GLEW_STATIC // Only define this if you are statically linking GLEW
#include "tData.hpp"

void showDatabaseConfigWindow(GLFWwindow* window, T_data& params);
int initGui(T_data& params);
