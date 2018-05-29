//
//  MPC.h
//  mpc
//
//  Created by Yang Taozheng on 5/26/18.
//  Copyright © 2018 Yang Taozheng. All rights reserved.
//

#ifndef MPC_H
#define MPC_H

#include <vector>
#include "Eigen-3.3/Eigen/Core"

using namespace std;

class MPC {
public:
    MPC();
    
    virtual ~MPC();
    
    // Solve the model given an initial state and polynomial coefficients.
    // Return the first actuatotions.
    vector<double> Solve(Eigen::VectorXd state, Eigen::VectorXd coeffs);
};

#endif /* MPC_H */
