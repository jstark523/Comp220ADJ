#include <iostream>
#include <fstream>
#include "SongStorage.h"
#include "LinkedList.h"
#include "PlaylistNode.h"
#include "Playlist.h"

void swap(std::string *xp, std::string *yp){
    std::string  temp= *xp;
    *xp= *yp;
    *yp= temp;
}
void bubbleSort(std::string arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void printArray(std::string arr[], int size){
    int i;
    for(i=0; i < size; i++)
        std::cout << arr[i] << std::endl;
    std::cout << std::endl;
}

void sortLibrary(Playlist* libraryIn){
    if(libraryIn->getSongCount() > 0) {
        std::string arr[libraryIn->getSongCount()];
        SongNode *iterator = libraryIn->getSongList()->getFront();
        Song tempSong = iterator->getItem();
        std::string tempSongString = tempSong.songToString(tempSong);
        arr[0] = tempSongString;
        for (int i = 1; i < libraryIn->getSongCount(); i++) {
            iterator = iterator->getNext();
            tempSong = iterator->getItem();
            tempSongString = tempSong.songToString(tempSong);
            arr[i] = tempSongString;
        }
        int n = sizeof(arr) / sizeof(arr[0]);
        bubbleSort(arr, n);
        std::cout << "Sorted array: \n";
        printArray(arr, n);
    }

    else{
        std::cout<<"Library has no songs"<<std::endl;
    }
}


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

void songInfo(Playlist* library){
    std::string artistName, titleName;
    std::cout<<"Artist Name: "<<std::endl;
    std::cin>>artistName;
    std::cout<<"Title of Song: "<<std::endl;
    std::cin>>titleName;
    Song songToCheck = library->findSong(artistName, titleName);

    std::string delimiter = "*";
    std::string songString = songToCheck.songToString(songToCheck);
    std::string titleString = songString.substr(0, songString.find(delimiter));
    songString.erase(0, songString.find(delimiter) + delimiter.length());
    std::string artistString = songString.substr(0,songString.find(delimiter));
    songString.erase(0, songString.find(delimiter) + delimiter.length());
    std::string durationString = songString.substr(0, songString.find(delimiter));
    songString.erase(0, songString.find(delimiter) + delimiter.length());
    std::string playCountString = songString.substr(0, songString.find(delimiter));
    songString.erase(0, songString.find(delimiter) + delimiter.length());

    std::string realTitle = "Title: " + titleString;
    std::string realArtist = "Artist: " + artistString;
    std::string realDurationSec = "Duration in Seconds: " + durationString;
    std::string realPlayCount = "Play Count: " + playCountString;

    std::cout<<"Song Info:"<<std::endl;
    std::cout<<realArtist<<std::endl;
    std::cout<<realTitle<<std::endl;
    std::cout<<realDurationSec<<std::endl;
    std::cout<<realPlayCount<<std::endl;
}

void removeSong(){
    std::string playlistName, titleName, artistName;
    std::cout<<"Playlist Name: "<<std::endl;
    std::cin>>playlistName;
    std::cout<<"Artist Name: "<<std::endl;
    std::cin>>artistName;
    std::cout<<"Title of Song: "<<std::endl;
    std::cin>>titleName;
    //Song song = SongStorage::remove(titleName);
}

void listArtists(Playlist* libraryIn){
    std::string artist, list, delimiter = "*", del2;
    std::cout<<"Pick an Artist: "<<std::endl;
    std::cin>>artist;
    list = libraryIn->songsOfArtist(artist);
    if(list != "Songs of that artist weren't found in Playlist"){
        while(del2 != "|"){
            std::string artistString = list.substr(0,list.find(delimiter));
            del2 =list.substr(list.find(delimiter) + 1);
            list.erase(0, list.find(delimiter) + delimiter.length());
            std::cout<<artistString<<std::endl;
        }
    }
    else{
        std::cout<<list<<std::endl;
    }

}

void discontinueSong(Playlist* library){
    std::string filename;
    std::cout<<"Enter a filename (with .txt at the end: "<<std::endl;
    std::cin>>filename;
    std::ifstream infile(filename);
    if (infile) {
        while (infile) {
            std::string line;
            getline(infile, line);
            if(line.size() != 0){
                Song* song = new Song(line);
                std::cout<<"test"<<std::endl;
                Song tempSong = library->findSong(song->getArtist(), song->getTitle());
                std::cout<<"test"<<std::endl;
                if((tempSong.getArtist() == song->getArtist()) && (tempSong.getTitle() == song->getTitle())){
                    library->remove(song->getTitle());
                }else{
                    std::cout<<"Song was not found!"<<std::endl;
                }

            }
        }
    }
}

void addToLibrary(Playlist* library){
    std::string filename;
    std::cout<<"Enter a filename (with .txt at the end: "<<std::endl;
    std::cin>>filename;
    std::ifstream infile(filename);
    if (infile) {
        while (infile) {
            std::string line;
            getline(infile, line);
            if(line.size() != 0){
                Song* song = new Song(line);
                library->add(*song);
            }
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
    //listOfPlayists[numOfPlaylists] = playlist;
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
    Playlist* library = new SongStorage();
    std::ifstream infile("library.txt");
    if (infile) {
        while (infile) {
            std::string line;
            getline(infile, line);
            if(line.size() != 0){
                Song* song = new Song(line);
                library->add(*song);
            }
        }
    }


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
            addToLibrary(library);
        }else if(command == "artist") {
            listArtists(library);
        }else if(command == "song") {
            songInfo(library);
        }else if(command == "discontinue"){
            discontinueSong(library);
        }else if(command == "playlists"){
            //display all playlists and durration
        }else if(command == "playlist"){
            //songs left in a given playlist
        }else if(command == "remove") {
            removeSong();
        }else if(command == "library"){
            sortLibrary(library);
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