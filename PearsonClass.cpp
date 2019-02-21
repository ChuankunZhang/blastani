#include "PearsonClass.h"
using namespace std;
PearsonClass::PearsonClass()
{ 
	m_N = 0;
	m_DDH = NULL;
	m_D0 = NULL;
	m_p = 0;
}

PearsonClass::~PearsonClass(void)
{
	

}

void PearsonClass::Pearson()
{	

	int DDHs = 0;
	float D0s = 0;
	int DDHs2 = 0;
	float D0s2 = 0;
	float DDm = 0;
	
	for(int i=0;i<m_N;i++)
	DDHs += m_DDH[i];

	for(int i=0;i<m_N;i++)
	D0s += m_D0[i];

	for(int i=0;i<m_N;i++)
	DDHs2 += m_DDH[i]*m_DDH[i];

	for(int i=0;i<m_N;i++)
	D0s2 += m_D0[i]*m_D0[i];

	for(int i=0;i<m_N;i++)
	DDm += m_DDH[i]*m_D0[i];

	float a = DDm-(DDHs*D0s/m_N);
	float b = DDHs2-(DDHs*DDHs/m_N);
	float c = D0s2-(D0s*D0s/m_N);
	
	m_p = a/(sqrt(b*c));
	
	cout<<m_p<<endl;
}

void PearsonClass::SetN(int n)
{
	m_N = n;
	
}

void PearsonClass::SetDDH(int* DDH)
{
	m_DDH = DDH;
	
}

void PearsonClass::SetD0(float* D0)
{
	m_D0 = D0;
	
}
