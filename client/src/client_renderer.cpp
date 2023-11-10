#include "client_renderer.h"

ClientRenderer::ClientRenderer(ProtectedQueue<std::string>& queue, std::atomic<bool>& game_status, std::vector<Grd>& map_info): 
message_queue(queue), keep_playing(game_status), map_info(map_info), sdl(SDL_INIT_VIDEO), 
game_window("Worms", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 800,SDL_WINDOW_RESIZABLE), 
renderer(this->game_window, -1, SDL_RENDERER_ACCELERATED) {}

void ClientRenderer::run() { 

    std::cout << "SOY EL RENDERER Y ACABO DE LANZARME\n";

	Texture sprites(renderer, Surface(DATA_PATH "/sprite_gusano.png")
			.SetColorKey(true, 0));

    // Enable alpha blending for the sprites
	sprites.SetBlendMode(SDL_BLENDMODE_BLEND);

	Texture gradient(renderer, SDL_PIXELFORMAT_BGR888, SDL_TEXTUREACCESS_STATIC, 1, 256);
	{

		unsigned char grad[256 * 3];
		int n = 0; // counter


		std::generate(grad, grad + sizeof(grad), [&](){ return 255 - n++ / 3; });


		gradient.Update(NullOpt, grad, 3)
			.SetBlendMode(SDL_BLENDMODE_BLEND)
			.SetColorMod(0, 255, 255)
			.SetAlphaMod(85);
    }

    bool is_running = false; // whether the character is currently running
	int run_phase = -1;      // run animation phase
	float position = 0.0;    // player position

	unsigned int prev_ticks = SDL_GetTicks();


    while (!this->keep_playing)
    {
		unsigned int frame_ticks = SDL_GetTicks();
		unsigned int frame_delta = frame_ticks - prev_ticks;
		prev_ticks = frame_ticks;

		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				return;
			} else if (event.type == SDL_KEYDOWN) {
				switch (event.key.keysym.sym) {
				case SDLK_ESCAPE: case SDLK_q:
					return;
				case SDLK_RIGHT: is_running = true; break;
				}
			} else if (event.type == SDL_KEYUP) {
				switch (event.key.keysym.sym) {
				case SDLK_RIGHT: is_running = false; break;
				}
			}
		}

		// Update game state for this frame:
		// if character is runnung, move it to the right
		if (is_running) {
			position += frame_delta * 0.2;
			run_phase = (frame_ticks / 100) % 8;
		} else {
			run_phase = 0;
		}

		// If player passes past the right side of the window, wrap him
		// to the left side
		if (position > renderer.GetOutputWidth())
			position = -50;

		int vcenter = renderer.GetOutputHeight() / 2; // Y coordinate of window center

		// Clear screen
		renderer.Clear();

		// Copy our gradient texture, stretching it to the whole window
		renderer.Copy(
				gradient,
				NullOpt,
				Rect(0, vcenter, renderer.GetOutputWidth(), renderer.GetOutputHeight() / 2)
			);

		// Pick sprite from sprite atlas based on whether
		// player is running and run animation phase
		int src_x = 8, src_y = 11; // by default, standing sprite
		if (is_running) {
			// one of 8 run animation sprites
			src_x = 8 + 51 * run_phase;
			src_y = 67;
		}

		// Draw player sprite
		sprites.SetAlphaMod(255); // sprite is fully opaque
		renderer.Copy(
				sprites,
				Rect(src_x, src_y, 50, 50),
				Rect((int)position, vcenter - 50, 50, 50)
			);

		// Draw the same sprite, below the first one, 50% transparent and
		// vertically flipped. It'll look like reflection in the mirror
		sprites.SetAlphaMod(127); // 50% transparent
		renderer.Copy(
				sprites,
				Rect(src_x, src_y, 50, 50),
				Rect((int)position, vcenter, 50, 50),
				0.0,              // don't rotate
				NullOpt,          // rotation center - not needed
				SDL_FLIP_VERTICAL // vertical flip
			);

		// Show rendered frame
		renderer.Present();

		// Frame limiter: sleep for a little bit to not eat 100% of CPU
		SDL_Delay(1);
    }
    
    std::cout << "Soy el renderer y acabo de terminar\n";
}

