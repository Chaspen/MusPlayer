#ifndef H_ALBUM
#define H_ALBUM





class Album {
    public:
        std::string bExposeAlbumData(std::string ResponseType, std::string MBID);

        struct bAlbumData {
            std::string     Title;
            std::string     Artist;
            std::string     Date;
        }; 
        bAlbumData AlbumData;
};


#endif