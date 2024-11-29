#pragma once
#include "Entidad.h"
enum MovimientosJugador{Arriba,Izquierda,Abajo,Derecha,DispararArriba,DispararIzquierda,DispararAbajo,DispararDerecha};
class Jugador :public Entidad {
private:
	MovimientosJugador acciones_jugador;
	short vidas;
	bool disparar;
	short puntaje;
public:
	Jugador(Graphics^ g, Random^ r) {
		this->x = r->Next(30, g->VisibleClipBounds.Width - 60);
		this->y = r->Next(30, g->VisibleClipBounds.Height - 60);
		this->dx = 0;
		this->dy = 0;
		this->ancho = 576 / 9;
		this->alto = 512 / 8;
		this->index_x = 0;
		acciones_jugador = Abajo;
		this->vidas = 3;
		this->disparar = false;
		this->puntaje = 0;
	}
	~Jugador() {}
	void Mover(Graphics^ g) {
		if (x + dx > 0 && x + dx + ancho <= g->VisibleClipBounds.Width)x += dx;
		if (y + dy > 0 && y + dy + alto <= g->VisibleClipBounds.Height)y += dy;
	}
	void Dibujar(Graphics^ g, Bitmap^ img) {
		Rectangle Corte = Rectangle(index_x * ancho, acciones_jugador * alto, ancho, alto); //una porcion
		g->DrawImage(img, Area(), Corte, GraphicsUnit::Pixel);
		if (acciones_jugador >= 0 && acciones_jugador <= 3) {
			if (dx != 0 || dy != 0) { //Si hay velocidad hay animacion
				index_x = (index_x + 1) % 9;//Un limite para que solamente se sume hasta el 3 y luego regrese a 0
			}
		}
		if (acciones_jugador >= 4 && acciones_jugador <= 7) {
			index_x = (index_x + 1) % 6;
		}
		if (index_x == 0) {
			if (acciones_jugador == DispararArriba)acciones_jugador = Arriba;
			if (acciones_jugador == DispararAbajo)acciones_jugador = Abajo;
			if (acciones_jugador == DispararIzquierda)acciones_jugador = Izquierda;
			if (acciones_jugador == DispararDerecha)acciones_jugador = Derecha;
		}
	}
	void set_Accion(MovimientosJugador acciones) {
		this->acciones_jugador = acciones;
	}
	MovimientosJugador get_Accion() {
		return this->acciones_jugador;
	}
	void set_Vidas(short vidas) {
		this->vidas = vidas;
	}
	short get_Vidas() {
		return this->vidas;
	}
	void set_Puntaje(short puntaje) {
		this->puntaje = puntaje;
	}
	short get_Puntaje() {
		return this->puntaje;
	}
};