#include "solarsystem.h" //header file
#include <cmath> 
#include <iostream>
#include <iomanip>
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
            
            //double pi = 2*acos(0.0);  

            //calculating forces
            double G = 4*(M_PI*M_PI); 
            vec3 oneForce  = (G * body1.mass * body2.mass/(dr*dr*dr)) * deltaRVector;
            body1.force -= oneForce;
            body2.force += oneForce;

            m_potentialEnergy += -G*body1.mass*body2.mass/dr; 

        }

        m_kineticEnergy += 0.5*body1.mass*body1.velocity.lengthSquared(); 
    }  
}

int SolarSystem::numberOfBodies() const{

    return m_bodies.size();
}

double SolarSystem::kineticEnergy() const{

    return m_kineticEnergy;
}

double SolarSystem::potentialEnergy() const{

    return m_potentialEnergy;
}

double SolarSystem::totalEnergy() const{
    
    return m_kineticEnergy + m_potentialEnergy;
}

void SolarSystem::writeToFile(){ 

    /*
    if(!m_file.good()){
        m_file.open(filename.c_str(), ofstream::out);
        if(!m_file.good()){
            cout <<"error opening " <<filename <<". " << endl;
            terminate();
        }
    }
    */
    
    //m_file << "name" << " position" <<endl; skips this so it will be easier 
    //to read file in python. 

    for(CelestialBody &body : m_bodies){

       m_file  << setprecision(15) << body.position.x() <<" " << body.position.y() << " " << body.position.z() <<" ";
    }
    m_file <<"\n";
}

    

std::vector<CelestialBody> &SolarSystem::bodies() {
    return m_bodies;
}

std::ofstream &SolarSystem::get_ostream(){
    return m_file;
}




