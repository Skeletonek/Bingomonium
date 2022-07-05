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
vector<string> BingoFileParser::getUnformattedData(){ return unformattedData; }
vector<string> BingoFileParser::getCategoriesData(){ return categoriesData; }
vector<string> BingoFileParser::getValuesData() { return valuesData; }

void BingoFileParser::readFile(string filename){
 string line;
 fstream file;
 unformattedData.clear();
 categoriesData.clear();
 valuesData.clear();

 file.open(filename, ios::in | ios::out);
 if(file.good()){
    while( !file.eof() ){
       getline(file, line);
       if(line != ""){
       unformattedData.push_back(line);
       }
    }
    _convertToFormatedBingoData();
 }
 else{
     cout << "There was an error while opening a file";
 }
}

vector<string> BingoFileParser::getAllFiles(){
    vector<string> allFilesList;
    try {
        string path = "bingos";
        for (const auto & entry : filesystem::directory_iterator(path)){
            allFilesList.insert(allFilesList.end(), (entry.path().string())); //FIX
        }
    } catch (filesystem::filesystem_error){
        cout << "Filesystem Error Caught";
    } catch (exception) {
        cout << "Exception Caught";
    }
    return allFilesList;
}

void BingoFileParser::_convertToFormatedBingoData(){
    for(string str : unformattedData){
        string key_str = str.substr(0, str.find("\\"));
        string value_str = str.substr(str.find("\\")+1, (str.length()-key_str.length()));
        categoriesData.push_back(key_str);
        valuesData.push_back(value_str);
    }
}
