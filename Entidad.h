#pragma once
#include <iostream>
using namespace System;
using namespace std;
using namespace System::Drawing;
using namespace System::Windows::Forms;
class Entidad {
protected:
	short x;
	short y;
	short dx;
	short dy;
	short ancho;
	short alto;
	short index_x;
public:
	Entidad() {
		this->x = 0;
		this->y = 0;
		this->dx = 0;
		this->dy = 0;
		this->ancho = 0;
		this->alto = 0;
		this->index_x = 0;
	}
	~Entidad(){}
	Rectangle Area() {
		return Rectangle(x, y, ancho, alto);
	}
	virtual void Mover() {}
	virtual void Dibujar() {}
	//Setters and Getters
	void set_X(short x) {
		this->x = x;
	}
	void set_Y(short y) {
		this->y = y;
	}
	void set_Dx(short dx) {
		this->dx = dx;
	}
	void set_Dy(short dy) {
		this->dy = dy;
	}
	short get_X() {
		return this->x;
	}
	short get_Y() {
		return this->y;
	}
	short get_Dx() {
		return this->dx;
	}
	short get_Dy() {
		return this->dy;
	}
	short get_Ancho() {
		return this->ancho;
	}
	short get_Alto() {
		return this->alto;
	}
};