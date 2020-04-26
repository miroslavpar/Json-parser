//
// Created by Miroslav Parapanov on 2020-03-30.
//

#include "JsonManager.h"
#include "../model/JsonString.h"
#include "../model/JsonBoolean.h"
#include "../model/JsonNumber.h"
#include <cmath>


JsonArray* JsonManager::readArray(stringstream& jsonStream) {
    char symbol = jsonStream.get();
    if(symbol != '['){
        throw runtime_error(" It's not starting with '[' ");
    }
    readWhitespace(jsonStream);
    symbol = jsonStream.peek();
    if (symbol == ']'){
        jsonStream.get();
        return new JsonArray();
    }
    vector<JsonValue*> arrayValue;

    do {
        arrayValue.push_back(readValue(jsonStream));
        symbol = jsonStream.get();
    }
    while(symbol == ',');

    if(symbol != ']'){
        throw runtime_error("Expected : ']'");
    }
    return new JsonArray(arrayValue);
}
JsonValue* JsonManager::readValue(stringstream& jsonStream) {
    readWhitespace(jsonStream);
    JsonValue* value;
    char symbol = jsonStream.peek();
    switch (symbol) {
        case '{' :
            value = readObject(jsonStream);
            break;
        case '[' :
            value = readArray(jsonStream);
            break;
        case '"' : {
            string keyValue = readString(jsonStream);
            value = new JsonString(keyValue);
            break;
        }
        case 'n':
            if (!readLiteral(jsonStream, "null"))
                throw runtime_error( "Expected to be : null ");
            value = nullptr;
            break;

        case 't':
            if (!readLiteral(jsonStream, "true")){
                throw runtime_error("Expected to be : true ");
            }
            value = new JsonBoolean(true);
            break;

        case 'f':
            if (!readLiteral(jsonStream, "false")) {
                throw runtime_error("Expected to be : false ");
            }
            value = new JsonBoolean(false);
            break;
        case 'e':
            value = readNumber(jsonStream);
            break;
        case '-':
            value = readNumber(jsonStream);
            break;

        case '0':
            value =  readNumber(jsonStream);
            break;

        default:
            if(isDigit(symbol)){
                value = readNumber(jsonStream);
            }
            else {
                throw runtime_error("Unexpected Value");
            }
    }
    readWhitespace(jsonStream);
    return value;
}
JsonObject* JsonManager::readObject(stringstream& jsonStream) {
    readWhitespace(jsonStream);
    char symbol = jsonStream.get();
    if(symbol != '{'){
        throw runtime_error("It's not '{' ");
    }
    readWhitespace(jsonStream);
    symbol = jsonStream.peek();
    unordered_map<string, JsonValue*> map;
    if(symbol == '"') {
        string key;
        do {
            readWhitespace(jsonStream);

            key = readString(jsonStream);

            readWhitespace(jsonStream);
            symbol = jsonStream.get();

            if (symbol != ':') {
                throw runtime_error("Expected ':' ");
            }

            map[key] = readValue(jsonStream);
            symbol = jsonStream.get();
        }
        while(symbol == ',');
    }
    if(symbol != '}'){
        throw runtime_error(" Expected '}' ");
    }
    return new JsonObject(map);
}
string JsonManager::readString(stringstream& jsonStream) {
    if(jsonStream.get() != '"'){
        throw runtime_error("It's not starting with \" ");
    }
    char symbol = jsonStream.get();
    vector<char> key;
    while (symbol != '"') {
        key.push_back(symbol);
        symbol = jsonStream.get();
    }
    return string(key.begin(),key.end());
}
JsonValue* JsonManager::readNumber(stringstream& jsonStream) {
    char symbol = jsonStream.get();
    if(isDigit(symbol)){
        double numValue = getNumber(symbol,jsonStream);
        return new JsonNumber(numValue);
    }
    else if (symbol == '-'){
        symbol = jsonStream.get();
        double numValue = -1 * getNumber(symbol,jsonStream);
        return new JsonNumber(numValue);
    }
    else if(symbol == 'e'){
        return new JsonNumber(geteNumber(symbol,jsonStream));
    }
    else if(symbol == 'E'){
        //       return new JsonNumber(//from a function);
    }
    return nullptr;
}
JsonValue* JsonManager::readJson(stringstream& jsonStream) {
    readWhitespace(jsonStream);
    char symbol = jsonStream.peek();
    switch (symbol) {
        case '{' :
            return readObject(jsonStream);
        case '[':
            return readArray(jsonStream);
        default: throw runtime_error(" Unexpected character occured !");
    }
}
void JsonManager::readWhitespace(stringstream &jsonStream){
    while (isWhiteSpace(jsonStream.peek())) {
        jsonStream.get();
    }
}
bool JsonManager::isWhiteSpace(char symbol) {
    string whitespaces = " \n\r\t";
    // StackOverflow :
    return whitespaces.find(symbol) != string::npos;
}
bool JsonManager::isOperation(char symbol){
    return symbol =='+' || symbol =='-';
}
bool JsonManager::isDigit(char symbol) {
    return symbol >='1' && symbol <= '9';
}
bool JsonManager::readLiteral(stringstream& jsonStream, const string& exp){
    char buffer[exp.size()];
    jsonStream.read(buffer, exp.size());
    return exp == buffer;
}
double JsonManager::geteNumber(char symbol, stringstream& jsonStream){
    if (symbol != 'e' && symbol != 'E'){
        throw runtime_error(" Expected to be 'e' or 'E' ");
    }
    symbol = jsonStream.get();
    if(isOperation(symbol)){
        switch (symbol){
            case '+':{
                symbol = jsonStream.get();
                double value = getNumber(symbol,jsonStream);
                return pow(10,value);
            }
            case '-':{
                symbol = jsonStream.get();
                double value = getNumber(symbol,jsonStream);
                return pow(10,-value);
            }
            default: throw runtime_error(" After operation there must be a digit ");
        }
    }
    else if (isDigit(symbol)) {
        double value = getNumber(symbol,jsonStream);
        return pow(10,value);
    }
    else {
        throw runtime_error(" Expected digit after 'e', 'E' ");
    }
}
double JsonManager::getNumber(char symbol,stringstream& jsonStream){
    stringstream parsingStream;
    if(!isDigit(symbol)){
        throw runtime_error("Unexpected symbol in number");
    }
    int dotCounter = -1;
    do{
        if(symbol == '.'){
            parsingStream << symbol;
            dotCounter +=1;
            if(dotCounter > 0){
                throw runtime_error("too many '.");
            }
            if(!isDigit(jsonStream.peek())){
                throw runtime_error("After . there must be a digit");
            }
            symbol = jsonStream.get();
            continue;
        }
        parsingStream << symbol;
        symbol = jsonStream.peek();
        if(symbol == ','){
            break;
        }
        else {
            symbol = jsonStream.get();
        }
    }
    while (isDigit(symbol) || symbol == '.' || symbol == '0');
    double power = 1;
    if(symbol == 'e'){
        power = geteNumber(symbol,jsonStream);
    }
    readWhitespace(jsonStream);

    double value = 0;
    parsingStream >> value;
    return pow(value, power);
}
bool JsonManager::getIsFileOpened(){
    return isFileOpened;
}
JsonManager::JsonManager(){
    isFileOpened= false;
}
void JsonManager::openFile(string& fileFromConsole){
    ifstream jsonFile(fileFromConsole, ios::in);
    if(!jsonFile){
        cerr << " File with name " << fileFromConsole << " is not found ! \n";
        cout << " Mading empty file with name " << fileFromConsole << endl;
        ofstream out(fileFromConsole, ios::out);
        if(!out){
            throw runtime_error(" Please, reload the program !");
        }
        out.close();
        return;
    }
    isFileOpened = true;
    dbFile = fileFromConsole;
    string line;
    while(!jsonFile.eof()){
        getline(jsonFile, line);
        jsonInfo << line;
    }
    cout << " Successfully opened file : " << fileFromConsole << endl;
    jsonFile.close();
}
bool JsonManager::validateJsonFile(){
    if(!isFileOpened){
        cerr << " No file opened to use validate command !";
        return false;
    }
    try {
        readJson(jsonInfo);
    }
    catch (const char* message){
        cout << message << endl;
        return false;
    }
    cout << " Json file is valid " << endl;
    return true;
}
void JsonManager::print() {
    if(!isFileOpened) {
        cerr << "No file opened to use print command !";
        return;
    }
   JsonValue* value = readJson(jsonInfo);
   value->print();
}
void JsonManager::search(string& key){
    if(!isFileOpened) {
        cerr << " No file opened to use search command !";
        return;
    }
    JsonValue* value = readJson(jsonInfo);
    value->searchFromKey(key);
}
void JsonManager::help(){
    cout << "The following commands are supported:\n"
            "\topen <file>\topens <file>\n"
            "\tclose\t\t\tcloses currently opened file\n"
            "\tsave\t\t\tsaves the currently open file\n"
            "\tsaveas <file>\tsaves the currently open file in <file>\n"
            "\thelp\t\t\tprints this information\n"
            "\tvalidate\t\tchecks if file i validate\n"
            "\tprint\t\t\tprints the content\n"
            "\tsearch <key>\tprints content by <key>\n "
            "\tset <path> <string>\t\tchange the value of <path> to <string>\n "
            "\tcreate <path> <string>\t\tkey is <path>, <string> is adding element in the content in <path>."
            " If there is no <path> the <string> is added to the end of the file\n "
            "\tdelete <path>\tdeletes content in <path>\n"
            "\tmove <from> <to>\tcontent from <from> go to <to>\n";

}
void JsonManager::closeFile() {
    if(!isFileOpened) {
        cerr << " No file opened to use close command !";
        return;
    }
    cout << " Successfully close file " <<dbFile <<endl;
    dbFile.clear();
    jsonInfo.clear();
    isFileOpened = false;
}