#include <iostream>
#include <fstream>
#include "SongStorage.h"
#include "LinkedList.h"

//LinkedList* listOfPlayists = new LinkedList;

void addSongToLibrary(){
    std::string song,title,artist,durr;
    std::getline(std::cin,song);
    std::cout<<"Enter a title: "<<std::endl;
    std::getline(std::cin,title);
    std::cout<<"Enter an artist: "<<std::endl;
    std::getline(std::cin,artist);
    std::cout<<"Enter a duration: "<<std::endl;
    std::getline(std::cin,durr);
    song.append(title+"*"+artist+"*"+durr+"*"+"0");

    std::ofstream outf;
    outf.open("library.txt", std::fstream::app);
    if (outf){
        outf<<song<<std::endl;
    }
    outf.close();

}

void songInfo(){
    std::string artistName, titleName;
    std::cout<<"Artist Name: "<<std::endl;
    std::cin>>artistName;
    std::cout<<"Title of Song: "<<std::endl;
    std::cin>>titleName;
    Song song = SongStorage::findSong(artistName, titleName);
}

void removeSong(){
    std::string playlistName, titleName, artistName;
    std::cout<<"Playlist Name: "<<std::endl;
    std::cin>>playlistName;
    std::cout<<"Artist Name: "<<std::endl;
    std::cin>>artistName;
    std::cout<<"Title of Song: "<<std::endl;
    std::cin>>titleName;
    Song song = SongStorage::remove(titleName);
}

void listArtists(){
    std::string artist, list, delimiter = "*", del2;
    std::cout<<"Pick an Artist: "<<std::endl;
    std::cin>>artist;
    list = SongStorage::songsOfArtist(artist);
    while(del2 != "|"){
        std::string artistString = list.substr(0,list.find(delimiter));
        del2 =list.substr(list.find(delimiter) + 1);
        list.erase(0, list.find(delimiter) + delimiter.length());
        std::cout<<artistString<<std::endl;
    }
}

void createLibrary(){
    SongStorage library = new SongStorage;
    std::ifstream infile("library.txt");
    if (infile) {
        while (infile) {
            std::string line;
            getline(infile, line);
            Song* song = new Song(line);
            SongStorage::add(song);
        }
    }
}


void addSongToPlaylist(){
    std::string name,artist,title;
    std::getline(std::cin,name);
    std::cout<<"Enter a Playlist name: "<<std::endl;
    std::getline(std::cin,artist);
    std::cout<<"Enter an artist: "<<std::endl;
    std::getline(std::cin,title);
    std::cout<<"Enter a song title: "<<std::endl;
    std::getline(std::cin,title);

    //find song in library
    Song* song = new Song () ;

}

void newRandom(SongStorage name){
    //add random shuffled songs to given playlist
}

void newPlaylist(std::string command){
    std::string playlistName;
    std::cerr<<"Please name the Playlist: "<<std::endl;
    std::cin >> playlistName;
    SongStorage playlist = SongStorage(playlistName);
    listOfPlayists[numOfPlaylists] = playlist;
    if(command == "newrandom"){
        //newRandom(playlist);
    }
}

void printCommandInfo(std::string filename , std::string command){
    std::ifstream infile(filename);
    if (infile){
        while (infile){
            std::string line;
            getline(infile, line);
            std::string delimiter = " ";
            std::string token = line.substr(0, line.find(delimiter));

            if(token == command){
                std::cout<<line<<std::endl;
            }
        }
    }
    else {
        std::cerr<<"Could not print command!"<<std::endl;
    }
}

int main() {

    /**
     * - Add a file input to run library restore and playlist restore
     * - When you quit this saves library and playlist to the file
     */


    std::string commandList[14] = {"help", "library", "artist", "song", "import", "discontinue", "playlists",
                                   "playlist", "new", "add", "remove", "playnext", "newrandom", "quit"};
    std::cout << "========== Hi, Welcome To Your Auto DJ! ==========" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Here is a list of commands to get you started:" << std::endl;
    std::cout << "" << std::endl;
    for (int i = 0; i <= 13; i++) {
        std::cout << commandList[i] << ":" << std::endl;
    }


    std::string command;
    std::cout << "What would you like to do: " << std::endl;
    std::cin >> command;
    while(command != "quit") {

        std::cout << "" << std::endl;

        if(command == "help"){
            for (int i = 0; i <= 13; i++) {
                std::cout << commandList[i] << ":" << std::endl;
            }
            std::cout << "Pick a command for further info: " << std::endl;
            std::cin >> command;
            printCommandInfo("commandList.txt", command);
        }else if (command == "add") {
            addSongToPlaylist();
        }else if(command == "new") {
            newPlaylist(command);
        }else if(command == "newrandom") {
            newPlaylist(command);
        }else if(command == "import") {
            createLibrary();
        }else if(command == "artist") {
            listArtists();
        }else if(command == "song") {
            songInfo();
        }else if(command == "discontinue"){
            //call destructor of playlist on the song playlist
        }else if(command == "playlists"){
            //display all playlists and durration
        }else if(command == "playlist"){
            //songs left in a given playlist
        }else if(command == "remove"){
            removeSong();
        }else if(command == "playnext"){

        }else{
            std::cout << "Sorry! this command has not been implemented yet " << std::endl;
        }
        std::cout << "What would you like to do: " << std::endl;
        std::cin >> command;
    }
    std::cout << "========== Thank You For Using Auto DJ! ==========" << std::endl;

    return 0;
}