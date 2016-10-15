/////////////////////////////////////////////
// OOP345 Workshop 3: Move and Copy Semantics 
// Name: Sanghun Kim
// Date: 10/10/2106
// email: ksanghun@myseneca.ca
/////////////////////////////////////////////


#pragma once

#include <string>

namespace w3
{
	class Text
	{
	public:
		Text();
		Text(const char* filename);

		Text(const Text& text);  // copy constructor
		Text(Text&& text);		// move constructor

		Text& operator=(const Text& text);	// copy assignment operator
		Text&& operator=( Text&& text);		// move assignment operator

		~Text();

		void init(const Text& text);
		size_t size() const { return m_numOfString; }

	private:
		std::string* m_pString;
		unsigned m_numOfString;
	};
}

