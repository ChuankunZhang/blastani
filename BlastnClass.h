#pragma once

#include <time.h>
#include <unistd.h>
#include <sstream>
#include <fstream>  
#include <cstring>  
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <cstdlib>
#include <cstdlib> 
#include <vector> 
#include <string> 
using namespace std;
class BlastnClass
{
private:
	string m_pPath;
	char* m_pTask;
	char* m_pQuery;
	char* m_pQuery2;
	const char* m_pDB;
	char* m_pOut;
	char* m_pNum_align;
  	char* m_pPenalty;
	char* m_pReward;
	char* m_pOutfmt;
	string m_pQueryPath;
	string m_Queryfna;

public:

	void BeginBlastn();
	void BeginMummer();
	//void SetPath(char* pathc = NULL);
	void SetPath(string paths = NULL);
	void SetTask(char* task = NULL);
	void SetQuery(char* query = NULL);
	void SetQuery2(char* query = NULL);
	void SetDB(const char* db = NULL);
	void SetOut(char* out = NULL);
	void SetNum_align(int num_align);
	void SetPenalty(int penalty);
	void SetReward(int reward);
	void SetOutfmt(int outfmt);

	void SetCopy();
	void SetQueryPath(string querypaths = NULL);
	string GetQueryfna(){return m_Queryfna;}
public:
	
	BlastnClass();  
	virtual ~BlastnClass(void);  

};
