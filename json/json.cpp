#include <string>
#include <curl/curl.h>
#include "json.h"
#include <iostream>
#include <vector>
#include <cstring>

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

    /* Convert string to char since libcurl doesn't accept string objects */
    

    curl = curl_easy_init();
    if(curl) {
        /*  !! CAN'T PASS std::string AS A URL!!   */
        std::vector<char> cstr(readBuffer.c_str(), readBuffer.c_str() + readBuffer.size() + 1);
        //curl_easy_setopt(curl, CURLOPT_URL, "https://musicbrainz.org/ws/2/release/9ae9a9d6-f25c-4633-894c-2eb3935ea08c?inc=aliases%2Bartist-credits%2Blabels%2Bdiscids%2Brecordings&fmt=json");
        curl_easy_setopt(curl, CURLOPT_URL, GetURL);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "curl/7.85.0");
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);  
    } else {
        std::cout << "libcurl not installed!" << std::endl;
    }

    const char* wow = readBuffer.c_str();
    //std::cout << wow << std::endl;
    
    return wow;
}