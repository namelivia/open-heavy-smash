/*
 * VsScreen.h
 *
 *  Created on: 20/08/2010
 *      Author: endlessdark
 */

#ifndef VSSCREEN_H_
#define VSSCREEN_H_

#include "Musica.h"
#include "Constantes.h"
#include "UserInterface/Portrait.h"
#include "CurrentScreen.h"
#include "SoundFX.h"
#include "UserInterface/UserInterface.h"

class VsScreen : CurrentScreen{
private:
	static const Uint8 horizontalMargin = 24;
public:
	Musica *musica;
	SoundFX *sonido;
	Portrait *portrait1;
	Portrait *portrait2;
	Sprite *vs;

	VsScreen () {};
	VsScreen(NewMatch *newMatch,ResourceManager *resourceManager){
		musica = new Musica();
		sonido = new SoundFX();
		musica->cargar((char *)M_VS,resourceManager);
		sonido->load((char *)S_SHINY,resourceManager);
		portrait1 = new Portrait(horizontalMargin,-210,newMatch->getPlayer1Team());
		portrait1->load_image((char *)G_PORTRAITS,resourceManager);
		portrait2 = new Portrait(ANCHO_PANTALLA-(horizontalMargin+80),ALTO_PANTALLA+50,newMatch->getPlayer2Team());
		portrait2->load_image((char *)G_PORTRAITS,resourceManager);

		vs = new Sprite();
		vs->load_image((char *)G_UI,resourceManager);
		vs->set_x(ANCHO_PANTALLA/2-72/2);
		vs->set_y(ALTO_PANTALLA/2-60/2);
		vs->set_width(72);
		vs->set_height(60);
		vs->set_source_x(118);
		vs->set_source_y(0);
		vs->make_flasheable(255);

		portrait2->load_image((char *)G_PORTRAITS,resourceManager);
		musica->reproducir();
	}
	void update();
	void draw(SDL_Surface *screen);
	int leer_teclado();
	void terminar();
	bool get_destroyMe();
};

#endif /* NIVEL_H_ */
