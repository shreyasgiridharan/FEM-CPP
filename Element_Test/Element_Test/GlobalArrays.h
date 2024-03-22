#pragma once

#ifndef GLOBAL_ARRAYS_H
#define GLOBAL_ARRAYS_H

#include <vector>
#include <array>


extern std::vector<bool> IsFixDof; // Equivalent to logical, dimension(:), allocatable

extern int ndtn;
extern int ITime;
extern int NDivX; 
extern int NDivY;
extern int NEl; 
extern int NNod;

extern const int DATUnit;
extern const int LOGUnit;
extern const int MSHUnit;
extern const int RESUnit;

extern double gx; 
extern double gy;
extern double Meshdx;
extern double Meshdy;
extern double dt;

extern std::vector<std::array<int, 4>> ICon;  // Connectivity array, assuming 4 nodes per element

extern std::vector<double> GrvF;  // Gravity Force at each node
extern std::vector<double> InrF;  // Internal Force at each node
extern std::vector<double> ExtF;  // External Force at each node
extern std::vector<double> Mas;   // Mass at each node
extern std::vector<double> Area;
extern std::vector<double> V;
extern std::vector<double> V0;
extern std::vector<double> Dis;
extern std::vector<double> DamF;
extern std::array<double, 32> MatProp;                      // Material properties, array of fixed size 32

extern std::vector<std::array<double, 2>> NodCo; // Node coordinates

// Multidimensional arrays for stress, strain, and other FEM-related properties
extern std::vector<std::vector<std::vector<double>>> SigG;
extern std::vector<std::vector<std::vector<double>>> EpsG; 
extern std::vector<std::vector<std::vector<double>>> F;
extern std::vector<std::vector<std::vector<double>>> HS;
extern std::vector<std::vector<std::vector<double>>> Sig0; 
extern std::vector<std::vector<std::vector<double>>> Statevar; 

extern std::vector<std::vector<std::vector<std::vector<double>>>> B;

#endif // GLOBAL_ARRAYS_H