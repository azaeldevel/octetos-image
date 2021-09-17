
#ifndef OCTETOS_CORE_BMP_HH
#define OCTETOS_CORE_BMP_HH

#include <fstream>
#include <string>
#include <octetos/core/Exception.hh>

namespace oct::image
{

class BMP
{
public:
	struct Header
	{
		char signature[2];
		unsigned int size;
		short reserved1;
		short reserved2;
		unsigned int offset;

		Header();
	};
public:
	BMP(const std::string& file);
	~BMP();
	const std::ifstream& get_file()const;
	const Header& get_header()const;

	void load(const std::string& file);

private:
	std::ifstream file;
	Header header;
};

}

#endif