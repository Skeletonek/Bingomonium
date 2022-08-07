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
        cout << "File parser threw an unknown error while opening a file."
                "Check if it's accessible for current logged in user.\n";
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
        cout << "Filesystem Error caught. "
                "Check if 'bingos' folder exist and is accessbile for current user.";
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
        value_str = _translateFile(value_str);
        categoriesData.push_back(key_str);
        valuesData.push_back(value_str);
    }
}

string BingoFileParser::_translateFile(string value_str) {
    value_str = _translateAngleBrackets(value_str);
    value_str = _translateAmpersandToHTML(value_str);

    return value_str;
}

string BingoFileParser::_translateAmpersandToHTML(string value) {
    bool htmlOpened = true;
    for(unsigned long i = 0; i < value.length(); i++) {
        if(value[i] == '&') {
            if(value[i+1] == '&') {
                value.erase(value.begin()+i+1);
            } else if (value.substr(i,4) == "&lt;" || value.substr(i,4) == "&gt;") {
                //Do nothing.
                //It is simply a check to not replace '<' and '>' escape characters for HTML
            } else {
                string highlight;
                if(htmlOpened)
                    highlight = "<span style=\"color:#00ff00;\">";
                else
                    highlight = "</span>";
                value = value.replace(i, 1, highlight);
                htmlOpened = !htmlOpened;
                i += highlight.length();
            }
        }
    }

    return value;
}

string BingoFileParser::_translateAngleBrackets(string value) {
    for(unsigned long i = 0; i < value.length(); i++) {
        if(value[i] == '<') {
            value = value.replace(i, 1, "&lt;");
        } else if(value[i] == '>') {
            value = value.replace(i, 1, "&gt;");
        }
    }

    return value;
}
