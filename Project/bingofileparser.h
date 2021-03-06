#ifndef BINGOFILEPARSER_H
#define BINGOFILEPARSER_H

#include <string>
#include <iostream>
#include <filesystem>
#include <map>
#include <fstream>
#include <vector>
#include <QFile>
#include <QTextStream>
#include <QString>

using namespace std;

class BingoFileParser {
public:
    BingoFileParser();

    vector<string> getUnformattedData();
    vector<string> getCategoriesData();
    vector<string> getValuesData();

    vector<string> getAllFiles();
    void readFile(string filename);

private:
    vector<string> unformattedData;
    vector<string> categoriesData;
    vector<string> valuesData;

    void _convertToFormatedBingoData();
    vector<string> _convertToFriendlyFileNames(vector<string> allFilesList);
};

#endif // BINGOFILEPARSER_H
