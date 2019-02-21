#pragma once

#include <time.h>
#include <unistd.h>
#include <sstream>
#include <fstream>  
#include <string>
#include <cstring>  
#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <cstdlib>
#include <cstdio>
#include <vector> 

#define CHOP_LEN 1020 
#define CVP 30 
#define ID 70

using namespace std;
class QueryCopyBClass
{
	
private:
	char* m_pInQuery;
	char* m_pOutQuery;
	int m_count;
	int m_Count;
	vector<int> m_V1;
	vector<float> m_V3;
	vector<int> m_V4;
	vector<int> m_V7;
	vector<int> m_Icount;
	float m_ANI;
	float m_PCD;	
	int m_hc;
	vector<int> m_At;

public:

	void SetInQuery(char* in_query = NULL);
	void SetOutQuery(char* out_query = NULL);
	float GetANI();
	float GetPCD();
	

	vector<int> GetVec1();
	vector<float> GetVec3();
	vector<int> GetVec4();	
	vector<int> GetVec7();
	
	void SetVecAt(vector <int> &va);
	void SetVecIcount(vector <int> &vi);
	void SetCount(int Count);	

	void Copy(int type);
	int Getcount();
	int Gethc(){return m_hc;}
public:
	
	QueryCopyBClass();  
	virtual ~QueryCopyBClass(void);  

};


