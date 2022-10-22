#include <iostream>
#include <string>
#include "album.h"
#include "rest/rest.h"
#include "include/tinyxml2/tinyxml2.h"
#include <vector>
#include <cstring>


struct bAlbumData {
    const char*     Title;
    const char*     Artist;
    const char*     Date;
} AlbumData;


std::string Album::bExposeAlbumData(std::string ResponseType, std::string MBID) {
    Rest rest;
    bAlbumData AlbumData;


    
    std::string SampleURL = rest.bGetRestResponse("https://musicbrainz.org/ws/2/release-group/24f48c6e-8298-3dcf-992c-d3dc07d00a43?inc=aliases%2Bartist-credits%2Breleases");
    
    const char* pstr = SampleURL.c_str();

    tinyxml2::XMLDocument ret;
    ret.Parse(pstr);

    tinyxml2::XMLElement* titleElement = ret.FirstChildElement("metadata")->FirstChildElement("release-group")->FirstChildElement("title");


    const char* ATitle = AlbumData.Title;
    ATitle = titleElement->GetText();
    std::cout << ATitle;

    //std::cout << fat;

}