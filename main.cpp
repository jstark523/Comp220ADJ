#include <iostream>
#include <fstream>

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


    std::string commandList[14] = {"help", "library", "artist", "song",
                                   "import", "discontinue", "playlists",
                                   "playlist", "new", "add",
                                   "remove", "playnext",
                                   "newrandom <name, duration>", "quit"};
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
        }else if (command == "add"){
            addSongToLibrary();
        }else{
            std::cout << "Sorry! this command has not been implemented yet " << std::endl;
        }
        std::cout << "What would you like to do: " << std::endl;
        std::cin >> command;
    }
    std::cout << "========== Thank You For Using Auto DJ! ==========" << std::endl;

    return 0;
}