//Struktura pliku
//Kategoria:Tutaj tekst karty &bingo&
//
//Ten format jest podobny do poprzedniej wersji z tym że wpisywana jest teraz
// nazwa kategorii a nie ID kategorii.
//& - ampersandy oznaczją wyróżnienie tekstu

#include "bingofileparser.h"

BingoFileParser::BingoFileParser(){

}

//getters
vector<string> BingoFileParser::getUnformattedData() { return unformattedData; }
vector<string> BingoFileParser::getCategoriesData() { return categoriesData; }
vector<string> BingoFileParser::getValuesData() { return valuesData; }

void BingoFileParser::readFile(string filename) {
//    string line;
//    fstream file;
    unformattedData.clear();
    categoriesData.clear();
    valuesData.clear();

    QFile file(QString::fromStdString(filename));

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        cout << "File parser threw an unknown error while opening a file. Check if it's accessible for current logged in user.\n";
        return;
    }

    QTextStream ts(&file);
    while (!ts.atEnd()) {
        string line = ts.readLine().toStdString();
        if(line != "") {
            unformattedData.push_back(line);
        }
    }

    _convertToFormatedBingoData();
//    file.open(filename, ios::in | ios::out);
//    if(file.good()){
//       while( !file.eof() ) {
//          getline(file, line);
//          if(line != "") {
//          unformattedData.push_back(line);
//          }
//       }
//       _convertToFormatedBingoData();
//    }
//    else {
//        cout << "There was an error while opening a file";
//    }
}

vector<string> BingoFileParser::getAllFiles() {
    vector<string> allFilesList;
    try {
        string path = "bingos";
        for (const auto & entry : filesystem::directory_iterator(path)) {
            allFilesList.insert(allFilesList.end(), (entry.path().string()));
        }
    } catch (filesystem::filesystem_error) {
        cout << "Filesystem Error caught. Check if 'bingos' folder exist and is accessbile for current user.";
    } catch (exception) {
        cout << "Unknown Exception caught";
    }
    return _convertToFriendlyFileNames(allFilesList);
}

vector<string> BingoFileParser::_convertToFriendlyFileNames(vector<string> allFilesList) {
    vector<string> allFilesFriendlyList;
    for(string str : allFilesList) {
        string str_fr = str.substr(7, str.length()-11);
        allFilesFriendlyList.push_back(str_fr);
    }
    return allFilesFriendlyList;
}

void BingoFileParser::_convertToFormatedBingoData() {
    for(string str : unformattedData) {
        string key_str = str.substr(0, str.find("\\"));
        string value_str = str.substr(str.find("\\")+1, (str.length()-key_str.length()));
        categoriesData.push_back(key_str);
        valuesData.push_back(value_str);
    }
}
