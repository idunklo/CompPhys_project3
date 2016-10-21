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
        CelestialBody& createCelestialBody(vec3 position, vec3 velocity, double mass, std::string name);
        void calculateForcesAndEnergy();
        int numberOfBodies() const;  

        void writeToFile();
        std::vector<CelestialBody> &bodies();  
        std::ofstream &get_ostream();

    private:
        std::vector<CelestialBody> m_bodies;
        vec3 m_angularMomentum;   
        std::ofstream m_file;
        double m_kineticEnergy;
        double m_potentialEnergy;
};


//const int * const * foo() const; 

#endif // SOLARSYSTEM_H
        
                            
