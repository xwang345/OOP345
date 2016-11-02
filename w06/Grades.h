
/////////////////////////////////////////////
// OOP345 Workshop 6: Lambda Expressions  
// Name: Sanghun Kim
// Date: 11/02/2106
// email: ksanghun@myseneca.ca
/////////////////////////////////////////////


#pragma once
#include <vector>
#include <iostream>
#include <functional>
#include <string>


typedef std::string(*pFunc)(float);
struct GradeInfo{
	unsigned int sid;
	float fscore;
};

namespace w6{
	class Grades
	{
		std::vector<GradeInfo> pData;
	public:
		Grades();
		Grades(const char* filepath);
		~Grades();

		void readFile(const char* filepath);
		void displayGrades(std::ostream& os, pFunc lambda) const;
	};
}
