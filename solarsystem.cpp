#include "solarsystem.h" //header file
#include <cmath> 
#include <iostream>
using namespace std;

SolarSystem::SolarSystem():
    m_kineticEnergy(0),
    m_potentialEnergy(0)
{
}


CelestialBody& SolarSystem::createCelestialBody(vec3 position, vec3 velocity, double mass, std::string name){

    m_bodies.push_back(CelestialBody(position, velocity, mass, name)); //adds a body to m_bodies
    return m_bodies.back(); // Return reference to the newest added celestial body    
}  

void SolarSystem::calculateForcesAndEnergy(){

    m_kineticEnergy = 0;
    m_potentialEnergy = 0;
    m_angularMomentum.zeros();

    for(CelestialBody &body : m_bodies){
        //reset forces on all bodies
        body.force.zeros();
    }

    for(int i = 0; i < numberOfBodies() ; i++){ 
        //looping over all bodies. Also looping over the last element to get E_k.
        CelestialBody &body1 = m_bodies[i];
        for(int j = i+1; j < numberOfBodies(); j++){
            //Avoiding to calculate the force between the same bodies twice.
            CelestialBody &body2 = m_bodies[j];

            vec3 deltaRVector = body1.position - body2.position;
            double dr = deltaRVector.length(); //finding distance between bodies. 

            //calculating forces
            double G = 6.6740E-11; //m^2 kg^-1 s^-2
            vec3 oneForce  = (G * body1.mass * body2.mass/dr) * deltaRVector;
            body1.force += oneForce;
            body2.force += oneForce;
        }
    }  
}

int SolarSystem::numberOfBodies() const{

    return m_bodies.size();
}

void SolarSystem::writeToFile(string filename){ 

    if(!m_file.good()){
        m_file.open(filename.c_str(), ofstream::out);
        if(!m_file.good()){
            cout <<"error opening " <<filename <<". " << endl;
            terminate();
        }
    }
    
    m_file << numberOfBodies() << endl; //TODO does this write first line of file?
    m_file << "second line of file I guess, no idea what's supposed to stad here" <<endl;

    for(CelestialBody &body : m_bodies){

        m_file  << body.position.x() << body.position.y() << body.position.z() << "\n";
    }
}

    

std::vector<CelestialBody> &SolarSystem::bodies() {
    return m_bodies;
}




