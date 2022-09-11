# Numerical-Integration
#Uses OpenMP to compute the integral

The midpoint rule divides the region to be integrated into N evenly spaced segments.  
The value of the function is determined at each location and then multiplied by the size of the subsection.  
This product is then summed for all the subsections to get an estimate of the actual value.
Takes a single command line argument that is the number of subdivisions (N) to use in 
the calculations.
