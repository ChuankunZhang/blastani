#include "BLAST_ANI.h"

using namespace std;
int main(int argc,char* argv[]){
	
	
	
//int h[]={90,60,30};
//float d0[]={0.62,0.32,0.0};
//g_pPearson = new PearsonClass();
//g_pPearson->SetDDH(h);
//g_pPearson->SetD0(d0);
//g_pPearson->SetN(3);
//g_pPearson->Pearson();
	
	In(argc,argv);

	Blastn_blastdbinit();
	Blastn_cut();

	//cout<<"begin"<<endl;
	//g_pQueryCopyM = new QueryCopyMClass();
	//g_pQueryCopyM->SetCount(Count1);
	//g_pQueryCopyM->SetVecIcount(icount1);
	//g_pQueryCopyM->SetVecAt(at1);
	//g_pQueryCopyM->Copy();
	//ANI1 = g_pQueryCopyM->GetANI();
	//PCD1 = g_pQueryCopyM->GetPCD();
	//cout<<"ANI:"<<ANI1<<endl;
	//cout<<"PCD:"<<PCD1<<endl;
	//cout<<"over"<<endl;
	
		

	//system("pause"); 

	Blastn_blastdb();
	Blastn_copy();
	//Blastn_coverage();
	
	//cout<<(ixy1+iyx2)/2<<endl;
	//cout<<"ixy:"<<ixy1<<" iyx:"<<iyx2<<endl;
	Out();
	
	

	//cout<<"^"<<hc1<<"^"<<Count1<<"^"<<hc2<<"^"<<Count2<<endl;
	//cout<<"PCD2:"<<(float)hc1/(float)Count1<<" "<<(float)hc2/(float)Count2<<endl;
	//float Ixy = ixy1+iyx2;
	//cout<<"Ixy:"<<Ixy<<endl;
	//int IXY = X+Y;
	//cout<<"IXY:"<<IXY<<endl;
	//cout<<hc1<<" "<<hc2<<endl;
	//float D4 = 1-(float)IXY/(hc1+hc2);
	//float D6 = 1-(float)IXY/(Count1+Count2);
	//float D0 = 1-(float)(hc1+hc2)/(Count1+Count2);
	//cout<<IXY<<endl;
	//cout<<hc1+hc2<<endl;
	//cout<<(float)IXY/(hc1+hc2)<<endl;
	//cout<<D4<<endl<<D0<<endl<<D6<<endl;
	//fileAry("old.txt","old1.txt",7);
	
	
	vector <int>().swap(icount1);
	vector <int>().swap(icount2);
	vector <int>().swap(at1);
	vector <int>().swap(at2);
	vector <int>().swap(r1v1);
	vector <float>().swap(r3v1);
	vector <int>().swap(r4v1);
	vector <int>().swap(r7v1);
	vector <int>().swap(r1v2);
	vector <float>().swap(r3v2);
	vector <int>().swap(r4v2);
	vector <int>().swap(r7v2);


  	return 0;
}

void Blastn_cut()
{
	cout<<"Cutting..."<<endl;
	g_pQueryCut1 = new QueryCutClass();
	g_pQueryCut2 = new QueryCutClass();
	
	g_pQueryCut1->SetInQuery(onlyin.Q1);
	g_pQueryCut1->SetOutQuery("Query1.fna");	

	g_pQueryCut1->Cut();
	//g_pQueryCut1->Kiri();

	Count1 = g_pQueryCut1->GetCount();
	icount1 = g_pQueryCut1->GetIcount();
	at1 = g_pQueryCut1->GetAt();
	//
	g_pQueryCut2->SetInQuery(onlyin.Q2);
	g_pQueryCut2->SetOutQuery("Query2.fna");	

	g_pQueryCut2->Cut();
	//g_pQueryCut2->Kiri();

	Count2 = g_pQueryCut2->GetCount();
	icount2 = g_pQueryCut2->GetIcount();
	at2 = g_pQueryCut2->GetAt();	

	delete g_pQueryCut1;
	delete g_pQueryCut2;
	
	cout<<"Cut_ok"<<endl;	
}

void Blastn_blastdb()
{
	const char *g2=Q_2.c_str();	
	const char *g1=Q_1.c_str();
	if(onlyin.type == 1)
	{
	cout<<"blastn+ running..."<<endl;
	g_pDataBase->SetPath(Q_2);		
	g_pBlastn->SetQuery("Query1.fna");
	g_pBlastn->SetOut("old1.txt");	
	g_pBlastn->SetDB(g2);

	g_pDataBase->FormatDB();	
	g_pBlastn->BeginBlastn();

	cout<<"blast1_ok"<<endl;

	g_pDataBase->SetPath(Q_1);	
	g_pBlastn->SetQuery("Query2.fna");
	g_pBlastn->SetOut("old2.txt");	
	g_pBlastn->SetDB(g1);	

	g_pDataBase->FormatDB();	
	g_pBlastn->BeginBlastn();

	cout<<"blast2_ok"<<endl;

	g_pBlastnVersion = new BlastnVersionClass();
	g_pBlastnVersion->Cmd();
	//g_pBlastnVersion->End();
	o = g_pBlastnVersion->GetVector();
	
	}
	else
	{
		cout<<"Mummer running..."<<endl;
				
		g_pBlastn->SetQuery("Query1.fna");
		g_pBlastn->SetQuery2("Query2.fna");
		g_pBlastn->SetOut("old1");	
		
		g_pBlastn->BeginMummer();

		cout<<"Mummer1_ok"<<endl;

		
		g_pBlastn->SetQuery("Query2.fna");
		g_pBlastn->SetQuery2("Query1.fna");
		g_pBlastn->SetOut("old2");	
		

			
		g_pBlastn->BeginMummer();

		cout<<"Mummer2_ok"<<endl;
	}
	delete g_pBlastn;
	delete g_pDataBase;

	remove("Query1.fna");
	remove("Query2.fna");
	
}

void Blastn_blastdbinit()
{	
	cout<<"loading..."<<endl;
	g_pBlastn = new BlastnClass();
	g_pDataBase= new DataBaseClass();

	g_pBlastn->SetPath(onlyin.d);
	g_pBlastn->SetQueryPath(onlyin.Q2);	
	g_pBlastn->SetCopy();
	Q_2 = g_pBlastn->GetQueryfna();
	g_pBlastn->SetQueryPath(onlyin.Q1);	
	g_pBlastn->SetCopy();
	Q_1 = g_pBlastn->GetQueryfna();
}

void Blastn_copy()
{
	cout<<"copy..."<<endl;
	g_pQueryCopy = new QueryCopyBClass();
	g_pQueryCopy1 = new QueryCopyBClass();
	
	if(onlyin.type == 1)
		g_pQueryCopy->SetInQuery("old1.txt");
	else
		g_pQueryCopy->SetInQuery("old1.delta");
	g_pQueryCopy->SetOutQuery("new1.txt");
	g_pQueryCopy->SetVecIcount(icount1);
	g_pQueryCopy->SetVecAt(at1);
	g_pQueryCopy->SetCount(Count1);
	g_pQueryCopy->Copy(onlyin.type);
	//r1v1 = g_pQueryCopy->GetVec1();
	//r3v1 = g_pQueryCopy->GetVec3();
	//r4v1 = g_pQueryCopy->GetVec4();
	//r7v1 = g_pQueryCopy->GetVec7();
	ANI1 = g_pQueryCopy->GetANI();
	PCD1 = g_pQueryCopy->GetPCD();

	//count1 = g_pQueryCopy->Getcount();
	//hc1 = g_pQueryCopy->Gethc();
	
	if(onlyin.type == 1)
		g_pQueryCopy1->SetInQuery("old2.txt");
	else
		g_pQueryCopy1->SetInQuery("old2.delta");
	g_pQueryCopy1->SetOutQuery("new2.txt");
	g_pQueryCopy1->SetVecIcount(icount2);
	g_pQueryCopy1->SetVecAt(at2);
	g_pQueryCopy1->SetCount(Count2);
	g_pQueryCopy1->Copy(onlyin.type);
	
	//r1v2 = g_pQueryCopy1->GetVec1();
	//r3v2 = g_pQueryCopy1->GetVec3();
	//r4v2 = g_pQueryCopy1->GetVec4();
	//r7v2 = g_pQueryCopy1->GetVec7();
	ANI2 = g_pQueryCopy1->GetANI();
	PCD2 = g_pQueryCopy1->GetPCD();

	//count2 = g_pQueryCopy1->Getcount();
	//hc2 = g_pQueryCopy1->Gethc();

	delete g_pQueryCopy;
	delete g_pQueryCopy1;
	remove("old1.txt");
	remove("old2.txt");
	remove("old1.delta");
	remove("old2.delta");
	cout<<"Copy_ok"<<endl;
}

void Blastn_coverage()
{
	g_pCoverage = new CoverageClass();
	g_pCoverage1 = new CoverageClass();
	g_pCoverage->SetVec3(r3v1);
	g_pCoverage->SetVec4(r4v1);
	g_pCoverage->SetVec7(r7v1);
	g_pCoverage->SetVec1(r1v1);
	g_pCoverage->SetCount(Count1);		
	g_pCoverage->Setcount(count1);
	g_pCoverage->BeginCoverage();
	ixy1=g_pCoverage->GetSum();
	X=g_pCoverage->GetSumG();
	PCD1 = g_pCoverage->GetPCD();
	
	g_pCoverage1->SetVec3(r3v2);
	g_pCoverage1->SetVec4(r4v2);
	g_pCoverage1->SetVec7(r7v2);
	g_pCoverage1->SetVec1(r1v2);
	g_pCoverage1->SetCount(Count2);		
	g_pCoverage1->Setcount(count2);
	g_pCoverage1->BeginCoverage();
	iyx2=g_pCoverage1->GetSum();
	Y=g_pCoverage1->GetSumG();
	PCD2 = g_pCoverage1->GetPCD();
	
	delete g_pCoverage;
	delete g_pCoverage1;

	cout<<"Coverage_ok"<<endl;
}

void Out()
{
	g_pQueryOut = new QueryOutClass();
	if (onlyin.cj == "cmd")
	{
		g_pQueryOut->SetArg(ANI1,ANI2,PCD1,PCD2);
		g_pQueryOut->OutCmd();
	}
	else
	{
		g_pQueryOut->SetArg(ANI1,ANI2,PCD1,PCD2);
		g_pQueryOut->SetJson(Q_1,Q_2,onlyin.bm,o);
		g_pQueryOut->OutJson();
	}
}

void In(int argc,char* argv[])
{
	g_pQueryIn = new QueryInClass();
	//g_pQueryIn->SetIn(string Q1,string Q2,string d,string bm,string cj,int type);
	g_pQueryIn->In(argc,argv); 
	onlyin = g_pQueryIn->Getcmd();
	//onlyin.Q1 = g_pQueryIn->GetQ1();
	//onlyin.Q2 = g_pQueryIn->GetQ2();
	//onlyin.d = g_pQueryIn->Getd();
	//onlyin.cj = g_pQueryIn->Getcj();
	//onlyin.bm = g_pQueryIn->Getbm();
	//onlyin.type = g_pQueryIn->Gettype();
}
