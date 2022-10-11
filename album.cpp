#include <boost/algorithm/string.hpp>
#include "include/json.hpp"
#include <iostream>
#include <string>
#include "album.h"
#include "json/json.h"




using json = nlohmann::json;


struct bAlbumData {
    std::string     Title;
    std::string     Artist;
    std::string     Date;
} AlbumData;


std::string Album::bExposeAlbumData(std::string ResponseType, std::string MBID) {

    //acess custom url parser and NOT the third party json library, should probably rename this tbh.
    Json JsonLocal;

    bAlbumData AlbumData;

    ///init string concat
    std::string Initializer = "https://musicbrainz.org/ws/2/";
    std::string ResponseInc = "?inc=aliases%2Bartist-credits%2Breleases&fmt=json";

    std::string MBIDUrl = Initializer + ResponseType + "/" + MBID + ResponseInc;
    const char* TestURL = MBIDUrl.c_str();
    
    
    std::string response = JsonLocal.bGetRestResponse(TestURL);
    //std::cout << response << std::endl;

    json ParsedJson = json::parse(response);
    //std::cout << std::setw(4) << j_complete << std::endl;

    //asign title to struct
    std::string title = AlbumData.Title;
    title = ParsedJson.value("title", "oops");

    //std::cout << title << std::endl;

    //assign artist to struct
    std::string artist = AlbumData.Artist;
    artist = ParsedJson["artist-credit"][0]["artist"]["name"];
    artist.erase(std::remove(artist.begin(), artist.end(), '"'), artist.end());

    //std::cout << artist << std::endl;

    //assign release date to struct
    std::string date = AlbumData.Date;
    date = ParsedJson["releases"][0]["date"];
    //date.erase(std::remove(date.begin(), date.end(), '"'), date.end());

    std::cout << date << std::endl;

    //const char* ReturnInfo[3] = []

    //return AlbumData;
}