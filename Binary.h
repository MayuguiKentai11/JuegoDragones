#pragma once
#include <chrono>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
using namespace std;
struct Record {
	char name[20];
	char status[20];
	char date[50];
	char level[20];
};

class Configuracion {
public:
	vector<string> lines;

	string archivo;

	Configuracion(string data) {
		this->archivo = "datos.data";
		fstream file(archivo);
		if (file.is_open()) {
			Record record;
			file.seekg(0 * sizeof(record), ios::beg);
			while (file.read((char*)&record, sizeof(record))) {
				stringstream ss;
				ss << record.name << " - " << record.status << " - " << record.date << " - " << record.level;
				lines.push_back(ss.str());
			}
			file.seekg(0, ios::end);
			file.close();
		}
	}

	vector<string> getlines() {
		return lines;
	}

	void guardar(string nombre, char* estado, char* nivel) {
		Record record;
		strcpy_s(record.name, nombre.c_str());
		strcpy_s(record.status, estado);
		// record.name = nombre;
		// record.status = estado;
		time_t now = chrono::system_clock::to_time_t(chrono::system_clock::now());
		stringstream transTime;
		transTime << put_time(localtime(&now), "%d-%m-%Y %H:%M:%S");
		strcpy_s(record.date, transTime.str().c_str());
		strcpy_s(record.level, nivel);
		// record.date = (char*)transTime.str().c_str();
		// record.level = nivel;
		fstream file(archivo, ios::app | ios::binary);
		if (file.is_open()) {
			file.write((char*)&record, sizeof(record));
			file.close();
		}
	}
};