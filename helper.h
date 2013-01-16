#ifndef _HELPER_H_
#define _HELPER_H_

#include <fstream>

using namespace std;

namespace ANN_ERROR{
	struct file_exception{
		const char* p;
		file_exception(const char* q);
	};
}

//for reading arrays from file
float** generateAsciiArray(char* file, int amount, int height, int width);



#endif
