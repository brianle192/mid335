#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std;

//frequency definitions
#define A4 440.0
#define F0 A4
#define F0_note A
#define F0_octave 4i

float arr[]={16.35,17.32,18.35,19.45,20.60,21.83,23.12,24.50,25.96,27.50,29.14,30.87,32.70,34.65,36.71,38.89,41.20,43.65, 46.25,49.00,51.91,55.00,58.27}; 

typedef enum {
    C = 1,
    Cs,
    D,
    Ds,
    E,
    F,
    Fs,
    G,
    Gs,
    A,
    As,
    B,
    END = B,
    HALF_STEPS_PER_OCTAVE = B 
    Z    
} note_t;

double freq(note_t note, int octave_delta);
const float tolerance = 0.004;
int octave;
int main(int argc, char *argv[])
{
    note_t note;
    int octave_delta;

    if (argc != 3) {
        cout << "Usage: " << argv[0] << " <NOTE>  <OCTAVE_DELTA>" << endl;
        return 0;
    }
    //
    note = (note_t)(toupper(argv[1][0]) - 64);
    switch(toupper(argv[1][0])) {
        case 'A': note = A; break;
        case 'B': note = B; break;
        case 'C': note = C; break;
        case 'D': note = D; break;
        case 'E': note = E; break;
        case 'F': note = F; break;
    }
    //You may call your unit test here...

    cout << "freq function unit-test"<< endl;
    
    cout << "note\t" << "octave\t " <<"value\t " << " diff\t " << endl;
    cout << "----\t " << "----\t "<< "-------\t" << "--------\t"<< endl;
    for (int i=1;i <13; i++)
        cout << i <<  endl;
    for (int i=0;i<108; i++)
        cout <<"\t\t"<< freq[i]<<endl;

    for (int i=0; i <108 ; i++){
    double ret = arr[i];
             double diff = ret - freq[i];
                cout << "\t\t\t " << diff << endl;
            }
                double diff = fabs(diff) ;
                    if (diff > tolerance)   
                        cout << "good "<< endl;
                    else
                        cout << "<---- bad" << endl;
               
        if (note = Z && octave = 0)
        cout <<" program execute"<< endl;
        return 1;
    
        cout << "bad element count: "<< diff << endl;
        cout << "unit test complete."<<endl;   
    
    if (note > END) {
        cout << "Invalid note!" << endl;
        return 1;
    }
    octave_delta = atoi(argv[2]);
    cout << HALF_STEPS_PER_OCTAVE << endl;
    cout << freq(note, octave_delta) << endl;
    return 0;
}

//-----------------------------------------------------------
//Generate a frequency in hz that is half_steps away from C_4
//Do not modify this function.
//-----------------------------------------------------------
double freq(note_t note, int octave_delta)
{
    double freq;
    double factor;
    double a;
    int n;
    int octave = octave_delta - F0_octave;

    a = pow(2.0, 1.0/(double)HALF_STEPS_PER_OCTAVE);
    n = note - F0_note;
    freq = F0 * pow(a, (double)n);
    factor = pow(2.0, (double)octave);
    freq = freq * factor;
    return freq;
}


