#include <iostream>
#include "json/json.h"

int main() {
    Json json;
    const char* TestURL = "https://musicbrainz.org/ws/2/release-group/24f48c6e-8298-3dcf-992c-d3dc07d00a43?inc=aliases%2Bartist-credits%2Breleases&fmt=json";
    std::cout << json.bGetRestResponse(TestURL) << std::endl;
    return 0;
}