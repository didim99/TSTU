#pragma once
class Processor
{
public:
	enum action { ADD, SUB, MULT, DIV };
	
	void setData(CArray<int>* data);
	void setData(CArray<double>* data);
	void setAction(action a);
	void process();
	CString getResult();
private:
	void processFP();
	void processInt();

	bool fp = false;
	action currAction;
	CArray<int>* data;
	CArray<double>* dataFP;
	int result = 0;
	double resultFP = 0;
};

