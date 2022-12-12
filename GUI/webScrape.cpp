#define PY_SSIZE_T_CLEAN
#pragma push_macro("slots")
#undef slots
#include <Python.h>
#pragma pop_macro("slots")

#include <string>
#include <iostream>


#include "webScrape.h"

using namespace std;

//Functions return skill value for current player

int webScrapeStrength(string importedURL)
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
        "   url = 'https://character-service.dndbeyond.com/character/v5/character/' + importedURL + '/?includeCustomItems=true'\n"\
        "   headers = {'value': 'application/json, text/plain, */*','accept': 'application/json, text/plain, */*; q=0.01','cookie': '_gsid=f2607384476d4731b4b03e80181b9119; Login.RedirectUrl=https://www.dndbeyond.com/; LoginState=4cebf440-3603-466a-9734-300418d63949; AWSALBTG=nVWa1cEqQzb1Dk7H4sFhxK5fUVoUx8WaGK4o2OsLicknT+jitW1XfGGl9CHotEcweY6GpfCo0FOu6H/HhxV4VFFm4qixaCoEybIINmStbEb2sj4dW8gUo68CVYCjk/6m6iG4eSk1GEmgqX1F/5yrSigXxvZm442nW97sSr/D5HGM; AWSALBTGCORS=nVWa1cEqQzb1Dk7H4sFhxK5fUVoUx8WaGK4o2OsLicknT+jitW1XfGGl9CHotEcweY6GpfCo0FOu6H/HhxV4VFFm4qixaCoEybIINmStbEb2sj4dW8gUo68CVYCjk/6m6iG4eSk1GEmgqX1F/5yrSigXxvZm442nW97sSr/D5HGM; AWSALB=yaMzOFcfLAPH1ePr/xnP1jmje+RXLqrNYn0YwPViB1o0EXUjk46E0C3XcALb/MyGK9kBwTAELYI2Ams/DFulq+4BXt+lStWznHKK1MKn/qVUG4wPE0nRHhyEB7Dt; AWSALBCORS=yaMzOFcfLAPH1ePr/xnP1jmje+RXLqrNYn0YwPViB1o0EXUjk46E0C3XcALb/MyGK9kBwTAELYI2Ams/DFulq+4BXt+lStWznHKK1MKn/qVUG4wPE0nRHhyEB7Dt; cookie-consent=granted; Geo={%22region%22:%22TX%22%2C%22country%22:%22US%22%2C%22continent%22:%22NA%22}'}\n"\
        "   page = requests.get(url, headers=headers).text\n"\
        "   jsonPage = json.loads(page)\n"\
        "   strength = jsonPage['data']['stats'][0]['value']\n"\
        "   return strength\n"\

    );

    PyObject* func = PyObject_GetAttrString(moduleMain, "mul");
    PyObject* result = PyObject_CallFunction(func, "s", importedURL.c_str());
    int strength = (int)_PyLong_AsInt(result);

    return strength;
}
int webScrapeDexterity(string importedURL)
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
        "   url = 'https://character-service.dndbeyond.com/character/v5/character/' + importedURL + '/?includeCustomItems=true'\n"\
        "   headers = {'value': 'application/json, text/plain, */*','accept': 'application/json, text/plain, */*; q=0.01','cookie': '_gsid=f2607384476d4731b4b03e80181b9119; Login.RedirectUrl=https://www.dndbeyond.com/; LoginState=4cebf440-3603-466a-9734-300418d63949; AWSALBTG=nVWa1cEqQzb1Dk7H4sFhxK5fUVoUx8WaGK4o2OsLicknT+jitW1XfGGl9CHotEcweY6GpfCo0FOu6H/HhxV4VFFm4qixaCoEybIINmStbEb2sj4dW8gUo68CVYCjk/6m6iG4eSk1GEmgqX1F/5yrSigXxvZm442nW97sSr/D5HGM; AWSALBTGCORS=nVWa1cEqQzb1Dk7H4sFhxK5fUVoUx8WaGK4o2OsLicknT+jitW1XfGGl9CHotEcweY6GpfCo0FOu6H/HhxV4VFFm4qixaCoEybIINmStbEb2sj4dW8gUo68CVYCjk/6m6iG4eSk1GEmgqX1F/5yrSigXxvZm442nW97sSr/D5HGM; AWSALB=yaMzOFcfLAPH1ePr/xnP1jmje+RXLqrNYn0YwPViB1o0EXUjk46E0C3XcALb/MyGK9kBwTAELYI2Ams/DFulq+4BXt+lStWznHKK1MKn/qVUG4wPE0nRHhyEB7Dt; AWSALBCORS=yaMzOFcfLAPH1ePr/xnP1jmje+RXLqrNYn0YwPViB1o0EXUjk46E0C3XcALb/MyGK9kBwTAELYI2Ams/DFulq+4BXt+lStWznHKK1MKn/qVUG4wPE0nRHhyEB7Dt; cookie-consent=granted; Geo={%22region%22:%22TX%22%2C%22country%22:%22US%22%2C%22continent%22:%22NA%22}'}\n"\
        "   page = requests.get(url, headers=headers).text\n"\
        "   jsonPage = json.loads(page)\n"\
        "   strength = jsonPage['data']['stats'][1]['value']\n"\
        "   return strength\n"\

    );

    PyObject* func = PyObject_GetAttrString(moduleMain, "mul");
    PyObject* result = PyObject_CallFunction(func, "s", importedURL.c_str());
    int dexterity = (int)_PyLong_AsInt(result);

    return dexterity;
}

int webScrapeConstitution(string importedURL)
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
        "   url = 'https://character-service.dndbeyond.com/character/v5/character/' + importedURL + '/?includeCustomItems=true'\n"\
        "   headers = {'value': 'application/json, text/plain, */*','accept': 'application/json, text/plain, */*; q=0.01','cookie': '_gsid=f2607384476d4731b4b03e80181b9119; Login.RedirectUrl=https://www.dndbeyond.com/; LoginState=4cebf440-3603-466a-9734-300418d63949; AWSALBTG=nVWa1cEqQzb1Dk7H4sFhxK5fUVoUx8WaGK4o2OsLicknT+jitW1XfGGl9CHotEcweY6GpfCo0FOu6H/HhxV4VFFm4qixaCoEybIINmStbEb2sj4dW8gUo68CVYCjk/6m6iG4eSk1GEmgqX1F/5yrSigXxvZm442nW97sSr/D5HGM; AWSALBTGCORS=nVWa1cEqQzb1Dk7H4sFhxK5fUVoUx8WaGK4o2OsLicknT+jitW1XfGGl9CHotEcweY6GpfCo0FOu6H/HhxV4VFFm4qixaCoEybIINmStbEb2sj4dW8gUo68CVYCjk/6m6iG4eSk1GEmgqX1F/5yrSigXxvZm442nW97sSr/D5HGM; AWSALB=yaMzOFcfLAPH1ePr/xnP1jmje+RXLqrNYn0YwPViB1o0EXUjk46E0C3XcALb/MyGK9kBwTAELYI2Ams/DFulq+4BXt+lStWznHKK1MKn/qVUG4wPE0nRHhyEB7Dt; AWSALBCORS=yaMzOFcfLAPH1ePr/xnP1jmje+RXLqrNYn0YwPViB1o0EXUjk46E0C3XcALb/MyGK9kBwTAELYI2Ams/DFulq+4BXt+lStWznHKK1MKn/qVUG4wPE0nRHhyEB7Dt; cookie-consent=granted; Geo={%22region%22:%22TX%22%2C%22country%22:%22US%22%2C%22continent%22:%22NA%22}'}\n"\
        "   page = requests.get(url, headers=headers).text\n"\
        "   jsonPage = json.loads(page)\n"\
        "   constitution = jsonPage['data']['stats'][2]['value']\n"\
        "   return constitution\n"\

    );

    PyObject* func = PyObject_GetAttrString(moduleMain, "mul");
    PyObject* result = PyObject_CallFunction(func, "s", importedURL.c_str());
    int constitution = (int)_PyLong_AsInt(result);

    if (Py_FinalizeEx() < 0) {
        exit(120);
    }
    return constitution;
}
int webScrapeIntelligence(string importedURL)
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
        "   url = 'https://character-service.dndbeyond.com/character/v5/character/' + importedURL + '/?includeCustomItems=true'\n"\
        "   headers = {'value': 'application/json, text/plain, */*','accept': 'application/json, text/plain, */*; q=0.01','cookie': '_gsid=f2607384476d4731b4b03e80181b9119; Login.RedirectUrl=https://www.dndbeyond.com/; LoginState=4cebf440-3603-466a-9734-300418d63949; AWSALBTG=nVWa1cEqQzb1Dk7H4sFhxK5fUVoUx8WaGK4o2OsLicknT+jitW1XfGGl9CHotEcweY6GpfCo0FOu6H/HhxV4VFFm4qixaCoEybIINmStbEb2sj4dW8gUo68CVYCjk/6m6iG4eSk1GEmgqX1F/5yrSigXxvZm442nW97sSr/D5HGM; AWSALBTGCORS=nVWa1cEqQzb1Dk7H4sFhxK5fUVoUx8WaGK4o2OsLicknT+jitW1XfGGl9CHotEcweY6GpfCo0FOu6H/HhxV4VFFm4qixaCoEybIINmStbEb2sj4dW8gUo68CVYCjk/6m6iG4eSk1GEmgqX1F/5yrSigXxvZm442nW97sSr/D5HGM; AWSALB=yaMzOFcfLAPH1ePr/xnP1jmje+RXLqrNYn0YwPViB1o0EXUjk46E0C3XcALb/MyGK9kBwTAELYI2Ams/DFulq+4BXt+lStWznHKK1MKn/qVUG4wPE0nRHhyEB7Dt; AWSALBCORS=yaMzOFcfLAPH1ePr/xnP1jmje+RXLqrNYn0YwPViB1o0EXUjk46E0C3XcALb/MyGK9kBwTAELYI2Ams/DFulq+4BXt+lStWznHKK1MKn/qVUG4wPE0nRHhyEB7Dt; cookie-consent=granted; Geo={%22region%22:%22TX%22%2C%22country%22:%22US%22%2C%22continent%22:%22NA%22}'}\n"\
        "   page = requests.get(url, headers=headers).text\n"\
        "   jsonPage = json.loads(page)\n"\
        "   intelligence = jsonPage['data']['stats'][3]['value']\n"\
        "   return intelligence\n"\

    );

    PyObject* func = PyObject_GetAttrString(moduleMain, "mul");
    PyObject* result = PyObject_CallFunction(func, "s", importedURL.c_str());
    int intelligence = (int)_PyLong_AsInt(result);

    if (Py_FinalizeEx() < 0) {
        exit(120);
    }
    return intelligence;
}
int webScrapeWisdom(string importedURL)
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
        "   url = 'https://character-service.dndbeyond.com/character/v5/character/' + importedURL + '/?includeCustomItems=true'\n"\
        "   headers = {'value': 'application/json, text/plain, */*','accept': 'application/json, text/plain, */*; q=0.01','cookie': '_gsid=f2607384476d4731b4b03e80181b9119; Login.RedirectUrl=https://www.dndbeyond.com/; LoginState=4cebf440-3603-466a-9734-300418d63949; AWSALBTG=nVWa1cEqQzb1Dk7H4sFhxK5fUVoUx8WaGK4o2OsLicknT+jitW1XfGGl9CHotEcweY6GpfCo0FOu6H/HhxV4VFFm4qixaCoEybIINmStbEb2sj4dW8gUo68CVYCjk/6m6iG4eSk1GEmgqX1F/5yrSigXxvZm442nW97sSr/D5HGM; AWSALBTGCORS=nVWa1cEqQzb1Dk7H4sFhxK5fUVoUx8WaGK4o2OsLicknT+jitW1XfGGl9CHotEcweY6GpfCo0FOu6H/HhxV4VFFm4qixaCoEybIINmStbEb2sj4dW8gUo68CVYCjk/6m6iG4eSk1GEmgqX1F/5yrSigXxvZm442nW97sSr/D5HGM; AWSALB=yaMzOFcfLAPH1ePr/xnP1jmje+RXLqrNYn0YwPViB1o0EXUjk46E0C3XcALb/MyGK9kBwTAELYI2Ams/DFulq+4BXt+lStWznHKK1MKn/qVUG4wPE0nRHhyEB7Dt; AWSALBCORS=yaMzOFcfLAPH1ePr/xnP1jmje+RXLqrNYn0YwPViB1o0EXUjk46E0C3XcALb/MyGK9kBwTAELYI2Ams/DFulq+4BXt+lStWznHKK1MKn/qVUG4wPE0nRHhyEB7Dt; cookie-consent=granted; Geo={%22region%22:%22TX%22%2C%22country%22:%22US%22%2C%22continent%22:%22NA%22}'}\n"\
        "   page = requests.get(url, headers=headers).text\n"\
        "   jsonPage = json.loads(page)\n"\
        "   wisdom = jsonPage['data']['stats'][0]['value']\n"\
        "   return wisdom\n"\

    );

    PyObject* func = PyObject_GetAttrString(moduleMain, "mul");
    PyObject* result = PyObject_CallFunction(func, "s", importedURL.c_str());
    int wisdom = (int)_PyLong_AsInt(result);

    if (Py_FinalizeEx() < 0) {
        exit(120);
    }
    return wisdom;
}
int webScrapeCharisma(string importedURL)
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
        "   url = 'https://character-service.dndbeyond.com/character/v5/character/' + importedURL + '/?includeCustomItems=true'\n"\
        "   headers = {'value': 'application/json, text/plain, */*','accept': 'application/json, text/plain, */*; q=0.01','cookie': '_gsid=f2607384476d4731b4b03e80181b9119; Login.RedirectUrl=https://www.dndbeyond.com/; LoginState=4cebf440-3603-466a-9734-300418d63949; AWSALBTG=nVWa1cEqQzb1Dk7H4sFhxK5fUVoUx8WaGK4o2OsLicknT+jitW1XfGGl9CHotEcweY6GpfCo0FOu6H/HhxV4VFFm4qixaCoEybIINmStbEb2sj4dW8gUo68CVYCjk/6m6iG4eSk1GEmgqX1F/5yrSigXxvZm442nW97sSr/D5HGM; AWSALBTGCORS=nVWa1cEqQzb1Dk7H4sFhxK5fUVoUx8WaGK4o2OsLicknT+jitW1XfGGl9CHotEcweY6GpfCo0FOu6H/HhxV4VFFm4qixaCoEybIINmStbEb2sj4dW8gUo68CVYCjk/6m6iG4eSk1GEmgqX1F/5yrSigXxvZm442nW97sSr/D5HGM; AWSALB=yaMzOFcfLAPH1ePr/xnP1jmje+RXLqrNYn0YwPViB1o0EXUjk46E0C3XcALb/MyGK9kBwTAELYI2Ams/DFulq+4BXt+lStWznHKK1MKn/qVUG4wPE0nRHhyEB7Dt; AWSALBCORS=yaMzOFcfLAPH1ePr/xnP1jmje+RXLqrNYn0YwPViB1o0EXUjk46E0C3XcALb/MyGK9kBwTAELYI2Ams/DFulq+4BXt+lStWznHKK1MKn/qVUG4wPE0nRHhyEB7Dt; cookie-consent=granted; Geo={%22region%22:%22TX%22%2C%22country%22:%22US%22%2C%22continent%22:%22NA%22}'}\n"\
        "   page = requests.get(url, headers=headers).text\n"\
        "   jsonPage = json.loads(page)\n"\
        "   charisma = jsonPage['data']['stats'][0]['value']\n"\
        "   return charisma\n"\

    );

    PyObject* func = PyObject_GetAttrString(moduleMain, "mul");
    PyObject* result = PyObject_CallFunction(func, "s", importedURL.c_str());
    int charisma = (int)_PyLong_AsInt(result);

    if (Py_FinalizeEx() < 0) {
        exit(120);
    }
    return charisma;
}

std::string webScrapeName(string importedURL)
{

    // Initialize the Python Interpreter
    Py_Initialize();

    PyObject* moduleMainString = PyUnicode_FromString("__main__");
    PyObject* moduleMain = PyImport_Import(moduleMainString);

    //function that performs web scraping
    PyRun_SimpleString(

        "def mul(importedURL):\n"\
        "   print('getting name')\n"
        "   import requests\n"\
        "   import json\n"\
        "   url = 'https://character-service.dndbeyond.com/character/v5/character/' + importedURL + '/?includeCustomItems=true'\n"\
        "   headers = {'value': 'application/json, text/plain, */*','accept': 'application/json, text/plain, */*; q=0.01','cookie': '_gsid=f2607384476d4731b4b03e80181b9119; Login.RedirectUrl=https://www.dndbeyond.com/; LoginState=4cebf440-3603-466a-9734-300418d63949; AWSALBTG=nVWa1cEqQzb1Dk7H4sFhxK5fUVoUx8WaGK4o2OsLicknT+jitW1XfGGl9CHotEcweY6GpfCo0FOu6H/HhxV4VFFm4qixaCoEybIINmStbEb2sj4dW8gUo68CVYCjk/6m6iG4eSk1GEmgqX1F/5yrSigXxvZm442nW97sSr/D5HGM; AWSALBTGCORS=nVWa1cEqQzb1Dk7H4sFhxK5fUVoUx8WaGK4o2OsLicknT+jitW1XfGGl9CHotEcweY6GpfCo0FOu6H/HhxV4VFFm4qixaCoEybIINmStbEb2sj4dW8gUo68CVYCjk/6m6iG4eSk1GEmgqX1F/5yrSigXxvZm442nW97sSr/D5HGM; AWSALB=yaMzOFcfLAPH1ePr/xnP1jmje+RXLqrNYn0YwPViB1o0EXUjk46E0C3XcALb/MyGK9kBwTAELYI2Ams/DFulq+4BXt+lStWznHKK1MKn/qVUG4wPE0nRHhyEB7Dt; AWSALBCORS=yaMzOFcfLAPH1ePr/xnP1jmje+RXLqrNYn0YwPViB1o0EXUjk46E0C3XcALb/MyGK9kBwTAELYI2Ams/DFulq+4BXt+lStWznHKK1MKn/qVUG4wPE0nRHhyEB7Dt; cookie-consent=granted; Geo={%22region%22:%22TX%22%2C%22country%22:%22US%22%2C%22continent%22:%22NA%22}'}\n"\
        "   page = requests.get(url, headers=headers).text\n"\
        "   jsonPage = json.loads(page)\n"\
        "   name = jsonPage['data']['name']\n"\
        "   return name\n"\

    );

    PyObject* func = PyObject_GetAttrString(moduleMain, "mul");
    PyObject* result = PyObject_CallFunction(func, "s", importedURL.c_str());
    std::string name;
    if(result != NULL){
        name = (string)_PyUnicode_AsString(result);
    }
    if (Py_FinalizeEx() < 0) {
        exit(120);
    }
    return name;
}
