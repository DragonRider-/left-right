#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL_image.h>
#include "config.h"
#include <string>

class Sprite {
public:
    explicit Sprite(size_t x, size_t y, size_t width, size_t height,
    	size_t layer, Config *config, const std::string &filename)
    	:
    m_config(config),
    m_layer(layer) {

    	m_aabb.x = x;
    	m_aabb.y = y;
    	m_aabb.w = width;
    	m_aabb.h = height;
    	Load(filename);
    }

    void Load(const std::string &filename);
    ~Sprite();

    void Draw();

private:
	Config *m_config;
	SDL_Texture *m_tex;
	SDL_Rect m_aabb;
	size_t m_layer;
};

#endif // SPRITE_H
