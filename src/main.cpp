#include "main.hpp"

double sigmoid(double x) {
    return 1.0 / (1.0 + std::exp(-x));
}

struct Neuron {
    std::vector<double> weights;
    double bias = 0.0;
};

double activation(double x) {
    if (std::isfinite(x)) {
        return x;
    }
    else {
        return 0.0;
    }
}

double output(const std::vector<double>& inputs, const std::vector<Neuron>& network) {
    double sum = 0.0;
    for (size_t i = 0; i < network.size(); i++) {
        double dot_product = 0.0;
        for (size_t j = 0; j < inputs.size(); j++) {
            dot_product += inputs[j] * network[i].weights[j];
        }
        sum += activation(dot_product + network[i].bias);
    }
    return sum;
}

std::vector<Neuron> train(std::vector<Neuron> network, double learning_rate, double diff, double inputs) {
    double grad_w0 = diff * inputs[0];
    double grad_b = diff;

    network[0].weights[0] -= learning_rate * grad_w0;
    network[0].bias -= learning_rate * grad_b;
    return network;
}

void save_network(double w1, double w2, double b, const std::string& filename) {
    std::ofstream file(filename, std::ios::binary);
    if (file.is_open()) {
        file << w1 << std::endl << w2 << std::endl << b;
        file.close();
    }
    else {
        std::cout << "Unable to open file: " << filename << std::endl;
    }
}

int load_weights(double w1, double b, const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    std::string line;
    if (file.is_open()) {
        std::getline(file, line);
        w1 = stod(line);
        std::getline(file, line);
        b = stod(line);
        file.close();
        return w1, b;
    }
    else {
        std::cout << "Unable to open file: " << filename << std::endl;
        return 1.0, 1.0;
    }
}

double words(std::string word) {
    std::map<std::string, double> wordMap;

    // "hello"
    wordMap["hello"] = 1.0;
    wordMap["hi"] = 1.0001;
    wordMap["howdy"] = 1.0002;
    wordMap["greetings"] = 1.0003;
    wordMap["salutations"] = 1.0004;
    wordMap["hey"] = 1.0005;
    wordMap["yo"] = 1.0006;
    wordMap["hola"] = 1.0007;
    wordMap["aloha"] = 1.0008;
    wordMap["namaste"] = 1.0009;

    // "boring"
    wordMap["boring"] = 2.0;
    wordMap["dull"] = 2.0001;
    wordMap["monotonous"] = 2.0002;
    wordMap["tedious"] = 2.0003;
    wordMap["uninteresting"] = 2.0004;
    wordMap["mundane"] = 2.0005;
    wordMap["humdrum"] = 2.0006;
    wordMap["stale"] = 2.0007;
    wordMap["lifeless"] = 2.0008;
    wordMap["vapid"] = 2.0009;

    // "nothing"
    wordMap["nothing"] = 0.0;
    wordMap["none"] = -0.0001;
    wordMap["nada"] = -0.0002;
    wordMap["zilch"] = -0.0003;
    wordMap["null"] = -0.0004;
    wordMap["zero"] = -0.0005;
    wordMap["void"] = -0.0006;
    wordMap["blank"] = -0.0007;
    wordMap["empty"] = -0.0008;
    wordMap["nil"] = -0.0009;

    // "happy"
    wordMap["happy"] = 5.0;
    wordMap["joyful"] = 5.0001;
    wordMap["elated"] = 5.0002;
    wordMap["ecstatic"] = 5.0003;
    wordMap["euphoric"] = 5.0004;
    wordMap["gleeful"] = 5.0005;
    wordMap["delighted"] = 5.0006;
    wordMap["overjoyed"] = 5.0007;
    wordMap["blissful"] = 5.0008;
    wordMap["content"] = 5.0009;

    // "good"
    wordMap["good"] = 4.2104;
    wordMap["great"] = 4.2105;
    wordMap["excellent"] = 4.2106;
    wordMap["superb"] = 4.2107;
    wordMap["magnificent"] = 4.2108;
    wordMap["wonderful"] = 4.2109;
    wordMap["fantastic"] = 4.2110;
    wordMap["terrific"] = 4.2111;
    wordMap["phenomenal"] = 4.2112;
    wordMap["spectacular"] = 4.2113;

    // "love"
    wordMap["love"] = 6.0;
    wordMap["adore"] = 6.0001;
    wordMap["cherish"] = 6.0002;
    wordMap["idolize"] = 6.0003;
    wordMap["revere"] = 6.0004;
    wordMap["worship"] = 6.0005;
    wordMap["admire"] = 6.0006;
    wordMap["fancy"] = 6.0007;
    wordMap["treasure"] = 6.0008;
    wordMap["dote"] = 6.0009;

    // "hate"
    wordMap["hate"] = 0.0;
    wordMap["despise"] = 0.0001;
    wordMap["abhor"] = 0.0002;
    wordMap["loathe"] = 0.0003;
    wordMap["detest"] = 0.0004;
    wordMap["dislike"] = 0.0005;
    wordMap["resent"] = 0.0006;
    wordMap["can't stand"] = 0.0007;
    wordMap["execrate"] = 0.0008;
    wordMap["abominate"] = 0.0009;

    // "sad"
    wordMap["sad"] = 1.5;
    wordMap["depressed"] = 1.5001;
    wordMap["melancholic"] = 1.5002;
    wordMap["somber"] = 1.5003;
    wordMap["gloomy"] = 1.5004;
    wordMap["dejected"] = 1.5005;
    wordMap["sorrowful"] = 1.5006;
    wordMap["mournful"] = 1.5007;
    wordMap["despondent"] = 1.5008;
    wordMap["crestfallen"] = 1.5009;

    // "funny"
    wordMap["funny"] = 4.5;
    wordMap["hilarious"] = 4.5001;
    wordMap["uproarious"] = 4.5002;
    wordMap["sidesplitting"] = 4.5003;
    wordMap["hysterical"] = 4.5004;
    wordMap["comical"] = 4.5005;
    wordMap["amusing"] = 4.5006;
    wordMap["droll"] = 4.5007;
    wordMap["facetious"] = 4.5008;
    wordMap["witty"] = 4.5009;

    // "angry"
    wordMap["angry"] = 2.5;
    wordMap["furious"] = 2.5001;
    wordMap["enraged"] = 2.5002;
    wordMap["irate"] = 2.5003;
    wordMap["livid"] = 2.5004;
    wordMap["incensed"] = 2.5005;
    wordMap["outraged"] = 2.5006;
    wordMap["indignant"] = 2.5007;
    wordMap["infuriated"] = 2.5008;
    wordMap["exasperated"] = 2.5009;

    // "beautiful"
    wordMap["beautiful"] = 5.5;
    wordMap["gorgeous"] = 5.5001;
    wordMap["stunning"] = 5.5002;
    wordMap["breathtaking"] = 5.5003;
    wordMap["exquisite"] = 5.5004;
    wordMap["lovely"] = 5.5005;
    wordMap["handsome"] = 5.5006;
    wordMap["pretty"] = 5.5007;
    wordMap["elegant"] = 5.5008;
    wordMap["divine"] = 5.5009;

    // "ugly"
    wordMap["ugly"] = 1.0;
    wordMap["hideous"] = 1.0001;
    wordMap["unsightly"] = 1.0002;
    wordMap["grotesque"] = 1.0003;
    wordMap["repulsive"] = 1.0004;
    wordMap["homely"] = 1.0005;
    wordMap["ghastly"] = 1.0006;
    wordMap["unsightly"] = 1.0007;
    wordMap["revolting"] = 1.0008;
    wordMap["loathsome"] = 1.0009;

    // "smart"
    wordMap["smart"] = 4.8;
    wordMap["intelligent"] = 4.8001;
    wordMap["brilliant"] = 4.8002;
    wordMap["genius"] = 4.8003;
    wordMap["exceptional"] = 4.8004;
    wordMap["clever"] = 4.8005;
    wordMap["astute"] = 4.8006;
    wordMap["sharp"] = 4.8007;
    wordMap["adept"] = 4.8008;
    wordMap["gifted"] = 4.8009;

    // "dumb"
    wordMap["dumb"] = 1.8;
    wordMap["idiotic"] = 1.8001;
    wordMap["moronic"] = 1.8002;
    wordMap["asinine"] = 1.8003;
    wordMap["imbecilic"] = 1.8004;
    wordMap["stupid"] = 1.8005;
    wordMap["foolish"] = 1.8006;
    wordMap["brainless"] = 1.8007;
    wordMap["dim-witted"] = 1.8008;
    wordMap["obtuse"] = 1.8009;

    // "brave"
    wordMap["brave"] = 5.2;
    wordMap["courageous"] = 5.2001;
    wordMap["fearless"] = 5.2002;
    wordMap["intrepid"] = 5.2003;
    wordMap["valiant"] = 5.2004;
    wordMap["heroic"] = 5.2005;
    wordMap["daring"] = 5.2006;
    wordMap["bold"] = 5.2007;
    wordMap["audacious"] = 5.2008;
    wordMap["gallant"] = 5.2009;

    // "health"
    wordMap["healthy"] = 5.0;
    wordMap["fit"] = 5.0001;
    wordMap["robust"] = 5.0002;
    wordMap["vigorous"] = 5.0003;
    wordMap["hale"] = 5.0004;
    wordMap["hearty"] = 5.0005;
    wordMap["spry"] = 5.0006;
    wordMap["sound"] = 5.0007;
    wordMap["buoyant"] = 5.0008;
    wordMap["resilient"] = 5.0009;

    // "movement"
    wordMap["walk"] = 3.0;
    wordMap["run"] = 3.1; 
    wordMap["drive"] = 3.2;
    wordMap["fly"] = 3.3;
    wordMap["swim"] = 3.4;
    wordMap["crawl"] = 3.5;
    wordMap["jump"] = 3.6;
    wordMap["fell"] = 3.61;
    wordMap["gallop"] = 3.7;
    wordMap["climb"] = 3.8;
    wordMap["ascend"] = 3.9;

    // "actions"
    wordMap["do"] = 4.0;
    wordMap["speak"] = 4.1;
    wordMap["listen"] = 4.2;
    wordMap["see"] = 4.3;
    wordMap["feel"] = 4.4;
    wordMap["think"] = 4.5;
    wordMap["feel"] = 4.55;
    wordMap["understand"] = 4.6;
    wordMap["assist"] = 4.7;
    wordMap["request"] = 4.8;
    wordMap["solve"] = 4.9;

    // "emotions"
    wordMap["love"] = 5.0;
    wordMap["rejoice"] = 5.2;
    wordMap["grieve"] = 5.3;
    wordMap["marvel"] = 5.4;
    wordMap["pride"] = 5.5;
    wordMap["anger"] = 5.6;
    wordMap["fear"] = 5.7;
    wordMap["hope"] = 5.8;
    wordMap["regret"] = 5.9;

    return wordMap[word];
}

std::string unwords(double token) {
    std::map<double, std::string> wordMap;

    // "hello"
    wordMap[1.0] = "hello";
    wordMap[1.0001] = "hi";
    wordMap[1.0002] = "howdy";
    wordMap[1.0003] = "greetings";
    wordMap[1.0004] = "salutations";
    wordMap[1.0005] = "hey";
    wordMap[1.0006] = "yo";
    wordMap[1.0007] = "hola";
    wordMap[1.0008] = "aloha";
    wordMap[1.0009] = "namaste";

    // "boring"
    wordMap[2.0] = "boring";
    wordMap[2.0001] = "dull";
    wordMap[2.0002] = "monotonous";
    wordMap[2.0003] = "tedious";
    wordMap[2.0004] = "uninteresting";
    wordMap[2.0005] = "mundane";
    wordMap[2.0006] = "humdrum";
    wordMap[2.0007] = "stale";
    wordMap[2.0008] = "lifeless";
    wordMap[2.0009] = "vapid";

    // "nothing"
    wordMap[0.0] = "nothing";
    wordMap[-0.0001] = "none";
    wordMap[-0.0002] = "nada";
    wordMap[-0.0003] = "zilch";
    wordMap[-0.0004] = "null";
    wordMap[-0.0005] = "zero";
    wordMap[-0.0006] = "void";
    wordMap[-0.0007] = "blank";
    wordMap[-0.0008] = "empty";
    wordMap[-0.0009] = "nil";

    // "happy"
    wordMap[5.0] = "happy";
    wordMap[5.0001] = "joyful";
    wordMap[5.0002] = "elated";
    wordMap[5.0003] = "ecstatic";
    wordMap[5.0004] = "euphoric";
    wordMap[5.0005] = "gleeful";
    wordMap[5.0006] = "delighted";
    wordMap[5.0007] = "overjoyed";
    wordMap[5.0008] = "blissful";
    wordMap[5.0009] = "content";

    // "good"
    wordMap[4.2104] = "good";
    wordMap[4.2105] = "great";
    wordMap[4.2106] = "excellent";
    wordMap[4.2107] = "superb";
    wordMap[4.2108] = "magnificent";
    wordMap[4.2109] = "wonderful";
    wordMap[4.2110] = "fantastic";
    wordMap[4.2111] = "terrific";
    wordMap[4.2112] = "phenomenal";
    wordMap[4.2113] = "spectacular";

    // "love"
    wordMap[6.0] = "love";
    wordMap[6.0001] = "adore";
    wordMap[6.0002] = "cherish";
    wordMap[6.0003] = "idolize";
    wordMap[6.0004] = "revere";
    wordMap[6.0005] = "worship";
    wordMap[6.0006] = "admire";
    wordMap[6.0007] = "fancy";
    wordMap[6.0008] = "treasure";
    wordMap[6.0009] = "dote";

    // "hate"
    wordMap[0.0] = "hate";
    wordMap[0.0001] = "despise";
    wordMap[0.0002] = "abhor";
    wordMap[0.0003] = "loathe";
    wordMap[0.0004] = "detest";
    wordMap[0.0005] = "dislike";
    wordMap[0.0006] = "resent";
    wordMap[0.0007] = "can't stand";
    wordMap[0.0008] = "execrate";
    wordMap[0.0009] = "abominate";

    // "sad"
    wordMap[1.5] = "sad";
    wordMap[1.5001] = "depressed";
    wordMap[1.5002] = "melancholic";
    wordMap[1.5003] = "somber";
    wordMap[1.5004] = "gloomy";
    wordMap[1.5005] = "dejected";
    wordMap[1.5006] = "sorrowful";
    wordMap[1.5007] = "mournful";
    wordMap[1.5008] = "despondent";
    wordMap[1.5009] = "crestfallen";

    // "funny"
    wordMap[4.5] = "funny";
    wordMap[4.5001] = "hilarious";
    wordMap[4.5002] = "uproarious";
    wordMap[4.5003] = "sidesplitting";
    wordMap[4.5004] = "hysterical";
    wordMap[4.5005] = "comical";
    wordMap[4.5006] = "amusing";
    wordMap[4.5007] = "droll";
    wordMap[4.5008] = "facetious";
    wordMap[4.5009] = "witty";

    // "angry"
    wordMap[2.5] = "angry";
    wordMap[2.5001] = "furious";
    wordMap[2.5002] = "enraged";
    wordMap[2.5003] = "irate";
    wordMap[2.5004] = "livid";
    wordMap[2.5005] = "incensed";
    wordMap[2.5006] = "outraged";
    wordMap[2.5007] = "indignant";
    wordMap[2.5008] = "infuriated";
    wordMap[2.5009] = "exasperated";

    return wordMap[token];
}

std::vector<double> get_request() {
    std::string word = "";
    std::string request;
    std::vector<double> convertedRequest = {};
    std::getline(std::cin, request);
    for (auto c : request) {
        if (c == ' ') {
            convertedRequest.push_back(words(word));
            word = "";
        }
        else if (!isdigit(c))
            word += c;
    }
    return convertedRequest;
}

int interpretate(std::string fileName, bool isDebug) {
    std::string line;
    std::ifstream file;
    std::vector<double> request = {};
    double weights[][2] = {};
    file.open(fileName);
    long lineNum = 0;
    if (!file) {
        std::cout << "  ERROR! Could NOT open file '" << fileName << "'!";
    }
    else {
        while (true) {
            std::getline(file, line);
            lineNum++;
            if (isDebug) {
                std::cout << "  INFO: Checking line '" << line << "'.\n";
            }
            if (line == "printTest") {
                while (std::getline(file, line)) {
                    lineNum++;
                    if (line == "end")
                        break;
                    std::cout << line << std::endl;
                }
            }
            else if (line == "getRequest") {
                if (request == {}) {
                    request = get_request();
                }
                else
                    std::cout << "  WARNING! Could NOT create new request! Request setting is not empty! Clear request first.\n";
            }
            else if (line == "getWeights") {
                if (request != {}) {
                    weights = get_weights(request);
                }
                else {
                    std::cout << "  ERROR! Could NOT get weights with empty request! Terminating...\n";
                    return 1;
                }
            }
            else if (line == "clearRequest") {
                request = {};
            }
            else if (line == "noDebug") {
                while (std::getline(file, line)) {
                    lineNum++;
                    if (isDebug) {
                        std::cout << "  INFO: Checking line '" << line << "'.\n";
                    }
                    if (line == "end")
                        break;
                    if (line == "true") {
                        isDebug = false;
                    }
                    else if (line == "false") {
                        isDebug = true;
                    }
                    else
                        std::cout << "  WARNING! Unexcepted setting in file '" << fileName << "' at line '" << lineNum << "'! skipping...\n";
                    std::cout << "  No Debug = " << isDebug << std::endl;
                }
            }
            else if (line == "printDebug") {
                while (std::getline(file, line)) {
                    lineNum++;
                    if (line == "end")
                        break;
                    if (isDebug) {
                        std::cout << "  DEBUG: " << line << std::endl;
                    }
                }
            }
            else if (line == "printDebugInfo") {
                while (std::getline(file, line)) {
                    lineNum++;
                    if (line == "end")
                        break;
                    if (isDebug) {
                        std::cout << "  INFO: " << line << std::endl;
                    }
                }
            }
            else if (line == "printDebugWarn") {
                while (std::getline(file, line)) {
                    lineNum++;
                    if (line == "end")
                        break;
                    if (isDebug) {
                        std::cout << "  WARNING: " << line << std::endl;
                    }
                }
            }
            else if (line == "printDebugErr") {
                while (std::getline(file, line)) {
                    lineNum++;
                    if (line == "end")
                        break;
                    if (isDebug) {
                        std::cout << "  ERROR! " << line << std::endl;
                    }
                }
            }
            if (line == "cmd") {
                while (std::getline(file, line)) {
                    lineNum++;
                    if (line == "end")
                        break;
                    system(line.c_str());
                }
            }
            else if (line == "check") {
                bool isCatch = false;
                while (std::getline(file, line)) {
                    lineNum++;
                    if (line == "catchError")
                        break;
                    std::ifstream checker;
                    checker.open(line);
                    if (!checker)
                        isCatch = true;
                }
                while (std::getline(file, line)) {
                    lineNum++;
                    if (line == "end")
                        break;
                    if (isCatch == true) {
                        if (line == "error") {
                            std::cout << "  ERROR! An 'error' called in '" << fileName << "' at line '" << lineNum << "'.\n";
                            return 1;
                        }
                        std::cout << "  ERROR! " << line << std::endl;
                    }
                }
            }
            else if (line == "function") {
                while (std::getline(file, line)) {
                    lineNum++;
                    if (line == "end")
                        break;
                    int eCode = interpretate(line, isDebug);
                    if (eCode != 0)
                        return 1;
                }
            }
            else if (line == "leave") {
                std::cout << "  INFO: An 'leave' called in '" << fileName << "' at line '" << lineNum << "'.\n";
                return 0;
            }
            else if (line == "error") {
                std::cout << "  ERROR! An 'error' called in '" << fileName << "' at line '" << lineNum << "'.\n";
                return 1;
            }
            else if (line == "end") {
            }
            else
                std::cout << "  WARNING! Unexcepted setting in file '" << fileName << "' at line '" << lineNum << "'!\n  (If you wouldn't know why and you did NOT leaved empty lines, try to save in UTF-8 encoding with no BOM)\n";
                //break;
        }
    }
    return 0;
}

int main() {
    std::string mainFile;
    std::ifstream settings;
    std::string line;
    bool isDebug = true;
    long lineNum = 0;
    settings.open("settings.conf");
    if (!settings) {
        std::cout << "  Unable to open 'settings.conf'!\n  Example:\n 0  settings.conf\n 1  MAINFILE\n 2  res/main.nlai\n 3  end";
        return 1;
    }
    else {
        while (std::getline(settings, line)) {
            lineNum++;
            if (isDebug) {
                std::cout << "  INFO: Checking line '" << line << "'.\n";
            }
            if (line == "MAINFILE") {
                while (std::getline(settings, line)) {
                    lineNum++;
                    if (isDebug) {
                        std::cout << "  INFO: Checking line '" << line << "'.\n";
                    }
                    if (line == "end")
                        break;
                    mainFile = line;
                    std::cout << "  Main File = " << mainFile << std::endl;
                }
            }
            else if (line == "printTest") {
                while (std::getline(settings, line)) {
                    lineNum++;
                    if (isDebug) {
                        std::cout << "  INFO: Checking line '" << line << "'.\n";
                    }
                    if (line == "end")
                        break;
                    std::cout << line << std::endl;
                }
            }
            else if (line == "noDebug") {
                while (std::getline(settings, line)) {
                    lineNum++;
                    if (isDebug) {
                        std::cout << "  INFO: Checking line '" << line << "'.\n";
                    }
                    if (line == "end")
                        break;
                    if (line == "true") {
                        isDebug = false;
                    }
                    else if (line == "false") {
                        isDebug = true;
                    }
                    else
                        std::cout << "  WARNING! Unexcepted setting in file 'settings.conf' at line '" << lineNum << "'! skipping...\n";
                    std::cout << "  No Debug = " << isDebug << std::endl;
                }
            }
            else if (line == "end") {
            }
            else
                std::cout << "  WARNING! Unexcepted setting in file 'settings.conf' at line '" << lineNum << "'! skipping...\n";
        }
        settings.close();
        std::cout << "\n\n\n\n\n";
    }
    int exitCode = interpretate(mainFile, isDebug);
    std::cout << "\n\nExit code:    " << exitCode << std::endl;
    return exitCode;
}
