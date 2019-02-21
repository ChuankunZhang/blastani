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

class PearsonClass
{
	public:
		void Pearson();
		void SetN(int n);

		void SetDDH(int* DDH);
		void SetD0(float* D0);
		
		float Getp(){return m_p;}
	
	public:
		PearsonClass();
		~PearsonClass(void);
	
	private:
		int m_N;
		int* m_DDH;
		float*  m_D0;
		float m_p;
};

