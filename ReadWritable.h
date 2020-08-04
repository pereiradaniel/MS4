#ifndef SDDS_READWRITABLE_H__
#define SDDS_READWRITABLE_H__
#include <iostream>
namespace sdds {
	class ReadWritable {
	private:
		bool	m_csvIO;
	public:
		ReadWritable();				// false
		bool isCsv() const;			// getter
		void setCsv(bool value);	// setter
		virtual std::istream& read(std::istream& istr = std::cin) = 0;
		virtual std::ostream& write(std::ostream& ostr = std::cout) const = 0;
		virtual ~ReadWritable();	// virtual destructor resolved during runtime:  safe option
	};
	// Global functions:  Use private member functions (read, write).
	std::ostream& operator<<(std::ostream& ostr, const ReadWritable& rw);
	std::istream& operator>>(std::istream& istr, ReadWritable& rw);
}
#endif