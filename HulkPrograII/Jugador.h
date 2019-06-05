#pragma once
#include "String.h"
enum Direcciones{arriba,abajo,izquierda,derecha,ninguna};
using namespace System::Drawing;
using namespace System;

class Jugador
{
private:
	int x, y;
	int dx, dy;
	int indicex, indicey;
	//char *imagen;
	int ancho, alto;
	Direcciones direccion;
	Direcciones ultima;
public:
	Jugador(int _x, int _y);
	~Jugador();
	void dibujarJugador(Graphics^g,Bitmap^bmpJugador);
	void moverJugador(Graphics^g, Bitmap^bmpJugador);
	void setdireccion(Direcciones direccionActual);
};
Jugador::Jugador(int _x,int _y)
{
	x = _x;
	y = _y;
	dx = dy = 0;
	indicex = indicey = 0;
	ancho = 40;
	alto = 56;
	direccion = ninguna;
	ultima = abajo;
}
void Jugador::dibujarJugador(Graphics^g, Bitmap^bmpJugador)
{
	Rectangle porcionUsar = Rectangle(indicex*ancho, indicey*alto, ancho, alto);
	Rectangle aumento = Rectangle(x,y,ancho*2,alto*2);
	g->DrawImage(bmpJugador, aumento, porcionUsar, GraphicsUnit::Pixel);
	x += dx;
	y += dy;
}
void Jugador::moverJugador(Graphics^g, Bitmap^bmpJugador)
{
	switch (direccion)
	{
	case arriba:
	{
		indicey = 3;
		if (indicex>=0&&indicex<3)
		{
			indicex++;
		}
		else
		{
			indicex = 0;
		}
		dx = 0;
		dy = -10;
		ultima = arriba;

		break;
	}
	case abajo:
	{
		indicey = 0;
		if (indicex >= 0 && indicex<3)
		{
			indicex++;
		}
		else
		{
			indicex = 0;
		}
		dx = 0;
		dy = +10;
		ultima = abajo;
		break;
	}
	case izquierda:
	{
		indicey = 1;
		if (indicex >= 0 && indicex<3)
		{
			indicex++;
		}
		else
		{
			indicex = 0;
		}
		dx = -10;
		dy = 0;
		ultima = izquierda;

		break;
	
	}
	case derecha:
	{
		indicey = 2;
		if (indicex >= 0 && indicex<3)
		{
			indicex++;
		}
		else
		{
			indicex = 0;
		}
		dx = +10;
		dy = 0;
		ultima = derecha;
		break;
	}
	case ninguna:
	{
		dx = 0;
		dy = 0;
		if (ultima==abajo)
		{
			indicex = 0;
			indicey = 0;
		}
		if (ultima==arriba)
		{
			indicex = 0;
			indicey = 3;
		}
		if (ultima==derecha)
		{
			indicex = 0;
			indicey = 2;
		}
		if (ultima==izquierda)
		{
			indicex = 0;
			indicey = 1;
		}

		break;
	}
	default:
		break;
	}
	dibujarJugador(g, bmpJugador);
}
void Jugador::setdireccion(Direcciones direccionActual)
{
	direccion = direccionActual;
}
Jugador::~Jugador()
{

}