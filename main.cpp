#include <iostream>
#include <cmath>
#include <stdlib.h>
#include "solarsystem.h"

using namespace std;

int main(int argc, char* argv[]){

    SolarSystem solarSystem; //initialize solarsystem
    
    //creating bodies, position given in AU and velocity given in AU/year. Mass given in solar masses.
    CelestialBody &sun = solarSystem.createCelestialBody( vec3(0, 0, 0), vec3(0, 0, 0), 1.0); //placing sun in origo
    CelestialBody &earth = solarSystem.createCelestialBody( vec3(1., 0., 0.), vec3(0., 6.28194273, 0.), 3.00245940E-6);  

    vector<CelestialBody> &bodies = solarSystem.bodies();

    for (int i = 0; i < bodies.size(); i++){

        CelestialBody &body = bodies[i];
        cout <<"position is" << body.position << "and velocity" << body.velocity << endl;
    }

    cout <<earth.position << endl;


    return 0;
}
