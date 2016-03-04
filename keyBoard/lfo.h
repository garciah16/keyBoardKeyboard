const float lfo[] = {
 0,   0.004016,   0.008032,    0.01204,    0.01606,     0.0200,    0.02409,    0.02811,    0.03212,    
 0.03614,    0.04016,    0.04417,    0.04819,    0.05220,    0.05622,    0.06024,    0.06425,    
 0.06827,    0.07228,    0.07630,    0.08032,    0.08433,    0.08835,    0.09236,    0.09638,   
 0.100,     0.1044,     0.1084,     0.1124,     0.1164,     0.1204,      0.124,     0.1285,     0.1325, 
 0.1365,     0.1405,     0.1445,     0.1485,     0.1526,     0.1566,     0.1606,     0.1646,     0.1686, 
 0.1726,     0.1767,     0.1807,     0.1847,     0.1887,     0.1927,     0.1967,      0.200,     0.2048,
 0.2088,     0.2128,     0.2168,     0.2208,      0.224,     0.2289,     0.2329,     0.2369,     0.2409,
 0.2449,       0.24,     0.2530,     0.2570,     0.2610,     0.2650,     0.2690,     0.2730,     0.2771,
 0.2811,     0.2851,     0.2891,     0.2931,     0.2971,      0.301,     0.3052,     0.3092,     0.3132,
 0.3172,     0.3212,      0.325,     0.3293,     0.3333,     0.3373,     0.3413,     0.3453,      0.349, 
 0.3534,     0.3574,     0.3614,     0.3654,     0.3694,     0.3734,     0.3775,     0.3815,     0.3855, 
 0.3895,     0.3935,     0.3975,     0.4016,     0.4056,     0.4096,     0.4136,     0.4176,     0.4216,  
 0.425,     0.4297,     0.4337,     0.4377,     0.4417,     0.4457,      0.449,     0.4538,     0.4578,   
 0.4618,     0.4658,     0.4698,      0.473,     0.4779,     0.4819,     0.4859,     0.4899,     0.4939, 
 0.4979,     0.5020,     0.5060,     0.5100,     0.5140,     0.5180,     0.5220,      0.526,     0.5301, 
 0.5341,     0.5381,     0.5421,     0.5461,      0.550,     0.5542,     0.5582,     0.5622,     0.5662, 
 0.5702,      0.574,     0.5783,     0.5823,     0.5863,     0.5903,     0.5943,     0.5983,     0.6024, 
 0.6064,     0.6104,     0.6144,     0.6184,     0.6224,     0.6265,     0.6305,     0.6345,     0.6385,  
 0.6425,     0.6465,      0.650,     0.6546,     0.6586,     0.6626,     0.6666,     0.6706,      0.674, 
 0.6787,     0.6827,     0.6867,     0.6907,     0.6947,      0.698,     0.7028,     0.7068,     0.7108,  
 0.7148,     0.7188,     0.7228,     0.7269,     0.7309,     0.7349,     0.7389,     0.7429,     0.7469,  
 0.75,     0.7550,     0.7590,     0.7630,     0.7670,     0.7710,      0.775,     0.7791,     0.7831,    
 0.7871,     0.7911,     0.7951,      0.799,     0.8032,     0.8072,     0.8112,     0.8152,     0.8192,  
 0.8232,     0.8273,     0.8313,     0.8353,     0.8393,     0.8433,     0.8473,     0.8514,     0.8554,  
 0.8594,     0.8634,     0.8674,     0.8714,      0.875,     0.8795,     0.8835,     0.8875,     0.8915,  
 0.8955,      0.899,     0.9036,     0.9076,     0.9116,     0.9156,     0.9196,     0.9236,     0.9277, 
 0.9317,     0.9357,     0.9397,     0.9437,     0.9477,     0.9518,     0.9558,     0.9598,     0.9638, 
 0.9678,     0.9718,      0.975,     0.9799,     0.9839,     0.9879,     0.9919,     0.9959,           1,
      0.9959,     0.9919,     0.9879,     0.9839,     0.9799,      0.975,     0.9718,     0.9678,    
 0.9638,     0.9598,     0.9558,     0.9518,     0.9477,     0.9437,     0.9397,     0.9357,     0.9317, 
 0.9277,     0.9236,     0.9196,     0.9156,     0.9116,     0.9076,     0.9036,      0.899,     0.8955, 
 0.8915,     0.8875,     0.8835,     0.8795,      0.875,     0.8714,     0.8674,     0.8634,     0.8594, 
 0.8554,     0.8514,     0.8473,     0.8433,     0.8393,     0.8353,     0.8313,     0.8273,     0.8232,  
 0.8192,     0.8152,     0.8112,     0.8072,     0.8032,      0.799,     0.7951,     0.7911,     0.7871,  
 0.7831,     0.7791,      0.775,     0.7710,     0.7670,     0.7630,     0.7590,     0.7550,       0.75,  
 0.7469,     0.7429,     0.7389,     0.7349,     0.7309,     0.7269,     0.7228,     0.7188,     0.7148, 
 0.7108,     0.7068,     0.7028,      0.698,     0.6947,     0.6907,     0.6867,     0.6827,     0.6787, 
 0.674,     0.6706,     0.6666,     0.6626,     0.6586,     0.6546,      0.650,     0.6465,     0.6425,  
 0.6385,     0.6345,     0.6305,     0.6265,     0.6224,     0.6184,     0.6144,     0.6104,     0.6064, 
 0.6024,     0.5983,     0.5943,     0.5903,     0.5863,     0.5823,     0.5783,      0.574,     0.5702, 
 0.5662,     0.5622,     0.5582,     0.5542,      0.550,     0.5461,     0.5421,     0.5381,     0.5341, 
 0.5301,      0.526,     0.5220,     0.5180,     0.5140,     0.5100,     0.5060,     0.5020,     0.4979, 
 0.4939,     0.4899,     0.4859,     0.4819,     0.4779,      0.473,     0.4698,     0.4658,     0.4618,  
 0.4578,     0.4538,      0.449,     0.4457,     0.4417,     0.4377,     0.4337,     0.4297,      0.425,  
 0.4216,     0.4176,     0.4136,     0.4096,     0.4056,     0.4016,     0.3975,     0.3935,     0.3895,  
 0.3855,     0.3815,     0.3775,     0.3734,     0.3694,     0.3654,     0.3614,     0.3574,     0.3534,  
 0.349,     0.3453,     0.3413,     0.3373,     0.3333,     0.3293,      0.325,     0.3212,     0.3172,   
 0.3132,     0.3092,     0.3052,      0.301,     0.2971,     0.2931,     0.2891,     0.2851,     0.2811,  
 0.2771,     0.2730,     0.2690,     0.2650,     0.2610,     0.2570,     0.2530,       0.24,     0.2449,  
 0.2409,     0.2369,     0.2329,     0.2289,      0.224,     0.2208,     0.2168,     0.2128,     0.2088,  
 0.2048,      0.200,     0.1967,     0.1927,     0.1887,     0.1847,     0.1807,     0.1767,     0.1726, 
 0.1686,     0.1646,     0.1606,     0.1566,     0.1526,     0.1485,     0.1445,     0.1405,     0.1365, 
 0.1325,     0.1285,      0.124,     0.1204,     0.1164,     0.1124,     0.1084,     0.1044,      0.100,  
 0.09638,    0.09236,    0.08835,    0.08433,    0.08032,    0.07630,    0.07228,    0.06827,    0.06425, 
 0.06024,    0.05622,    0.05220,    0.04819,    0.04417,    0.04016,    0.03614,    0.03212,    0.02811, 
 0.02409,     0.0200,    0.01606,    0.01204,   0.008032,   0.004016,           0
 };

const float lfo2[] = {
  0,   0.004016,   0.008032,    0.01204,    0.01606,     0.0200,    0.02409,    0.02811, 
  0.03212,    0.03614,    0.04016,    0.04417,    0.04819,    0.05220,    0.05622,    0.06024,  
  0.06425,    0.06827,    0.07228,    0.07630,    0.08032,    0.08433,    0.08835,    0.09236,  
  0.09638,      0.100,     0.1044,     0.1084,     0.1124,     0.1164,     0.1204,      0.124,
0.1285,     0.1325,     0.1365,     0.1405,     0.1445,     0.1485,     0.1526,     0.1566,     
0.1606,     0.1646,     0.1686,     0.1726,     0.1767,     0.1807,     0.1847,     0.1887,     
0.1927,     0.1967,      0.200,     0.2048,     0.2088,     0.2128,     0.2168,     0.2208,     
0.224,     0.2289,     0.2329,     0.2369,     0.2409,     0.2449,       0.24,     0.2530,    
0.2570,     0.2610,     0.2650,     0.2690,     0.2730,     0.2771,     0.2811,     0.2851,   
0.2891,     0.2931,     0.2971,      0.301,     0.3052,     0.3092,     0.3132,     0.3172,   
0.3212,      0.325,     0.3293,     0.3333,     0.3373,     0.3413,     0.3453,      0.349,   
0.3534,     0.3574,     0.3614,     0.3654,     0.3694,     0.3734,     0.3775,     0.3815,   
0.3855,     0.3895,     0.3935,     0.3975,     0.4016,     0.4056,     0.4096,     0.4136,   
0.4176,     0.4216,      0.425,     0.4297,     0.4337,     0.4377,     0.4417,     0.4457,   
0.449,     0.4538,     0.4578,     0.4618,     0.4658,     0.4698,      0.473,     0.4779,    
0.4819,     0.4859,     0.4899,     0.4939,     0.4979,     0.5020,     0.5060,     0.5100,   
0.5140,     0.5180,     0.5220,      0.526,     0.5301,     0.5341,     0.5381,     0.5421,   
0.5461,      0.550,     0.5542,     0.5582,     0.5622,     0.5662,     0.5702,      0.574,   
0.5783,     0.5823,     0.5863,     0.5903,     0.5943,     0.5983,     0.6024,     0.6064,   
0.6104,     0.6144,     0.6184,     0.6224,     0.6265,     0.6305,     0.6345,     0.6385,   
0.6425,     0.6465,      0.650,     0.6546,     0.6586,     0.6626,     0.6666,     0.6706,
0.674,     0.6787,     0.6827,     0.6867,     0.6907,     0.6947,      0.698,     0.7028,    
0.7068,     0.7108,     0.7148,     0.7188,     0.7228,     0.7269,     0.7309,     0.7349,   
0.7389,     0.7429,     0.7469,       0.75,     0.7550,     0.7590,     0.7630,     0.7670,   
0.7710,      0.775,     0.7791,     0.7831,     0.7871,     0.7911,     0.7951,      0.799,   
0.8032,     0.8072,     0.8112,     0.8152,     0.8192,     0.8232,     0.8273,     0.8313,   
0.8353,     0.8393,     0.8433,     0.8473,     0.8514,     0.8554,     0.8594,     0.8634,   
0.8674,     0.8714,      0.875,     0.8795,     0.8835,     0.8875,     0.8915,     0.8955,   
0.899,     0.9036,     0.9076,     0.9116,     0.9156,     0.9196,     0.9236,     0.9277,    
0.9317,     0.9357,     0.9397,     0.9437,     0.9477,     0.9518,     0.9558,     0.9598,   
0.9638,     0.9678,     0.9718,      0.975,     0.9799,     0.9839,     0.9879,     0.9919,     0.9959,    1,
};
