#ifndef TIME_H
#define TIME_H

#include <SDL2/SDL.h>

class Time {

public:
	explicit Time()
	: m_start_ticks(0),
	m_pause_ticks(0),
	m_started(false),
	m_paused(false) {

	}

	~Time();

	void Start();
	void Stop();
	void Pause();
	void Unpause();
	
	int Restart();

	int GetTicks() const;

	bool IsStarted() const { return m_started; }
	bool IsPaused() const { return m_paused; }

private:
	int m_start_ticks;
	int m_pause_ticks;
	bool m_started;
	bool m_paused;
};

#define FPS (1/60)

#endif // TIME_H
