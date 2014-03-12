#include "utils.h"

#include <iostream>

void cc::Dot(int value) {
    while (value > 0) {
        std::cout << ".";
        value--;
    }
}


void cc::Info(const std::string &text) {
    std::cerr << "\nINFO:\t" << text;
}

void cc::Info(const std::string &text1, const std::string &text2) {
    std::cerr << "\nINFO:\t" << text1 << text2;
}

void cc::Error(const std::string &text) {
    std::cerr << "\nError:\t" << text;
}

void cc::Error(const std::string &text1, const std::string &text2) {
    std::cerr << "\nError:\t" << text1 << text2;
}

SDL_Texture* cc::LoadImage(const std::string& filename, SDL_Renderer* m_ren) {

    SDL_Texture *texture = NULL;
    SDL_Surface *m_img = NULL;
    m_img = SDL_LoadBMP(filename.c_str());

    if (m_img != NULL) {
        texture = SDL_CreateTextureFromSurface(m_ren, m_img);
        SDL_FreeSurface(m_img);
        cc::Info("Load image: ", filename.c_str());
        if (texture == NULL) {
            cc::Error("SDL_CreateTextureFromSurface Error: ", SDL_GetError());
        } else {
        	cc::Info("Create texture: ", filename.c_str());
        }
    } else {
        cc::Error("SDL_LoadBMP Error: ", SDL_GetError());
    }

    return texture;
}
