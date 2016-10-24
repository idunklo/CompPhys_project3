#include <iostream>
#include <cmath>
#include <stdlib.h>
#include "solarsystem.h"
#include "euler.h"
#include "verlet.h"

using namespace std;

int main(int argc, char* argv[]){ 

    float t_0 = 0;
    float t_final = 15; //time in years
    float N = 1000;
    float dt = (t_final - t_0)/(N+1);

    SolarSystem solarSystem; //initialize solarsystem
    
    //creating bodies, position given in AU and velocity given in AU/year. Mass given in solar masses.
    CelestialBody &sun = solarSystem.createCelestialBody( vec3(3.575449E-3, 3.375340E-3, -1.600004E-4), vec3(-1.952401E-6, 6.851124E-6, 3.957326E-8)*365 , 1.0, "Sun"); //placing sun in origo   
    CelestialBody &mercury = solarSystem.createCelestialBody( vec3(-2.728175E-1, 2.020413E-1, 4.143016E-2), vec3(-2.216847E-2, -2.167266E-2, 2.621625E-4)*365, 1.652E-7, "Mercury"); 
    CelestialBody &venus = solarSystem.createCelestialBody( vec3(1.026660E-1, -7.170452E-1, -1.575634E-2), vec3(1.990043E-2, 2.691789E-3, -1.111638E-3)*365, 2.447E-7, "Venus");
    CelestialBody &earth = solarSystem.createCelestialBody( vec3(9.590546E-1, 2.934845E-1, -1.776190E-4), vec3(-5.286248E-3, 1.640189E-2, -7.691198E-8)*365, 3.00245940E-6, "Earth"); //creating earth 
    CelestialBody &mars = solarSystem.createCelestialBody( vec3(1.119656, -8.138412E-1, -4.467628E-2), vec3(8.796737E-3, 1.249663E-2, 4.583204E-5)*365, 3.213E-7, "mars");
    CelestialBody &jupiter = solarSystem.createCelestialBody(vec3(5.431136, -4.177504E-1, 1.231972E-1), vec3(4.910085E-4, -7.167928E-3, 1.876323E-5)*365 , 9.54265748E-4, "Jupiter"); //creating jupiter

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
