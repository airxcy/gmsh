Point(1) = {-0.2, 0.7, 0};
Point(2) = {0.4, 0.7, 1};
Point(3) = {-0.8, 0.7, 0};
Point(4) = {-0.8, 0, 0};
Point(5) = {-0.2, 0, 0};
Point(6) = {0.4, 0, 1};
Line(1) = {2, 1};
Line(2) = {1, 3};
Line(3) = {3, 4};
Line(4) = {4, 5};
Line(5) = {5, 1};
Line(6) = {5, 6};
Line(7) = {6, 2};
Line Loop(8) = {7, 1, -5, 6};
Plane Surface(9) = {8};
Line Loop(10) = {2, 3, 4, 5};
Point(7) = {-0.6, 0.4, 0.};
Point(8) = {-0.4, 0.4, 0.};
Point(9) = {-0.5, 0.3, 0.};
Line(13) = {7, 9};
Line(14) = {8, 9};
Line(15) = {8, 7};
Line Loop(100) = {13, -14, 15};
Plane Surface(11) = {10,100};

Compound Surface{9,11};