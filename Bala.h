#pragma once
#include "Entidad.h"
enum DireccionBala{IzquierdaB,ArribaB,DerechaB,AbajoB};
class Bala :public Entidad {
private:
	DireccionBala accion_bala;
	bool visible;
public:
	Bala(short x,short y,short dx,short dy,DireccionBala accion) {
		this->x = x;
		this->y = y;
		this->dx = dx;
		this->dy = dy;
		this->ancho = 512 / 8;
		this->alto = 256 / 4;
		this->index_x = 0;
		this->accion_bala = accion;
		this->visible = true;
	}
	~Bala(){}
	void Mover(Graphics^g) {
		if (x + dx > 0 && x + dx + ancho <= g->VisibleClipBounds.Width)x += dx;
		if (y + dy > 0 && y + dy + alto <= g->VisibleClipBounds.Height)y += dy;
	}
	void Dibujar(Graphics^g,Bitmap^img) {
		Rectangle Corte = Rectangle(index_x * ancho, accion_bala * alto, ancho, alto); //una porcion
		g->DrawImage(img, Area(), Corte, GraphicsUnit::Pixel);
			if (dx != 0 || dy != 0) { //Si hay velocidad hay animacion
				index_x = (index_x + 1) % 8;//Un limite para que solamente se sume hasta el 3 y luego regrese a 0
			}
	}
	void set_Accion(DireccionBala accion) {
		this->accion_bala = accion;
	}
	void set_Visible(bool visible) {
		this->visible = visible;
	}
	bool get_Visible() {
		return this->visible;
	}
};