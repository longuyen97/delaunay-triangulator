[![Build Status](https://travis-ci.com/longuyen97/triangulation.svg?token=skDcu5tZxPtyDMyKnKYN&branch=master)](https://travis-ci.com/longuyen97/triangulation)

# Two dimensional triangulation

Triangulation for terrain modelling is a classical engineering problem.

### [Bowyer Watson Algorithm](https://en.wikipedia.org/wiki/Bowyer%E2%80%93Watson_algorithm)

Following pseudocode inspired the implementation:

```
/*
 * pointList: An array of 2D points
 */
function BowyerWatson (pointList)
   triangulation := []
   find super-triangle which is so big that it encloses every original point
   add super-triangle to triangulation 

   for each point in pointList do 
      badEdges := []
      badTriangles := []
      polygon := []

      for each triangle in triangulation do 
         if point is inside circumcircle of triangle    
            add triangle to badTriangles
            add edges of triangle to polygon

      for each edge in polygon do
         if edge appears twice
            add edge to badEdges
        
      for each triangle in badTriangles:
         if triangle is in triangulation
            remove triangle from triangulation

      for edge in polygon:
         if edge is in badEdges:
            remove edge from polygon
         else:
            construct new triangle from edge and point and add it to triangulation

   remove super-triangle and every triangle that has an intersection with the super-triangle

   return triangulation
```

### [Flip Algorithm](https://en.wikipedia.org/wiki/Delaunay_triangulation#Flip_algorithms)
TODO:
* Implement flipping a triangulation
* Implement initial triangulation
* Implement local flipping