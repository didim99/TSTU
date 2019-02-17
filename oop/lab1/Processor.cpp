#include "stdafx.h"
#include "Processor.h"

void Processor::setData(CArray<int>* data)
{
	this->data = data;
	this->fp = false;
}

void Processor::setData(CArray<double>* data)
{
	this->dataFP = data;
	this->fp = true;
}

void Processor::setAction(action a)
{
	this->currAction = a;
	switch (a)
	{
	case Processor::ADD:
	case Processor::SUB:
		this->result = 0;
		this->resultFP = 0.0;
		break;
	case Processor::MULT:
	case Processor::DIV:
		this->result = 1;
		this->resultFP = 1.0;
		break;
	}
}

void Processor::process()
{
	if (fp) processFP();
	else processInt();
}

void Processor::processFP()
{
	CArray<double>* data = this->dataFP;
	for (int i = 0; i < data->GetSize(); i++)
	{
		switch (this->currAction)
		{
		case Processor::ADD:
			this->resultFP += data->GetAt(i);
			break;
		case Processor::SUB:
			if (i == 0) this->resultFP = data->GetAt(i);
			else this->resultFP -= data->GetAt(i);
			break;
		case Processor::MULT:
			this->resultFP *= data->GetAt(i);
			break;
		case Processor::DIV:
			if (i == 0) this->resultFP = data->GetAt(i);
			else this->resultFP /= data->GetAt(i);
			break;
		}
	}
}

void Processor::processInt()
{
	CArray<int>* data = this->data;
	for (int i = 0; i < data->GetSize(); i++)
	{
		switch (this->currAction)
		{
		case Processor::ADD:
			this->result += data->GetAt(i);
			break;
		case Processor::SUB:
			if (i == 0) this->result = data->GetAt(i);
			else this->result -= data->GetAt(i);
			break;
		case Processor::MULT:
			this->result *= data->GetAt(i);
			break;
		case Processor::DIV:
			if (i == 0) this->result = data->GetAt(i);
			else this->result /= data->GetAt(i);
			break;
		}
	}
}

CString Processor::getResult()
{
	CString str;
	if (fp) str.Format(L"Result: %.3f", this->resultFP);
	else str.Format(L"Result: %d", this->result);
	return str;
}

