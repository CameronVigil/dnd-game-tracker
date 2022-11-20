#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <string>
#include <xkeycheck.h>
#include <iostream>


#include "webScrape.h"

using namespace std;
int webScrape(string importedURL)
{

    // Initialize the Python Interpreter
    Py_Initialize();

    PyObject* moduleMainString = PyUnicode_FromString("__main__");
    PyObject* moduleMain = PyImport_Import(moduleMainString);
    
    //function that performs web scraping
    PyRun_SimpleString(
        
        "def mul(importedURL):\n"\
        "   import requests\n"\
        "   import json\n"\
        "   url = importedURL + '?includeCustomItems=true'\n"\
        "   print(url)\n"\
        "   headers = {'value': 'application/json, text/plain, */*','accept': 'application/json, text/javascript, */*; q=0.01','cookie': '_gsid=f2607384476d4731b4b03e80181b9119; Login.RedirectUrl=https://www.dndbeyond.com/; LoginState=4cebf440-3603-466a-9734-300418d63949; AWSALBTG=nVWa1cEqQzb1Dk7H4sFhxK5fUVoUx8WaGK4o2OsLicknT+jitW1XfGGl9CHotEcweY6GpfCo0FOu6H/HhxV4VFFm4qixaCoEybIINmStbEb2sj4dW8gUo68CVYCjk/6m6iG4eSk1GEmgqX1F/5yrSigXxvZm442nW97sSr/D5HGM; AWSALBTGCORS=nVWa1cEqQzb1Dk7H4sFhxK5fUVoUx8WaGK4o2OsLicknT+jitW1XfGGl9CHotEcweY6GpfCo0FOu6H/HhxV4VFFm4qixaCoEybIINmStbEb2sj4dW8gUo68CVYCjk/6m6iG4eSk1GEmgqX1F/5yrSigXxvZm442nW97sSr/D5HGM; AWSALB=yaMzOFcfLAPH1ePr/xnP1jmje+RXLqrNYn0YwPViB1o0EXUjk46E0C3XcALb/MyGK9kBwTAELYI2Ams/DFulq+4BXt+lStWznHKK1MKn/qVUG4wPE0nRHhyEB7Dt; AWSALBCORS=yaMzOFcfLAPH1ePr/xnP1jmje+RXLqrNYn0YwPViB1o0EXUjk46E0C3XcALb/MyGK9kBwTAELYI2Ams/DFulq+4BXt+lStWznHKK1MKn/qVUG4wPE0nRHhyEB7Dt; cookie-consent=granted; Geo={%22region%22:%22TX%22%2C%22country%22:%22US%22%2C%22continent%22:%22NA%22}'}\n"\
        "   print(headers)\n"\
        "   page = requests.get(url, headers=headers).text\n"\
        "   print(page)\n"
        "   jsonPage = json.loads(page)\n"\
        "   list_of_stats = jsonPage['data']['stats']\n"\
        "   print(list_of_stats)\n"\
        "   return list_of_stats\n"\

    );

    PyObject* func = PyObject_GetAttrString(moduleMain, "mul");
    PyObject* result = PyObject_CallFunction(func, "s", importedURL.c_str());

    //prints entire page
    std::cout << result << std::endl;

    if (Py_FinalizeEx() < 0) {
        exit(120);
    }
    return 0;
}