#include "CoverageClass.h"
using namespace std;
CoverageClass::~CoverageClass(void)
{
}


CoverageClass::CoverageClass()
{
	m_Sum = 0;
	m_SumG = 0;
	m_PCD = 0;
	m_count = 0;
	m_Count = 0;
}

void CoverageClass::BeginCoverage()
{	
	vector <float> r3ani(m_Count,0);
	vector <float> r4ani(m_Count,0);
	//r3ani.resize((int)Count);
	float m_Sum1 = 0;	 
		ofstream out("ppp.txt");
		for(int x=0;x<m_count;x++){		
			
			for(int y=(m_V1.at(x)+m_V7.at(x)-1);y<(m_V1.at(x)+m_V7.at(x)-1+m_V4.at(x));y++){				
						
						
						if(r3ani.at(y)<m_V3.at(x)){
							
							//m_Sum+=m_V3.at(x);
							//m_Sum-=r3ani.at(y);
							r3ani.at(y)=m_V3.at(x);
							r4ani.at(y)=m_V4.at(x);	
						}
						
			}	
							
		}
		int m = r3ani.size()/670000;
		int c=m_Count;
		vector <float> n(m+1,0);
		vector <float> n1(m+1,0);
		float k=101.00;
		float e=0;
		int r=0;
		for(int j=0;j<m;j++)
		for(int i=j*670000;i<(j+1)*670000;i++){

			if(r3ani.at(i) != k){
				k = r3ani.at(i);
				e +=(r4ani.at(i)-r4ani.at(i)*r3ani.at(i)/100);
				
}

			if(r3ani.at(i)!=0){
				n.at(j) = n.at(j)+r3ani.at(i);
				n1.at(j) = n1.at(j)+r4ani.at(i);
				r++;
			}else
			m_Count--;
			
}

		for(int i=m*670000;i<r3ani.size();i++){

			if(r3ani.at(i) != k){
				k = r3ani.at(i);
				e +=(r4ani.at(i)-r4ani.at(i)*r3ani.at(i)/100);
						
}

			if(r3ani.at(i)!=0){		
				n.at(m) = n.at(m)+r3ani.at(i);
				n1.at(m) = n1.at(m)+r4ani.at(i);
				r++;		
			}else
			m_Count--;
			
}
		for(int i=0;i<m+1;i++){
			m_Sum +=n[i];
			m_Sum1 +=(n[i]*n[i]);	
			m_SumG +=n1[i];
}
	
	m_Count -=(int)e;
	//r -=(int)e;
	m_Sum /= sqrt(m_Sum1);
	//m_SumG /= m_Count;
	m_SumG = m_Count; 
	
	//cout<<m_Count<<"@"<<r<<endl;
	m_PCD = ((float)(m_Count*100)/(float)c);
	
	vector <float>().swap(n);
	vector <float>().swap(n1);
	vector <float>().swap(r3ani);
	vector <float>().swap(r4ani);
	out.close();
}

void CoverageClass::SetVec3(vector <float> &v3){

	m_V3 = v3;
}

void CoverageClass::SetVec1(vector <int> &v1){

	m_V1 = v1;
}

void CoverageClass::SetVec4(vector <int> &v4){

	m_V4 = v4;
}

void CoverageClass::SetVec7(vector <int> &v7){

	m_V7 = v7;
}

void CoverageClass::Setcount(int count){

	m_count = count;
}

void CoverageClass::SetCount(int Count){

	m_Count = Count;
}
