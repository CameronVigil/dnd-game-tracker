import requests   
import json
                    
url = 'https://character-service.dndbeyond.com/character/v5/character/44851421?includeCustomItems=true'
headers = {'value': 'application/json, text/plain, */*','accept': 'application/json, text/plain, */*; q=0.01','cookie': '_gsid=f2607384476d4731b4b03e80181b9119; Login.RedirectUrl=https://www.dndbeyond.com/; LoginState=4cebf440-3603-466a-9734-300418d63949; AWSALBTG=nVWa1cEqQzb1Dk7H4sFhxK5fUVoUx8WaGK4o2OsLicknT+jitW1XfGGl9CHotEcweY6GpfCo0FOu6H/HhxV4VFFm4qixaCoEybIINmStbEb2sj4dW8gUo68CVYCjk/6m6iG4eSk1GEmgqX1F/5yrSigXxvZm442nW97sSr/D5HGM; AWSALBTGCORS=nVWa1cEqQzb1Dk7H4sFhxK5fUVoUx8WaGK4o2OsLicknT+jitW1XfGGl9CHotEcweY6GpfCo0FOu6H/HhxV4VFFm4qixaCoEybIINmStbEb2sj4dW8gUo68CVYCjk/6m6iG4eSk1GEmgqX1F/5yrSigXxvZm442nW97sSr/D5HGM; AWSALB=yaMzOFcfLAPH1ePr/xnP1jmje+RXLqrNYn0YwPViB1o0EXUjk46E0C3XcALb/MyGK9kBwTAELYI2Ams/DFulq+4BXt+lStWznHKK1MKn/qVUG4wPE0nRHhyEB7Dt; AWSALBCORS=yaMzOFcfLAPH1ePr/xnP1jmje+RXLqrNYn0YwPViB1o0EXUjk46E0C3XcALb/MyGK9kBwTAELYI2Ams/DFulq+4BXt+lStWznHKK1MKn/qVUG4wPE0nRHhyEB7Dt; cookie-consent=granted; Geo={%22region%22:%22TX%22%2C%22country%22:%22US%22%2C%22continent%22:%22NA%22}'}
page = requests.get(url, headers=headers).text

#print(page)
jsonPage = json.loads(page)
#print(stats)

list_of_stats = jsonPage['data']['stats']
print(list_of_stats)
  

input('Press ENTER to exit')