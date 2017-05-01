/*
 * Dibujo.cpp
 *
 *  Created on: 20/08/2010
 *      Author: endlessdark
 */

#include "Dibujo.h"
#include <iostream>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

using namespace std;

int Dibujo::load_image(char *path, ResourceManager *resourceManager){
	imagen = resourceManager->get_image(path);
	return 0;
}
SDL_Surface *Dibujo::get_dibujo(){return imagen;}

Uint32 Dibujo::get_pixel32(SDL_Surface *surface,Uint16 x,Uint16 y){
	Uint32 *pixels = (Uint32 *)surface->pixels;
	return pixels[(y*surface->w)+x];
}

void Dibujo::put_pixel32(SDL_Surface *surface, Uint16 x, Uint16 y, Uint32 pixel){
	Uint32 *pixels = (Uint32 *)surface->pixels;
	pixels[(y*surface->w)+x] = pixel;
}

void Dibujo::flip()
{
    //Pointer to the soon to be flipped surface
    SDL_Surface *flipped = NULL;

    flipped = SDL_CreateRGBSurface( SDL_SWSURFACE, imagen->w, imagen->h, imagen->format->BitsPerPixel, imagen->format->Rmask, imagen->format->Gmask, imagen->format->Bmask, imagen->format->Amask );

   //If the surface must be locked
   if( SDL_MUSTLOCK( imagen ) )
   {
       //Lock the surface
       SDL_LockSurface( imagen );
   }

   //Go through columns
   for(int x = 0,rx = flipped->w-1; x < flipped->w;x++,rx--)
   {
	   //Go through rows
	   for( int y = 0,ry = flipped->h-1; y < flipped->h;y++,ry--)
	   {
		   //Get pixel
		   Uint32 pixel = get_pixel32(imagen, x, y);

		   //Copy pixel
		   put_pixel32(flipped, rx, y, pixel);
	   }
   }

   //Unlock surface
   if( SDL_MUSTLOCK( imagen ) )
   {
       SDL_UnlockSurface( imagen );
   }

   //Return flipped surface
   imagen = flipped;
}


void Dibujo::flash(Uint8 strength)
{
    //Pointer to the soon to be flipped surface
    SDL_Surface *flashed = NULL;

    flashed = SDL_CreateRGBSurface(SDL_SWSURFACE,imagen->w,imagen->h,imagen->format->BitsPerPixel,imagen->format->Rmask,imagen->format->Gmask,imagen->format->Bmask,imagen->format->Amask);

    //If the surface must be locked
    if(SDL_MUSTLOCK(imagen))
    {
        //Lock the surface
        SDL_LockSurface(imagen);
    }

    //Go through columns
    for(int x = 0,rx = flashed->w-1; x < flashed->w;x++,rx--)
    {
        //Go through rows
        for( int y = 0,ry = flashed->h-1; y < flashed->h;y++,ry--)
        {
            //Get pixel
            Uint32 pixel = get_pixel32(imagen,x,y);
            Uint8 red,green,blue,alpha;
            SDL_GetRGBA(pixel,imagen->format,&red,&green,&blue,&alpha);
            red = add(red,strength);
            green = add(green,strength);
            blue = add(blue,strength);
            pixel = SDL_MapRGBA(imagen->format, red, green, blue, alpha);


            //Copy pixel
            put_pixel32(flashed,x,y,pixel);
        }
    }

    //Unlock surface
    if(SDL_MUSTLOCK(imagen))
    {
        SDL_UnlockSurface(imagen);
    }

    //Return flipped surface
    imagen = flashed;
  }

void Dibujo::grayscale()
{
    //Pointer to the soon to be flipped surface
    SDL_Surface *grayscaled = NULL;

    grayscaled = SDL_CreateRGBSurface(SDL_SWSURFACE,imagen->w,imagen->h,imagen->format->BitsPerPixel,imagen->format->Rmask,imagen->format->Gmask,imagen->format->Bmask,imagen->format->Amask);

    //If the surface must be locked
    if(SDL_MUSTLOCK(imagen))
    {
        //Lock the surface
        SDL_LockSurface(imagen);
    }

    //Go through columns
    for(int x = 0,rx = grayscaled->w-1; x < grayscaled->w;x++,rx--)
    {
        //Go through rows
        for( int y = 0,ry = grayscaled->h-1; y < grayscaled->h;y++,ry--)
        {
            //Get pixel
            Uint32 pixel = get_pixel32(imagen,x,y);
            Uint8 red,green,blue,alpha;
            SDL_GetRGBA(pixel,imagen->format,&red,&green,&blue,&alpha);
            red = red*0.3;
            green = green*0.59;
            blue = blue*0.11;
            Uint8 intensity = red+blue+green;
            pixel = SDL_MapRGBA(imagen->format, intensity, intensity, intensity, alpha);


            //Copy pixel
            put_pixel32(grayscaled,x,y,pixel);
        }
    }

    //Unlock surface
    if(SDL_MUSTLOCK(imagen))
    {
        SDL_UnlockSurface(imagen);
    }

    //Return flipped surface
    imagen = grayscaled;
  }

Uint8 Dibujo::add(Uint8 number1,Uint8 number2){
    Uint8 overflow = number1;
    number1=number1+number2;
    if (overflow > number1)number1 = 255;
	return number1;
}

