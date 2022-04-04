#ifndef _STRING_H_
#define _STRING_H_

#include <memory.h>

class string
{
public:
	string(const char *src);
	string(string *src);
	~string();

	void concat(string *src);
	const char *toPrint(void);
	int sentencesCount(void);
	int length(void);
private:
	char *data;
};

#endif //_STRING_H_