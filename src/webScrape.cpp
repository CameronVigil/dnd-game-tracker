#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <xkeycheck.h>

int webScrape()
{
    
    Py_Initialize();
    //import requests
    PyRun_SimpleString("from time import time,ctime\n"
        "print('Today is', ctime(time()))\n");
    /*
    
    response = requests.get("https://oxylabs.io/");
        print(response.text);
    */
    if (Py_FinalizeEx() < 0) {
        exit(120);
    }
    return 0;
}