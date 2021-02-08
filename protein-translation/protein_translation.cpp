#include "protein_translation.h"
#include <map>

using namespace std;

const string Methionine {"Methionine"};
const string Phenylalanine {"Phenylalanine"};
const string Leucine {"Leucine"};
const string Serine {"Serine"};
const string Tyrosine {"Tyrosine"};
const string Cysteine {"Cysteine"};
const string Tryptophan {"Tryptophan"};
const string stop {"STOP"};

const map<string, string> codons_to_proteins {
    {"AUG", Methionine},
    {"UUU", Phenylalanine}, {"UUC", Phenylalanine},
    {"UUA", Leucine}, {"UUG", Leucine},
    {"UCU", Serine}, {"UCC", Serine}, {"UCA", Serine}, 
    {"UCG", Serine},
    {"UAU", Tyrosine}, {"UAC", Tyrosine},
    {"UGU", Cysteine}, {"UGC", Cysteine},
    {"UGG", Tryptophan},
    {"UAA", stop}, {"UAG", stop}, {"UGA", stop},
};

vector<string> protein_translation::proteins(const string& rna) {
    
    vector<string> polypeptide {};

    for (unsigned int n{0}; n < rna.length(); n += 3) {
        string codon = rna.substr(n, 3);
        const string& protein = codons_to_proteins.at(codon);
        if (protein == stop) {
            break;
        }
        polypeptide.push_back(protein);
    }
    return polypeptide;
}



