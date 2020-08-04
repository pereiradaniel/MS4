#ifndef SDDS_VEHICLE_H__
#define SDDS_VEHICLE_H__
#include "ReadWritable.h"
namespace sdds {
	class Vehicle : public ReadWritable {
	private:
		char	m_licensePlate[9];		// 8 characters + '0', static array
		char*	m_makeModel;			// dynamic array
		int		m_parkingSpot;			// 0 by default
	public:
		Vehicle();
		Vehicle(const char* licensePlate, const char* makeModel);
		Vehicle(const Vehicle&) = delete;
		void operator=(const Vehicle&) = delete;
		virtual ~Vehicle();
		void			setEmpty();
		bool			isEmpty()const;
		const char*		getLicensePlate()const;				// getter
		const char*		getMakeModel()const;				// getter
		void			setMakeModel()const;				// setter
		int				getParkingSpot()const;				// getter
		void			setParkingSpot(int value);			// setter
		bool operator=(const char* licensePlate) const;		// overload comparison operator
		bool operator=(const Vehicle& v) const;				// overload comparison operator
		std::istream&	read(std::istream& istr);
		std::ostream&	write(std::ostream& ostr) const;
	};
}
#endif