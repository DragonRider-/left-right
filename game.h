#ifndef GAME_H
#define GAME_H

#include "config.h"
#include <SDL2/SDL.h>
#include "time.h"
#include "sprite.h"
#include "types.h"

class Game
{
public:
	Game();
	~Game();
	void Init();
	void Run();
	void ProcessEvent();
	void Update(double dt);
	void Draw();


private:

	bool m_is_done;

	Sprite *m_player;


	Time *m_main_time;
	Config *config;
};



#endif // GAME_H
