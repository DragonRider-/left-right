#include "sprite.h"

#include "utils.h"

void Sprite::Load(const std::string &filename) {
	m_tex = IMG_LoadTexture(m_config->GetRenderer(), filename.c_str());
	if (m_tex == NULL) {
		cc::Error("cannot load image: ", filename.c_str());
	}
}

Sprite::~Sprite() {
	SDL_DestroyTexture(m_tex);
}

void Sprite::Draw() {
	SDL_RenderCopy(m_config->GetRenderer(), m_tex, NULL, &m_aabb);
}
