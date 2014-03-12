#include "game.h"

#include "utils.h"

Game::Game() {
	cc::Info("Start of program...");

}

void Game::Init() {
	config = new Config();
	if (config->Init(600, 400) == false) {
		cc::Error("Failed to initialize -> ", SDL_GetError());
	}
	m_main_time = new Time();
	m_main_time->Start();

	m_player = new Sprite(50, 50, 100, 100, DL::Player, config,
		"data/player.png");

}

Game::~Game() {
	cc::Info("End of program...\n\n");
	delete config;
}

void Game::Run() {
	Init();
	while ( !m_is_done) {
		
		ProcessEvent();
		double delta_time = m_main_time->GetTicks() / 1000.0;
		m_main_time->Restart();

		if (delta_time > 0) {
			Update(delta_time);
		}

		Draw();
	}


}

void Game::ProcessEvent() {
	SDL_Event *ev = config->GetEvent();
	SDL_PollEvent(ev);

	if (ev->type == SDL_QUIT) {
		m_is_done = true;
	}

	if (ev->type == SDL_KEYDOWN) {

		if (ev->key.keysym.sym == SDLK_ESCAPE) {
			m_is_done = true;
		} /*else if (ev->key.keysym.sym == SDLK_LEFT) {
			player->GoLeft();
		} else if (ev->key.keysym.sym == SDLK_RIGHT) {
			player->GoRight();
		}*/
	}

	else if (ev->type == SDL_KEYUP) {

		/*if (ev->key.keysym.sym == SDLK_LEFT) {
			player->StopLeft();
		} else if (ev->key.keysym.sym == SDLK_RIGHT) {
			player->StopRight();
		}*/
	}

}

void Game::Update(double dt) {
	UNUSED(dt);
}

void Game::Draw() {
	//	clean
	SDL_RenderClear(config->GetRenderer());
	//	images
	// ....
	m_player->Draw();

	//	render graphics
	SDL_RenderPresent(config->GetRenderer());

}


