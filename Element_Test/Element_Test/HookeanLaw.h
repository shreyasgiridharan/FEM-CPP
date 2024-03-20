#pragma once
#ifndef HOOKEAN_LAW_H
#define HOOKEAN_LAW_H

#include "MaterialProperties.h"
#include <array>

// HookeanMaterialProperties class definition
class HookenLaw : public MaterialProperties {
public:
    // Using std::array to represent 3D vectors for stress and strain
    using Vector3D = std::array<double, 3>;

    // Default constructor
    HookenLaw() : MaterialProperties() {}

    // Parameterized constructor
    HookenLaw(double E, double nu, double rho)
        : MaterialProperties(E, nu, rho) {}

    // Calculate stress from strain using Hooke's Law for isotropic material
    Vector3D calculateStress(const Vector3D& strain) const {
        Vector3D stress;
        double lambda = poissonRatio * youngsModulus / ((1 + poissonRatio) * (1 - 2 * poissonRatio));
        double mu = youngsModulus / (2 * (1 + poissonRatio));

        // Using the Lamé parameters (lambda, mu), calculate stress
        for (int i = 0; i < 3; ++i) {
            stress[i] = 2 * mu * strain[i] + lambda * (strain[0] + strain[1] + strain[2]);
        }

        return stress;
    }

    // Calculate strain from stress using Hooke's Law for isotropic material
    // This function would be similar in structure to calculateStress, but it solves for strain given stress.
    // The implementation would depend on the specific form of Hooke's law being applied (e.g., 3D stress-strain relations).
};

#endif // HOOKEAN_LAW_H