/*
 * Match.h
 *
 *  Created on: 20/08/2010
 *      Author: endlessdark
 */

#ifndef MATCH_H_
#define MATCH_H_

#include "Camara.h"
#include "Musica.h"
#include "Constantes.h"
#include "CurrentScreen.h"
#include "UserInterface/Portrait.h"
//#include "Escenario.h"
//#include "Personaje.h"
//#include "Ventana.h"
#include "UserInterface/UserInterface.h"

class Match : CurrentScreen{
private:
public:
	Camara *camara;
	//Personaje *personaje;
	//Escenario *escenario;
	Musica *musica;
	UserInterface *userInterface;
	MatchState *matchState;

	Match () {};
	Match(NewMatch *newMatch,ResourceManager *resourceManager){
		//escenario = new Escenario();
		//personaje = new Personaje(45,1);
		//ventana_zona = new Ventana(0,ALTO_PANTALLA-1.5*ALTO_TILE,3,12,500);
		camara = new Camara();
		musica = new Musica();
		matchState = new MatchState(newMatch->getTime());
		userInterface = new UserInterface(0,0,ANCHO_PANTALLA,ALTO_PANTALLA,newMatch);
		//ventana_zona ->set_mensaje(nombre);
		//escenario->cargar_escenario(path_nivel);
		musica->cargar((char *)M_USA,resourceManager);
		//personaje->sprite.dibujo.load_image(path_personaje);
		userInterface->cargar((char *)G_UI,resourceManager);

		musica->reproducir();
	}
	void actualizar_camara();
	virtual void update();
	virtual void draw(SDL_Surface *screen);
	virtual int leer_teclado();
	virtual void terminar();
};

#endif /* MATCH_H_ */
