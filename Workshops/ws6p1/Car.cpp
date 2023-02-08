//#include <iostream>
//#include <iomanip>
//#include "Name.h"
//
//using namespace std;
//namespace sdds
//{
//	Name::Name()
//	{
//		m_tag = '\0';
//		m_condition = '\0';
//		m_make = "";
//		m_topSpeed = 0.0;
//	}
//
//	Name::Name(std::istream& in)
//	{
//		while (in.get() || !in.eof() )
//		{
//			
//
//		}
//	}
//
//	std::string Name::condition() const
//	{
//		string condition = "";
//		if (m_condition == 'n'){
//			condition = "new";
//		}
//		else if (m_condition == 'u'){
//			condition = "used";
//		}
//		else if (m_condition == 'b'){
//			condition = "broken";
//		}
//		else {
//			condition = "BUG::Invalid Condition passed";
//		}
//		return condition;
//	}
//
//	double Name::topspeed() const
//	{
//		return m_topSpeed;
//	}
//
//	void Name::display(std::ostream& out)
//	{
//		out << "| " << setw(10) << m_make << " | " << setw(6) << m_condition <<
//			" | " << setw(6) << setprecision(2) << m_topSpeed << " |" << endl;
//	}
//}
//
