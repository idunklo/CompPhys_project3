#include "euler.h"
#include "solarsystem.h" 

Euler::Euler(double dt):
    m_dt(dt)

{
}
   
void Euler::integrateOneStep(SolarSystem &system){

    system.calculateForcesAndEnergy(); //

    for(CelestialBody &body : system.bodies()){

        body.position += m_dt * body.velocity;
        body.velocity += m_dt * body.force / body.mass;
    }
}


