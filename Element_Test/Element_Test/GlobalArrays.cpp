#include "GlobalArrays.h"

std::vector<bool> IsFixDof; // Equivalent to logical, dimension(:), allocatable

int ndtn = 0;
int ITime = 0;
int NDivX = 0;
int NDivY = 0;
int NEl = 0;
int NNod = 0;

const int DATUnit = 2;
const int LOGUnit = 2;
const int MSHUnit = 3;
const int RESUnit = 4;

double gx = 0.0; // Gravity in X-direction
double gy = 9.81; // Gravity in Y-direction 
double Meshdx = 0.0;
double Meshdy = 0.0;
double dt = 0.0;

std::vector<std::array<int, 4>> ICon;  // Connectivity array, assuming 4 nodes per element

std::vector<double> GrvF;  // Gravity Force at each node
std::vector<double> InrF;  // Internal Force at each node
std::vector<double> ExtF;  // External Force at each node
std::vector<double> Mas;   // Mass at each node
std::vector<double> Area; // Area of each element 
std::vector<double> V;
std::vector<double> V0;
std::vector<double> Dis;
std::vector<double> DamF;

std::array<double, 32> MatProp = {}; // Material properties, array of fixed size 32

std::vector<std::array<double, 2>> NodCo; // Node coordinates

// Multidimensional arrays for stress, strain, and other FEM-related properties
std::vector<std::vector<std::vector<double>>> SigG; // Global stress matrix 
std::vector<std::vector<std::vector<double>>> EpsG; // Global strain matrix
std::vector<std::vector<std::vector<double>>> F; // 
std::vector<std::vector<std::vector<double>>> HS; // Shape function
std::vector<std::vector<std::vector<double>>> Sig0; // Initial stress, copy stress from current time step to the next
std::vector<std::vector<std::vector<double>>> Statevar; // State variables

std::vector<std::vector<std::vector<std::vector<double>>>> B; // Strain displacement matrix