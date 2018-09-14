#ifndef MULTIPOLYREGRESSIONDATA_H
#define MULTIPOLYREGRESSIONDATA_H

#include <tigon/tigon_global.h>

namespace Tigon {

/*!
 * \li X1 in [0:25:600] indicated torque (Nm)
 * \li X2 in [750:250:4500] engine speed (rpm)
 */
TVector<TVector<double>> breakTorque {
    {-2.366560e+01, -2.425234e+01, -2.650957e+01, -2.945022e+01, -3.195520e+01, -3.695697e+01, -4.248798e+01, -4.866277e+01, -3.609956e+01, -3.552092e+01, -3.668526e+01, -3.814151e+01, -3.842200e+01, -3.897767e+01, -4.056059e+01, -4.233138e+01},
    {2.883341e+00, 2.953720e+00, 4.729870e+00, 7.722602e+00, -8.734036e-01, -1.806924e-02, -1.722689e+01, -2.366547e+01, -1.925279e+01, -2.137792e+01, -2.367667e+01, -2.595654e+01, -2.590449e+01, -2.621764e+01, -2.662739e+01, -2.714946e+01},
    {2.558267e+01, 2.127352e+01, 2.422454e+01, 2.145405e+01, 2.118813e+01, 1.842559e+01, 8.034212e+00, 1.331824e+00, -2.406011e+00, -7.234913e+00, -1.066808e+01, -1.377157e+01, -1.338698e+01, -1.345761e+01, -1.269420e+01, -1.196754e+01},
    {4.543837e+01, 4.216676e+01, 4.451853e+01, 3.850172e+01, 4.571671e+01, 4.188556e+01, 3.455108e+01, 2.995495e+01, 2.468527e+01, 1.958158e+01, 1.696757e+01, 1.526062e+01, 1.540663e+01, 1.543986e+01, 1.607981e+01, 1.651043e+01},
    {6.796083e+01, 6.062938e+01, 6.251861e+01, 6.160700e+01, 6.748141e+01, 6.614195e+01, 6.106795e+01, 5.857808e+01, 5.177656e+01, 4.639808e+01, 4.460323e+01, 4.429281e+01, 4.420024e+01, 4.433734e+01, 4.485382e+01, 4.498840e+01},
    {9.170202e+01, 8.277823e+01, 8.515616e+01, 9.018065e+01, 8.816826e+01, 9.232821e+01, 8.743643e+01, 8.450559e+01, 7.856501e+01, 7.240463e+01, 7.001192e+01, 6.782798e+01, 6.921872e+01, 7.012731e+01, 7.022272e+01, 6.995542e+01},
    {1.175590e+02, 1.072271e+02, 1.132724e+02, 1.175546e+02, 1.150332e+02, 1.185335e+02, 1.138049e+02, 1.104331e+02, 1.053535e+02, 9.841118e+01, 9.542060e+01, 9.136314e+01, 9.423719e+01, 9.591728e+01, 9.559162e+01, 9.492245e+01},
    {1.435999e+02, 1.360553e+02, 1.401826e+02, 1.428976e+02, 1.423403e+02, 1.440267e+02, 1.380850e+02, 1.340442e+02, 1.309683e+02, 1.243817e+02, 1.222684e+02, 1.195866e+02, 1.206477e+02, 1.198876e+02, 1.173866e+02, 1.145135e+02},
    {1.652325e+02, 1.618787e+02, 1.665247e+02, 1.686726e+02, 1.697939e+02, 1.692359e+02, 1.623651e+02, 1.576553e+02, 1.565832e+02, 1.503522e+02, 1.491162e+02, 1.478101e+02, 1.470582e+02, 1.438578e+02, 1.391815e+02, 1.341045e+02},
    {1.652918e+02, 1.945284e+02, 1.905210e+02, 1.919089e+02, 1.955282e+02, 1.936238e+02, 1.878227e+02, 1.853348e+02, 1.823307e+02, 1.762531e+02, 1.745511e+02, 1.728648e+02, 1.711680e+02, 1.672481e+02, 1.644744e+02, 1.609021e+02},
    {1.654179e+02, 1.958659e+02, 2.137456e+02, 2.152515e+02, 2.215586e+02, 2.185966e+02, 2.132804e+02, 2.130143e+02, 2.080781e+02, 2.021541e+02, 1.999860e+02, 1.979195e+02, 1.952777e+02, 1.906383e+02, 1.897672e+02, 1.876996e+02},
    {1.655314e+02, 1.957538e+02, 2.320902e+02, 2.423925e+02, 2.469695e+02, 2.441846e+02, 2.389707e+02, 2.404972e+02, 2.370448e+02, 2.284943e+02, 2.255669e+02, 2.224630e+02, 2.207822e+02, 2.174390e+02, 2.171569e+02, 2.158968e+02},
    {1.655709e+02, 1.956285e+02, 2.320812e+02, 2.694654e+02, 2.717832e+02, 2.686565e+02, 2.646610e+02, 2.679800e+02, 2.660115e+02, 2.548345e+02, 2.511478e+02, 2.470066e+02, 2.462867e+02, 2.442397e+02, 2.445466e+02, 2.440940e+02},
    {1.656579e+02, 1.956541e+02, 2.320082e+02, 2.957316e+02, 2.988078e+02, 2.957997e+02, 2.924320e+02, 2.957234e+02, 2.923917e+02, 2.817574e+02, 2.792622e+02, 2.765430e+02, 2.765501e+02, 2.758355e+02, 2.720682e+02, 2.668492e+02},
    {1.657135e+02, 1.957057e+02, 2.321181e+02, 3.223746e+02, 3.254264e+02, 3.226895e+02, 3.202031e+02, 3.234668e+02, 3.187720e+02, 3.086804e+02, 3.073766e+02, 3.060794e+02, 3.068136e+02, 3.074312e+02, 2.995898e+02, 2.896044e+02},
    {1.656512e+02, 1.956294e+02, 2.318767e+02, 3.481644e+02, 3.521412e+02, 3.501341e+02, 3.502832e+02, 3.532751e+02, 3.490287e+02, 3.392948e+02, 3.373209e+02, 3.315234e+02, 3.232290e+02, 3.168626e+02, 3.065031e+02, 2.957547e+02},
    {1.656202e+02, 1.956244e+02, 2.321005e+02, 3.579365e+02, 3.853613e+02, 3.821047e+02, 3.803634e+02, 3.830835e+02, 3.792855e+02, 3.699093e+02, 3.672652e+02, 3.569674e+02, 3.396445e+02, 3.262940e+02, 3.134164e+02, 3.019051e+02},
    {1.657507e+02, 1.956228e+02, 2.319442e+02, 3.573338e+02, 4.165266e+02, 4.137559e+02, 4.100636e+02, 4.064336e+02, 3.996180e+02, 3.834371e+02, 3.724658e+02, 3.569248e+02, 3.397237e+02, 3.263719e+02, 3.134447e+02, 3.020048e+02},
    {1.656245e+02, 1.956666e+02, 2.320232e+02, 3.579565e+02, 4.459847e+02, 4.428936e+02, 4.397639e+02, 4.297837e+02, 4.199504e+02, 3.969649e+02, 3.776663e+02, 3.568822e+02, 3.398030e+02, 3.264498e+02, 3.134730e+02, 3.021045e+02},
    {1.656765e+02, 1.955250e+02, 2.319474e+02, 3.576351e+02, 4.584303e+02, 4.591638e+02, 4.403236e+02, 4.304720e+02, 4.196128e+02, 3.970735e+02, 3.777253e+02, 3.569968e+02, 3.397649e+02, 3.263794e+02, 3.134218e+02, 3.019971e+02},
    {1.657545e+02, 1.956579e+02, 2.319798e+02, 3.572335e+02, 4.584130e+02, 4.589182e+02, 4.408833e+02, 4.311602e+02, 4.192752e+02, 3.971821e+02, 3.777842e+02, 3.571114e+02, 3.397269e+02, 3.263090e+02, 3.133706e+02, 3.018898e+02},
    {1.658353e+02, 1.956428e+02, 2.320196e+02, 3.576345e+02, 4.583684e+02, 4.588934e+02, 4.408412e+02, 4.311179e+02, 4.193981e+02, 3.970601e+02, 3.776986e+02, 3.571257e+02, 3.396671e+02, 3.262872e+02, 3.134278e+02, 3.019638e+02},
    {1.659325e+02, 1.956863e+02, 2.320416e+02, 3.575760e+02, 4.584181e+02, 4.590966e+02, 4.407990e+02, 4.310757e+02, 4.195211e+02, 3.969381e+02, 3.776130e+02, 3.571401e+02, 3.396073e+02, 3.262654e+02, 3.134851e+02, 3.020378e+02},
    {1.659212e+02, 1.955235e+02, 2.320454e+02, 3.578970e+02, 4.585022e+02, 4.588847e+02, 4.407669e+02, 4.298495e+02, 4.195515e+02, 3.969562e+02, 3.776405e+02, 3.571051e+02, 3.396775e+02, 3.263321e+02, 3.134476e+02, 3.020969e+02},
    {1.660198e+02, 1.956166e+02, 2.320192e+02, 3.571754e+02, 4.581573e+02, 4.592176e+02, 4.407348e+02, 4.286234e+02, 4.195818e+02, 3.969743e+02, 3.776680e+02, 3.570700e+02, 3.397477e+02, 3.263988e+02, 3.134102e+02, 3.021559e+02}
};

} // namespace Tigon

#endif // MULTIPOLYREGRESSIONDATA_H