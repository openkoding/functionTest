#include "inc.h"
using namespace std;

int main(int argc, char * argv[])
{
	cout << "Test start..." << endl;
	CUtility::SFunctionParam sParam;
	IFunctionInterface::initFunctionStr();
	IFunctionInterface *pFunction = NULL;

	if(CUtility::parseInputArgs(argc, argv, sParam) != 0)
	{
		IFunctionInterface::usage();
		return -1;
	}
	switch(sParam.iFunction)
	{
		case IFunctionInterface::EPTHREAD_FUNCTION_TYPE:
			pFunction = new CPthreadFunction(sParam);
			break;
		case IFunctionInterface::EFILE_FUNCTION_TYPE:
			pFunction = new CFileFunction(sParam);
			break;
		default:
			IFunctionInterface::usage();
			break;
	}
	if(pFunction != NULL)
		pFunction->run();
	cout << "Test end." << endl;
	return 0;
}
