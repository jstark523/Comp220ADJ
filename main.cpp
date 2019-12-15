#include <iostream>
#include <fstream>
#include "SongStorage.h"
#include "LinkedList.h"
#include "PlaylistNode.h"
#include "Playlist.h"
#include "PlaylistCollection.h"
#include "PlayListStorage.h"

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
/**
     * This function takes a users artist and song name and then displays
    * all the data on the song
 */

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

/**
     * This function takes our library of songs and with a file input
     * removes all instances of the songs given from library and playlists
 */
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

/**
     * This function takes file name and add all given songs to the library
 */

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

/**
     * This function is called from the new playlist function when the user asks for a random playlist
     * it usues rand() to generate random numbers and with this add random songs to the new playlist
 */

Playlist* randomPlaylist(Playlist* randomList, int totalDurationIn, Playlist* libraryIn){

        bool totalDurationReached = false;
        while(totalDurationReached == false){
            int temp= (rand() % (libraryIn->getSongCount()));
            SongNode* iterator;
            Song songTemp;
            iterator = libraryIn->getSongList()->getFront();
            songTemp = iterator->getItem();
            if(temp == 0){
                if(randomList)
                    if(randomList->getTotalDuration() + songTemp.getDuration() < totalDurationIn){
                        randomList->add(songTemp);
                    }
                    else
                        {
                        totalDurationReached = true;
                    }

            }
            else {
                for (int i = 1; i <= temp; i++) {
                    iterator = iterator->getNext();
                    songTemp = iterator->getItem();
                    if(temp == i){
                        if(randomList->getTotalDuration() + songTemp.getDuration() < totalDurationIn){
                            randomList->add(songTemp);
                        }
                        else{
                            totalDurationReached = true;
                        }
                    }
                }
            }
        }
        return randomList;
    }


/**
     * This function creates a new playlist and calls new random is requested
 */
void newPlaylist(std::string command, Playlist* library){
    std::string playlistName;
    std::cerr<<"Please name the Playlist: "<<std::endl;
    std::cin >> playlistName;
    Playlist* playlist = new SongStorage(playlistName);
    //listOfPlayists[numOfPlaylists] = playlist;
    if(command == "newrandom"){
        std::string duration;
        std::cerr<<"What would you like the duration of the playlist to be?: "<<std::endl;
        std::cin >> duration;
        int durr = std::stoi(duration);
        randomPlaylist(playlist, durr, library);
    }
}

void displayPlaylists(PlaylistCollection* playlists){
    std::string output = playlists->playListNames();
    output += "Duration " + playlists->getTotalDuration();
    std::cout<<output<<std::endl;
}

void displayPlaylist(PlaylistCollection* playlists){
    std::string playlistName;
    std::cerr<<"What playlist are you looking for?"<<std::endl;
    std::cin >> playlistName;
    SongStorage temPlaylist = playlists->findPlaylist(playlists,playlistName);
    int count=0;
    LinkedQueueSong* tempSongList = temPlaylist.getSongList();
    while(count == 0){
        temPlaylist.songsInPlaylist();
        std::cout<<"Total duration in seconds: "<<temPlaylist.getTotalDuration()<<std::endl;
    }
}


/**
     * This function prints the command list and information
 */
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
/**
     * This is where the initial reads are for library and playlists files and also where
     * the bulk of the user interaction is. Where commands are taken and functions are called
 */
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

    PlaylistCollection* playlists = new PlayListStorage();
    std::string delimiter="|", del2;
    std::ifstream file("playlist.txt");
    int count = 0;
    SongStorage* playlist;
    if (file) {
        while (file) {
            std::string line;
            getline(file, line);
            if(line.size() != 0){
                while(del2 != "%"){
                    if(count == 0) {
                        std::string playlistName = line.substr(0, line.find(delimiter));
                        line.erase(0, line.find(delimiter) + delimiter.length());
                        playlist = new SongStorage(playlistName);
                        count++;
                    }
                    std::string songString = line.substr(0, line.find(delimiter));
                    del2 =line.substr(line.find(delimiter) + 1);
                    line.erase(0, line.find(delimiter) + delimiter.length());
                    Song* song1 = new Song(songString);
                    playlist->add(*song1);
                }

                playlists->getPlaylists()->enqueue(*playlist);
                playlists->incPlaylistCount();
            }
        }
    }


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

        /**
            * These if statements are where the user can call the different commands
        */
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
            newPlaylist(command, library);
        }else if(command == "newrandom") {
            newPlaylist(command, library);
        }else if(command == "import") {
            addToLibrary(library);
        }else if(command == "artist") {
            listArtists(library);
        }else if(command == "song") {
            songInfo(library);
        }else if(command == "discontinue"){
            discontinueSong(library);
        }else if(command == "playlists"){
            displayPlaylists(playlists);
        }else if(command == "playlist"){
            displayPlaylist(playlists);
        }else if(command == "remove") {
            removeSong();
        }else if(command == "library"){
            sortLibrary(library);
        }else if(command == "playnext"){
            std::cout << "Sorry! This command has not been implemented yet " << std::endl;
        }else{
            std::cout << "Sorry! This command has not been implemented yet " << std::endl;
        }
        std::cout << "What would you like to do: " << std::endl;
        std::cin >> command;
    }
    std::cout << "========== Thank You For Using Auto DJ! ==========" << std::endl;

    return 0;
}