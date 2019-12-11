#include "IIData.hpp"

IIData::IIData() {

}

IIData::IIData(const std::string &word) {

    this->word = word;
}

std::string &IIData::getWord() {

    return word;
}

std::vector<std::pair<std::string, std::vector<int> > > &IIData::getOccurrences() {

    return occurrences;
}

void IIData::setWord(const std::string &word) {

    this->word = word;
}

void IIData::setOccurrences(const std::vector<std::pair<std::string, std::vector<int> > > &occurrences) {

    this->occurrences = occurrences;
}

void IIData::addOccurrence(const std::string &documentName, int position) {
    int i=0;
    int k=0;
    for(int i=0 ; i < occurrences.size() ; i++){
        if(occurrences[i].first == documentName){
            k++;
            break;
        }
    }
    if(k!=0){
        int j=0;
        while(occurrences[j].first != documentName){
            j++;
        }
        occurrences[j].second.push_back(position);
    }
    else{
        std::pair<std::string, std::vector<int> > newpair;
        newpair.first = documentName;
        newpair.second.push_back(position);
        occurrences.push_back(newpair);
    }
}

void IIData::removeOccurrences(const std::string &documentName) {
    for(int i=0 ; i < occurrences.size() ; i++){
        if(occurrences[i].first == documentName){
            occurrences.erase(occurrences.begin() + i);
        }
    }
}

bool IIData::operator<(const IIData &rhs) const {

    return word < rhs.word;
}

bool IIData::operator>(const IIData &rhs) const {

    return word > rhs.word;
}

bool IIData::operator==(const IIData &rhs) const {

    return word == rhs.word;
}

std::ostream &operator<<(std::ostream &os, const IIData &data) {

    os << "{";
    os << "word: " << data.word << ", ";
    os << "occurrences: [";
    for (unsigned int i = 0 ; i < data.occurrences.size() ; ++i) {
        os << "(";
        os << data.occurrences[i].first << ", ";
        os << "[";
        if (!data.occurrences[i].second.empty()) {
            for (unsigned int j = 0 ; j < data.occurrences[i].second.size() - 1; ++j) {
                os << data.occurrences[i].second[j] << ", ";
            }
            os << data.occurrences[i].second[data.occurrences[i].second.size() - 1];
        }
        os << "]";
        os << ")";
        if (i != data.occurrences.size() - 1) {
            os << ", ";
        }
    }
    os << "]";
    os << "}";

    return os;
}
