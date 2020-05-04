
# importing the requests library 
import requests 
import sys
# api-endpoint 
URL = "https://api.mylnikov.org/geolocation/wifi?v=1.1&data=open&bssid="+sys.argv[1]
print (URL)
# location given here 
location = "delhi technological university"
  
# defining a params dict for the parameters to be sent to the API 
PARAMS = {'address':location} 
  
# sending get request and saving the response as response object 
r = requests.get(url = URL, params = '') 
  
# extracting data in json format 
data = r.json()
if(data['result'] == 200):
    print ("yes")
    print (data['data']['lat'])
    print (data['data']['lon'])
else:
    print("Not found")

