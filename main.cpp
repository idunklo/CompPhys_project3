#include <iostream>
#include <cmath>
#include <stdlib.h>
#include "solarsystem.h"
#include "euler.h"
#include "verlet.h"

using namespace std;

int main(int argc, char* argv[]){ 

    float t_0 = 0;
    float t_final = 1; //time in years
    float N = 1000;
    float dt = (t_final - t_0)/(N+1);

    SolarSystem solarSystem; //initialize solarsystem
    
    //creating bodies, position given in AU and velocity given in AU/year. Mass given in solar masses.
    CelestialBody &sun = solarSystem.createCelestialBody( vec3(0, 0, 0), vec3(0, 0, 0), 1.0, "Sun"); //placing sun in origo
    CelestialBody &earth = solarSystem.createCelestialBody( vec3(1., 0., 0.), vec3(0., 6.28194273, 0.), 3.00245940E-6, "Earth"); //creating earth 

    vector<CelestialBody> &bodies = solarSystem.bodies(); 
    ofstream &file = solarSystem.get_ostream();
    string filename = "positions.xyz";
    file.open(filename.c_str(), ofstream::out);

    if(!file.good()){
        cout << "error" <<endl;
        terminate();
            
    }

    for (int i = 0; i < bodies.size(); i++){

        CelestialBody &body = bodies[i];
        file << body.name <<" ";
        
    }  

    file <<"\n";   

    //Euler integrator(dt);  
    Verlet integrator(dt);

    for (int timestep = t_0; timestep < N; timestep++){

        integrator.integrateOneStep(solarSystem);

        solarSystem.writeToFile();
    }             

    file.close();

    cout <<"created solarsystem with " << solarSystem.bodies().size() << " planets" << endl;
    
    return 0;
}
