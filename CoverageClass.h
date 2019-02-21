#pragma once

#include <time.h>
#include <unistd.h>
#include <sstream>
#include <fstream>  
#include <string.h>  
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <cstdlib>
#include <stdlib.h> 
#include <vector> 
#include <cmath>
using namespace std;
class CoverageClass
{
private:
	float m_Sum;
	int m_SumG;
	int m_count;
	int m_Count;
	float m_PCD;
	vector <float> m_V3;
	vector <int> m_V1;
	vector <int> m_V4;
	vector <int> m_V7;

public:
	
	void BeginCoverage();
	float GetSum(){return m_Sum;}
	int GetSumG(){return m_SumG;}
	float GetPCD(){return m_PCD;}
	void SetVec3(vector <float> &v3);
	void SetVec4(vector <int> &v4);	
	void SetVec7(vector <int> &v7);
	void SetVec1(vector <int> &v1);
	
	void SetCount(int Count);
	void Setcount(int count);

public:
	
	CoverageClass();  
	virtual ~CoverageClass(void);  

};


