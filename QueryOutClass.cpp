#include "QueryOutClass.h"

QueryOutClass::QueryOutClass()
{
	m_Q_1 = " ";
	m_Q_2 = " ";
	m_bm = " ";
	m_ver = " ";
	m_ANI1 = 0;
	m_ANI2 = 0;
	m_PCD1 = 0;
	m_PCD2 = 0;
}

QueryOutClass::~QueryOutClass(void)
{
	
}

void QueryOutClass::SetJson(string Q_1,string Q_2,string bm,string ver)
{
	m_Q_1 = Q_1;
	m_Q_2 = Q_2;
	m_bm = bm;
	m_ver = ver;
}

void QueryOutClass::SetArg(float ANI1,float ANI2,float PCD1,float PCD2)
{
	int a1;
	int a2;
	int p1;
	int p2;
	
	a1 = (int)(ANI1*100);
	m_ANI1 = (float)a1 / 100;

	a2 = (int)(ANI2*100);
	m_ANI2 = (float)a2 / 100;

	p1 = (int)(PCD1*100);
	m_PCD1 = (float)p1 / 100;

	p2 = (int)(PCD2*100);
	m_PCD2 = (float)p2 / 100;
}

void QueryOutClass::OutCmd()
{
	cout<<"=================================================================="<<endl;
	cout<<"ANI:"<<m_ANI1<<" "<<m_ANI2<<endl;
	cout<<"PCD:"<<m_PCD1<<" "<<m_PCD2<<endl;
	
}

void QueryOutClass::OutJson()
{
	ifstream in("json.txt");
	ofstream out("json.txt");
	
		Json::Value root;

		root["genome1"] = Json::Value(m_Q_1);

		root["genome2"] = Json::Value(m_Q_2);

		root["tool"] = Json::Value(m_bm);

		root["verson"] = Json::Value(m_ver);

		Json::Value ANI;

		ANI["ANI_1->2"] = Json::Value(m_ANI1);

		ANI["ANI_2->1"] = Json::Value(m_ANI2);

		root["ANI"] = Json::Value(ANI);

		Json::Value PCD;

		PCD["PCD_1->2"] = Json::Value(m_PCD1);

		PCD["PCD_2->1"] = Json::Value(m_PCD2);

		root["PCD"] = Json::Value(PCD);
	
		out << "Writer:" << endl;

		Json::StyledWriter sw;

		out << sw.write(root) << endl;

	in.close();
	out.close();
	cout<<"json_ok"<<endl;
}
