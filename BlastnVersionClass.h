#include <time.h>
#include <unistd.h>
#include <sstream>
#include <fstream>
#include <string>  
//#include <string.h>  
#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <cstdlib>
#include <cstdio> 
#include <vector> 

#include "DataBaseClass.h"
#include "BlastnClass.h"
#include "CoverageClass.h"
#include "QueryCutClass.h"
#include "QueryCopyBClass.h"

using namespace std;  


class BlastnVersionClass{

	private:
	
		int m_Version1;
		int m_Version2;
		int m_Version3;
		string m_Version;
		
		int m_VersionEnd;



	public:

		void Cmd();
		void End();		
		int GetEnd(){return m_VersionEnd;}
		string GetVector(){return m_Version;}


	public:

		BlastnVersionClass();
		virtual ~BlastnVersionClass(void);

};
