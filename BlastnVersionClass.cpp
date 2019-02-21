#include "BlastnVersionClass.h"

BlastnVersionClass::BlastnVersionClass()
{
	m_Version1 = 0;
	m_Version2 = 0;
	m_Version3 = 0;
	m_VersionEnd = 2;
	m_Version = "???";
}


BlastnVersionClass::~BlastnVersionClass(void)
{


}

void BlastnVersionClass::Cmd()
{
	char buffer[128];	
	char result[1024*4]; 
	char *next1;
	char *l;

	FILE* pipe = popen("blastn -version", "r"); 
	//if (!pipe) return 0; 
	
	while(!feof(pipe)) {
		if(fgets(buffer, 128, pipe)){ 
			strcat(result,buffer);
		}
	}

	pclose(pipe); 
	
	next1 = result;
	l = strsep(&next1,"\n");
	m_Version = l;
	//next1 = strsep(&l," ");
	//next1 = strsep(&l,".");

	//m_Version1 = atoi(next1);
	//next1 = strsep(&l,".");

	//m_Version2 = atoi(next1);
	//next1 = strsep(&l,".");

	//m_Version3 = atoi(next1);
	
}

void BlastnVersionClass::End()
{
	if(m_Version1 == 2)
	{
		if(m_Version2 == 2)
			if(m_Version3 == 23)
				m_VersionEnd = 0;
		if(m_Version2 == 4)
			m_VersionEnd = 1;
	}
}
