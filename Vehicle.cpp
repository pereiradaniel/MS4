#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <sstream>
#include "Vehicle.h"
#include "Utils.h"
using namespace std;
namespace sdds {
	Vehicle::Vehicle() : ReadWritable(), m_licensePlate{}, m_makeModel(nullptr), m_parkingSpot(0) {
		setEmpty();
	}

	Vehicle::Vehicle(const char* licensePlate, const char* makeModel) : ReadWritable(), m_licensePlate{}, m_makeModel(nullptr), m_parkingSpot(0) {
		// if license plate not null, not empty string, <= 8,
		// make/model not null and >=2
		if (licensePlate != nullptr && licensePlate[0] != '\0' && strlen(licensePlate) <= 8 && makeModel != nullptr && strlen(makeModel) >= 2) {
			// copy license plate
			strcpy(m_licensePlate, licensePlate);
			// set make/model and capitalize make/model using Utils
			m_makeModel = new char[strlen(makeModel) + 1];
			strcpy(m_makeModel, makeModel);
			// Utils::toUpper(m_licensePlate);
		}
		else {
			// otherwise set empty
			setEmpty();
		}
	}

	Vehicle::~Vehicle() {
		delete[] m_makeModel;
	}

	bool Vehicle::isEmpty() const {
		return m_makeModel == nullptr;
	}

	void Vehicle::setEmpty() {
		delete[] m_makeModel;
		m_makeModel = nullptr;
		m_licensePlate[0] = 0;
		m_parkingSpot = -1;
	}

	int Vehicle::getParkingSpot() const {
		//
		return m_parkingSpot;
	}

	void Vehicle::setParkingSpot(int value) {
		// if value is negative set empty
		if (value < 0) {
			setEmpty();
		}
		else {
			// otherwise copy value to m_parkingSpot
			m_parkingSpot = value;
		}
	}

	const char* Vehicle::getLicensePlate() const {
		//
		return m_licensePlate;
	}

	const char* Vehicle::getMakeModel() const {
		//
		return m_makeModel;
	}

	void Vehicle::setMakeModel(const char* value) {
		// if value is not null and not empty string
		if (value != nullptr) {
			// delete make/model
			delete[] m_makeModel;
			// allocate new memory
			m_makeModel = new char[strlen(value) + 1];
			// copy string
			strcpy(m_makeModel, value);
		}
		else {
			// otherwise - setEmpty()
			setEmpty();
		}
	}

	bool Vehicle::operator==(const char* licensePlate) const {
		bool result = false;
		// if object not empty and license plate is valid
		if (!isEmpty() && licensePlate != nullptr && licensePlate[0] != '\0' && strlen(licensePlate) <= 8) {
			// copy license plate to temporary array of char
			char* temp;
			temp = new char[strlen(licensePlate) + 1];
			strcpy(temp, licensePlate);
			// convert to upper case
			Utils::toUpper(temp);
			// call strcmp()
			if (strcmp(temp, licensePlate) == 0) {
				result = true;
			}
			else {
				result = false;
			}
		}
		return result;
	}

	bool Vehicle::operator==(const Vehicle& V) const {
		return operator==(V.m_licensePlate);
	}

	istream& Vehicle::read(istream& istr) {
		// read data according to MS documentation
		// use istr.getline(buffer, length, separator) if csv mode
		if (isCsv()) {
			// Get parking spot number:
			char spotNo[9];
			istr.get(spotNo, 9, ',');
			istr.ignore(2000, ',');

			// Get plate number:
			char plate[9];
			istr.get(plate, 9, ',');
			istr.ignore(2000, ',');

			// Get make and model:
			char makeModel[61];
			istr.get(makeModel, 61, ',');
			istr.ignore(2000, ',');

			m_parkingSpot = stoi(spotNo);
			strcpy(m_licensePlate, plate);
			if (m_licensePlate[0] != '\0') {
				Utils::toUpper(m_licensePlate);
			}
			setMakeModel(makeModel);
		}
		else if (!isCsv()) {
			// use utils::read() otherwise
			cout << "Enter Licence Plate Number: ";
			// static void read(int& val, int min, int max, const char* errorMessage = "", std::istream & is = std::cin);
			char licensePlate[9];
			// licensePlate = new char[9];
			Utils::read(licensePlate, 8, "Invalid Licence plate, try again: ", istr);
			strcpy(m_licensePlate, licensePlate);
			Utils::toUpper(m_licensePlate);

			cout << "Enter Make and Model: ";
			char makeModel[61];
			Utils::read(makeModel, 2, 60, "Invalid Make and model, try again: ", istr);
			setMakeModel(makeModel);

			m_parkingSpot = 0;
		}
		return istr;
	}

	ostream& Vehicle::write(ostream& ostr) const {
		// write data according to MS documentation
		if (!this->isEmpty()) {
			if (isCsv()) {
				ostr << m_parkingSpot << "," << m_licensePlate << "," << m_makeModel << ",";
			}
			else {
				ostr << "Parking Spot Number: ";
				if (m_parkingSpot == 0) {
					ostr << "N/A";
				}
				else {
					ostr << m_parkingSpot;
				}
				ostr << endl;
				ostr << "Licence Plate: " << m_licensePlate << endl;
				ostr << "Make and Model: " << m_makeModel << endl;
			}
		}
		else {
			ostr << "Invalid Vehicle Object" << endl;
		}

		return ostr;
	}
}