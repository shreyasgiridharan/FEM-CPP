#include <vector>
#include <array>
#include <cmath>
#include <algorithm>
#include "GlobalArrays.h"
#include "Initial.h"

void initial() {

    std::vector<std::array<std::array<double, 2>, 4>> dNxi(4); // Derivative of shape functions wrt xi and eta
    std::array<std::array<double, 2>, 2> Ja; // Jacobian matrix
    std::array<std::array<double, 2>, 2> JaI; // Inverse of Jacobian

    //double temp = 0.0; // For the case where the number of Gauss points is 1
    double temp = 1.0 / std::sqrt(3.0); // For the case where the number of Gauss points are 4
    
    for (int IEl = 0; IEl < NEl; ++IEl) {
        auto INod = ICon[IEl];

        for (int ig = 0; ig < 4; ++ig) {
            double xi, eta;
            // Calculate xi, eta based on ig
            switch (ig) {
            case 0: xi = -temp; eta = -temp; break;
            case 1: xi = temp; eta = -temp; break;
            case 2: xi = temp; eta = temp; break;
            case 3: xi = -temp; eta = temp; break;
            }

            double rp = 1.0 + xi, rm = 1.0 - xi;
            double sp = 1.0 + eta, sm = 1.0 - eta;

            std::array<std::array<double, 4>, 2> dNxi = { {
                {-0.25 * sm, 0.25 * sm, 0.25 * sp, -0.25 * sp},
                {-0.25 * rm, -0.25 * rp, 0.25 * rp, 0.25 * rm}
            } };

            // Reset Jacobian to zero
            Ja = { {{0.0, 0.0}, {0.0, 0.0}} };

            // Compute Jacobian matrix Ja
            for (int i = 0; i < 2; ++i) {
                for (int j = 0; j < 2; ++j) {
                    for (int k = 0; k < 4; ++k) {
                        int nodeIndex = INod[k] - 1;  // Adjust for zero-based indexing
                        Ja[i][j] += dNxi[i][k] * NodCo[nodeIndex][j];  // Using [j] for x (0) or y (1)
                    }
                }
            }

            // Calculate determinant of Ja
            double detJa = Ja[0][0] * Ja[1][1] - Ja[0][1] * Ja[1][0];
            if (detJa > 0.0) {
                std::array<std::array<double, 2>, 2> JaI = { {
                    {Ja[1][1] / detJa, -Ja[0][1] / detJa},
                    {-Ja[1][0] / detJa, Ja[0][0] / detJa}
                } };

                for (int j = 0; j < 4; ++j) {
                    B[IEl][ig][0][j] = dNxi[0][j] * JaI[0][0] + dNxi[1][j] * JaI[0][1]; // B matrix, row 1
                    B[IEl][ig][1][j] = dNxi[0][j] * JaI[1][0] + dNxi[1][j] * JaI[1][1]; // B matrix, row 2
                }
            }
            else {
                std::cerr << "Negative or zero Jacobian encountered in element " << IEl << std::endl;
                // Error handling, such as exiting the function or handling the condition gracefully
                return;
            }
        }

          // Calculate area of the element (assuming a quadrilateral element)
        Area[IEl] = std::abs((NodCo[INod[2] - 1][0] - NodCo[INod[0] - 1][0]) *
            (NodCo[INod[2] - 1][1] - NodCo[INod[0] - 1][1])) / 2.0;
    }

}
