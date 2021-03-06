#include "euler.h"
#include "solarsystem.h"

Euler::Euler(double dt) :
    m_dt(dt)
{

}

void Euler::integrateOneStep(SolarSystem &system)
{
    system.calculateForcesAndEnergy(); //24 flops

    for(CelestialBody &body : system.bodies()) {
        body.position += body.velocity*m_dt;
        body.velocity += body.force / body.mass * m_dt; //5 flops tot(29)
    }
}
