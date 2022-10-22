#ifndef H_ALBUM
#define H_ALBUM


#include <vector>


class Album {
    public:
        std::string bExposeAlbumData(std::string ResponseType, std::string MBID);

        struct bAlbumData {
            const char*     Title;
            const char*     Artist;
            const char*     Date;
        }; 
        bAlbumData AlbumData;
};


#endif