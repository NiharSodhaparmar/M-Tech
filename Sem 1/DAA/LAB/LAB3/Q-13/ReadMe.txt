System Specifications:
Operating System: Windows
Compiler: g++


1. Alogithm
    Alogithm (A):
        FindRelation((x1,y1,z1),(x2,y2,z2), (x3,y3,z3),(x4,y4,z4))
        1.  line_m <- line with vertices (x1,y1,z1),(x2,y2,z2)
        2.  linr_n <- line with vertices (x3,y3,z3),(x4,y4,z4)
        3.  line_a <- projection of line_m in x-y plane
        4.  line_b <- projection of line_n in x-y plane
        5.  point(x0,y0) <- intersection of line_a and line_b
        6.  if point(x0,y0) doesnt exist line_m and line_n are not related
        7.  z01 <- z coordinate of point(x0,y0) in line_m
        8.  z02 <- z coordinate of point(x0,y0) in line_n
        9.  if z01 > z02 then line_m is above line_n
        10. if z02 > z01 then line_n is above line_m

    Alogithm (B): 
        OrderToPickSticks()
        1.  sort them in order (sticks that are above to below) using Alogithm(A).
        2.  If there is transitivity (line_a > line_b > line_c >line_a) sticks cant be picked.
        3.  else pick them in the sorted order.