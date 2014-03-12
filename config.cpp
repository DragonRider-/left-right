#include "config.h"

#include "utils.h"

Config::Config() {
}

bool Config::Init(size_t window_width, size_t window_height) {
	m_window_width = window_width;
	m_window_height = window_height;
	SDL_Init(SDL_INIT_EVERYTHING);
	m_win = SDL_CreateWindow("Left-right", 100, 100, m_window_width, m_window_height, 
		SDL_WINDOW_SHOWN);
	if (m_win == NULL) { 
		cc::Error("creating window failed", SDL_GetError());
		return false;
	}
	m_ren = SDL_CreateRenderer(m_win, -1, 
		SDL_RENDERER_ACCELERATED);

	m_ev = new SDL_Event();

	return true;
}

Config::~Config() {
	delete m_ev;
	SDL_DestroyWindow(m_win);
	SDL_DestroyRenderer(m_ren);
	SDL_Quit();
}
