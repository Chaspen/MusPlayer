#include <boost/algorithm/string.hpp>
#include "include/json.hpp"
#include <iostream>
#include <string>
#include "album.h"
#include "json/json.h"




using json = nlohmann::json;


typedef struct bAlbumData {
    std::string     Title;
    std::string     Artist;
    std::string     Date;
} AlbumData;


std::string Album::bExposeAlbumData() {

    //acess custom url parser and NOT the third party json library, should probably rename this tbh.
    Json JsonLocal;

    bAlbumData AlbumData;
    const char* TestURL = "https://musicbrainz.org/ws/2/release-group/8d0f0148-7c6e-455d-872e-9851284c5522?inc=aliases%2Bartist-credits%2Breleases&fmt=json";
    
    
    std::string response = JsonLocal.bGetRestResponse(TestURL);
    //std::cout << response << std::endl;

    json ParsedJson = json::parse(response);
    //std::cout << std::setw(4) << j_complete << std::endl;

    //asign title to struct
    std::string title = AlbumData.Title;
    title = ParsedJson.value("title", "oops");
    std::cout << title << std::endl;

    //assign artist to struct
    std::string artist = AlbumData.Artist;
    artist = ParsedJson["artist-credit"][0]["artist"]["name"];
    artist.erase(std::remove(artist.begin(), artist.end(), '"'), artist.end());
    std::cout << artist << std::endl;

    //assign release date to struct
    std::string date = AlbumData.Date;
    date = ParsedJson["releases"][0]["date"];
    //date.erase(std::remove(date.begin(), date.end(), '"'), date.end());
    std::cout << date << std::endl;

}