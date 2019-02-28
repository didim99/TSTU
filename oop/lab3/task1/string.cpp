#include "string.h"

string::string(const char *src)
{
	int len = 0;
	const char *tmp = src;
	while (*(tmp++)) len++;
	data = new char[len + 1];
	memcpy(data, src, len);
	data[len] = 0;
}

string::string(string *src)
{
	int len = src->length();
	data = new char[++len];
	memcpy(data, src->data, len);
}

string::~string()
{
	delete[] data;
}

void string::concat(string *src)
{
	int mylen = length();
	int otherlen = src->length();
	char *newData = new char[mylen + otherlen + 1];
	memcpy(newData, data, mylen);
	memcpy(newData+mylen, src->data, otherlen);
	newData[mylen + otherlen] = 0;
	delete[] data;
	data = newData;
}

const char *string::toPrint(void)
{
	return (const char*) data;
}

int string::sentencesCount(void)
{
	int count = 0;
	char *tmp = data;
	while (*(tmp++))
		if (*tmp == '.' || *tmp == '!' || *tmp == '?') count++;
	return count ? count : 1;
}

int string::length(void)
{
	int len = 0;
	char *tmp = data;
	while (*(tmp++)) len++;
	return len;
}
