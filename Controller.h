#pragma once
#include <vector>
#include <fstream>
#include "DragonAzul.h"
#include "DragonNegro.h"
#include "DragonRojo.h"
#include "Jugador.h"
#include "Bala.h"
class Controller {
private:
	vector<DragonAzul*>vector_azul;
	vector<DragonNegro*>vector_negro;
	vector<DragonRojo*>vector_rojo;
	vector<Bala*>vector_bala;
	Jugador* Player;
public:
	Controller(Graphics^g,Random^r) {
		Player = new Jugador(g, r);
	}
	~Controller() {
		delete Player;
	}
	//Agregar Dragones
	void Agregar_Azul(Graphics^g,Random^r) {
		vector_azul.push_back(new DragonAzul(g, r));
	}
	void Agregar_Rojo(Graphics^g,Random^r) {
		vector_rojo.push_back(new DragonRojo(g, r));
	}
	void Agregar_Negro(Graphics^g,Random^r) {
		vector_negro.push_back(new DragonNegro(g, r));
	}
	void Agregar_Bala(short x,short y,short dx,short dy,DireccionBala accion) {
		vector_bala.push_back(new Bala(x, y, dx, dy, accion));
	}
	void MoverDragones(Graphics^g,Bitmap^img) {
		if (!vector_azul.empty()) {
			for (DragonAzul* C : vector_azul) {
				C->Mover(g);
				C->Dibujar(g, img);
			}
		}
		if (!vector_rojo.empty()) {
			for (DragonRojo* C : vector_rojo) {
				C->Mover(g);
				C->Dibujar(g, img);
			}
		}
		if (!vector_negro.empty()) {
			for (DragonNegro* C : vector_negro) {
				C->Mover(g);
				C->Dibujar(g, img);
			}
		}
	}
	void CambiarVelocidadJugador(Keys k,bool mover) {
		short velocidad = 4;
		short velocidad_bala = 15;
		if (mover == true) {
			if (k == Keys::Up) {
				Player->set_Dy(-velocidad);
				Player->set_Accion(Arriba);
			}
			if (k == Keys::Down) {
				Player->set_Dy(velocidad);
				Player->set_Accion(Abajo);
			}
			if (k == Keys::Right) {
				Player->set_Dx(velocidad);
				Player->set_Accion(Derecha);
			}
			if (k == Keys::Left) {
				Player->set_Dx(-velocidad);
				Player->set_Accion(Izquierda);
			}
			//Disparar
			if (k == Keys::X) {
				if (Player->get_Accion() == Arriba || Player->get_Accion()==DispararArriba) {
					Player->set_Accion(DispararArriba);
					Agregar_Bala(Player->get_X(), Player->get_Y() - 5, 0, -velocidad_bala, ArribaB);
				}
				if (Player->get_Accion() == Izquierda || Player->get_Accion()==DispararIzquierda) {
					Player->set_Accion(DispararIzquierda);
					Agregar_Bala(Player->get_X() - 5, Player->get_Y(), -velocidad_bala, 0, IzquierdaB);
				}
				if (Player->get_Accion() == Derecha || Player->get_Accion()==DispararDerecha) {
					Player->set_Accion(DispararDerecha);
					Agregar_Bala(Player->get_X() + 5, Player->get_Y(), velocidad_bala,0, DerechaB);
				}
				if (Player->get_Accion() == Abajo || Player->get_Accion()==DispararAbajo) {
					Player->set_Accion(DispararAbajo);
					Agregar_Bala(Player->get_X(), Player->get_Y() + 5, 0, velocidad_bala, AbajoB);
				}
			}
		}
		else {
			if (k == Keys::Up) {
				Player->set_Dy(0);
			}
			if (k == Keys::Down) {
				Player->set_Dy(0);
			}
			if (k == Keys::Right) {
				Player->set_Dx(0);
			}
			if (k == Keys::Left) {
				Player->set_Dx(0);
			}
		}
	}
	void MoverBala(Graphics^g,Bitmap^img) {
		if (!vector_bala.empty()) {
			for (Bala* C : vector_bala) {
				C->Mover(g);
				C->Dibujar(g, img);
			}
		}
	}
	void FuncionalidadJugador(Graphics^g,Bitmap^img) {
		Player->Mover(g);
		Player->Dibujar(g, img);
	}
	//Colisiones
	bool ColisionesDragonJugador() {
		if (!vector_azul.empty()) 
		{

			for (short i = 0; i < vector_azul.size(); i++) 
			{

				if (vector_azul[i]->Area().IntersectsWith(Player->Area())) 
				{
					short vidaa = Player->get_Vidas() - 1;
					vector_azul.erase(vector_azul.begin() + i);
					Player->set_Vidas(vidaa);
				}
			}
		}
		if (!vector_negro.empty()) {
			for (short i = 0; i < vector_negro.size(); i++) {
				if (vector_negro[i]->Area().IntersectsWith(Player->Area())) {
					short vidaa2 = Player->get_Vidas() - 1;
					vector_negro.erase(vector_negro.begin() + i);
					Player->set_Vidas(vidaa2);
				}
			}
		}
		if (!vector_rojo.empty()) {
			for (short i = 0; i < vector_rojo.size(); i++) {
				if (vector_rojo[i]->Area().IntersectsWith(Player->Area())) {
					short vidaa1 = Player->get_Vidas() - 1;
					vector_rojo.erase(vector_rojo.begin() + i);
					Player->set_Vidas(vidaa1);
				}
			}
		}
		if (Player->get_Vidas() <= 0) {
			return true;
		}
		else {
			return false;
		}
	}
	void ColisionDragonBala(Graphics^g) {
		if (!vector_bala.empty() && !vector_azul.empty()) { //Listo
			for (short i = 0; i < vector_bala.size(); i++) {
				for (short j = 0; j < vector_azul.size(); j++) {
					if (vector_bala[i]->Area().IntersectsWith(vector_azul[j]->Area())) {
						vector_bala[i]->set_Visible(false);
						vector_azul.erase(vector_azul.begin() + j);
						//Obtienes 100 de puntaje
						short puntaje1 = Player->get_Puntaje() + 100;
						Player->set_Puntaje(puntaje1);
					}
				}
			}
		}
		if (!vector_rojo.empty() && !vector_bala.empty()) { //Listo
			for (short i = 0; i < vector_bala.size(); i++) {
				for (short j = 0; j < vector_rojo.size(); j++) {
					if (vector_bala[i]->Area().IntersectsWith(vector_rojo[j]->Area())) {
						vector_bala[i]->set_Visible(false);
						short vida_rojo = vector_rojo[j]->get_Vidas() - 1;
						vector_rojo[j]->set_Vidas(vida_rojo);
						if (vector_rojo[j]->get_Vidas() <= 0) {
							vector_rojo.erase(vector_rojo.begin() + j);
							//Obtienes 200 de puntaje
							short puntaje2 = Player->get_Puntaje() + 200;
							Player->set_Puntaje(puntaje2);
						}
					}
				}
			}
		}
		if (!vector_negro.empty() && !vector_bala.empty()) { // 
			for (short i = 0; i < vector_bala.size(); i++) {
				for (short j = 0; j < vector_negro.size(); j++) {
					if (vector_bala[i]->Area().IntersectsWith(vector_negro[j]->Area())) {
						vector_bala[i]->set_Visible(false);
						vector_negro[j]->set_Vidas(vector_negro[j]->get_Vidas() - 1);
						if (vector_negro[j]->get_Vidas() <= 0) {
							vector_negro.erase(vector_negro.begin() + j);
							//Obtienes 300 de puntaje
							short puntaje3 = Player->get_Puntaje() + 300;
							Player->set_Puntaje(puntaje3);
						}
					}
				}
			}
		}
		if (!vector_bala.empty()) {
			for (short i = 0; i < vector_bala.size(); i++) {
				if (vector_bala[i]->get_Visible() == false) {
					vector_bala.erase(vector_bala.begin() + i);
				}
			}
		}
		if (!vector_bala.empty()) {
			for (short i = 0; i < vector_bala.size(); i++) {
				if (vector_bala[i]->get_Y() +vector_bala[i]->get_Dy() <= 40 || vector_bala[i]->get_Y() +vector_bala[i]->get_Dy()+vector_bala[i]->get_Alto()
					>=g->VisibleClipBounds.Height - 20|| vector_bala[i]->get_X() + vector_bala[i]->get_Dx() <= 20|| vector_bala.at(i)->get_X() 
					+vector_bala[i]->get_Dx()+vector_bala[i]->get_Ancho() >= g->VisibleClipBounds.Width - 20) {
					vector_bala.erase(vector_bala.begin() + i);
				}
			}
		}
	}
	//Colisiones Terminadas
	void GuardarInformacion() {
		ofstream archivo("archivo.txt");
		if (archivo.is_open()) {
			archivo << "-----ULTIMA PARTIDA!-----" << endl;
			archivo << "Variable Inicial X: " << Player->get_X() << endl;
			archivo << "Variable Inicial Y: " << Player->get_Y() << endl;
			//archivo << "Puntaje de la ultima partida: " << Player->get_Puntaje() << endl;
			archivo.close();
		}
	}
	short get_Vidas() {
		return Player->get_Vidas();
	}
	short get_Puntaje() {
		return Player->get_Puntaje();
	}
};