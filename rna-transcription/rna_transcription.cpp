#include "rna_transcription.h"
#include <stdexcept>
#include <sstream>


char rna_transcription::to_rna(char nuc) {
    switch (nuc) {
        case 'C' : return 'G';
        case 'G' : return 'C';
        case 'A' : return 'U';
        case 'T' : return 'A';
    }
    throw invalid_argument( "invalid nucleotide");
} 

string rna_transcription::to_rna(const string dna) {
    
    stringstream strand {""};
    
    for (auto &nuc : dna) {
        strand << rna_transcription::to_rna(nuc);
    }
    return strand.str();
}
