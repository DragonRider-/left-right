#ifndef CONFIG_H
#define CONFIG_H

#include <SDL2/SDL.h>

class Config {
public:
    Config();
    bool Init(size_t window_width, size_t window_height);

    ~Config();

    SDL_Renderer *GetRenderer() const { return m_ren; }
    SDL_Event *GetEvent() const { return m_ev; }

private:
	size_t m_window_width;
	size_t m_window_height;

	SDL_Window *m_win;
	SDL_Renderer *m_ren;
	SDL_Event *m_ev;

};

#endif // CONFIG_H
