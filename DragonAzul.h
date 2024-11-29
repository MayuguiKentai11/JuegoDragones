#pragma once
#include "Entidad.h"
enum MovDragonAzul{Abajo2,Izquierda2,Derecha2,Arriba2};
class DragonAzul :public Entidad {
private:
	MovDragonAzul accion_Azul;
public:
	DragonAzul(Graphics^g,Random^r) { //Movimiento Horizontal
		this->x = r->Next(20, g->VisibleClipBounds.Width - 40);
		this->y = r->Next(20, g->VisibleClipBounds.Height - 50);
		this->dx = r->Next(5, 8);
		this->dy = 0;
		this->ancho = 432 / 9;
		this->alto = 224 / 4;
		this->index_x = 3;
		this->accion_Azul = Izquierda2;
	}
	~DragonAzul(){}
	void Mover(Graphics^g) {
		if (x + dx < 0 || x + dx + ancho >= g->VisibleClipBounds.Width)dx *= -1;
		if (dx < 0)accion_Azul = Izquierda2;
		if (dx > 0)accion_Azul = Derecha2;
		x += dx;
	}
	void Dibujar(Graphics^g,Bitmap^img) {
		Rectangle Corte = Rectangle(index_x * ancho, accion_Azul * alto, ancho, alto); //una porcion
		g->DrawImage(img, Area(), Corte, GraphicsUnit::Pixel);
			if (dx != 0 || dy!=0) { //Si hay velocidad hay animacion
				index_x = (index_x + 1) % 5;//Un limite para que solamente se sume hasta el 3 y luego regrese a 0
			}
			if (index_x == 0)index_x = 3;
	}
	void set_Accion(MovDragonAzul accion) {
		this->accion_Azul = accion;
	}

};