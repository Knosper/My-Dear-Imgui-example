#include "Data.hpp"
#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#endif
#include "stb_image.h"
/* Do this:
      #define STB_IMAGE_IMPLEMENTATION
   before you include this file (stb_image.h) in *one* C or C++ file to create the implementation.*/

void Data::loadIcons()
{
    this->addIconTextureID(AppConfig::_ICON_APPERANCE, loadImage(AppConfig::_ICON_APPERANCE));
    this->addIconTextureID(AppConfig::_ICON_DATABASE_BACKUP, loadImage(AppConfig::_ICON_DATABASE_BACKUP));
    this->addIconTextureID(AppConfig::_ICON_BUG, loadImage(AppConfig::_ICON_BUG));
    this->addIconTextureID(AppConfig::_ICON_CREATE_DATABASE, loadImage(AppConfig::_ICON_CREATE_DATABASE));
    this->addIconTextureID(AppConfig::_ICON_DATABASE_LOGS, loadImage(AppConfig::_ICON_DATABASE_LOGS));
    this->addIconTextureID(AppConfig::_ICON_DATABASE, loadImage(AppConfig::_ICON_DATABASE));
    this->addIconTextureID(AppConfig::_ICON_DELETE_DATABASE, loadImage(AppConfig::_ICON_DELETE_DATABASE));
    this->addIconTextureID(AppConfig::_ICON_DOCS, loadImage(AppConfig::_ICON_DOCS));
    this->addIconTextureID(AppConfig::_ICON_DATABASE_EXPORT, loadImage(AppConfig::_ICON_DATABASE_EXPORT));
    this->addIconTextureID(AppConfig::_ICON_HELP, loadImage(AppConfig::_ICON_HELP));
    this->addIconTextureID(AppConfig::_ICON_DATABASE_IMPORT, loadImage(AppConfig::_ICON_DATABASE_IMPORT));
    this->addIconTextureID(AppConfig::_ICON_LIST_DATABASE, loadImage(AppConfig::_ICON_LIST_DATABASE));
    this->addIconTextureID(AppConfig::_ICON_MANAGE_CONNECTION, loadImage(AppConfig::_ICON_MANAGE_CONNECTION));
    this->addIconTextureID(AppConfig::_ICON_NEW_CONNECTION, loadImage(AppConfig::_ICON_NEW_CONNECTION));
    this->addIconTextureID(AppConfig::_ICON_PREFERENCES, loadImage(AppConfig::_ICON_PREFERENCES));
    this->addIconTextureID(AppConfig::_ICON_RESTORE, loadImage(AppConfig::_ICON_RESTORE));
    this->addIconTextureID(AppConfig::_ICON_SETTINGS, loadImage(AppConfig::_ICON_SETTINGS));
    this->addIconTextureID(AppConfig::_ICON_TOOLS, loadImage(AppConfig::_ICON_TOOLS));
    this->addIconTextureID(AppConfig::_ICON_UPDATE, loadImage(AppConfig::_ICON_UPDATE));
    this->addIconTextureID(AppConfig::_ICON_VISUALIZE_DATABASE, loadImage(AppConfig::_ICON_VISUALIZE_DATABASE));
}

GLuint Data::loadImage(const char* imagePath)
{
    // Load the image using stb_image
    int width, height, channels;
    unsigned char* data = stbi_load(imagePath, &width, &height, &channels, 4);
    if (data == nullptr) {
        std::cerr << "Failed to load image: " << imagePath << std::endl;
        return (0);
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
