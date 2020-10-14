#include <stdio.h>
#include <curl/curl.h>
#include <iostream>
#include <string>

using namespace std;

int sendTelegramMessage(string sendstr)
{
  CURL *curl;
  CURLcode res;
  
  //拼接字段 
  //https://api.telegram.org/bot1116069769:AAGX0xRcq1LLDEXjXKzsaTt0rl9jfU53L94/sendMessage?chat_id=-321010467&text=I am is Notice Robot
  const string telegramboturl = "https://api.telegram.org/bot"; //api
  const string robotid = "1116069769"; //robotid
  const string token = "AAGX0xRcq1LLDEXjXKzsaTt0rl9jfU53L94";  //telegram token
  const string opstyle = "sendmessage";  //操作方式
  const string chatid = "-451359637";
  string buf;
  buf.append(telegramboturl);
  buf.append(robotid);
  buf.append(":");
  buf.append(token);
  buf.append("/");
  buf.append(opstyle);
  buf.append("?chat_id=");
  buf.append(chatid);
  buf.append("&text=");
  buf.append(sendstr);
   
  const char *sendMessage = buf.c_str(); 
  cout << sendMessage << endl; 
  
  curl_global_init(CURL_GLOBAL_DEFAULT);
 
  curl = curl_easy_init();
  if(curl) {	 
    curl_easy_setopt(curl, CURLOPT_URL, sendMessage); 
    /* Perform the request, res will get the return code */
    res = curl_easy_perform(curl);
    /* Check for errors */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",curl_easy_strerror(res));
 
    /* always cleanup */
    curl_easy_cleanup(curl);
  }
  curl_global_cleanup();
  
  return 0;
}


//test 
int main(void)
{
	string sendstr = "I love china";
	sendTelegramMessage(sendstr);
	return 0;
}
