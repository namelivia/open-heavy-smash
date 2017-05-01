#include "Drawing.h"
#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

using namespace std;

int Drawing::load_image(char *path, ResourceManager *resourceManager){
	image = resourceManager->get_image(path);
	return 0;
}
SDL_Texture *Drawing::get_drawing(){
	return image;
}
/*
Uint32 Drawing::get_pixel32(SDL_Surface *surface,Uint16 x,Uint16 y){
	Uint32 *pixels = (Uint32 *)surface->pixels;
	return pixels[(y*surface->w)+x];
}

void Drawing::put_pixel32(SDL_Surface *surface, Uint16 x, Uint16 y, Uint32 pixel){
	Uint32 *pixels = (Uint32 *)surface->pixels;
	pixels[(y*surface->w)+x] = pixel;
}

void Drawing::flip()
{
    //Pointer to the soon to be flipped surface
    SDL_Surface *flipped = NULL;

    flipped = SDL_CreateRGBSurface( SDL_SWSURFACE, image->w, image->h, image->format->BitsPerPixel, image->format->Rmask, image->format->Gmask, image->format->Bmask, image->format->Amask );

   //If the surface must be locked
   if( SDL_MUSTLOCK( image ) )
   {
       //Lock the surface
       SDL_LockSurface( image );
   }

   //Go through columns
   for(int x = 0,rx = flipped->w-1; x < flipped->w;x++,rx--)
   {
	   //Go through rows
	   for( int y = 0,ry = flipped->h-1; y < flipped->h;y++,ry--)
	   {
		   //Get pixel
		   Uint32 pixel = get_pixel32(image, x, y);

		   //Copy pixel
		   put_pixel32(flipped, rx, y, pixel);
	   }
   }

   //Unlock surface
   if( SDL_MUSTLOCK( image ) )
   {
       SDL_UnlockSurface( image );
   }

   //Return flipped surface
   image = flipped;
}


void Drawing::flash(Uint8 strength)
{
    //Pointer to the soon to be flipped surface
    SDL_Surface *flashed = NULL;

    flashed = SDL_CreateRGBSurface(SDL_SWSURFACE,image->w,image->h,image->format->BitsPerPixel,image->format->Rmask,image->format->Gmask,image->format->Bmask,image->format->Amask);

    //If the surface must be locked
    if(SDL_MUSTLOCK(image))
    {
        //Lock the surface
        SDL_LockSurface(image);
    }

    //Go through columns
    for(int x = 0,rx = flashed->w-1; x < flashed->w;x++,rx--)
    {
        //Go through rows
        for( int y = 0,ry = flashed->h-1; y < flashed->h;y++,ry--)
        {
            //Get pixel
            Uint32 pixel = get_pixel32(image,x,y);
            Uint8 red,green,blue,alpha;
            SDL_GetRGBA(pixel,image->format,&red,&green,&blue,&alpha);
            red = add(red,strength);
            green = add(green,strength);
            blue = add(blue,strength);
            pixel = SDL_MapRGBA(image->format, red, green, blue, alpha);


            //Copy pixel
            put_pixel32(flashed,x,y,pixel);
        }
    }

    //Unlock surface
    if(SDL_MUSTLOCK(image))
    {
        SDL_UnlockSurface(image);
    }

    //Return flipped surface
    image = flashed;
  }

void Drawing::grayscale()
{
    //Pointer to the soon to be flipped surface
    SDL_Surface *grayscaled = NULL;

    grayscaled = SDL_CreateRGBSurface(SDL_SWSURFACE,image->w,image->h,image->format->BitsPerPixel,image->format->Rmask,image->format->Gmask,image->format->Bmask,image->format->Amask);

    //If the surface must be locked
    if(SDL_MUSTLOCK(image))
    {
        //Lock the surface
        SDL_LockSurface(image);
    }

    //Go through columns
    for(int x = 0,rx = grayscaled->w-1; x < grayscaled->w;x++,rx--)
    {
        //Go through rows
        for( int y = 0,ry = grayscaled->h-1; y < grayscaled->h;y++,ry--)
        {
            //Get pixel
            Uint32 pixel = get_pixel32(image,x,y);
            Uint8 red,green,blue,alpha;
            SDL_GetRGBA(pixel,image->format,&red,&green,&blue,&alpha);
            red = red*0.3;
            green = green*0.59;
            blue = blue*0.11;
            Uint8 intensity = red+blue+green;
            pixel = SDL_MapRGBA(image->format, intensity, intensity, intensity, alpha);


            //Copy pixel
            put_pixel32(grayscaled,x,y,pixel);
        }
    }

    //Unlock surface
    if(SDL_MUSTLOCK(image))
    {
        SDL_UnlockSurface(image);
    }

    //Return flipped surface
    image = grayscaled;
  }

Uint8 Drawing::add(Uint8 number1,Uint8 number2){
    Uint8 overflow = number1;
    number1=number1+number2;
    if (overflow > number1)number1 = 255;
	return number1;
}
*/

