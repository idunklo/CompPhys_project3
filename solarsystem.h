#ifndef SOLARSYSTEM_H
#define SOLARSYSTEM_H

#include "celestialbody.h"
#include <vector>
#include <string>
#include <fstream>

class SolarSystem
{
    public:
        SolarSystem();
        CelestialBody& createCelestialBody();
        void calculateForcesAndEnergy();
        

