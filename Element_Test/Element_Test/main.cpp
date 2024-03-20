
#include <iostream>
#include <vector>
#include <omp.h>
#include "globals.h"
#include "HookeanLaw.h"
#include "ReadData.h"

int main() {

    try {
        // Call readData to load input data and initialize global variables and arrays
        readData();

        // Your simulation code goes here

    }
    catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return 1; // Return a non-zero value to indicate failure
    }

    std::cout << "This is a test program";


    HookenLaw steel(200e9, 0.3, 7850);

    // Example strain values (simplified)
    std::vector<HookenLaw::Vector3D> strainScenarios = {
     {0.001, 0.0, 0.0},
     {0.002, 0.0, 0.0},
     {0.003, 0.0, 0.0},
     {0.004, 0.0, 0.0},
     {0.005, 0.0, 0.0}
    };

    std::vector<HookenLaw::Vector3D> stressResults(strainScenarios.size());

    for (int i = 0; i < strainScenarios.size(); ++i) {
        stressResults[i] = steel.calculateStress(strainScenarios[i]);
    }

    for (size_t i = 0; i < strainScenarios.size(); ++i) {
        const auto& strain = strainScenarios[i];
        const auto& stress = stressResults[i];
        std::cout << "Strain: [" << strain[0] << ", " << strain[1] << ", " << strain[2] << "]\n"
            << "Calculated Stress (Pa): ["
            << "Sigma_x: " << stress[0] << ", "
            << "Sigma_y: " << stress[1] << ", "
            << "Sigma_z: " << stress[2] << "]\n\n";
    }
    
    return 0;
 }

