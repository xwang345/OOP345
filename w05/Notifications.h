/////////////////////////////////////////////
// OOP345 Workshop 5: Containers 
// Name: Sanghun Kim
// Date: 10/25/2106
// email: ksanghun@myseneca.ca
/////////////////////////////////////////////

#pragma once
#include "Message.h"
#include <vector>

typedef unsigned short ushort;
namespace w5{
	class Notifications
	{
		std::vector<Message> vecmsg;
		ushort numOfmsg;
				
	public:
		Notifications();
		Notifications(const Notifications& N);
		Notifications& operator=(const Notifications& N);
		Notifications(Notifications&& N);
		Notifications&& operator=(Notifications&& N);
		~Notifications();

		void operator+=(const Message& msg);
		void display(std::ostream& os) const;
	};
}

