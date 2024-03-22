#include "ReadData.h"
#include "GlobalArrays.h" // Ensure this file is correctly set up as per previous instructions
#include "Initial.h"
#include <fstream>
#include <cmath>
#include <iostream>
#include <vector>

void readData() {

    int i = 0;

    std::ifstream inputFile("input.dat");
    if (!inputFile.is_open()) {
        std::cerr << "Failed to open input.dat" << std::endl;
        return;
    }

    double temp = 0.0; // Initialising temp

    inputFile >> NDivX >> NDivY;
    inputFile >> Meshdx >> Meshdy;

    NNod = (NDivX + 1) * (NDivY + 1);
    NEl = NDivX * NDivY;

    NodCo.resize(NNod);
    ICon.resize(NEl); // Resize ICon for NEl elements, each with 4 nodes
    IsFixDof.resize(2 * NNod);
    Mas.resize(2 * NNod, 0.0);
    GrvF.resize(2 * NNod, 0.0);
    InrF.resize(2 * NNod, 0.0);
    ExtF.resize(2 * NNod, 0.0);
    DamF.resize(2 * NNod, 0.0);
    V.resize(2 * NNod, 0.0);
    V0.resize(2 * NNod, 0.0);
    Dis.resize(2 * NNod, 0.0);
    // Initialize other arrays similarly...

    // Loop to read node coordinates
    for (i = 0; i < NNod; ++i) {
        inputFile >> temp >> NodCo[0][i] >> NodCo[1][i] >> temp;
        std::cout << NodCo[0][i] << NodCo[1][i];
    }
    
    // Loop to read connectivity
    for (i = 0; i < NEl; ++i) {
                 inputFile >> temp >> ICon[0][i] >> ICon[1][i] >> ICon[2][i] >> ICon[3][i];
                 std::cout << temp << ICon[0][i] << ICon[1][i] << ICon[2][i] << ICon[3][i];
    }

    // Reading material properties
    for (auto& prop : MatProp) {
        inputFile >> prop;
    }

    inputFile >> gx >> gy >> ndtn >> dt;

    for (i = 0; i < NNod; ++i) {
        // If the y-coordinate of the node is 0
        if (NodCo[i][1] == 0.0) {
            IsFixDof[2 * i] = true;     // Fix x DoF
            IsFixDof[2 * i + 1] = true; // Fix y DoF
        }
        // If the x-coordinate of the node is 1.0
        if (NodCo[i][0] == 1.0) {
            IsFixDof[2 * i] = true; // Fix x DoF
        }
        // If the x-coordinate of the node is 0
        if (NodCo[i][0] == 0.0) {
            IsFixDof[2 * i] = true; // Fix x DoF
        }
       
    }

    inputFile.close();

    initial(); // Initialise the shape functions etc. 

    // Set IsFixDof based on specific conditions as in the Fortran code
    // Initialize IsFixDof, adjust other arrays as necessary
}
