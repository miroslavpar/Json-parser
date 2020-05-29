//
// Created by Miroslav Parapanov on 2020-03-30.
//

#include "JsonManager.h"
#include "../Accessors/Accessor.h"
#include "../model/JsonString.h"
#include "../model/JsonBoolean.h"
#include "../model/JsonNumber.h"
#include <cmath>
JsonArray* JsonManager::readArray(stringstream& jsonStream)const {
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
JsonValue* JsonManager::readValue(stringstream& jsonStream)const {
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
                throw runtime_error("Expected to be : null ");
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
JsonObject* JsonManager::readObject(stringstream& jsonStream) const{
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
string JsonManager::readString(stringstream& jsonStream)const {
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
JsonValue* JsonManager::readNumber(stringstream& jsonStream)const {
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
JsonValue* JsonManager::readJson(stringstream& jsonStream)const {
    readWhitespace(jsonStream);
    char symbol = jsonStream.peek();
    switch (symbol) {
        case '{' :
            return readObject(jsonStream);
        case '[':
            return readArray(jsonStream);
        default: throw runtime_error(" Unexpected character occurred !");
    }
}
void JsonManager::readWhitespace(stringstream &jsonStream)const{
    while (isWhiteSpace(jsonStream.peek())){
        jsonStream.get();
    }
}
bool JsonManager::isWhiteSpace(char symbol)const {
    string whitespaces = " \n\r\t";
    // StackOverflow :
    return whitespaces.find(symbol) != string::npos;
}
bool JsonManager::isOperation(char symbol)const{
    return symbol =='+' || symbol =='-';
}
bool JsonManager::isDigit(char symbol)const {
    return (symbol >='1' && symbol <= '9') || symbol == '0';
}
bool JsonManager::readLiteral(stringstream& jsonStream, const string& exp)const{
    char buffer[exp.size()];
    jsonStream.read(buffer, exp.size());
    return exp == buffer;
}
double JsonManager::geteNumber(char symbol, stringstream& jsonStream)const{
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
double JsonManager::getNumber(char symbol,stringstream& jsonStream)const{
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
JsonManager::JsonManager(){
    isFileOpened= false;
}
void JsonManager::openFile( string& fileFromConsole){
    if(isFileOpened){
        cerr << "Cannot open file twice !\n";
        return;
    }
    ifstream jsonFile(fileFromConsole, ios::in);
    if(!jsonFile){
        cerr << "File with name " << fileFromConsole << " is not found ! \n";
        cout << "Making empty file with name " << fileFromConsole << endl;
        ofstream out(fileFromConsole, ios::out);
        if(!out){
            throw runtime_error("Please, reload the program !");
        }
        out.close();
        return;
    }
    isFileOpened = true;
    dbFile = fileFromConsole;
    jsonInfo << jsonFile.rdbuf();
    workingJson = readObject(jsonInfo);
    jsonInfo.seekg(0);
    cout << "Successfully opened file : " << fileFromConsole << endl;
}
bool JsonManager::validateJsonFile(){
    if(!isFileOpened){
        cerr << "No file opened to use validate command !";
        return false;
    }
    try {
        readJson(jsonInfo);
    }
    catch (...){
        cout << "File is not in JSON standard!\n";
        return false;
    }
    cout << "Json file is valid " << endl;
    jsonInfo.seekg(0);
    return true;
}
void JsonManager::print()const{
    if(!isFileOpened) {
        cerr << "No file opened to use print command !\n";
        return;
    }
   workingJson->print();
}
void JsonManager::search(const string& key)const{
    if(!isFileOpened) {
        cerr << "No file opened to use search command !\n";
        return;
    }
    cout << " Searching value is : ";
    workingJson->searchFromKey(key);
    cout << "\n";
}
void JsonManager::help() const{
    cout << "The following commands are supported:\n"
            "\topen <file>\topens <file>\n"
            "\tclose\t\t\tcloses currently opened file\n"
            "\tsave\t\t\tsaves the currently open file\n"
            "\tsaveAs <file>\tsaves the currently open file in <file>\n"
            "\thelp\t\t\tprints this information\n"
            "\texit\t\t\texits from program\n"
            "\tvalidate\t\tchecks if file i validate\n"
            "\tprint\t\t\tprints the content\n"
            "\tsearch <key>\tprints content by <key>\n "
            "\tset <path> <string>\t\tchange the value of <path> to <string>   for <path> use <string>.<string>...\n "
            "\tcreate <path> <string>\t\tkey is <path>, <string> is adding element in the content in <path>."
            " If there is no <path> the <string> is added to the end of the file\n "
            "\tdelete <path>\tdeletes content in <path>\n"
            "\tmove <from> <to>\tcontent from <from> go to <to>\n";
}
void JsonManager::closeFile() {
    if(!isFileOpened) {
        cerr << "No file opened to use close command !";
        return;
    }
    cout << "Successfully close file " <<dbFile << endl;
    dbFile.clear();
    jsonInfo.clear();
    isFileOpened = false;
}
void JsonManager::save() {
    if(!isFileOpened) {
        cerr << "The file is closed or never has been opened !";
        return;
    }
    ofstream oFile(dbFile,ios::trunc | ios::out);
    if(!oFile) {
        cerr << "File cannot be opened !\n";
        return;
    }

    workingJson->write(oFile);
    cout << "Changes are saved !\n";
    oFile.close();
    isFileOpened = false;
    jsonInfo.clear();
}
void JsonManager::saveAs(const string& currentFile) {
    if(!isFileOpened) {
        cerr << "Source file has never been opened or has been closed !\n";
        return;
    }
    ofstream oFile(currentFile);
    if(!oFile){
        cerr << "File with name " << currentFile << " cannot be accessed!\n";
    }
    workingJson->write(oFile);
    cout << "Everything is saved in file : " << currentFile << endl;
    oFile.close();
    isFileOpened = false;
    jsonInfo.clear();
}
void JsonManager::exitFromFunction()const{
    exit(0);
}
int convertFromString(const string& line){
    int lineSymbols = line.size();
    int res = 0;
    for(int i = 0 ; i  <lineSymbols ; i++){
        if(line[i] != '[' && line[i] != ']'){
            res = res * 10 + line[i] - '0';
        }
    }
    return res;
}
vector<Accessor> parseLineIntoAccessors(const string& line){
    size_t lineSymbols = line.size();
    vector<Accessor> accessors;
    string parsedWord;
    for (int i = 0 ; i < lineSymbols ; i++){
        if(line[i] == '.' || line[i] == '[' ||line[i] ==']' || i == lineSymbols - 1){

            if(line[i] == ']'){
                parsedWord.push_back(line[i]);
                Accessor obj(parsedWord,convertFromString(parsedWord));
                accessors.push_back(obj);
                parsedWord.clear();
                continue;
            }
            if(i == lineSymbols - 1){
                parsedWord.push_back(line[i]);
                Accessor obj(parsedWord,-1);
                accessors.push_back(obj);
                parsedWord.clear();
                continue;
            }
            Accessor obj(parsedWord,-1);
            accessors.push_back(obj);
            parsedWord.clear();
            if (line[i] =='.')
                continue;

        }
        parsedWord.push_back(line[i]);
    }
    return accessors;
}
void JsonManager::set(const string& key, stringstream& value) {
    if(!isFileOpened){
        cerr << "No file is opened to use set command !\n";
        return;
    }
    JsonValue* jsonValue;
    try{
        jsonValue = readValue(value);
    }
    catch(...){
        cerr << "VALUE is not in JSON standard!\n";
        return;
    }
    vector<Accessor> accessors = parseLineIntoAccessors(key);
    int counter = accessors.size() - 1;
    JsonObject* jsonObject = workingJson;
    for (auto & it : accessors) {
        if(jsonObject->checkKeyByString(it.getField())) {
            JsonValue* checkType = jsonObject->getSecondPropertyByKey(it.getField());
            if (checkType->getType() == JSONOBJECT) {
                if (it.getValue() == -1) {
                    JsonObject* setTypeObj = dynamic_cast<JsonObject *>(checkType);
                    if (counter == 0) {
                        setTypeObj->set(it.getField(), jsonValue);
                        return;
                    }
                    jsonObject = dynamic_cast<JsonObject*>(checkType);
                    counter--;
                    continue;
                }
            }
            //array not done !!!!!
            else if (checkType->getType() == JSONARRAY){
                JsonArray* setTypeArr = dynamic_cast<JsonArray*>(checkType);
                if (counter == 0){
                    setTypeArr->set(it.getValue(),jsonValue);
                    break;
                }
                counter--;
                continue;
            }
            else if (checkType->getType() == JSONSTRING){
                JsonString* setTypeStr  = dynamic_cast<JsonString*>(checkType);
                if(counter == 0){
                    string temp = jsonValue->getValueFromJsonString();
                    setTypeStr->set(temp);
                    break;
                }
                counter--;
                continue;
            }
            else if(checkType->getType() == JSONBOOLEAN){
                JsonBoolean* setTypeBool  = dynamic_cast<JsonBoolean*>(checkType);
                if(counter == 0){
                    setTypeBool->set(jsonValue->getValueFromJsonBoolean());
                    break;
                }
                counter--;
                continue;
            }
            else if(checkType->getType() == JSONNUMBER) {
                JsonNumber* setTypeNum = dynamic_cast<JsonNumber*>(checkType);
                if(counter == 0) {
                    setTypeNum->set(jsonValue->getValueFromJsonNumber());
                    break;
                }
                counter--;
                continue;
            }
        }
        else {
            cerr << "Not existing key !\n";
            return;
        }
    }
    cout << "Changes are made successfully!\n";

}
void JsonManager::deleteByPath(const string& key){
    if(!isFileOpened){
        cerr << "No file is opened to use delete command !\n";
        return;
    }
    vector<Accessor> accessors = parseLineIntoAccessors(key);
    for(auto& it : accessors){
        workingJson->deleteByKey(it.getField());
    }
}
void JsonManager::create(const string& key, stringstream& value) {
    if(!isFileOpened){
        cerr << "No file is opened to use set command !\n";
        return;
    }
    JsonValue* jsonValue;
    try{
        jsonValue = readValue(value);
    }
    catch(...){
        cerr << "VALUE is not in JSON standard!\n";
        return;
    }
    vector<Accessor> accessors = parseLineIntoAccessors(key);
    int counter = accessors.size() - 1;
    JsonObject* jsonObject = workingJson;
    for (auto & it : accessors) {
        pair<string,JsonValue*> newInsertedValue(it.getField(),jsonValue);
        if(counter == 0){
            jsonObject->insertValue(newInsertedValue);
        }
        else{
            JsonValue* checkType = jsonObject->getSecondPropertyByKey(it.getField());
            if(checkType->getType() == JSONOBJECT){
                jsonObject = dynamic_cast<JsonObject*> (checkType);
                counter--;
            }
        }
    }
}