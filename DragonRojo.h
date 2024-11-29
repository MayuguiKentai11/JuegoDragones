#pragma once
#include "Entidad.h"
enum MovDragonRojo { Abajo1, Izquierda1, Derecha1, Arriba1 };
class DragonRojo :public Entidad {
private:
	MovDragonRojo accion_Rojo;
	short vidas;
public:
	DragonRojo(Graphics^ g, Random^ r) { //Movimiento Vertical
		this->x = r->Next(20, g->VisibleClipBounds.Width - 40);
		this->y = r->Next(20, g->VisibleClipBounds.Height - 50);
		this->dx = 0;
		this->dy = r->Next(5, 8);
		this->ancho = 432 / 9;
		this->alto = 224 / 4;
		this->index_x = 0;
		this->accion_Rojo = Izquierda1;
		this->vidas = 2;
	}
	~DragonRojo() {}
	void Mover(Graphics^ g) {
		if (y + dy < 0 || y + dy + alto >= g->VisibleClipBounds.Height)dy *= -1;
		if (dy < 0)accion_Rojo = Arriba1;
		if (dy > 0)accion_Rojo = Abajo1;
		y += dy;
	
	}
	void Dibujar(Graphics^ g, Bitmap^ img) {
		Rectangle Corte = Rectangle(index_x * ancho, accion_Rojo * alto, ancho, alto); //una porcion
		g->DrawImage(img, Area(), Corte, GraphicsUnit::Pixel);
		if (dy!=0 || dx!=0) { //Si hay velocidad hay animacion
			index_x = (index_x + 1) % 3;//Un limite para que solamente se sume hasta el 3 y luego regrese a 0
		}
	}
	void set_Accion(MovDragonRojo accion) {
		this->accion_Rojo = accion;
	}
	void set_Vidas(short vidas) {
		this->vidas = vidas;
	}
	short get_Vidas() {
		return this->vidas;
	}

};