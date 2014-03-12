#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <SDL2/SDL.h>

#define UNUSED(x) ((void)(x))

namespace cc {
void Dot(int value);
void Info(const std::string& text);
void Info(const std::string &text1, const std::string& text2);
void Error(const std::string& text);
void Error(const std::string &text1, const std::string& text2);

SDL_Texture* LoadImage(const std::string& filename, SDL_Renderer* m_ren);

}


#endif // UTILS_H
