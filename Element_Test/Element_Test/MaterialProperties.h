#pragma once
// Ensure the header is only included once per compilation unit
#ifndef MATERIAL_PROPERTIES_H
#define MATERIAL_PROPERTIES_H

// MaterialProperties struct definition
struct MaterialProperties {
    double youngsModulus; // Young's modulus (E)
    double poissonRatio;  // Poisson's ratio (?)
    double density;       // Density (?)

    // Default constructor
    MaterialProperties() : youngsModulus(0.0), poissonRatio(0.0), density(0.0) {}

    // Parameterized constructor for easy initialization
    MaterialProperties(double E, double nu, double rho) : youngsModulus(E), poissonRatio(nu), density(rho) {}
};

// Function declarations related to MaterialProperties (if any)
// Example: Function to print material properties
void printMaterialProperties(const MaterialProperties& material);

#endif // MATERIAL_PROPERTIES_H