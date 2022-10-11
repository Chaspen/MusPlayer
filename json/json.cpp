#include <string>
#include <curl/curl.h>
#include <iostream>
#include <vector>
#include <cstring>
#include "json.h"

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}


std::string Json::bGetRestResponse(const char* GetURL) {
    //init curl
    CURL *curl;
    CURLcode res;
    std::string readBuffer;

    curl = curl_easy_init();
    if(curl) {
        /*  !! CAN'T PASS std::string AS A URL!!   */
        std::vector<char> cstr(readBuffer.c_str(), readBuffer.c_str() + readBuffer.size() + 1);
        curl_easy_setopt(curl, CURLOPT_URL, GetURL);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "curl/7.85.0");
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);  
    } else {
        std::cout << "libcurl not installed!" << std::endl;
    }

    /* Convert string to char since libcurl doesn't accept string objects */
    const char* pstr = readBuffer.c_str();
    
    return pstr;
}