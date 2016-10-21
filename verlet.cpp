#include "verlet.h"
#include "solarsystem.h"
#include <iostream>

Verlet::Verlet(double dt):
    m_dt(dt)  
{

}

void Verlet::integrateOneStep(SolarSystem &system){

    system.calculateForcesAndEnergy();

    for(CelestialBody &body :system.bodies()){ 

        vec3 prevAccel = body.force/body.mass;
        body.position += m_dt*body.velocity + m_dt*m_dt/2 * prevAccel;

        system.calculateForcesAndEnergy();

        body.velocity += m_dt/2 * (body.force/body.mass + prevAccel);

    }
}

