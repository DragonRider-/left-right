#include "time.h"

void Time::Start() {
	m_started = true;
	m_paused = false;
	m_start_ticks = SDL_GetTicks();
}

void Time::Stop() {
	m_started = false;
	m_paused = false;
}

void Time::Pause() {
	if (m_started && !m_paused) {
		m_paused = true;
		m_pause_ticks = SDL_GetTicks() - m_start_ticks;
	}
}

void Time::Unpause() {
	if (m_paused) {
		m_paused = false;
		m_started = true;
		m_start_ticks = SDL_GetTicks() - m_pause_ticks;
		m_pause_ticks = 0;
	}
}

int Time::Restart() {
	int elapsed_ticks = GetTicks();
	Start();
	return elapsed_ticks;
}

int Time::GetTicks() const {
	if (m_started){
		if(m_paused) {
			return m_pause_ticks;
		} else {
			return SDL_GetTicks() - m_start_ticks;
		}
	}

	return 0;
}
