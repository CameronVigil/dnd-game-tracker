#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <string>
#include <xkeycheck.h>
#include <iostream>
using namespace std;
int webScrape(string importedURL)
{

    // Initialize the Python Interpreter
    Py_Initialize();

    PyObject* moduleMainString = PyUnicode_FromString("__main__");
    PyObject* moduleMain = PyImport_Import(moduleMainString);
    
    //function that performs web scraping
    PyRun_SimpleString(
        "import requests                              \n"\
        "def mul(importedURL):                        \n"\

        "   url = importedURL                              \n"\
        "   print(importedURL)                                     \n"\
        "   agent = { \"User-Agent\":'Mozilla/5.0 (Windows NT 6.3; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/59.0.3071.115 Safari/537.36' }\n"\
        "   print(agent)\n"\
        "   response = requests.get(url, headers=agent).text\n"\
        "   print(response)\n"
        "   return response                              \n"\

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