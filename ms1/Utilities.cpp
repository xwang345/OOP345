#include "Utilities.h"

char Utilities::delimiter = '|';
Utilities::Utilities()
{
	
}

std::string& Utilities::ltrim(std::string& s, const char* t)
{
	s.erase(0, s.find_first_not_of(t));
	return s;
}
std::string& Utilities::rtrim(std::string& s, const char* t)
{
	s.erase(s.find_last_not_of(t) + 1);
	return s;
}

const std::string Utilities::nextToken(const std::string& str, size_t& next_pos, bool& more)
{
	std::string token;
	for(; (str.size() > next_pos) && (str[next_pos] != delimiter); next_pos++){
		token += str[next_pos];
	}

	// trim left & right //
	token = ltrim(rtrim(token));


	if (str.size() > next_pos){
		more = true;
		next_pos++;
	}
	else{
		more = false;
	}

	
	if (field_width < token.size()) {
		field_width = token.size();
	}
	return token;
}

void Utilities::setDelimiter(const char c) {
	delimiter = c;
}

