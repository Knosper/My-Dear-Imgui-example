#include "tData.hpp"
#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#endif
#include "stb_image.h"

T_data::T_data():_backgroundTextureID(), _iconTextureIDs(), _window(), _io(), _status(false)
{
    std::cout << "default T_data created" << std::endl; 
}

T_data::~T_data()
{
    std::cout << "T_data deleted" << std::endl; 
}

void T_data::addIconTextureID(const std::string& name, GLuint textureID)
{
    _iconTextureIDs[name] = textureID;
}

GLuint T_data::getIconTextureID(const std::string& name) const
{
    auto it = _iconTextureIDs.find(name);
    if (it != _iconTextureIDs.end()) {
        return it->second;
    }
    return (0);
}

GLuint T_data::loadImage(const char* imagePath)
{
    // Load the image using stb_image
    int width, height, channels;
    unsigned char* data = stbi_load(imagePath, &width, &height, &channels, 4);
    if (data == nullptr) {
        std::cerr << "Failed to load image: " << imagePath << std::endl;
        return 0;
    }
    // Create a texture
    GLuint textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    // Set the texture wrapping and filtering options
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Load the texture data
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    GLenum error = glGetError();
    if (error != GL_NO_ERROR) {
        std::cerr << "OpenGL Error after glGenerateMipmap: " << error << std::endl;
    }
    // Free the image memory and unbind the texture
    stbi_image_free(data);
    glBindTexture(GL_TEXTURE_2D, 0);

    return textureID;
}

void T_data::loadIcons()
{
    this->addIconTextureID(_ICON_APPERANCE, loadImage(_ICON_APPERANCE));
    this->addIconTextureID(_ICON_DATABASE_BACKUP, loadImage(_ICON_DATABASE_BACKUP));
    this->addIconTextureID(_ICON_BUG, loadImage(_ICON_BUG));
    this->addIconTextureID(_ICON_CREATE_DATABASE, loadImage(_ICON_CREATE_DATABASE));
    this->addIconTextureID(_ICON_DATABASE_LOGS, loadImage(_ICON_DATABASE_LOGS));
    this->addIconTextureID(_ICON_DATABASE, loadImage(_ICON_DATABASE));
    this->addIconTextureID(_ICON_DELETE_DATABASE, loadImage(_ICON_DELETE_DATABASE));
    this->addIconTextureID(_ICON_DOCS, loadImage(_ICON_DOCS));
    this->addIconTextureID(_ICON_DATABASE_EXPORT, loadImage(_ICON_DATABASE_EXPORT));
    this->addIconTextureID(_ICON_HELP, loadImage(_ICON_HELP));
    this->addIconTextureID(_ICON_DATABASE_IMPORT, loadImage(_ICON_DATABASE_IMPORT));
    this->addIconTextureID(_ICON_LIST_DATABASE, loadImage(_ICON_LIST_DATABASE));
    this->addIconTextureID(_ICON_MANAGE_CONNECTION, loadImage(_ICON_MANAGE_CONNECTION));
    this->addIconTextureID(_ICON_NEW_CONNECTION, loadImage(_ICON_NEW_CONNECTION));
    this->addIconTextureID(_ICON_PREFERENCES, loadImage(_ICON_PREFERENCES));
    this->addIconTextureID(_ICON_RESTORE, loadImage(_ICON_RESTORE));
    this->addIconTextureID(_ICON_SETTINGS, loadImage(_ICON_SETTINGS));
    this->addIconTextureID(_ICON_TOOLS, loadImage(_ICON_TOOLS));
    this->addIconTextureID(_ICON_UPDATE, loadImage(_ICON_UPDATE));
    this->addIconTextureID(_ICON_VISUALIZE_DATABASE, loadImage(_ICON_VISUALIZE_DATABASE));
}
