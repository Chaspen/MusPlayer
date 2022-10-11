#ifndef H_ALBUM
#define H_ALBUM





class Album {
    public:
        std::string bExposeAlbumData();

        typedef struct bAlbumData {
            std::string     Title;
            std::string     Artist;
            std::string     Date;
        } AlbumData;
};


#endif