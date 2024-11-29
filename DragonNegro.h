#pragma once
#include "Entidad.h"
enum MovDragonNegro { Abajo3, Izquierda3, Derecha3, Arriba3 };
class DragonNegro :public Entidad {
private:
	MovDragonNegro accion_Negro;
	short vidas;
public:
	DragonNegro(Graphics^ g, Random^ r) { //Movimiento a cualquier lado
		this->x = r->Next(20, g->VisibleClipBounds.Width - 40);
		this->y = r->Next(20, g->VisibleClipBounds.Height - 50);
		this->dx = r->Next(5, 10);
		this->dy = r->Next(5, 10);
		this->ancho = 432 / 9;
		this->alto = 224 / 4;
		this->index_x = 7;
		this->accion_Negro= Abajo3;
		this->vidas = 3;
	}
	~DragonNegro() {}
	void Mover(Graphics^ g) {
		if (x + dx < 0 || x + dx + ancho >= g->VisibleClipBounds.Width)dx *= -1;
		if (y + dy < 0 || y + dy + alto >= g->VisibleClipBounds.Height)dy *= -1;
		if (dx > 0 && dy > 0)accion_Negro = Derecha3;
		if (dx < 0 && dy < 0)accion_Negro = Izquierda3;
		if (dx == 0 && dy < 0)accion_Negro = Arriba3;
		if (dx == 0 && dy > 0)accion_Negro = Abajo3;
		x += dx;
		y += dy;
	}
	void Dibujar(Graphics^ g, Bitmap^ img) {
		Rectangle Corte = Rectangle(index_x * ancho, accion_Negro * alto, ancho, alto); //una porcion
		g->DrawImage(img, Area(), Corte, GraphicsUnit::Pixel);
		if (dx != 0 || dy!=0) { //Si hay velocidad hay animacion
			index_x = (index_x + 1) % 9;//Un limite para que solamente se sume hasta el 3 y luego regrese a 0
			if (index_x <=6)index_x = 7;
		}
	}
	void set_Accion(MovDragonNegro accion) {
		this->accion_Negro = accion;
	}
	void set_Vidas(short vidas) {
		this->vidas = vidas;
	}
	short get_Vidas() {
		return this->vidas;
	}
};