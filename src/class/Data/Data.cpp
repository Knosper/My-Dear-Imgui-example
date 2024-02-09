#include "Data.hpp"

Data::Data():_backgroundTextureID(), _iconTextureIDs(), _window(), _io(), _currentMenuItem(AppConfig::SelectedMenuItem::StartPage)
{
    std::cout << "default data created" << std::endl;
}

Data::~Data()
{
    for (auto& pair : this->_iconTextureIDs)
    {
        GLuint textureID = pair.second;
        glDeleteTextures(1, &textureID);
    }
    glDeleteTextures(1, &this->_backgroundTextureID);
    std::cout << "Data deleted" << std::endl;
}


void Data::setBackgroundTextureID(const GLuint& backgroundTextureID)
{ 
    _backgroundTextureID = backgroundTextureID;
}

void Data::setWindow(GLFWwindow* window)
{
    _window = window;
}

void Data::setIo(ImGuiIO* io)
{
    _io = io;
}

void Data::setCurrentMenuItem(AppConfig::SelectedMenuItem menuItem) 
{
    _currentMenuItem = menuItem;
}

GLuint Data::getBackgroundTextureID() const 
{
    return (_backgroundTextureID);
}

GLFWwindow* Data::getWindow() const
{
    return (_window);
}

ImGuiIO* Data::getIo() const
{
    return (_io);
}

AppConfig::SelectedMenuItem Data::getCurrentMenuItem() const 
{
    return (_currentMenuItem);
}

void Data::addIconTextureID(const std::string& name, const GLuint& textureID)
{
    _iconTextureIDs[name] = textureID;
}

GLuint Data::getIconTextureID(const std::string& name) const
{
    auto it = this->_iconTextureIDs.find(name);
    if (it != this->_iconTextureIDs.end()) {
        return it->second;
    }
    return (0);
}

static void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

static bool initializeWindow(GLFWwindow** outWindow)
{
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW." << std::endl;
        return (false);
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    *outWindow = glfwCreateWindow(1280, 720, "Sql-Crawler 🔍", NULL, NULL);
    if (*outWindow == NULL) {
        std::cerr << "Failed to create GLFW window." << std::endl;
        glfwTerminate();
        return (false);
    }
    glfwMakeContextCurrent(*outWindow);
    GLenum err = glewInit();
    if (GLEW_OK != err) {
        fprintf(stderr, "GLEW Error: %s\n", glewGetErrorString(err));
        glfwDestroyWindow(*outWindow);
        glfwTerminate();
        return (false);
    }
    glfwSwapInterval(1); // Enable vsync
    return (true);
}

int Data::initImgui()
{
    // Create window with graphics context
    ImGuiIO io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;  // Enable Keyboard Controls
    GLFWwindow* window;
    if (!initializeWindow(&window))
    {
        std::cerr << "Shutdown App." << std::endl;
        //TODO: Try recover and restart.
        return (EXIT_FAILURE);
    }
    this->setWindow(window);
    this->setIo(&io);
        // Load BackgroundTexture
    GLuint backgroundTextureID = this->loadImage(AppConfig::_THUB_PATH);
    if (backgroundTextureID == 0)
    {
        std::cerr << "Failed to load the background texture." << std::endl;
        glfwDestroyWindow(this->getWindow());
        glfwTerminate();
        return (EXIT_FAILURE);
    }
    this->setBackgroundTextureID(backgroundTextureID);
    this->loadIcons();

    return (EXIT_SUCCESS);
}

bool Data::setupImGui()
{
    const char* glsl_version = "#version 130";
    if (!this->getWindow())
    {
        std::cerr << "setupImGui: Provided GLFWwindow pointer is null." << std::endl;
        return false;
    }
    // Initialize ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    this->setIo(&(ImGui::GetIO()));
    ImGui::StyleColorsDark();
    if (!ImGui_ImplGlfw_InitForOpenGL(this->getWindow(), true))
    {
        std::cerr << "Failed to initialize ImGui GLFW." << std::endl;
        return false;
    }
    if (!ImGui_ImplOpenGL3_Init(glsl_version))
    {
        std::cerr << "Failed to initialize ImGui OpenGL." << std::endl;
        return false;
    }
    return true;
}

// ########################### Cleanup function ###########################
void Data::cleanup()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    if (_window) {
        glfwDestroyWindow(_window);
    }
    glfwTerminate();
}

// ########################### MainLoop ###########################
bool Data::mainLoop()
{
    while (!glfwWindowShouldClose(getWindow()))
    {
        glfwPollEvents();
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Fetch the new window size
        ImVec2 windowSize = ImGui::GetIO().DisplaySize;
        //set params to render
        renderSelected(windowSize);
        renderMenuBar();
        ImGui::End();
        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(getWindow(), &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(getWindow());
    }
    return EXIT_SUCCESS;
}

// ########################### Main app (Init & cleanup) ###########################
int Data::initGui()
{
    //init window && io && textures
    if (initImgui())
        return (EXIT_FAILURE);

    // Setup ImGui binding
    if (!setupImGui())
    {
        std::cerr << "Failed to setup ImGui." << std::endl;
        glfwDestroyWindow(getWindow());
        glfwTerminate();
        return (EXIT_FAILURE);
    }
    if (mainLoop())
    {
        std::cerr << "An error occurred during the main loop." << std::endl;
        cleanup();
        return (EXIT_FAILURE);
    }
    // Cleanup
    cleanup();
    return (EXIT_SUCCESS);
}