#include <iostream>
#include <cstring>
#include "Vehicle.h"
#include "Utils.h"
using namespace std;
namespace sdds {
	Vehicle::Vehicle() : ReadWritable(), m_licensePlate{}, m_makeModel(nullptr), m_parkingSpot(0) {
		setEmpty();
	}

	Vehicle::Vehicle(const char* licensePlate, const char* makeModel) : ReadWritable(), m_licensePlate, m_makeModel(nullptr), m_parkingSpot(0) {
		// if license plate not null, not empty string, <= 8,
		// make/model not null and >=2
		// copy license plate
		// set make/model and capitalize make/model using Utils
		// otherwise set empty
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
	}

	void Vehicle::setParkingSpot(int value) {
		// if value is negative set empty
		// otherwise copy value to m_parkingSpot
	}

	const char* Vehicle::getLicensePlate() const {
		//
	}

	const char* Vehicle::getMakeModel() const {
		//
	}

	void Vehicle::setMakeModel(const char* value) {
		// if value is not null and not empty string
		// delete make/model
		// allocate new memory
		// copy string
		// otherwise - setEmpty()
	}

	bool Vehicle::operator==(const char* licensePlate) const {
		// if object not empty and license plate is valid
		// copy license plate to temporary array of char
		// convert to upper case
		// call strcmp()
		// return true/false accordingly
	}

	bool Vehicle::operator==(const Vehicle& V) const {
		return operator==(V.m_licensePlate);
	}

	istream& Vehicle::read(istream& istr) {
		// read data according to MS documentation
		// use istr.getline(buffer, length, separator) if csv mode
		// use utils::read() otherwise

		if (istr) {
			setMakeModel(makeModel);
			Utils::toUpper(m_licensePlate);
		}
		else {
			setEmpty();
		}
		return istr;
	}

	ostream& Vehicle::write(ostream& ostr) const {
		// write data according to MS documentation
		return ostr;
	}
}