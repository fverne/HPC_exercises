#include "data.h"
#include <math.h>

#ifdef ARRAY_OF_STRUCTS
double 
distance(particle_t *p, int n) {
    
    double dist = -99.0;
    /* fill in your code here
     *
     */

    dist = 0;

    for (int i = 0; i < n; i++) {
        p[i].dist = sqrt(pow(p[i].x, 2) + pow(p[i].y, 2) + pow(p[i].z, 2));
    }

    return dist;
}
#else
double 
distance(particle_t p, int n) {

    double dist = -99.0;
    /* fill in your code here
     *
     */
    dist = 0;

    for (int i = 0; i < n; i++) {
        p.dist[i] = sqrt(pow(p.x[i], 2) + pow(p.y[i], 2) + pow(p.z[i], 2));
    }
    
    return dist;
}
#endif
